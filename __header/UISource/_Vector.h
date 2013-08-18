/***********************************************************************
Copyright:2010-2013 Double One<dfghj77777@gmail.com>

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
MA 02110-1301, USA., or go to http://www.gnu.org/copyleft/lesser.txt

--------------------------------------------------------------------
@File Name:stdafx.h
@Describe:This is a part of XM_GUI
@Create Date:2010-10-7 14:01:29
@Version:1.0
@Author£ºDouble One
@Blog£º http://onedouble.cnblogs.com
@Modifier: Double One (dfghj77777@gmail.com)
@Modify Date£º2013-08-05 14:01:30
@Modify Reason£º
***********************************************************************/
#ifndef H_XM_VECTORT_H
#define H_XM_VECTORT_H

namespace XM{

	template<class T> class xmVec
	{
		friend class xmVec;
	protected:
		T*				m_pData;
		int				m_nSize;			
		int				m_nAllocated;

	public:
		xmVec();
		xmVec(xmVec& other);
		~xmVec();

		void			clear();

		int				size() const;
		void			resize(int nNewSize);

		void			push_back(const T tData);
		void			push_front(const T tData);

		void			pop_front();
		void			pop_back();

		bool			insert(int nIndex, T tData);
		void			erase(int nIndex);

		void			remove(T tData);

		int find(T tData) const;
		int findCount(T tData) const;
		int find_back(T tData) const;

		void replace(T tData, T otherData);

		T front();
		T back();

		const T& operator[](int nIndex) const;
        T& operator[](int nIndex);
		
	}; // class xmVec

	template<class T> xmVec<T>::xmVec()
	{
		m_nAllocated	= 0;
		m_nSize			= 0;
		m_pData			= 0;
	}
	template<class T> xmVec<T>::xmVec(xmVec& other)
	{
		m_nAllocated = other.m_nAllocated;
		m_nSize = other.m_nSize;
		m_pData = new T[m_nAllocated];
		XM_ASSERT(m_pData);
		memcpy(m_pData, other.m_pData, sizeof(T) * m_nSize);
	}
	template<class T> xmVec<T>::~xmVec()
	{
		clear();
	}

	template<class T> void xmVec<T>::clear()
	{
		m_nAllocated = 0;
		m_nSize = 0;
		_SAFE_DELETE_ARRAY(m_pData);
		m_pData = 0;
	}

	template<class T> int xmVec<T>::size() const
	{
		return m_nSize;
	}

	template<class T> void xmVec<T>::resize(int nNewSize)
	{
		if(m_nSize > nNewSize)
		{
			return;
		}

		T* pData = new T[nNewSize];
		XM_ASSERT(pData);

		if(m_nSize > 0)
		{
			XM_ASSERT(m_pData);
			for(int i = 0; i<m_nSize; ++i)
			{
				pData[i] = m_pData[i];
			}
		}

		_SAFE_DELETE_ARRAY(m_pData);
		m_pData = pData;
		m_nAllocated = nNewSize;
	}

	template<class T> void xmVec<T>::push_back(const T tData)
	{
		if(m_nAllocated == 0)
		{
			resize(H_DEF_VECTORT_BASESIZE_H);
		}
		else if(m_nSize >= m_nAllocated)
		{
			resize(m_nAllocated * 2);
		}

		m_pData[m_nSize++] = tData;
	}

	template<class T> void xmVec<T>::push_front(const T tData)
	{
		if(m_nAllocated == 0)
		{
			resize(H_DEF_VECTORT_BASESIZE_H);
		}
		else if(m_nSize >= m_nAllocated)
		{
			resize(m_nAllocated * 2);
		}

		if(m_nSize > 0)
		{
			XM_ASSERT(m_pData);
			for(int i = m_nSize; i>0; --i)
			{
				m_pData[i] = m_pData[i-1];
			}
		}

		m_pData[0] = tData;
		m_nSize++;
	}

