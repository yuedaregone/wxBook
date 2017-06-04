#include "Utility.h"
#include <stdio.h>
#include <string.h>

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