#pragma once

/*
 *	Singleton����, �S��ThreadSafe
 */

template<typename T>
class ASingleton
{
public:
	//�z�פW�غc������Opublic,���L�ڦۤv��,���ǿ��N�n= =+
	ASingleton(void)
	{
	}
	~ASingleton(void)
	{
	}

	//���o����
	static T* GetInstance() 
	{
		if ( __Instance__ == NULL )
		{
			//�S���Nnew���L
			T* temp_ = new T();

			//�b����������
			__AutoEnd__.__Instance__ = temp_;
			__Instance__ = temp_;
		}

		return __Instance__;
	}

private:

	//�Ѻc�ɷ|����delete�Y��instance
	class AutoEnd
	{
	public:
		T* __Instance__;
		AutoEnd(T* p)
		{
			__Instance__ = p;
		}
		~AutoEnd()
		{
			if(__Instance__)
				delete __Instance__;
		}
	};

private:
	static T*			__Instance__;
	static AutoEnd		__AutoEnd__;

};

template<typename T> 
T* ASingleton<T>::__Instance__ = NULL;

template<typename T> 
typename ASingleton<T>::AutoEnd ASingleton<T>::__AutoEnd__(NULL);
