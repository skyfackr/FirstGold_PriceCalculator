#pragma once
#ifndef SKYFACKR_FGPC_LANGUAGE_H_
/*���ļ������������ĵ��ⲿ��ܽӿ�*/
#define SKYFACKR_FGPC_LANGUAGE_H_

#include"stdafx.h"
namespace fgpc
{
	class LanguageCenter//��������
	{
		typedef std::string string;
	public:
		
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
