#pragma once
/*���ļ����ڴ�ų���汾��Ϣ���浵�汾��Ϣ��Ӧ�����Ƶȵ�Ԫ����*/
#ifndef SKYFACKR_FGPC_VERSIONS_H_
#define SKYFACKR_FGPC_VERSIONS_H_

//�����汾
constexpr auto FGPC_VERSIONS = "0.0.1";

//����������ð汾
constexpr auto FGPC_SETTINGS_VERSIONS = "0.0.1";

//�����Ҫ�������ð汾
constexpr auto FGPC_SETTINGS_REQUIREMINVERSIONS = "0.0.1";

//����Ĵ洢���ݰ汾
constexpr auto FGPC_DATA_VERSIONS = "0.0.1";

//�����Ҫ�Ĵ洢���ݰ汾
constexpr auto FGPC_DATA_REQUIREMINVERSIONS = "0.0.1";

//Ĭ�ϴ浵λ��
constexpr auto FGPC_DEFAULT_DATATREE = "FGPC_data";

//Ĭ�������ô浵��
#define FGPC_DEFAULT_SETTING_FILENAME FGPC_DEFAULT_DATATREE+"/mainsettings.fgpc"
namespace fgpc
{
	//����汾��
	void cutthreeversion(const std::string &ver, int &ver1, int &ver2, int &ver3);
}

#endif // !SKYFACKR_FGPC_VERSIONS_H_
