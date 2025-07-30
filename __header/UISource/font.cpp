
#include "stdafx.h"

#define TEXT_MAG (1)
#define INVALID_INDEX (0xFFFFFFFF)
#define TabWidthInSpaces (4)

static LPDIRECT3DDEVICE9 s_pD3DDevice = NULL;
static unsigned int s_FontCount = 0;
static HDC s_FontHDC = NULL;
static HBITMAP s_FontBMP = NULL;

CFontRenderBatcher* g_FontRenderBatcher = NULL;

CFontTexture::CFontTexture()
    :m_bDirty(true)
    ,m_pD3DTexture(NULL)
{
}

CFontTexture::~CFontTexture()
{
    _SAFE_RELEASE(m_pD3DTexture);
}

IDirect3DTexture9* CFontTexture::GetD3DTexture()
{
    if(m_bDirty)
    {
        if(m_pD3DTexture == NULL)
        {
            HRESULT ret = s_pD3DDevice->CreateTexture(FONT_TEXTURE_SIZE, FONT_TEXTURE_SIZE, 1, 0, D3DFMT_A8, D3DPOOL_MANAGED, &m_pD3DTexture, NULL);
            XM_ASSERT(ret == D3D_OK && m_pD3DTexture != NULL);
        }

        D3DLOCKED_RECT rect;
        m_pD3DTexture->LockRect(0, &rect, NULL, D3DLOCK_DISCARD);
        memcpy(rect.pBits, m_BMP, sizeof(m_BMP));
        m_pD3DTexture->UnlockRect(0);

        m_bDirty = false;
    }

    return m_pD3DTexture;
}

void CFontTexture::AddBitmap(const CharInfo& ci, const unsigned char* bmp, unsigned int rowStride)
{
    unsigned int c;
    m_bDirty = true;
    for(unsigned int y = 0; y < ci.height; ++y)
    {
        for(unsigned int x = 0; x < ci.width; ++x)
        {
            c = static_cast<unsigned int>(bmp[y * rowStride + x]) << 2;
            if( c > 255 )
                c = 255;

            m_BMP[(ci.yOffset + y)*FONT_TEXTURE_SIZE + (ci.xOffset + x)] = static_cast<unsigned char>(c);
        }
    }
}

CFont::CFont(HFONT hFont)
    :m_hFont(hFont)
    ,m_RefCount(0)
{
    for(unsigned int i = 0; i < ARRAY_SIZE(m_RemapTable); ++i)
        m_RemapTable[i] = INVALID_INDEX;

    SelectObject(s_FontHDC, s_FontBMP);
    SelectObject(s_FontHDC, m_hFont);
    GetTextMetrics(s_FontHDC, &m_TextMetric);

    m_CurX = INVALID_INDEX;
    m_CurY = INVALID_INDEX;
    m_CurSheet = INVALID_INDEX;
}

CFont::~CFont()
{
    XM_ASSERT(m_RefCount == 0);

    for(unsigned int i = 0; i < m_TextureSheets.size(); ++i)
    {
        delete m_TextureSheets[i];
    }

    DeleteObject(m_hFont);
}

unsigned int CFont::AddRef()
{
    return ++m_RefCount;
}

void CFont::Release()
{
    XM_ASSERT(m_RefCount > 0)
        --m_RefCount;
    if(m_RefCount == 0)
    {
        g_pStaticFontMgr->remove(this);
    }
}

