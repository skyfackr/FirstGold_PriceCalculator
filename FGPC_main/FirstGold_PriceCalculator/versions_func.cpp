#include "stdafx.h"
#include "versions.h"
/*���ļ����ڶ�����ֹ���Ԫ���ݵĿ��ٴ�����*/
using namespace std;
using namespace fgpc;
void cutthreeversion(const std::string & ver, int & ver1, int & ver2, int & ver3)
{
	using namespace std;
	int point1 = 0, point2 = 0;
	if (string::npos == (point1 = ver.find('.'))||point1==0)
	{
		goto fail;
	}
	ver1 = 0;
	for (int i = 0; i <= point1-1; i++)
	{
		if (!isdigit(ver[i])) goto fail;
		ver1 *= 10;
		ver1 += ver[i] - '0';
	}
	if (string::npos==(point2=ver.find('.',point1+2))) goto fail;
	ver2 = 0;
	for (int i = point1 + 1; i <= point2 - 1; i++)
	{
		if (!isdigit(ver[i])) goto fail;
		ver2 *= 10;
		ver2 += ver[i] - '0';
	}
	ver3 = 0;
	for (int i = point2 + 1; i <= ver.size() - 1; i++)
	{
		if (!isdigit(ver[i])) goto fail;
		ver3 *= 10;
		ver3 += ver[i] - '0';
	}
	return;//�˴�Ϊ��������
fail://�쳣����ִ�д˴�
	ver1 = -1; ver2 = -1; ver3 = -1;
	return;
}
class FGPC_Versiontool
{
private:
	int ver1, ver2, ver3;//�ְ汾��
	string ver;//�汾���ַ�����ʽ
	bool get(string s)//��ȡ����
	{

	}
};
