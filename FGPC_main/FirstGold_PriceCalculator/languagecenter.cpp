/*���ļ�����������������*/
#include"stdafx.h"
#include"debugcenter.h"
#include"language.h"
#include"language_test.h"
#include"language_data_resources.h"
using namespace fgpc;
using namespace std;
using namespace Json;
class LanguageCenter
{
private:
	class Errors//�����¼����
	{
	private:
		const string error_class_name = "languagecenter";//���������������
		string error_where;//����λ��
		string error_what;//��������
		bool is_error = false;//��û�г���
		bool is_error_where = false;//��û�м�¼����λ��
	public:
		string what()//�������û�����nothing
		{
			if (!is_error) return "nothing";
			return error_class_name + "_err_" + error_what + (is_error_where ? "--at:" + error_what : "");
		}
		void throwerr(string err_what, string err_where)//��¼������Ϣ
		{
			is_error = is_error_where = true;
			error_what = err_what;
			error_where = err_where;
			return;
		}
		void throwerr(string err_what)//��¼������Ϣ����λ�ã�
		{
			is_error = true;
			is_error_where = false;
			error_what = err_what;
			return;
		}errors;
	};
};