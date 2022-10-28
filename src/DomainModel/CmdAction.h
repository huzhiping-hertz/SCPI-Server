#ifndef CMDACTION_H
#define CMDACTION_H

#include <iostream>
#include <vector>
#include <string>
#include "CmdResult.h"
#include "DeviceBase.h"
#include "DeviceFactory.h"

#include <rttr/registration>
#include <rttr/type>

using namespace std;
using namespace HZP;
using namespace rttr;

namespace HZP
{
	class CmdAction
	{
	public:
		CmdAction(std::string device);
		CmdResult IDN();
		CmdResult CLS();
		CmdResult PSC(vector<string> parameters);
		string m_device;
		shared_ptr<DeviceBase> m_ptrDevice;
		RTTR_ENABLE()
	};

	RTTR_REGISTRATION
	{
		registration::class_<CmdAction>("CmdAction")
		.constructor<std::string>()
		.method("IDN", &CmdAction::IDN)
		.method("CLS", &CmdAction::CLS)
		.method("PSC", &CmdAction::PSC)
		.property("device",&CmdAction::m_device);
	}

}


#endif
