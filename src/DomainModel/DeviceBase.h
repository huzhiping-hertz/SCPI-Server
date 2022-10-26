#ifndef DEVICEBASE_H
#define DEVICEBASE_H

#include <string>
#include <iostream>
#include <vector>
#include "CmdResult.h"

namespace HZP
{
	using namespace std;
	class DeviceBase
	{
	public:
		DeviceBase();
		~DeviceBase();
	public:
		virtual CmdResult IDN();
		virtual CmdResult CLS();
		virtual CmdResult PSC(vector<string>parameters);
	};
}
#endif
