#pragma once
/*���ļ������������ĵĲ���ϵͳ�Ľӿ�*/
#ifndef SKYFACKR_FGPC_LANGUAGE_TEST_H_
#define SKYFACKR_FGPC_LANGUAGE_TEST_H_

#include"stdafx.h"
#include"jsoncpp.h"
namespace fgpc
{
	class LanguageTester//�������Ĳ���ϵͳ
	{
		typedef std::string string;
		typedef Json::Value Value;

		//�������û�о����"nothing"
		string error();

		//��������
		bool test(Value &testdata);

		LanguageTester();
		~LanguageTester();
	};
}

#endif // !SKYFACKR_FGPC_LANGUAGE_TEST_H_
