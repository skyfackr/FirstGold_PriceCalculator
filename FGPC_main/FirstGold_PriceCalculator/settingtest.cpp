#include"stdafx.h"
#include"settingtest.h"
#include"jsoncpp.h"
#include"resource.h"
#include<Windows.h>
using namespace fgpc;
using namespace std;
using namespace Json;
class MainSettingTest
{
private:
	Value testdata;
	queue<string> needed;//��Ҫ����������Ϣ
	string lasterror="nothing";//��Ŵ�����Ϣ
	bool load()//���������б�
	{
		const LPCTSTR loadname = MAKEINTRESOURCE(IDR_TXT2);
		HRSRC fp = FindResource(NULL, loadname, TEXT("TXT"));//�ļ���Դ��ָ��
		if (fp == NULL)
		{
			lasterror = "not_found";
			return false;
		}
		DWORD fsize = SizeofResource(NULL, fp);//�ļ���С
		if (fsize == 0)
		{
			lasterror = "file_empty";
			return false;
		}
		HGLOBAL fmem = LoadResource(NULL, fp);//�ļ��ڴ���ָ��
		if (fmem == NULL)
		{
			lasterror = "load_failed";
			return false;
		}
		LPVOID fmemp = LockResource(fmem);//�ļ��ڴ���ָ�루��������
		if (fmemp == NULL)
		{
			lasterror = "lock_failed";
			return false;
		}
		char tem_name[L_tmpnam] = {'\0'};//��ʱ�ļ�����
		tmpnam(tem_name);
		ofstream tem_fout;//�������б��������ʱ�ļ�
		tem_fout.open(tem_name, ios::out | ios::trunc);
		if (!tem_fout)
		{
			lasterror = "tempotary_file_create_failed";
			return false;
		}
		tem_fout.write((char*)fmem, fsize);
		tem_fout.close();
		ifstream tem_fin;//���¶�ȡ��ʱ�ļ���������Ϊʲô��ô���ģ�
		tem_fin.open(tem_name, ios::in);
		if (!tem_fin)
		{
			lasterror = "tempotary_file_open_failed";
			return false;
		}
		while (!tem_fin.eof())
		{
			string s;
			tem_fin >> s;
			needed.push(s);
		}
		tem_fin.close();
		remove(tem_name);
		return true;
	}
};