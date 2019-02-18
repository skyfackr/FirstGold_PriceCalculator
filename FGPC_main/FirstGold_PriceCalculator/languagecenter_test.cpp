/*���ļ������������ĵĲ���ϵͳ*/
#include"stdafx.h"
#include"language_test.h"
#include"jsoncpp.h"
#include"versions.h"
#include<Windows.h>
#include"language_resources.h"
using namespace std;
using namespace Json;
using namespace fgpc;
class LanguageTester
{
private:
	Value data;//��������
	class Errors//�����¼����
	{
	private:
		bool haveerror = false;//�Ƿ����
		bool haveerrorlocation = false;//�������û�м�¼λ��
		string err_data;//��������
		string err_where;//����λ��
	public:
		void throwerr(string errdata, string errwhere)//��¼����
		{
			haveerror = true;
			haveerrorlocation = true;
			err_data = errdata;
			err_where = errwhere;
			return;
		}
		void throwerr(string errdata)//��¼���󣨲���¼λ����Ϣ��
		{
			haveerror = true;
			haveerrorlocation = false;
			err_data = errdata;
			err_where.clear();
			return;
		}
		string what()//���������Ϣ
		{
			if (!haveerror) return "nothing";
			string ans = "err_" + err_data;
			if (haveerrorlocation) ans += "_at_" + err_where;
			return ans;
		}
	} errors;
	bool test_version()//�������Կ�汾��Ϣ
	{
		if (!data.isMember("version"))
		{
			errors.throwerr("version_not_found", "test_version");
			return false;
		}
		FGPC_Versiontool nowver = data["version"].asString();//��ǰ�汾
		FGPC_Versiontool reqver = (string)FGPC_LANGUAGE_DATA_REQUIREMINVERSIONS;//��Ҫ��Ͱ汾��Ϣ
		if (nowver < reqver)
		{
			errors.throwerr("low_version", "test_version");
			return false;
		}
		return true;
	}
	bool test_lang()//�������Կ�������
	{
		const LPCTSTR filename = MAKEINTRESOURCE(LANG_REC_IDR_languagename_txt);
		const LPCTSTR filetype = TEXT("TXT");
		constexpr auto where_err_name = "test_lang";
		HRSRC fp = FindResource(NULL, filename, filetype);
		if (fp == NULL)
		{
			errors.throwerr("name_not_found", where_err_name);
			return false;
		}
		DWORD fsize = SizeofResource(NULL, fp);
		if (fsize == 0)
		{
			errors.throwerr("file_empty", where_err_name);
			return false;
		}
		HGLOBAL fmem = LoadResource(NULL, fp);
		if (fmem == NULL)
		{
			errors.throwerr("load_failed", where_err_name);
			return false;
		}
		LPVOID fmemp = LockResource(fmem);
		if (fmemp == NULL)
		{
			errors.throwerr("lock_failed", where_err_name);
			return false;
		}
		char tem_name[L_tmpnam] = { '\0' };
		tmpnam_s(tem_name);
		ofstream tem_fout;
		tem_fout.open(tem_name, ios::out | ios::trunc);
		if (!tem_fout)
		{
			errors.throwerr("tempotary_file_create_failed", where_err_name);
			return false;
		}
		tem_fout.write((char*)fmem, fsize);
		tem_fout.close();
		FreeResource(fmem);
		ifstream tem_fin;
		tem_fin.open(tem_name, ios::in);
		if (!tem_fin)
		{
			errors.throwerr("tempotary_file_open_failed", where_err_name);
			return false;
		}
		queue<string> needed;//���������
		while (!tem_fin.eof())
		{
			string s;
			getline(tem_fin, s);
			needed.push(s);
		}
		tem_fin.close();
		remove(tem_name);
		
		while (!needed.empty())
		{
			string s = needed.front();
			needed.pop();
			if (!data.isMember(s))
			{
				errors.throwerr("something_not_found", where_err_name);
				return false;
			}
		}
		return true;
	}
public:
	string error()
	{
		return errors.what();
	}
	bool test(Value &testdata)
	{
		data = testdata;
		return (test_version() || test_lang());
	}

	LanguageTester(){}
	~LanguageTester(){}
};