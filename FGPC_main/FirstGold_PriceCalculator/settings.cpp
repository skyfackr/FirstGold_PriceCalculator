#include"stdafx.h"
#include"jsoncpp.h"
#include"settings.h"
#include"versions.h"
using namespace std;
using namespace Json;
using namespace fgpc;
class MainSetting
{
private:
	//通过jsoncpp存储读取所有配置信息
	Value setdata;
	//可用标记
	bool is_ok = false;
	//记录错误，没错误返回nothing
	class Errors
	{
	private:
		//error信息
		string errdata="nothing";
		//error位置
		string errwhere = "null";
	public:
		//error读取
		inline string what()
		{
			if (errdata == "nothing") return errdata;
			return "mainsettingcenter_err_" + errdata + "--at:" + errwhere;
		}
		//error记录
		inline void throwerr(string err,string where_err)
		{
			errdata = err;
			errwhere = where_err;
			return;
		}
		//error记录（无位置）
		inline void throwerr(string err)
		{
			errdata = err;
			errwhere = "null";
			return;
		}
	} errors;
	//文件名
	string name;
	inline string readtostring(unique_ptr<ifstream> &in)//将文件数据全部导入到string
	{
		ostringstream oss;
		while (!in->eof()) oss<<in;
		return oss.str();
	}
	//文件载入
	inline bool read()
	{
		unique_ptr<ifstream> in;//读取文件
		CharReaderBuilder jsrb;
		unique_ptr<CharReader> jsread(jsrb.newCharReader);//解析json
		in->open(name, ios::in);
		if (!in)
		{
			errors.throwerr("filenotfound", "read");
			return false;
		}
		string data = readtostring(in);//读取数据
		string jserr;
		if (!jsread->parse(data.c_str(), data.c_str() + data.length(), &setdata, &jserr))
		{
			errors.throwerr(jserr, "read");
			return false;
		}
		return true;
	}
	inline bool test()//测试文件是否合法
	{

	}
};