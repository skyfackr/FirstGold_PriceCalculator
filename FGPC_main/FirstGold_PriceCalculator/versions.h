#pragma once
/*���ļ����ڴ�ų���汾��Ϣ���浵�汾��Ϣ��Ӧ�����Ƶȵ�Ԫ����*/
#ifndef SKYFACKR_FGPC_VERSIONS_H_
#define SKYFACKR_FGPC_VERSIONS_H_

constexpr auto FGPC_VERSIONS = "0.0.1";
constexpr auto FGPC_SETTINGS_VERSIONS = "0.0.1";
constexpr auto FGPC_SETTINGS_REQUIREMINVERSIONS = "0.0.1";
constexpr auto FGPC_DATA_VERSIONS = "0.0.1";
constexpr auto FGPC_DATA_REQUIREMINVERSIONS = "0.0.1";
namespace fgpc
{
	//����汾��
	void cutthreeversion(const std::string &ver, int &ver1, int &ver2, int &ver3);
}

#endif // !SKYFACKR_FGPC_VERSIONS_H_
