#include "stdafx.h"
#include "versions.h"
void fgpc::cutthreeversion(const std::string & ver, int & ver1, int & ver2, int & ver3)
{
	using namespace std;
	int point1 = 0, point2 = 0;
	if (string::npos == (point1 = ver.find('.'))||point1==0)
	{
		goto fail;
	}
	ver1 = 0;
	for (int i = 0; i <= point1-1; i++)
	{
		if (!isdigit(ver[i])) goto fail;
		ver1 *= 10;
		ver1 += ver[i] - '0';
	}
	if (string::npos==(point2=ver.find('.',point1+2))) goto fail;
	ver2 = 0;
	for (int i = point1 + 1; i <= point2 - 1; i++)
	{
		if (!isdigit(ver[i])) goto fail;
		ver2 *= 10;
		ver2 += ver[i] - '0';
	}
	ver3 = 0;
	for (int i = point2 + 1; i <= ver.size() - 1; i++)
	{
		if (!isdigit(ver[i])) goto fail;
		ver3 *= 10;
		ver3 += ver[i] - '0';
	}
	return;//此处为正常跳出
fail://异常跳出执行此处
	ver1 = 0; ver2 = 0; ver3 = 0;
	return;
}
