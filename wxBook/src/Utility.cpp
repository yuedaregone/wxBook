#include "Utility.h"
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <windows.h>
#define MAX_BUFF 256

unsigned long Utility::str2hex(const char * str)
{
	unsigned long ret = 0;

	for (int i = strlen(str) - 1; i >= 0; --i)
	{
		char ch = str[i];
		if (ch >= '0' && ch <= '9')
		{
			ch = ch - '0';
		}
		else if (ch >= 'A' && ch <= 'F')
		{
			ch = ch - 'A' + 10;
		}
		else if (ch >= 'a' && ch <= 'f')
		{
			ch = ch - 'a' + 10;
		}
		else
		{
			ch = 0;
		}
		ret += ch * (1 << (4 * (strlen(str) - 1 - i)));
	}

	return ret;
}

std::string Utility::GetCurPath()
{
	char buff[MAX_BUFF] = { '\0' };
	GetModuleFileName(NULL, buff, sizeof(buff));
	std::string str = buff;
	size_t last = str.find_last_of('\\');

	return str.substr(0, last);
}

std::string Utility::GetExtenName(std::string p)
{
	return p.substr(p.find_last_of("."), p.length());
}

void Utility::GetFiles(std::vector<std::string> &files, std::string &dir, const char* suffix)
{
    WIN32_FIND_DATA file;
    HANDLE lf;
    if ((lf = ::FindFirstFile(dir.c_str(), &file)) == INVALID_HANDLE_VALUE) {
        std::cout << dir << " not found!!!" << std::endl;
    } else {
        while(::FindNextFile(lf, &file) == 0) {
            if (strcmp((char*)file.cFileName, ".") == 0 || strcmp((char*)file.cFileName, "..") == 0)
                continue;
			std::string exten = Utility::GetExtenName((char*)file.cFileName);
			if (suffix != NULL && strcmp(exten.c_str(), suffix) != 0)
				continue;

            files.push_back((char*)file.cFileName);
        }
    }
    FindClose(lf);
}

void Utility::FindAllFile(std::vector<std::string>& strFiles, std::string lpPath, const char* suffix)
{
	WIN32_FIND_DATA FindFileData;
	std::string szFind = lpPath + "\\*.*";

	HANDLE hFind = ::FindFirstFile(szFind.c_str(), &FindFileData);
	if (INVALID_HANDLE_VALUE == hFind) return;
	while (::FindNextFile(hFind, &FindFileData))
	{
		if (strcmp((char*)FindFileData.cFileName, ".") == 0 || strcmp((char*)FindFileData.cFileName, "..") == 0)
		{
			continue;
		}
		std::string szFile = lpPath + "\\";
		szFile = szFile + FindFileData.cFileName;

		if (FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
		{
			FindAllFile(strFiles, szFile);
		}
		else
		{
			std::string exten = Utility::GetExtenName(FindFileData.cFileName);
			if (strcmp(exten.c_str(), suffix) == 0)
			{
				strFiles.push_back(szFile);
			}
		}
	}
	FindClose(hFind);
}
