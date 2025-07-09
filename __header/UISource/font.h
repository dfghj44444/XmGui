#ifndef FONT_H
#define FONT_H

#define ARRAY_SIZE( x ) ( sizeof(x) / sizeof(x[0]) )
#define INVALID_LEN (0xFFFFFFFF)

namespace XM
{
    class fontCreateParam;
}

struct CharInfo
{
    unsigned int bitmapIndex;     ///< @note -1 indicates character is NOT to be
    ///  rendered, i.e., \n, \r, etc.
    unsigned int  xOffset;        ///< x offset into bitmap sheet
    unsigned int  yOffset;        ///< y offset into bitmap sheet

    unsigned int  width;          ///< width of character (pixels)
    unsigned int  height;         ///< height of character (pixels)
    int  xOrigin;
    int  yOrigin;
    unsigned int  xIncrement;
};

struct FontVertex
{
    float x, y, z, w;
    unsigned int color;
    float u,v;

    enum
    {
        FVF = D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1,
    };
};

// 包含配置文件
#include "../../include/XmGuiConfig.h"

#define FONT_TEXTURE_SIZE XMGUI_FONT_TEXTURE_SIZE
class CFontTexture
{
public:
    CFontTexture();
    ~CFontTexture();
    void AddBitmap(const CharInfo& ci, const unsigned char* bmp, unsigned int rowStride);
    IDirect3DTexture9* GetD3DTexture();

private:
    bool m_bDirty;
    unsigned char m_BMP[FONT_TEXTURE_SIZE*FONT_TEXTURE_SIZE];
    IDirect3DTexture9* m_pD3DTexture;
};

class CFont
{
public:
    CFont(HFONT hFont);
    virtual ~CFont();

    unsigned int AddRef();
    void Release();
    unsigned int GetRefCount() const { return m_RefCount; }

    INT DrawTextW(LPD3DXSPRITE pSprite, LPCWSTR pString, INT Count, LPRECT pRect, DWORD Format, D3DCOLOR Color);
    INT DrawTextA(LPD3DXSPRITE pSprite, LPCSTR pString, INT Count, LPRECT pRect, DWORD Format, D3DCOLOR Color);

    HRESULT OnLostDevice();
    HRESULT OnResetDevice();

    HDC GetDC();
    //-------------------------------------------------------------------------------------------------------------------------------------------------------- 
    IDirect3DTexture9* GetTexture(unsigned int index) const;

    const CharInfo& GetCharInfo(wchar_t c);
    bool LoadCharInfo(wchar_t c);

    unsigned int GetCharHeight(wchar_t c) { return GetCharInfo(c).height; }
    unsigned int GetCharWidth(wchar_t c) { return GetCharInfo(c).width; }
    unsigned int GetCharXIncrement(wchar_t c) { return GetCharInfo(c).xIncrement; }
    bool IsValidChar(wchar_t c) const { return c != 0; }

    void AddBitmap(CharInfo &ci, const unsigned char* bmp, unsigned int rowStride);
    void AddSheet();

    unsigned int GetHeight() const   { return m_TextMetric.tmHeight; }
    unsigned int GetBaseline() const { return m_TextMetric.tmAscent; }
    unsigned int GetDescent() const { return m_TextMetric.tmDescent; }

    int DrawTextN(int x, int y, const wchar_t *string, unsigned int color, unsigned int n = INVALID_LEN);
    int DrawTextCenter(int x, int y, const wchar_t *string, unsigned int color, unsigned int n = INVALID_LEN);
	void WrapString(const wchar_t *str, unsigned int n, unsigned int width, std::vector<unsigned int> &startLineOffset, std::vector<unsigned int> &lineLen);
    unsigned int GetBreakPos(const wchar_t *str, unsigned int n, unsigned int width, bool breakOnWhitespace);
    unsigned int GetStrWidth(const wchar_t *str, unsigned int n = INVALID_LEN);

    static void Init();
    static void Destroy();

private:

    unsigned int m_RefCount;

    HFONT m_hFont;
    TEXTMETRIC m_TextMetric;

    unsigned int m_RemapTable[65536];
    std::vector<CharInfo> m_CharInfoList;

    unsigned int m_CurX;
    unsigned int m_CurY;
    unsigned int m_CurSheet;
    std::vector<CFontTexture*> m_TextureSheets;
};

#define MAX_BATCH_COUNT XMGUI_MAX_BATCH_COUNT
class CFontRenderBatcher
{
    struct CharMarker
    {
        int c;
        float x;
        float y;
        unsigned int color; 
        CharInfo *ci;
    };

    struct SheetMarker
    {
        unsigned int numChars;
        unsigned int startVertex;
        CharMarker charIndex[MAX_BATCH_COUNT];
    };

    std::vector<SheetMarker> m_Sheets;
    SheetMarker &GetSheetMarker(unsigned int sheetID);
    CFont *m_pFont;
    unsigned int m_BatchCount;
    bool m_bCache;

public:
    CFontRenderBatcher()
        :m_bCache(false)
    {
    }

    void Begin(CFont *font);
    void End(bool flush = false);

    bool BeginCache(CFont *font);
    void EndCache();

    int QueueChar(wchar_t c, int x, int y, unsigned int color);
};

extern CFontRenderBatcher* g_FontRenderBatcher;

#endif