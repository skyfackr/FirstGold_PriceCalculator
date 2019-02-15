#pragma once
/*本文件用于存放程序版本信息、存档版本信息、应用名称等等元数据*/
/*本文件同时可用于声明各种关于元数据的快速处理工具*/
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

//最低需要的语言库版本
constexpr auto FGPC_LANGUAGE_DATA_REQUIREMINVERSIONS = "0.0.1";

namespace fgpc
{
	
	//分离版本号
	void cutthreeversion(const std::string &ver, int &ver1, int &ver2, int &ver3);
	
	class FGPC_Versiontool//版本号处理中心
	{
		
		
		/*
		警告：本处理中心含有以下自定义异常：
			1、FGPC_Versiontool_Unknown_version_data
				当传入的数据格式错误时将引发此异常
		*/



		typedef std::string string;
	public:

		//小于号比较
		friend bool operator<(FGPC_Versiontool a, FGPC_Versiontool b);

		//大于号比较
		friend bool operator>(FGPC_Versiontool a, FGPC_Versiontool b);

		//等于号比较
		friend bool operator==(FGPC_Versiontool a, FGPC_Versiontool b);

		//小于等于号比较
		friend bool operator<=(FGPC_Versiontool a, FGPC_Versiontool b);

		//大于等于号比较
		friend bool operator>=(FGPC_Versiontool a, FGPC_Versiontool b);

		//从字符串获取数据（返回值表示是否成功）
		bool operator=(string data);

		//从其他版本号控制中心获取数据（返回值表示是否成功）
		bool operator=(FGPC_Versiontool data);

		//获取ver1值
		int get_ver1();

		//获取ver2值
		int get_ver2();

		//获取ver3值
		int get_ver3();

		//修改ver1值
		bool change_ver1(int data);

		//修改ver2值
		bool change_ver2(int data);

		//修改ver3值
		bool change_ver3(int data);

		FGPC_Versiontool();
		~FGPC_Versiontool();
	};
}

#endif // !SKYFACKR_FGPC_VERSIONS_H_
