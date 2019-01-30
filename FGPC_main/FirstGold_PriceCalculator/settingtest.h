#pragma once
/*本头文件用于定义主设置测试类，尽可用于主设置中*/
#ifndef SKYFACKR_FGPC_SETTINGTEST_H_
#define SKYFACKR_FGPC_SETTINGTEST_H_
#include"stdafx.h"
#include"jsoncpp.h"
namespace fgpc
{
	class MainSettingTest
	{
	public:
		std::string what() const;//读取错误原因，默认nothing
		bool teststart(Json::Value &data);//启动测试
	};
}
#endif // !SKYFACKR_FGPC_SETTINGTEST_H_
