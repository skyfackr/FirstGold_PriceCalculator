/*本文件定义语言中心的测试系统*/
#include"stdafx.h"
#include"language_test.h"
#include"jsoncpp.h"
#include"versions.h"
using namespace std;
using namespace Json;
using namespace fgpc;
class LanguageTester
{
private:
	Value data;//测试数据
	class Errors//错误记录中心
	{
	private:
		bool haveerror = false;//是否出锅
		bool haveerrorlocation = false;//这个锅有没有记录位置
		string err_data;//错误详情
		string err_where;//错误位置
	public:
		void throwerr(string &errdata, string &errwhere)//记录错误
		{
			haveerror = true;
			haveerrorlocation = true;
			err_data = errdata;
			err_where = errwhere;
			return;
		}
		void throwerr(string &errdata)//记录错误（不记录位置信息）
		{
			haveerror = true;
			haveerrorlocation = false;
			err_data = errdata;
			err_where.clear();
			return;
		}
		string what()//输出错误信息
		{
			if (!haveerror) return "nothing";
			string ans = "err_" + err_data;
			if (haveerrorlocation) ans += "_at_" + err_where;
			return ans;
		}
	} errors;
	bool test_version()//测试语言库版本信息
	{
		const string now_ver = data["version"].asString();//语言库版本号
		constexpr auto req_ver = FGPC_LANGUAGE_DATA_REQUIREMINVERSIONS;//最低所需版本号
		
	}
};