INT CFont::DrawTextW(LPD3DXSPRITE pSprite, LPCWSTR pString, INT Count, LPRECT pRect, DWORD Format, D3DCOLOR Color)
{
    XM_ASSERT(pSprite == NULL);

    if(!pString || pString[0] == '\0' || Count == 0)
        return 0;

    if(Count == -1)
        Count = wcslen(pString);

	std::vector<unsigned int> startLineOffset; 
	std::vector<unsigned int> lineLen;

    unsigned int width = pRect->right - pRect->left;
    unsigned int height = pRect->bottom - pRect->top;
    WrapString(pString, Count, pRect->right - pRect->left, startLineOffset, lineLen);
    XM_ASSERT(startLineOffset.size() == lineLen.size());

    int y = pRect->top;
    if (Format & DT_VCENTER)
    {
        y = pRect->top + static_cast<int>(height - startLineOffset.size() * GetHeight())/2;
    }
    else if (Format & DT_BOTTOM)
    {
        y = pRect->top + static_cast<int>(height - startLineOffset.size() * GetHeight());
    }

    wchar_t c;
    g_FontRenderBatcher->Begin(this);
    for(unsigned int i = 0; i < startLineOffset.size() && static_cast<LONG>(y + 4) < pRect->bottom; ++i, y += GetHeight())
    {
        int x = pRect->left;
        if (Format & DT_CENTER)
        {
            x = pRect->left + static_cast<int>(width - GetStrWidth(pString + startLineOffset[i], lineLen[i]))/2;
        }
        else if (Format & DT_RIGHT)
        {
            x = pRect->left + static_cast<int>(width - GetStrWidth(pString + startLineOffset[i], lineLen[i]));
        }

        for(unsigned int j = 0; j < lineLen[i] && static_cast<LONG>(x + 4) < pRect->right; ++j)
        {
            c = *(pString + startLineOffset[i] + j);
            if( c != L'\t' )
            {
                x = g_FontRenderBatcher->QueueChar(c, x, y, Color);
            }
            else
            {
                x += TabWidthInSpaces * GetCharInfo(L' ').xIncrement;
            }
        }
    }
    g_FontRenderBatcher->End();

    return startLineOffset.size() * GetHeight();
}

INT CFont::DrawTextA(LPD3DXSPRITE pSprite, LPCSTR pString, INT Count, LPRECT pRect, DWORD Format, D3DCOLOR Color)
{
    if(!pString || pString[0] == '\0' || Count == 0)
        return 0;

    XM_ASSERT(pSprite == NULL);
    if(Count == -1)
        Count = strlen(pString);

    XM_ASSERT(Count < 512);
    wchar_t wstr[1024];

    int ret = MultiByteToWideChar(936, 0, pString, Count, wstr, ARRAY_SIZE(wstr));
    if(ret > 0)
        return DrawTextW(NULL, wstr, ret, pRect, Format, Color);

    return 0;
}

HRESULT CFont::OnResetDevice()
{
    return S_OK;
}

HRESULT CFont::OnLostDevice()
{
    return S_OK;
}

HDC CFont::GetDC()
{
    return s_FontHDC;
}

IDirect3DTexture9* CFont::GetTexture(unsigned int index) const
{
    XM_ASSERT(index < m_TextureSheets.size());
    return m_TextureSheets[index]->GetD3DTexture();
}

const CharInfo& CFont::GetCharInfo(wchar_t c)
{
    XM_ASSERT(IsValidChar(c));

    if( m_RemapTable[c] == INVALID_INDEX )
        LoadCharInfo(c);

    XM_ASSERT(m_RemapTable[c] != INVALID_INDEX);

    return m_CharInfoList[m_RemapTable[c]];
}

bool CFont::LoadCharInfo(wchar_t c)
{
    if(m_RemapTable[c] != INVALID_INDEX)
        return true;    // Not really an error

    CharInfo ci;
    memset(&ci, 0, sizeof(ci));
    ci.bitmapIndex = INVALID_INDEX;

    SelectObject(s_FontHDC, m_hFont);

    MAT2 matrix;
    GLYPHMETRICS metrics;

    FIXED zero;
    zero.fract = 0;
    zero.value = 0;
    FIXED one;
    one.fract = 0;
    one.value = 1;

    matrix.eM11 = one;
    matrix.eM12 = zero;
    matrix.eM21 = zero;
    matrix.eM22 = one;

    static unsigned char scratchPad[65536];
    if(GetGlyphOutline(s_FontHDC, c, GGO_GRAY8_BITMAP, &metrics, sizeof(scratchPad), scratchPad, &matrix) != GDI_ERROR)
    {
        unsigned int rowStride = (metrics.gmBlackBoxX + 3) & ~3; // DWORD aligned
        unsigned int size = rowStride * metrics.gmBlackBoxY;

        XM_ASSERT( size <= sizeof(scratchPad) );
        XM_ASSERT( metrics.gmCellIncX > 0 );

        ci.xOffset = 0;
        ci.yOffset = 0;
        ci.width = metrics.gmBlackBoxX;
        ci.height = metrics.gmBlackBoxY;
        ci.xOrigin = metrics.gmptGlyphOrigin.x;
        ci.yOrigin = metrics.gmptGlyphOrigin.y;
        ci.xIncrement = static_cast<unsigned int>(metrics.gmCellIncX);

        AddBitmap(ci, scratchPad, rowStride);
    }
    else
    {
        SIZE size;
        GetTextExtentPoint32W(s_FontHDC, &c, 1, &size);
        if(size.cx)
        {
            ci.xIncrement = size.cx;
            ci.bitmapIndex = 0;
        }
    }

    m_CharInfoList.push_back(ci);
    m_RemapTable[c] = m_CharInfoList.size() - 1;

    return true;
}

