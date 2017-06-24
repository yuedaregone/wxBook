#pragma once
#include <iostream>
#include <vector>
#include <string>
class Utility
{
public:
	static unsigned long str2hex(const char* str);

	static std::string GetCurPath();

	static std::string GetExtenName(std::string p);

	static void FindAllFile(std::vector<std::string>& strFiles, std::string lpPath, bool recurs = false, const char* suffix = NULL);

	static long GetFileSize(FILE* fp);

	static std::string* GetFileContent(FILE* fp);
};
