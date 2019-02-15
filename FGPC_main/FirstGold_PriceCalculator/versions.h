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

//Ĭ�������ô浵��
#define FGPC_DEFAULT_SETTING_FILENAME FGPC_DEFAULT_DATATREE+"/mainsettings.fgpc"

//�����Ҫ�����Կ�汾
constexpr auto FGPC_LANGUAGE_DATA_REQUIREMINVERSIONS = "0.0.1";

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



		typedef std::string string;
	public:

		//С�ںűȽ�
		friend bool operator<(FGPC_Versiontool a, FGPC_Versiontool b);

		//���ںűȽ�
		friend bool operator>(FGPC_Versiontool a, FGPC_Versiontool b);

		//���ںűȽ�
		friend bool operator==(FGPC_Versiontool a, FGPC_Versiontool b);

		//С�ڵ��ںűȽ�
		friend bool operator<=(FGPC_Versiontool a, FGPC_Versiontool b);

		//���ڵ��ںűȽ�
		friend bool operator>=(FGPC_Versiontool a, FGPC_Versiontool b);

		//���ַ�����ȡ���ݣ�����ֵ��ʾ�Ƿ�ɹ���
		bool operator=(string data);

		//�������汾�ſ������Ļ�ȡ���ݣ�����ֵ��ʾ�Ƿ�ɹ���
		bool operator=(FGPC_Versiontool data);

		//��ȡver1ֵ
		int get_ver1();

		//��ȡver2ֵ
		int get_ver2();

		//��ȡver3ֵ
		int get_ver3();

		//�޸�ver1ֵ
		bool change_ver1(int data);

		//�޸�ver2ֵ
		bool change_ver2(int data);

		//�޸�ver3ֵ
		bool change_ver3(int data);

		FGPC_Versiontool();
		~FGPC_Versiontool();
	};
}

#endif // !SKYFACKR_FGPC_VERSIONS_H_
