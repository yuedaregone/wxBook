#pragma once

#include <stdio.h>

template<typename T>
class Singleton
{
public:
	static T& Get()
	{		
		if (NULL == ms_pInstance)
		{
			ms_pInstance = new T();
		}	

		return *ms_pInstance;
	}
	
	static void Destroy()
	{		
		if (NULL != ms_pInstance)
		{
			delete ms_pInstance;
			ms_pInstance = NULL;
		}	
	}
protected:
	static T	*ms_pInstance;
protected:
	Singleton()
	{
	}
	virtual ~Singleton()
	{
	}
};

template<typename T>
T* Singleton<T>::ms_pInstance = NULL;


