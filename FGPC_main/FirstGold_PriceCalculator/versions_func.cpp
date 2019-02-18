#include "stdafx.h"
#include "versions.h"
/*本文件用于定义各种关于元数据的快速处理工具*/
using namespace std;
using namespace fgpc;
void cutthreeversion(const std::string & ver, int & ver1, int & ver2, int & ver3)
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
	ver1 = -1; ver2 = -1; ver3 = -1;
	return;
}
class FGPC_Versiontool
{
private:
	int ver1, ver2, ver3;//分版本号
	string ver;//版本号字符串形式
	bool get(string s)//获取数据
	{

	}
};
