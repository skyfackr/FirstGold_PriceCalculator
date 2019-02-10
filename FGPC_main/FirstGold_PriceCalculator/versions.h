#pragma once
/*本文件用于存放程序版本信息、存档版本信息、应用名称等等元数据*/
#ifndef SKYFACKR_FGPC_VERSIONS_H_
#define SKYFACKR_FGPC_VERSIONS_H_

//发布版本
constexpr auto FGPC_VERSIONS = "0.0.1";

//输出的主设置版本
constexpr auto FGPC_SETTINGS_VERSIONS = "0.0.1";

//最低需要的主设置版本
constexpr auto FGPC_SETTINGS_REQUIREMINVERSIONS = "0.0.1";

//输出的存储数据版本
constexpr auto FGPC_DATA_VERSIONS = "0.0.1";

//最低需要的存储数据版本
constexpr auto FGPC_DATA_REQUIREMINVERSIONS = "0.0.1";

//默认存档位置
constexpr auto FGPC_DEFAULT_DATATREE = "FGPC_data";

//默认主配置存档名
#define FGPC_DEFAULT_SETTING_FILENAME FGPC_DEFAULT_DATATREE+"/mainsettings.fgpc"
namespace fgpc
{
	//分离版本号
	void cutthreeversion(const std::string &ver, int &ver1, int &ver2, int &ver3);
}

#endif // !SKYFACKR_FGPC_VERSIONS_H_
