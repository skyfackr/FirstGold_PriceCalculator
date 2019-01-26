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
	unique_ptr<Value> setdata;
	bool is_ok = false;

};