void CFont::AddBitmap(CharInfo &ci, const unsigned char* bmp, unsigned int rowStride)
{
    unsigned int nextCurX = m_CurX + ci.width;
    unsigned int nextCurY = m_CurY + GetHeight();

    // These are here for postmortem debugging.
    bool routeA = false, routeB = false;

    if(m_CurSheet == INVALID_INDEX || nextCurY >= FONT_TEXTURE_SIZE)
    {
        routeA = true;
        AddSheet();

        // Recalc our nexts.
        nextCurX = m_CurX + ci.width;
        nextCurY = m_CurY + GetHeight();
    }

    if( nextCurX >= FONT_TEXTURE_SIZE)
    {
        routeB = true;
        m_CurX = 0;
        m_CurY = nextCurY;

        // Recalc our nexts.
        nextCurX = m_CurX + ci.width;
        nextCurY = m_CurY + GetHeight();
    }

    // Check the Y once more - sometimes we advance to a new row and run off
    // the end.
    if(nextCurY >= FONT_TEXTURE_SIZE)
    {
        routeA = true;
        AddSheet();

        // Recalc our nexts.
        nextCurX = m_CurX + ci.width;
        nextCurY = m_CurY + GetHeight();
    }

    ci.bitmapIndex = m_CurSheet;
    ci.xOffset = m_CurX;
    ci.yOffset = m_CurY;

    m_CurX = nextCurX;

    m_TextureSheets[m_CurSheet]->AddBitmap(ci, bmp, rowStride);
}

void CFont::AddSheet()
{
    m_TextureSheets.push_back(new CFontTexture());

    m_CurX = 0;
    m_CurY = 0;
    m_CurSheet = m_TextureSheets.size() - 1;
}

int CFont::DrawTextN(int x, int y, const wchar_t *string, unsigned int color, unsigned int n /*= INVALID_LEN*/)
{
   // return on zero length strings
    if (!string || !string[0] || n == 0)
        return x;

    if(n == INVALID_LEN)
        n = wcslen(string);

   int ptX = x;

   // Queue everything for render.   
   g_FontRenderBatcher->Begin(this);

   unsigned int i;
   wchar_t c;
   for(i = 0, c = string[i]; string[i] && i < n; ++i, c = string[i])
   {
       if( c != L'\t' )
       {
           ptX = g_FontRenderBatcher->QueueChar(c, ptX, y, color);
       }
       else
       {
           ptX += TabWidthInSpaces * GetCharInfo(L' ').xIncrement;
       }
   }

   g_FontRenderBatcher->End();

   return ptX - x;
}

int CFont::DrawTextCenter(int x, int y, const wchar_t *string, unsigned int color, unsigned int n)
{
   // return on zero length strings
    if (!string || !string[0] || n == 0)
        return x;

    if(n == INVALID_LEN)
        n = wcslen(string);

    unsigned int w = GetStrWidth(string, n);
    x -= w / 2;
    y -= GetHeight() / 2;

    return DrawTextN(x, y, string, color, n);
}

void CFont::WrapString(const wchar_t *str, unsigned int n, unsigned int width, std::vector<unsigned int> &startLineOffset, std::vector<unsigned int> &lineLen)
{
    startLineOffset.clear();
    lineLen.clear();

    if (!str || !str[0] || n == 0 || width < GetCharWidth(L'W')) //make sure the line width is greater then a single character
        return;

    if(n == INVALID_LEN)
        n = wcslen(str);

    unsigned int startLine;
    for (unsigned int i = 0; i < n;)
    {
        startLine = i;
        startLineOffset.push_back(startLine);

        // loop until the string is too large
        bool needsNewLine = false;
        unsigned int lineStrWidth = 0;
        for (; i < n; ++i)
        {
            if( str[ i ] == L'\n' )
            {
                needsNewLine = true;
                break;
            }
            else
            {
                lineStrWidth += GetCharInfo(str[i]).xIncrement;
                if( lineStrWidth > width )
                {
                    needsNewLine = true;
                    break;
                }
            }
        }

        if (!needsNewLine)
        {
            // we are done!
            lineLen.push_back(i - startLine);
            return;
        }

        unsigned int j; 

        // Did we hit a hardwrap (newline character) in the string.
        bool hardwrap = ( str[i] == '\n' );

        if ( hardwrap )
        {
            j = i;

			lineLen.push_back(j - startLine);
        }
        else
        {
            j = i - 1;

			lineLen.push_back(j - startLine + 1);
        }

        
        i = j;

        // Now we need to increment through any space characters at the
        // beginning of the next line.
        // We don't skip spaces after a hardwrap because they were obviously intended.
        for (i++; i < n; i++)
        {
            if ( str[i] == L' ' && !hardwrap )
                continue;

            break;
        }
    }
}

