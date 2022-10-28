#include <iostream>
#include <string>
#include "gflags/gflags.h"
#include <vector>
#include "DomainModel/CmdAction.h"
#include <rttr/type>
#include "CommonUtility/Loger.h"
#include <Poco/Net/ICMPClient.h>
/*
How to run:
ScpiServer --flagfile=config.flags
*/
DEFINE_string(zmq_address, "tcp://127.0.0.1:6666", "zmq address");
DEFINE_string(scpi_server_port, "5025", "default scpi server port");

using namespace std; 
using namespace HZP;
using namespace rttr;

using Poco::Net::ICMPClient;
using Poco::Net::IPAddress;

int main()
{
    Loger::Init();
    Loger::Write("scpi server start...");
    Loger::Write("scpi server port:"+FLAGS_scpi_server_port);

    ICMPClient icmp(IPAddress::IPv4);
    int rs=icmp.ping("172.25.65.247");
    cout << rs << endl;

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