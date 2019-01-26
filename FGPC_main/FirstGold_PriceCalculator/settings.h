#pragma once
#ifndef SKYFACKR_FGPC_SETTINGS_H_
#define SKYFACKR_FGPC_SETTINGS_H_
#include"stdafx.h"
namespace fgpc
{
	class MainSetting
	{
	public:
		//用于测试目标文件是否符合配置文件标准
		bool filetest(std::string filename);

		//表示当前是否可用
		bool readok();

		//读取主配置文件，成功返回true
		bool readfile(std::string filename);

		//返回上一个错误的代码
		std::string getlasterr();

		//读取某个配置，如果当前不可用或者没有此配置将返回空
		std::string load(std::string settingname);

		//解除文件占用，删除全部配置记录，置可用状态为false
		bool freefile();

		//配置修改器
		void changer();

		//重载至load函数
		friend std::string &operator[](std::string settingname);

		MainSetting();
		~MainSetting();
	};
}
#endif // !SKYFACKR_FGPC_SETTINGS_H_

