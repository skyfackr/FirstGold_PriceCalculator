#pragma once
/*本文件声明语言中心的测试系统的接口*/
#ifndef SKYFACKR_FGPC_LANGUAGE_TEST_H_
#define SKYFACKR_FGPC_LANGUAGE_TEST_H_

#include"stdafx.h"
#include"jsoncpp.h"
namespace fgpc
{
	class LanguageTester//语言中心测试系统
	{
		typedef std::string string;
		typedef Json::Value Value;

		//输出错误，没有就输出"nothing"
		string error();

		//启动测试
		bool test(Value &testdata);

		LanguageTester();
		~LanguageTester();
	};
}

#endif // !SKYFACKR_FGPC_LANGUAGE_TEST_H_
