#pragma once
#include <iostream>
#include <string>
#include <map>
#include "Singleton.h"

class Config : public Singleton<Config>
{
	typedef struct _ConfigStruct
	{
		int width;
		int height;
		int fontSize;
		int spacing;
	}ConfigStruct;
public:
	Config();
	void Init();
	void GetWH(int & w, int & h);
private:
	void DefaultConfigData();
	std::map<std::string, std::string*>* LoadAllText();
	void ReadConfig();
private:
	ConfigStruct m_config;
};
