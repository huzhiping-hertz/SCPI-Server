#include <iostream>
#include <string>
#include "gflags/gflags.h"
#include <rttr/registration>
#include <vector>
/*
How to run:
ScpiServer --gflagfile=config.flags
*/
DEFINE_string(zmq_address, "tcp://127.0.0.1:6666", "zmq address");
DEFINE_string(server_address, "5025", "default scpi server port");

using namespace std; 
using namespace rttr;

class MyStruct {
public:
    MyStruct():data(0) {
        std::cout << "construct envoke" << endl;
    };
    void func(double x ) {
        std::cout << "function output " << x << endl;
    };
    void test(vector<string> params)
    {
        for each (string param in params)
        {
            cout << param << endl;
        }
    }
    int data;
};

RTTR_REGISTRATION
{
    registration::class_<MyStruct>("MyStruct")
         .constructor<>()
         .property("data", &MyStruct::data)
         .method("func", &MyStruct::func)
         .method("test",&MyStruct::test);
}


int main()
{
	cout << pow(2, 32);



    type t = type::get_by_name("MyStruct");
    for (auto& prop : t.get_properties())
        std::cout << "name: " << prop.get_name()<<endl;

    for (auto& meth : t.get_methods())
        std::cout << "name: " << meth.get_name()<<endl;

    variant var = t.create();    // will invoke the previously registered ctor
    //constructor ctor = t.get_constructor();  // 2nd way with the constructor class
    //var = ctor.invoke();

    method meth = t.get_method("func");
    meth.invoke(var, 42.0);

    vector<string> params;
    params.push_back("hello");
    params.push_back("reflection");
    method testMeth = t.get_method("test");
    testMeth.invoke(var, params);

    //std::cout << var.get_type().get_name(); // prints 'MyStruct'

	return 0; 
}