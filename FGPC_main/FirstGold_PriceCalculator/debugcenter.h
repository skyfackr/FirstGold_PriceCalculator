#pragma once
/*��ע�ͽ��������debugģʽ��ע�͵���ر�
ͨ������ isindebugmode() ���Գ�������ʱ�鿴�Ƿ��ڱ���ʱ����debugģʽ*/
//#define DEBUGMODEISONLALALALALA
/*����debug�ò��Ժ����Ķ�����ƽ�ȫ�����ɴ�ͷ�ļ�ͳһ����*/
#ifndef SKYFACKR_FGPC_DEBUGCENTER_H_
#define SKYFACKR_FGPC_DEBUGCENTER_H_

#ifdef DEBUGMODEISONLALALALALA

inline bool isindebugmode()
{
	return true;
}
#else
inline bool isindebugmode()
{
	return false;
}
#endif // DEBUGMODEISONLALALALALA

#endif // !SKYFACKR_FGPC_DEBUGCENTER_H_
