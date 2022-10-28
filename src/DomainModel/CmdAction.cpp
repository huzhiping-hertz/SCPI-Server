#include "CmdAction.h"
#include <iostream>
#include "CommonUtility/Loger.h"
using namespace HZP;


CmdAction::CmdAction(string device):m_device(device)
{
	this->m_ptrDevice= DeviceFactory::CreateDevice(device);
}
CmdResult CmdAction::IDN()
{
	Loger::Write("Action IDN");
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
