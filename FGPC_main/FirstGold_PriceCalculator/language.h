#pragma once
/*���ļ������������ĵ��ⲿ��ܽӿ�*/
#ifndef SKYFACKR_FGPC_LANGUAGE_H_
#define SKYFACKR_FGPC_LANGUAGE_H_

#include"stdafx.h"
namespace fgpc
{
	class LanguageCenter//��������
	{
	public:
		typedef std::string string;
		
		//�����һ������û�о����"nothing"
		string error();

		//����Ƿ����һ������
		bool isAlang(string &langname);

		//�������ԿⲢ����
		bool open(string &langname);

		//ж�����ԿⲢ�ر�
		bool close();

		//��ѯ��ǰ����״̬
		bool isready();

		//��ȡ���ԣ����ʧ�ܾͷ��ؿ�
		string load(string &sentencename);

		//���ص�load
		string operator[](string &sentencename);

		LanguageCenter();
		~LanguageCenter();
	};
}

#endif // !SKYFACKR_FGPC_LANGUAGE_H_
