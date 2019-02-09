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

		//��ȡĳ�����ã������ǰ�����û���û�д����ý�����"null"
		std::string load(std::string settingname);

		//����ļ�ռ�ã�ɾ��ȫ�����ü�¼���ÿ���״̬Ϊfalse
		bool freefile();

		//�޸�������
		bool change(std::string name,std::string what);

		//������load����
		std::string operator[](std::string settingname) ;

		//���ñ���
		bool save();

		//ֱ�Ӵ���Դ����Ĭ������
		bool readinitsetting();

		MainSetting();
		~MainSetting();
	};
}
#endif // !SKYFACKR_FGPC_SETTINGS_H_