	template<class T> void xmVec<T>::pop_front()
	{
		if(m_nSize <= 0)
		{
			return;
		}

		XM_ASSERT(m_pData);
		for(int i = 0; i<m_nSize-1; ++i)
		{
			m_pData[i] = m_pData[i+1];
		}
		m_nSize--;
	}
	template<class T> void xmVec<T>::pop_back()
	{
		if(m_nSize <= 0)
		{
			return;
		}
		m_nSize--;
	}

	template<class T> bool xmVec<T>::insert(int nIndex, T tData)
	{
		if((nIndex < 0)||(nIndex >= m_nSize)||(m_pData == 0))
		{
			return false;
		}

		if(m_nAllocated == 0)
		{
			resize(H_DEF_VECTORT_BASESIZE_H);
		}
		else if(m_nSize >= m_nAllocated)
		{
			resize(m_nAllocated * 2);
		}

		for(int i = m_nSize; i>nIndex; --i)
		{
			m_pData[i] = m_pData[i-1];
		}
		m_pData[nIndex] = tData;
		m_nSize++;

		return true;
	}

	template<class T> void xmVec<T>::erase(int nIndex)
	{
		if((nIndex >= m_nSize)||(m_nSize == 0))
		{
			return;
		}
		for(int i = nIndex; i<m_nSize-1; ++i)
		{
			m_pData[i] = m_pData[i+1];
		}
		m_nSize--;
	}

	template<class T> void xmVec<T>::remove(T tData)
	{
		if(m_nSize <= 0)
		{
			return;
		}

		T* pData = new T[m_nAllocated];
		XM_ASSERT(pData);

		int curIndex = 0;
		for(int i = 0; i<m_nSize; ++i)
		{
			if(m_pData[i] != tData)
			{
				pData[curIndex++] = m_pData[i];
			}
		}
		delete[] m_pData;
		m_pData = pData;
		m_nSize = curIndex;
	}

	template<class T> int xmVec<T>::find(T tData) const
	{
		for(int i = 0; i<m_nSize; ++i)
		{
			if(m_pData[i] == tData)
			{
				return i;
			}
		}
		return -1;
	}

	template<class T> int xmVec<T>::findCount(T tData) const
	{
		int nCount = 0;
		for(int i = 0; i<m_nSize; ++i)
		{
			if(m_pData[i] == tData)
			{
				++nCount;
			}
		}
		return nCount;
	}

	template<class T> int xmVec<T>::find_back(T tData) const
	{
		for(int i = m_nSize-1; i>=0; --i)
		{
			if(m_pData[i] == tData)
			{
				return i;
			}
		}
		return -1;
	}

	template<class T> void xmVec<T>::replace(T tData, T otherData)
	{
		for(int i = 0; i<m_nSize; ++i)
		{
			if(m_pData[i] == tData)
			{
				m_pData[i] = otherData;
			}
		}
	}

    template<class T> 
    const T& xmVec<T>::operator[](int nIndex) const
    {
        XM_ASSERT(nIndex >= 0);
        XM_ASSERT(nIndex < m_nSize);
        XM_ASSERT(m_pData);
        return m_pData[nIndex];
    }


	template<class T> T& xmVec<T>::operator[](int nIndex)
	{
		XM_ASSERT(nIndex >= 0);
		XM_ASSERT(nIndex < m_nSize);
		XM_ASSERT(m_pData);
		return m_pData[nIndex];
	}

	template<class T> T	xmVec<T>::front()
	{
		XM_ASSERT(m_nSize > 0);
		XM_ASSERT(m_pData);
		return m_pData[0];
	}
	template<class T> T xmVec<T>::back()
	{
		XM_ASSERT(m_nSize > 0);
		XM_ASSERT(m_pData);
		return m_pData[m_nSize - 1];
	}
} // namespace XM

#endif // H_XM_VECTORT_H