#pragma once
#include <iostream>
#include <vector>
#include <string>
class Utility
{
public:
	static unsigned long str2hex(const char* str);

	static std::string GetCurPath();

	static void GetFiles(std::vector<std::string> &files, std::string &dir, const char* suffix = NULL);

	static std::string GetExtenName(std::string p);

	static void FindAllFile(std::vector<std::string>& strFiles, std::string lpPath, const char* suffix = NULL);
};
