#include "DeviceCMW.h"
#include "Poco/Logger.h"
#include "CommonUtility/Loger.h"

using Poco::Logger;
using namespace HZP;

DeviceCMW::DeviceCMW()
{
}
DeviceCMW::~DeviceCMW()
{
}
CmdResult DeviceCMW::IDN()
{
	Loger::Write("IDN");
	return CmdResult(1,"Rohde&Schwarz CMW");
}
CmdResult DeviceCMW::CLS()
{
	return CmdResult::UnRealizeCmd();
}
CmdResult DeviceCMW::PSC(vector<string>parameters)
{
	return CmdResult(1, "Run PSC Cmd CMW");
}
