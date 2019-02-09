#pragma once
/*将注释解除将启动debug模式，注释掉会关闭
通过函数 isindebugmode() 可以程序运行时查看是否在编译时启动debug模式*/
//#define DEBUGMODEISONLALALALALA
/*所有debug用测试函数的定义控制将全部交由此头文件统一管理*/
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
