#include "Config.h"
#include <fstream>
#include <windows.h>
#include <map>
#include <stdlib.h>
#define MAX_BUFF 256

Config::Config()
{
	ReadConfig();
}

static std::string GetCurPath()
{
	char buff[MAX_BUFF] = {'\0'};
	GetModuleFileName(NULL, buff, sizeof(buff));
	std::string str = buff;
	size_t last = str.find_last_of('\\');

	return str.substr(0, last);
}

void Config::DefaultConfigData()
{
	m_config.width = 500;
	m_config.height = 500;
}

std::map<std::string, std::string*>* Config::LoadAllText()
{
	std::string path = GetCurPath();

	std::ifstream fs(path + "\\config", std::ios::in);	

	if (!fs)
	{
		return NULL;
	}

	std::map<std::string, std::string*>* mapData = new std::map<std::string, std::string*>();

	std::string line = "";

	char buff[MAX_BUFF] = {'\0'};
	while (fs.getline(buff, MAX_BUFF))
	{
		line = buff;
		if (line.length() < 3 || (line.at(0) == '/' && line.at(1) == '/') || line.at(0) == '#')
		{
			continue;
		}
		
		size_t offset = line.find('=');
		std::string head = line.substr(0, offset);
		std::string* trail = new std::string(line.substr(offset + 1, line.length() - offset - 1));
		mapData->insert(std::make_pair(head, trail));

		memset(buff, 0, MAX_BUFF);
		line.clear();
	}	
	return mapData;
}

void Config::ReadConfig()
{
	DefaultConfigData();

	std::map<std::string, std::string*>* data = LoadAllText();
	if (data == NULL)
	{		
		return;
	}
	
	std::string key = "width";
	std::map<std::string, std::string*>::iterator it = data->find(key);
	if (it != data->end())
	{
		m_config.width = atoi(it->second->c_str());
	}
	
	key = "height";
	it = data->find(key);
	if (it != data->end())
	{
		m_config.height = atoi(it->second->c_str());
	}
}

void Config::GetWH(int & w, int & h)
{
	w = m_config.width;
	h = m_config.height;
}
