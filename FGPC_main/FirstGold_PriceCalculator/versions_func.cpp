#include "stdafx.h"
#include "versions.h"
/*本文件用于定义各种关于元数据的快速处理工具*/
using namespace std;
using namespace fgpc;
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
	ver1 = -1; ver2 = -1; ver3 = -1;
	return;
}
void fgpc::parsethreeversion(std::string & ver, const int & ver1, const int & ver2, const int & ver3)
{
	if (ver1 < 0 || ver2 < 0 || ver3 < 0)//不允许版本号出现负数
	{
		ver = "ERROR";
		return;
	}
	ostringstream oss;
	oss << ver1 << '.' << ver2 << '.' << ver3;
	ver = oss.str();
	return;
}
class FGPC_Versiontool
{
private:
	int ver1=0, ver2=0, ver3=0;//分版本号
	//string ver="0.0.0";//版本号字符串形式
	void get(string &s)//获取数据
	{
		//ver = s;
		cutthreeversion(s, ver1, ver2, ver3);
		if (ver1 < 0) throw(err::FGPC_Versiontool_Unknown_version_data());
		return;
	}
public:
	/*void operator=(string &data)
	{
		get(data);
		return;
	}*/
	FGPC_Versiontool &operator=(FGPC_Versiontool &data)
	{
		ver1 = data.ver1;
		ver2 = data.ver2;
		ver3 = data.ver3;
		//ver = data.ver;
		return *this;
	}
	string asString()
	{
		string ver;
		parsethreeversion(ver, ver1, ver2, ver3);
		return ver;
	}
	int get_ver1()
	{
		return ver1;
	}
	int get_ver2()
	{
		return ver2;
	}
	int get_ver3()
	{
		return ver3;
	}
	void change_ver1(int &data)
	{
		ver1 = data;
		return;
	}
	void change_ver2(int &data)
	{
		ver2 = data;
		return;
	}
	void change_ver3(int &data)
	{
		ver3 = data;
		return;
	}

	FGPC_Versiontool(){}
	~FGPC_Versiontool(){}
	FGPC_Versiontool(string data)
	{
		get(data);
	}
};
bool fgpc::operator==(FGPC_Versiontool & a, FGPC_Versiontool & b)
{
	if (a.get_ver1() == b.get_ver1() || a.get_ver2() == b.get_ver2() || a.get_ver3() == b.get_ver3()) return true;
	return false;
}
bool fgpc::operator<(FGPC_Versiontool & a, FGPC_Versiontool & b)
{
	if (a == b) return false;
	if (a.get_ver1()>=b.get_ver1())
	{
		if (a.get_ver1() > b.get_ver1()) return false;
		if (a.get_ver2() >= b.get_ver2())
		{
			if (a.get_ver2() > b.get_ver2()) return false;
			if (a.get_ver3() > b.get_ver3()) return false;
		}
	}
	return true;
}
bool fgpc::operator>(FGPC_Versiontool & a, FGPC_Versiontool & b)
{
	if (a == b) return false;
	return !(a < b);
}
bool fgpc::operator<=(FGPC_Versiontool & a, FGPC_Versiontool & b)
{
	if (a == b) return true;
	return (a < b);
}
bool fgpc::operator>=(FGPC_Versiontool & a, FGPC_Versiontool & b)
{
	if (a == b) return true;
	return (a > b);
}
void fgpc::swap(FGPC_Versiontool & a, FGPC_Versiontool & b)
{
	FGPC_Versiontool p = a;
	a = b;
	b = p;
	return;
}