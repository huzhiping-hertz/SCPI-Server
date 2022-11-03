#include <iostream>
#include <string>
#include "gflags/gflags.h"
#include <vector>
#include "DomainModel/CmdAction.h"

#include "CommonUtility/Loger.h"



/*
How to run:
ScpiServer --flagfile=config.flags
*/
DEFINE_string(zmq_address, "tcp://127.0.0.1:6666", "zmq address");
DEFINE_string(scpi_server_port, "5025", "default scpi server port");
DEFINE_bool(log_debug, false, "Debug");

using namespace std; 
using namespace HZP;

int main(int argc, char* argv[])
{
    google::ParseCommandLineFlags(&argc, &argv, true);


    Loger::Init("scpi.log");
    Loger::Write("scpi server start...");
    Loger::Write("scpi server port:"+FLAGS_scpi_server_port);

    Loger::WriteError("xxxxxx");
	return 0; 
}