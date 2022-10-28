#include <iostream>
#include <string>
#include "gflags/gflags.h"
#include <vector>
#include "DomainModel/CmdAction.h"
#include <rttr/type>
#include "CommonUtility/Loger.h"

/*
How to run:
ScpiServer --flagfile=config.flags
*/
DEFINE_string(zmq_address, "tcp://127.0.0.1:6666", "zmq address");
DEFINE_string(server_address, "5025", "default scpi server port");

using namespace std; 
using namespace HZP;
using namespace rttr;


int main()
{
    Loger::Init();
    Loger::Write("scpi server start...");

    string device = "CMW";

    std::shared_ptr<CmdAction> ptrCmdAction = std::make_shared<CmdAction>(device);
    type cmdActionType=type::get_by_name("CmdAction");
    

    string cmd = "IDN";
    variant rsObj = cmdActionType.get_method(cmd).invoke(ptrCmdAction);
    cout << rsObj.get_value<CmdResult>().GetResult() << endl;;
 
    cmd = "PSC";
    vector<string> params;
    params.push_back("hello");
    params.push_back("reflection");
    rsObj = cmdActionType.get_method(cmd).invoke(ptrCmdAction, params);
    cout << rsObj.get_value<CmdResult>().GetResult() << endl;;

	return 0; 
}