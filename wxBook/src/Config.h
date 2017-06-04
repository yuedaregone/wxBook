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
		int edge;
		unsigned long backColor;
		unsigned long frontColor;		
	}ConfigStruct;
public:
	Config();
	void Init();
	void GetWH(int & w, int & h);
	int GetFontSize() { return m_config.fontSize; }
	int GetFontSpacing() { return m_config.spacing; }
	int GetEdge() { return m_config.edge; }
	unsigned long GetBackColor() { return m_config.backColor; }
	unsigned long GetFrontColor() { return m_config.frontColor; }
private:
	void DefaultConfigData();
	void LoadAllText(std::map<std::string, std::string> &mapData);
	void ReadConfig();
private:
	ConfigStruct m_config;
};
