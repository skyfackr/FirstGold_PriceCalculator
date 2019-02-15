#pragma once
/*本文件声明语言中心的外部框架接口*/
#ifndef SKYFACKR_FGPC_LANGUAGE_H_
#define SKYFACKR_FGPC_LANGUAGE_H_

#include"stdafx.h"
namespace fgpc
{
	class LanguageCenter//语言中心
	{
	public:
		typedef std::string string;
		
		//输出上一个错误，没有就输出"nothing"
		string error();

		//检测是否存在一种语言
		bool isAlang(string &langname);

		//加载语言库并启动
		bool open(string &langname);

		//卸载语言库并关闭
		bool close();

		//查询当前可用状态
		bool isready();

		//读取语言，如果失败就返回空
		string load(string &sentencename);

		//重载到load
		string operator[](string &sentencename);

		LanguageCenter();
		~LanguageCenter();
	};
}

#endif // !SKYFACKR_FGPC_LANGUAGE_H_
