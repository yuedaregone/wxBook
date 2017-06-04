#include "Config.h"
#include <fstream>
#include <windows.h>
#include <map>
#include <stdlib.h>
#include <sstream>
#include "Utility.h"
#define MAX_BUFF 256

#define BEGIN_READ std::string key; std::string val;
#define TRY_GET_INT_VALUE(PARAM, KEY) key = #KEY; \
			if (TryGetValue(data, key, val)) \
			{ \
				PARAM.KEY = atoi(val.c_str()); \
			}
#define TRY_GET_ULONG_VALUE(PARAM, KEY) key = #KEY; \
			if (TryGetValue(data, key, val)) \
			{ \
				PARAM.KEY = Utility::str2hex(val.c_str()); \
			}
#define END_READ


Config::Config()
{
}

void Config::Init()
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
	m_config.fontSize = 10;
	m_config.spacing = 5;
}

void Config::LoadAllText(std::map<std::string, std::string> &mapData)
{
	std::string path = GetCurPath();

	std::ifstream fs(path + "\\config", std::ios::in);

	if (!fs)
	{
		return;
	}

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
		std::string trail = line.substr(offset + 1, line.length() - offset - 1);
		mapData.insert(std::make_pair(head, trail));

		memset(buff, 0, MAX_BUFF);
		line.clear();
	}
}

static bool TryGetValue(std::map<std::string, std::string> &data, std::string &key, std::string &val)
{
	std::map<std::string, std::string>::iterator it = data.find(key);
	if (it != data.end())
	{
		val = it->second.c_str();
		return true;
	}
	return false;
}



void Config::ReadConfig()
{
	DefaultConfigData();

	std::map<std::string, std::string> data;
	LoadAllText(data);
	if (data.empty())
	{
		return;
	}

BEGIN_READ
	TRY_GET_INT_VALUE(m_config, width)
	TRY_GET_INT_VALUE(m_config, height)
	TRY_GET_INT_VALUE(m_config, fontSize)
	TRY_GET_INT_VALUE(m_config, spacing)
	TRY_GET_ULONG_VALUE(m_config, backColor)
	TRY_GET_ULONG_VALUE(m_config, frontColor)
END_READ

}

void Config::GetWH(int & w, int & h)
{
	w = m_config.width;
	h = m_config.height;
}
