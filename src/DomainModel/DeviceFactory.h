#ifndef DEVICEFACTORY_H
#define DEVICEFACTORY_H

#include <string>
#include <iostream>
#include <vector>
#include "CmdResult.h"
#include "DeviceBase.h"

namespace HZP
{
	using namespace std;
	class DeviceFactory
	{
	private:
		DeviceFactory() {};
	public:
		static shared_ptr<DeviceBase> CreateDevice(string deviceType);
	};
}
#endif
