#include <iostream>
#include <string>
#include "gflags/gflags.h"
#include <vector>
#include "DomainModel/CmdAction.h"
#include <rttr/type>
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
    type t = type::get_by_name("CmdAction");
    variant var = t.create({"CMW"});

    method meth = t.get_method("IDN");
    meth.invoke(var);

    vector<string> params;
    params.push_back("hello");
    params.push_back("reflection");
    method testMeth = t.get_method("PSC");
    testMeth.invoke(var, params);

    //std::cout << var.get_type().get_name(); // prints 'MyStruct'

	return 0; 
}