/*���ļ������������ĵĲ���ϵͳ*/
#include"stdafx.h"
#include"language_test.h"
#include"jsoncpp.h"
#include"versions.h"
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
		void throwerr(string &errdata, string &errwhere)//��¼����
		{
			haveerror = true;
			haveerrorlocation = true;
			err_data = errdata;
			err_where = errwhere;
			return;
		}
		void throwerr(string &errdata)//��¼���󣨲���¼λ����Ϣ��
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
		const string now_ver = data["version"].asString();//���Կ�汾��
		constexpr auto req_ver = FGPC_LANGUAGE_DATA_REQUIREMINVERSIONS;//�������汾��
		
	}
};