#include"stdafx.h"
#include"settingtest.h"
#include"jsoncpp.h"
#include"resource.h"
#include<Windows.h>
#include"versions.h"
using namespace fgpc;
using namespace std;
using namespace Json;
class MainSettingTest
{
private:
	Value testdata;
	queue<string> needed;//需要检测的配置信息
	string lasterror="nothing";//存放错误信息
	bool load()//加载配置列表
	{
		const LPCTSTR loadname = MAKEINTRESOURCE(IDR_TXT2);
		HRSRC fp = FindResource(NULL, loadname, TEXT("TXT"));//文件资源中指针
		if (fp == NULL)
		{
			lasterror = "not_found";
			return false;
		}
		DWORD fsize = SizeofResource(NULL, fp);//文件大小
		if (fsize == 0)
		{
			lasterror = "file_empty";
			return false;
		}
		HGLOBAL fmem = LoadResource(NULL, fp);//文件内存中指针
		if (fmem == NULL)
		{
			lasterror = "load_failed";
			return false;
		}
		LPVOID fmemp = LockResource(fmem);//文件内存中指针（已锁定）
		if (fmemp == NULL)
		{
			lasterror = "lock_failed";
			return false;
		}
		char tem_name[L_tmpnam] = {'\0'};//临时文件名称
		tmpnam_s(tem_name);
		ofstream tem_fout;//将配置列表输出到临时文件
		tem_fout.open(tem_name, ios::out | ios::trunc);
		if (!tem_fout)
		{
			lasterror = "tempotary_file_create_failed";
			return false;
		}
		tem_fout.write((char*)fmem, fsize);
		tem_fout.close();
		ifstream tem_fin;//重新读取临时文件（别问我为什么这么无聊）
		tem_fin.open(tem_name, ios::in);
		if (!tem_fin)
		{
			lasterror = "tempotary_file_open_failed";
			return false;
		}
		while (!tem_fin.eof())
		{
			string s;
			tem_fin >> s;
			needed.push(s);
		}
		tem_fin.close();
		remove(tem_name);
		return true;
	}
	inline bool versiontest()//测试版本号
	{
		int ver1, ver2, ver3,reqver1,reqver2,reqver3;
		string reqver = FGPC_SETTINGS_REQUIREMINVERSIONS;
		string ver = testdata["settingversions"].asString();
		cutthreeversion(ver, ver1, ver2, ver3);
		cutthreeversion(reqver, reqver1, reqver2, reqver3);
		if (ver1 < reqver1) return false;
		else if (ver1 == reqver1)
		{
			if (ver2 < reqver2) return false;
			else if (ver2 == reqver2)
			{
				if (ver3 < reqver3) return false;
			}
		}
		return true;
	}
	bool test()//测试部分
	{
		if (!testdata.isMember("settingversions"))
		{
			lasterror = "cannotfind:settingversions";
			return false;
		}
		if (!versiontest())
		{
			lasterror = "data_version_low";
			return false;
		}
		string ts ;//当前测试项目
		while (!needed.empty())
		{
			ts = needed.front();
			needed.pop();
			if (!testdata.isMember(ts))
			{
				lasterror = "cannotfind:" + ts;
				return false;
			}
		}
		return true;
	}
public:
	string what() const
	{
		return lasterror;
	}
	bool teststart(Value &data)
	{
		testdata = data;
		if (!load()) return false;
		return test();
	}
};