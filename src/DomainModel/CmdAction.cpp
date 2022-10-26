#include "CmdAction.h"
#include <rttr/registration>

using namespace HZP;
CmdAction::CmdAction()
{
	this->m_ptrDevice = DeviceFactory::CreateDevice("");
}
CmdAction::CmdAction(string deviceType):m_deviceType(deviceType)
{
	this->m_ptrDevice= DeviceFactory::CreateDevice(m_deviceType);
}
CmdResult CmdAction::IDN()
{
	return this->m_ptrDevice->IDN();
}
CmdResult CmdAction::CLS()
{
	return this->m_ptrDevice->CLS();
}
CmdResult CmdAction::PSC(vector<string> parameters)
{
	return this->m_ptrDevice->PSC(parameters);
}

RTTR_REGISTRATION
{
using namespace rttr;
	registration::class_<CmdAction>("CmdAction")
	.constructor()
	.constructor<string>()
	.method("IDN", &CmdAction::IDN)
	.method("CLS", &CmdAction::CLS)
	.method("PSC", &CmdAction::PSC);
}