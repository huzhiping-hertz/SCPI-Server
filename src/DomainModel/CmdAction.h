#ifndef CMDACTION_H
#define CMDACTION_H

#include <iostream>
#include <rttr/type>
#include <vector>
#include <string>
#include "CmdResult.h"
#include "DeviceBase.h"
#include "DeviceFactory.h"
using namespace std;
namespace HZP
{
    class CmdAction
    {
    private:
        string m_deviceType;
        shared_ptr<DeviceBase> m_ptrDevice;
    public:
        CmdAction();
        CmdAction(string deviceType);
        CmdResult IDN();
        CmdResult CLS();
        CmdResult PSC(vector<string> parameters);

        RTTR_ENABLE()
    };
}
#endif
