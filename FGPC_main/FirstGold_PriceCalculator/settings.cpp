#include"stdafx.h"
#include"jsoncpp.h"
#include"settings.h"
#include"versions.h"
using namespace std;
using namespace Json;
using namespace fgpc;
class MainSetting
{
private:
	//ͨ��jsoncpp�洢��ȡ����������Ϣ
	Value setdata;
	//���ñ��
	bool is_ok = false;
	//��¼����û���󷵻�nothing
	class Errors
	{
	private:
		//error��Ϣ
		string errdata="nothing";
		//errorλ��
		string errwhere = "null";
	public:
		//error��ȡ
		inline string what()
		{
			if (errdata == "nothing") return errdata;
			return "mainsettingcenter_err_" + errdata + "--at:" + errwhere;
		}
		//error��¼
		inline void throwerr(string err,string where_err)
		{
			errdata = err;
			errwhere = where_err;
			return;
		}
		//error��¼����λ�ã�
		inline void throwerr(string err)
		{
			errdata = err;
			errwhere = "null";
			return;
		}
	} errors;
	//�ļ���
	string name;
	inline string readtostring(unique_ptr<ifstream> &in)//���ļ�����ȫ�����뵽string
	{
		ostringstream oss;
		while (!in->eof()) oss<<in;
		return oss.str();
	}
	//�ļ�����
	inline bool read()
	{
		unique_ptr<ifstream> in;//��ȡ�ļ�
		CharReaderBuilder jsrb;
		unique_ptr<CharReader> jsread(jsrb.newCharReader);//����json
		in->open(name, ios::in);
		if (!in)
		{
			errors.throwerr("filenotfound", "read");
			return false;
		}
		string data = readtostring(in);//��ȡ����
		string jserr;
		if (!jsread->parse(data.c_str(), data.c_str() + data.length(), &setdata, &jserr))
		{
			errors.throwerr(jserr, "read");
			return false;
		}
		return true;
	}
	inline bool test()//�����ļ��Ƿ�Ϸ�
	{

	}
};