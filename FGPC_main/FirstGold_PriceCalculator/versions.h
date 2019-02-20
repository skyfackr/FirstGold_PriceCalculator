#pragma once
/*���ļ����ڴ�ų���汾��Ϣ���浵�汾��Ϣ��Ӧ�����Ƶȵ�Ԫ����*/
/*���ļ�ͬʱ�������������ֹ���Ԫ���ݵĿ��ٴ�����*/
#ifndef SKYFACKR_FGPC_VERSIONS_H_
#define SKYFACKR_FGPC_VERSIONS_H_

//�����汾
constexpr auto FGPC_VERSIONS = "0.0.1";

//����������ð汾
constexpr auto FGPC_SETTINGS_VERSIONS = "0.0.1";

//�����Ҫ�������ð汾
constexpr auto FGPC_SETTINGS_REQUIREMINVERSIONS = "0.0.1";

//����Ĵ洢���ݰ汾
constexpr auto FGPC_DATA_VERSIONS = "0.0.1";

//�����Ҫ�Ĵ洢���ݰ汾
constexpr auto FGPC_DATA_REQUIREMINVERSIONS = "0.0.1";

//Ĭ�ϴ浵λ��
constexpr auto FGPC_DEFAULT_DATATREE = "FGPC_data";

//Ĭ�Ϻ�׺��
constexpr auto FGPC_DEFAULT_SUFFIX_NAME = ".fgpc";

//Ĭ�������ô浵��
#define FGPC_DEFAULT_SETTING_FILENAME FGPC_DEFAULT_DATATREE + "/mainsettings" + FGPC_DEFAULT_SUFFIX_NAME

//�����Ҫ�����Կ�汾
constexpr auto FGPC_LANGUAGE_DATA_REQUIREMINVERSIONS = "0.0.1";

#include"stdafx.h"
using std::exception;
using std::string;
namespace fgpc
{
	
	//����汾��
	void cutthreeversion(const std::string &ver, int &ver1, int &ver2, int &ver3);
	
	class FGPC_Versiontool//�汾�Ŵ�������
	{
		
		
		/*
		���棺���������ĺ��������Զ����쳣��
			1��FGPC_Versiontool_Unknown_version_data
				����������ݸ�ʽ����ʱ���������쳣
		*/



		
	public:

		//С�ںűȽ�
		friend bool operator<(FGPC_Versiontool &a, FGPC_Versiontool &b);

		//���ںűȽ�
		friend bool operator>(FGPC_Versiontool &a, FGPC_Versiontool &b);

		//���ںűȽ�
		friend bool operator==(FGPC_Versiontool &a, FGPC_Versiontool &b);

		//С�ڵ��ںűȽ�
		friend bool operator<=(FGPC_Versiontool &a, FGPC_Versiontool &b);

		//���ڵ��ںűȽ�
		friend bool operator>=(FGPC_Versiontool &a, FGPC_Versiontool &b);

		
		//void operator=(string &data);

		//�������汾�ſ������Ļ�ȡ����
		void operator=(FGPC_Versiontool &data);

		//���Ϊ�ַ���
		string asString();

		//��ȡver1ֵ
		int get_ver1();

		//��ȡver2ֵ
		int get_ver2();

		//��ȡver3ֵ
		int get_ver3();

		//�޸�ver1ֵ
		void change_ver1(int &data);

		//�޸�ver2ֵ
		void change_ver2(int &data);

		//�޸�ver3ֵ
		void change_ver3(int &data);

		//����
		friend void swap(FGPC_Versiontool &a, FGPC_Versiontool &b);

		FGPC_Versiontool();
		//���ַ���ת������
		FGPC_Versiontool(string data);
		~FGPC_Versiontool();
	};
	namespace err
	{
		class FGPC_Versiontool_Unknown_version_data:exception
		{
		public:
			exception(string) {};
		};
	}
}

#endif // !SKYFACKR_FGPC_VERSIONS_H_
