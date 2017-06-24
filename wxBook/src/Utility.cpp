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

void Utility::FindAllFile(std::vector<std::string>& strFiles, std::string lpPath, bool recurs, const char* suffix)
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
			if (!recurs)
				continue;
			FindAllFile(strFiles, szFile, recurs, suffix);
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

long Utility::GetFileSize(FILE* fp)
{
	long cur = ftell(fp);	fseek(fp, 0, SEEK_END);	long length = ftell(fp);	fseek(fp, cur, SEEK_SET);
	return length;
}

std::string* Utility::GetFileContent(FILE* fp)
{
	long length = GetFileSize(fp);

	char* buff = new char[length + 1];	fread(buff, 1, (size_t)length, fp);	buff[(size_t)length] = '\0';

	std::string* content = new std::string(buff);
	delete[] buff;
	return content;
}
