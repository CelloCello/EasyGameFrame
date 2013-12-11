#pragma once
#include <wtypes.h>

// 不能放 內含自己有 new 行為 class 
template <typename T>
class ArrayList
{
public:
	ArrayList<T>& operator=(ArrayList<T> &Data)
	{
		if(Data._iMax != _iMax)
			return *this;
		CopyMemory(_pObj,Data._pObj,_iSizeof*_iMax);
		_Pos = Data._Pos;
		return *this;
	}
	T& operator[]( UINT index )
	{
		if(index >= _iMax)
			return _pObj[_iMax-1];
		else
			return _pObj[index];
	}

	bool ChangeMax(int max)
	{
		if(_Pos > max)
			return false;
		T *temp = new T[max];
		CopyMemory(temp,_pObj,_iSizeof*_Pos);
		delete[] _pObj;
		_pObj = temp;
		_iMax = max;
		return true;
	}

	ArrayList(int max)
	{
		_iMax = max;
		_Pos = 0;
		_iSizeof = sizeof(T);
		_pObj = new T[max];
	}
	~ArrayList()
	{
		delete[] _pObj;
	}

	bool IsFull()
	{
		return (_Pos==_iMax);
	}

	bool CopyList(ArrayList<T> *tag)
	{
		if(_Pos > tag->_iMax)
			return false;
		tag->_Pos = _Pos;
		CopyMemory(tag->_pObj,_pObj,_iSizeof*_Pos);
		return true;
	}

	bool Find(T* src)
	{
		for(int i=0;i<_Pos;++i)
		{
			if(_pObj[i]==*src)
				return true;
		}
		return false;
	}

	T* Put(T& src)
	{
		if(_Pos<_iMax)
		{
			CopyMemory(_pObj+_Pos,&src,_iSizeof);
			++_Pos;
			return (_pObj+_Pos-1);
		}
		else
			return NULL;

	}
	bool GetBack(T* goal)
	{
		if(_Pos>0)
		{
			CopyMemory(goal,_pObj+_Pos-1,_iSizeof);
			return true;
		}
		else
			return false;
	}
	bool PopBack(T* goal)
	{
		if(_Pos>0)
		{
			--_Pos;
			CopyMemory(goal,_pObj+_Pos,_iSizeof);
			return true;
		}
		else
			return false;
	}
	bool Remove(T& src)
	{
		for(int i=0;i<_Pos;++i)
		{
			if(_pObj[i]==src)
			{
				--_Pos;
				CopyMemory(_pObj+i,_pObj+_Pos,_iSizeof);
				return true;
			}
		}
		return false;
	}
	bool Remove(int src)
	{
		if(src>=0 && src<_Pos)
		{
			--_Pos;
			CopyMemory(_pObj+src,_pObj+_Pos,_iSizeof);
			return true;			
		}
		return false;
	}
	void RemoveAll()
	{
		_Pos = 0;
	}



	T		*_pObj;
	int		_iMax;
	int		_Pos;
	int		_iSizeof;

};