#include "DeviceCMW.h"

using namespace HZP;

DeviceCMW::DeviceCMW()
{
}
DeviceCMW::~DeviceCMW()
{
}
CmdResult DeviceCMW::IDN()
{
	return CmdResult("1","Rohde&Schwarz CMW");
}
CmdResult DeviceCMW::CLS()
{
	return CmdResult::UnRealizeCmd();
}
CmdResult DeviceCMW::PSC(vector<string>parameters)
{
	return CmdResult::UnRealizeCmd();
}
