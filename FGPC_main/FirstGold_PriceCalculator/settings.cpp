#include"stdafx.h"
#include"jsoncpp.h"
#include"settings.h"
#include"versions.h"
#include"settingtest.h"
#include"resource.h"
#include<Windows.h>
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
	bool is_save = true;//��¼��ǰ�汾�Ƿ񱣴�
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
		unique_ptr<CharReader> jsread(jsrb.newCharReader());//����json
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
		MainSettingTest settest;
		if (!settest.teststart(setdata))
		{
			errors.throwerr(settest.what(), "mainsettingtest");
			return false;
		}
		return true;
	}
	inline string get(string getname)//��õ�������
	{
		return setdata[getname].asString();
	}
	inline void isntok_err()//�����ǰ�����ò���������ô˺���
	{
		errors.throwerr("isn't_ready");
		return;
	}

#define oktest() if (!is_ok){isntok_err();return false;}//��鵱ǰ���ÿ��Ƿ���ã������ý�ֱ���޸�error���ݲ�����false
public:
	bool change(string name,string what)
	{
		oktest();
		if (!setdata.isMember(name))
		{
			errors.throwerr("namenotfound", "changer");
			return false;
		}
		setdata[name] = what;
		is_save = false;
		return true;
	}
	bool filetest(string filename)
	{
		name = filename;
		bool ans = true;
		if ((!read()) || (!test())) ans = false;
		name.clear();
		setdata.clear();
		return ans;
	}
	bool freefile()
	{
		oktest();
		is_ok = false;
		name.clear();
		setdata.clear();
		return true;
	}
	string getlasterr()
	{
		return errors.what();
	}
	MainSetting()
	{
		name.clear();
		setdata.clear();
	}
	~MainSetting()
	{
		if (!is_save)
		{
			save();
		}
	}
	string load(string settingname)
	{
		if (!is_ok)
		{
			isntok_err();
			return "null";
		}
		if (!setdata.isMember(settingname))
		{
			errors.throwerr("namenotfound", "load");
			return "null";
		}
		return get(settingname);
	}
	bool readok()
	{
		return is_ok;
	}
	bool readfile(string filename)
	{
		name = filename;
		return (read() && test());
	}
	string operator[](string settingname) 
	{
		return load(settingname);
	}
	bool save()
	{
		oktest();
		if (is_save) return true;
		StreamWriterBuilder jswb;
		unique_ptr<StreamWriter> jswriter(jswb.newStreamWriter());
		Value savedata = setdata;
		savedata["settingversions"] = FGPC_SETTINGS_VERSIONS;
		savedata["releaseversions"] = FGPC_VERSIONS;
		ofstream savefile;
		savefile.open(name, ios::out | ios::trunc);
		if (!savefile)
		{
			errors.throwerr("file_open_failed", "saver");
			return false;
		}
		jswriter->write(savedata, &savefile);
		savefile.close();
		return true;
	}
	bool readinitsetting(string savename)
	{
		const LPCTSTR filename = MAKEINTRESOURCE(IDR_TXT1);
		const LPCTSTR filetype = TEXT("TXT");
		constexpr auto where_err_name = "read_initialation";
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
		ofstream saver;
		saver.open(savename, ios::out | ios::trunc);
		if (!saver)
		{
			errors.throwerr("file_create_failed", where_err_name);
			return false;
		}
		saver.write((char*)fmem, fsize);
		saver.close();
		return readfile(savename);
	}
};