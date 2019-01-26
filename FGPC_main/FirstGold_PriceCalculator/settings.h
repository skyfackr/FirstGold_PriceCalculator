#pragma once
#ifndef SKYFACKR_FGPC_SETTINGS_H_
#define SKYFACKR_FGPC_SETTINGS_H_
#include"stdafx.h"
namespace fgpc
{
	class MainSetting
	{
	public:
		//���ڲ���Ŀ���ļ��Ƿ���������ļ���׼
		bool filetest(std::string filename);

		//��ʾ��ǰ�Ƿ����
		bool readok();

		//��ȡ�������ļ����ɹ�����true
		bool readfile(std::string filename);

		//������һ������Ĵ���
		std::string getlasterr();

		//��ȡĳ�����ã������ǰ�����û���û�д����ý����ؿ�
		std::string load(std::string settingname);

		//����ļ�ռ�ã�ɾ��ȫ�����ü�¼���ÿ���״̬Ϊfalse
		bool freefile();

		//�����޸���
		void changer();

		//������load����
		friend std::string &operator[](std::string settingname);

		MainSetting();
		~MainSetting();
	};
}
#endif // !SKYFACKR_FGPC_SETTINGS_H_

