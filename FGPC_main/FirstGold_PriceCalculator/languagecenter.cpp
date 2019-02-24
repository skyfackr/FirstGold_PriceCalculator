/*本文件定义了语言中心类*/
#include"stdafx.h"
#include"debugcenter.h"
#include"language.h"
#include"language_test.h"
#include"language_data_resources.h"
using namespace fgpc;
using namespace std;
using namespace Json;
class LanguageCenter
{
private:
	class Errors//错误记录中心
	{
	private:
		const string error_class_name = "languagecenter";//类名，输出错误用
		string error_where;//出锅位置
		string error_what;//锅的详情
		bool is_error = false;//有没有出锅
		bool is_error_where = false;//有没有记录出锅位置
	public:
		string what()//输出锅，没锅输出nothing
		{
			if (!is_error) return "nothing";
			return error_class_name + "_err_" + error_what + (is_error_where ? "--at:" + error_what : "");
		}
		void throwerr(string err_what, string err_where)//记录错误信息
		{
			is_error = is_error_where = true;
			error_what = err_what;
			error_where = err_where;
			return;
		}
		void throwerr(string err_what)//记录错误信息（无位置）
		{
			is_error = true;
			is_error_where = false;
			error_what = err_what;
			return;
		}errors;
	};
};