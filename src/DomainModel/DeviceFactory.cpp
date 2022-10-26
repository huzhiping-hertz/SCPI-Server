#include "DeviceFactory.h"
#include "DeviceCMW.h"

namespace HZP
{
	shared_ptr<DeviceBase> DeviceFactory::CreateDevice(string deviceType)
	{
		if (deviceType == "CMW")
		{
			make_shared<DeviceCMW>();
		}
		return make_shared<DeviceBase>();
	}
}