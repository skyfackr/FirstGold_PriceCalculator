#pragma once
/*��ͷ�ļ����ڶ��������ò����࣬����������������*/
#ifndef SKYFACKR_FGPC_SETTINGTEST_H_
#define SKYFACKR_FGPC_SETTINGTEST_H_
#include"stdafx.h"
#include"jsoncpp.h"
namespace fgpc
{
	class MainSettingTest
	{
	public:
		std::string what() const;//��ȡ����ԭ��Ĭ��nothing
		bool teststart(Json::Value &data);//��������
	};
}
#endif // !SKYFACKR_FGPC_SETTINGTEST_H_