unsigned int CFont::GetBreakPos(const wchar_t *str, unsigned int n, unsigned int width, bool breakOnWhitespace)
{
    if (str == NULL || str[0] == L'\0' || n == 0)
        return 0;

    if (n == INVALID_LEN)
        n = wcslen(str);

    unsigned int ret = 0;
    unsigned int lastws = 0;
    wchar_t c;
    unsigned int charCount = 0;

    for (charCount=0; charCount < n; ++charCount)
    {
        c = str[charCount];
        if(c == L'\0')
            break;

        if(c == L'\t')
            c = L' ';

        if(c == L' ')
            lastws = ret+1;

        const CharInfo& ci = GetCharInfo(c);
        if(ci.width > width || ci.xIncrement > width)
        {
            if(lastws && breakOnWhitespace)
                return lastws;
            return ret;
        }

        width -= ci.xIncrement;

        ret++;
    }
    return ret;
}

unsigned int CFont::GetStrWidth(const wchar_t *str, unsigned int n)
{
    if (str == NULL || str[0] == L'\0' || n == 0)
        return 0;

    if (n == INVALID_LEN)
        n = wcslen(str);

    unsigned int totWidth = 0;
    wchar_t curChar;
    unsigned int charCount;

    for(charCount = 0; charCount < n; ++charCount)
    {
        curChar = str[charCount];
        if(curChar == '\0')
            break;

        if(curChar != L'\t')
        {
            totWidth += GetCharInfo(curChar).xIncrement;
        }
        else
        {
            totWidth += GetCharInfo(L' ').xIncrement * TabWidthInSpaces;
        }
    }

    return(totWidth);
}

void CFont::Init()
{
    s_pD3DDevice = g_pStaticDevice;

    s_FontHDC = CreateCompatibleDC(NULL);
    s_FontBMP = CreateCompatibleBitmap(s_FontHDC, 256, 256);

    SelectObject(s_FontHDC, s_FontBMP);
    SetBkColor(s_FontHDC, RGB(  0,   0,   0));
    SetTextColor(s_FontHDC, RGB(255, 255, 255));

    g_FontRenderBatcher = new CFontRenderBatcher();
}

