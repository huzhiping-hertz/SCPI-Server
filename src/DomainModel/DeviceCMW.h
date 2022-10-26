#ifndef DEVICECMW_H
#define DEVICECMW_H

#include <string>
#include <iostream>
#include <vector>
#include "CmdResult.h"
#include "DeviceBase.h"

namespace HZP
{
	using namespace std;
	class DeviceCMW:public DeviceBase
	{
	public:
		DeviceCMW();
		~DeviceCMW();
	public:
		CmdResult IDN();
		CmdResult CLS();
		CmdResult PSC(vector<string>parameters);
	};
}
#endif
