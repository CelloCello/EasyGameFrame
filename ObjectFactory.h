#pragma once
#include "ArrayList.h"

/*
 *	���󲣥;�, �@�˨S�� ThreadSafe
 */

template<typename T>
class ObjectFactory
{
public:
	ObjectFactory(UINT Num):m_UsedList(Num), m_FreeList(Num)
	{
		m_Num = Num;
		m_ObjList = new T[Num];
		FreeAll();
	}

	~ObjectFactory(void)
	{
		delete [] m_ObjList;
	}

	T* GetOne()
	{
		T* rst_;
		if ( m_FreeList.PopBack(&rst_) )
		{
			m_UsedList.Put(rst_);
			return rst_;
		}
		return NULL;
	}

	bool FreeOne(T* Obj)
	{
		if ( m_UsedList.Remove(Obj) )
		{
			m_FreeList.Put(Obj);
			return true;
		}

		return false;
	}

	//�M������
	void FreeAll()
	{
		m_UsedList.RemoveAll();
		T* temp_;
		for ( UINT i=0 ; i<m_Num ; ++i )
		{
			temp_ = &(m_ObjList[i]);
			m_FreeList.Put(temp_);
		}
	}

private:
	ArrayList<T*>	m_UsedList;		//���b�Ϊ�
	ArrayList<T*>	m_FreeList;		//�S�b�Ϊ�
	T*				m_ObjList;		//�u������
	UINT			m_Num;			//�`��
};