void CFont::Destroy()
{
    DeleteObject(s_FontBMP);
    s_FontBMP = NULL;

    DeleteObject(s_FontHDC);
    s_FontHDC = NULL;

    _SAFE_DELETE(g_FontRenderBatcher);
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//use cache to render
bool CFontRenderBatcher::BeginCache(CFont* font)
{
    if (m_bCache)
        return false;

    m_bCache = true;
    Begin(font);

    return true;
}

void CFontRenderBatcher::EndCache()
{
    End(true);
    m_bCache = false;
}

void CFontRenderBatcher::Begin(CFont *font)
{
    m_pFont = font;
}
//real render
void CFontRenderBatcher::End(bool flush)
{
    if(m_bCache && !flush)
        return;

    if( m_BatchCount == 0)//这样queue里调用玩count后，这儿不会二次渲染
        return;

	FontVertex verts[(MAX_BATCH_COUNT + 4)*6];

    const float fillConventionOffset = 0.5f;
    float drawX, drawY;
    float texLeft, texRight, texTop, texBottom;
    float screenLeft, screenRight, screenTop, screenBottom;

    unsigned int currentPt = 0;
    for( size_t i = 0; i < m_Sheets.size(); ++i )
    {
        // Do some early outs...
        if(!m_Sheets[i].numChars)
            continue;

        m_Sheets[i].startVertex = currentPt;
        for( unsigned int j = 0; j < m_Sheets[i].numChars; ++j )
        {
            // Get some general info to proceed with...
            const CharMarker &m = m_Sheets[i].charIndex[j];
            const CharInfo &ci = m_pFont->GetCharInfo( m.c );

            // Where are we drawing it?
            drawY = m.y + m_pFont->GetBaseline() - ci.yOrigin * TEXT_MAG;
            drawX = m.x + ci.xOrigin;

            texLeft   = static_cast<float>(ci.xOffset)             / static_cast<float>(FONT_TEXTURE_SIZE);
            texRight  = static_cast<float>(ci.xOffset + ci.width)  / static_cast<float>(FONT_TEXTURE_SIZE);
            texTop    = static_cast<float>(ci.yOffset)             / static_cast<float>(FONT_TEXTURE_SIZE);
            texBottom = static_cast<float>(ci.yOffset + ci.height) / static_cast<float>(FONT_TEXTURE_SIZE);

            screenLeft   = drawX - fillConventionOffset;
            screenRight  = drawX - fillConventionOffset + ci.width * TEXT_MAG;
            screenTop    = drawY - fillConventionOffset;
            screenBottom = drawY - fillConventionOffset + ci.height * TEXT_MAG;

            verts[currentPt].x = screenLeft;
            verts[currentPt].y = screenTop;
            verts[currentPt].z = 0.f;
            verts[currentPt].w = 1.f;
            verts[currentPt].color = m.color;
            verts[currentPt].u = texLeft;
            verts[currentPt].v = texTop;
            currentPt++;

            verts[currentPt].x = screenRight;
            verts[currentPt].y = screenTop;
            verts[currentPt].z = 0.f;
            verts[currentPt].w = 1.f;
            verts[currentPt].color = m.color;
            verts[currentPt].u = texRight;
            verts[currentPt].v = texTop;
            currentPt++;

            verts[currentPt].x = screenRight;
            verts[currentPt].y = screenBottom;
            verts[currentPt].z = 0.f;
            verts[currentPt].w = 1.f;
            verts[currentPt].color = m.color;
            verts[currentPt].u = texRight;
            verts[currentPt].v = texBottom;
            currentPt++;

            verts[currentPt] = verts[currentPt - 1];
            currentPt++;

            verts[currentPt].x = screenLeft;
            verts[currentPt].y = screenBottom;
            verts[currentPt].z = 0.f;
            verts[currentPt].w = 1.f;
            verts[currentPt].color = m.color;
            verts[currentPt].u = texLeft;
            verts[currentPt].v = texBottom;
            currentPt++;

            verts[currentPt] = verts[currentPt - 5];
            currentPt++;
        }
    }

    s_pD3DDevice->SetFVF(FontVertex::FVF);
    s_pD3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
    s_pD3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
    s_pD3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
    s_pD3DDevice->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_ADD);

    // Now do an optimal render!
    for( unsigned int i = 0; i < m_Sheets.size(); i++ )
    {
        if(!m_Sheets[i].numChars)
            continue;

        s_pD3DDevice->SetTexture(0, m_pFont->GetTexture(i));
        s_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST, m_Sheets[i].numChars * 2, &verts[m_Sheets[i].startVertex], sizeof(FontVertex));
    }

    s_pD3DDevice->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_MODULATE);

    m_BatchCount = 0;
    for(unsigned int i = 0; i < m_Sheets.size(); ++i)
    {
        m_Sheets[i].numChars = 0;
        m_Sheets[i].startVertex = 0;
    }
}

int CFontRenderBatcher::QueueChar(wchar_t c, int x, int y, unsigned int color)
{
    const CharInfo &ci = m_pFont->GetCharInfo( c );

    if( ci.width != 0 && ci.height != 0 )
    {
        SheetMarker &sm = GetSheetMarker(ci.bitmapIndex);

        XM_ASSERT(sm.numChars < MAX_BATCH_COUNT);

        CharMarker &m = sm.charIndex[sm.numChars];
        sm.numChars++;

        m.c = c;
        m.x = static_cast<float>(x);
        m.y = static_cast<float>(y);
        m.color = color;

        ++m_BatchCount;

        if( m_BatchCount >= MAX_BATCH_COUNT )
        {
            End(true);
            Begin(m_pFont);
        }
    }

    return x + ci.xIncrement;
}

CFontRenderBatcher::SheetMarker & CFontRenderBatcher::GetSheetMarker( unsigned int sheetID )
{
    // Allocate if it doesn't exist...
    if(m_Sheets.size() <= sheetID)
    {
        if(sheetID >= m_Sheets.size())
            m_Sheets.resize(sheetID+1);

        m_Sheets[sheetID].numChars = 0;
        m_Sheets[sheetID].startVertex = 0; // cosmetic initialization
    }

    return m_Sheets[sheetID];
}