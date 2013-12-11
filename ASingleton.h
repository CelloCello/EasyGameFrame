#pragma once

/*
 *	Singleton物件, 沒有ThreadSafe
 */

template<typename T>
class ASingleton
{
public:
	//理論上建構式不能是public,不過我自己用,不犯錯就好= =+
	ASingleton(void)
	{
	}
	~ASingleton(void)
	{
	}

	//取得實體
	static T* GetInstance() 
	{
		if ( __Instance__ == NULL )
		{
			//沒有就new給他
			T* temp_ = new T();

			//在關閉時釋放
			__AutoEnd__.__Instance__ = temp_;
			__Instance__ = temp_;
		}

		return __Instance__;
	}

private:

	//解構時會幫忙delete某個instance
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
