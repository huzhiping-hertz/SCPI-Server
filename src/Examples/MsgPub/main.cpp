#include "ZmqMessager/DataPublisher.h"
#include "CommonUtility/Loger.h"

using namespace HZP;
//DEFINE_string(zmq_address, "tcp://127.0.0.1:6666", "zmq address");
DEFINE_string(zmq_address, "ipc://rspub", "zmq address");
DEFINE_bool(log_debug, false, "Debug");
using namespace std;
using namespace HZP;

int main()
{
    Loger::Init("pub.log", "both");
    Loger::Write("Publisher address "+FLAGS_zmq_address);

    DataPublisher* ptrPublisher = DataPublisher::GetInstance();

    string msg_topic = "Test";

    for (int i = 0; i < 1000; i++)
    {
        zmq_sleep(1);
        string msg_data = "ZMQ Num "+to_string(i);
        ptrPublisher->SendMsg((char*)msg_data.c_str(), msg_data.length(), "KKK");
        Loger::Write("Send Topic Msg:" + msg_data);

        ptrPublisher->SendMsg((char*)msg_data.c_str(), msg_data.length(), "Test2");
        Loger::Write("Send No Topic Msg:" + msg_data);
        
    }


    return 0;
}