#include "DeviceBase.h"


namespace HZP
{
	DeviceBase::DeviceBase()
	{
	}
	DeviceBase::~DeviceBase()
	{
	}
	CmdResult DeviceBase::IDN()
	{
		return CmdResult::UnRealizeCmd();
	}
	CmdResult DeviceBase::CLS()
	{
		return CmdResult::UnRealizeCmd();
	}
	CmdResult DeviceBase::PSC(vector<string>parameters)
	{
		return CmdResult::UnRealizeCmd();
	}
}