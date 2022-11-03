#include "ZmqMessager/DataSubscriber.h"
#include "CommonUtility/Loger.h"

//DEFINE_string(zmq_address, "tcp://127.0.0.1:6666", "zmq address");
DEFINE_string(zmq_address, "ipc://rspub", "zmq address");
DEFINE_bool(log_debug, false, "Debug");
using namespace HZP;
using namespace std;

int main()
{
    Loger::Init("sub.log", "both");
    char msg[1000] = { '\0' };
    char nomsg[1000] = { '\0' };
    DataSubscriber subscriber = DataSubscriber("KKK");
    DataSubscriber noTopicSub = DataSubscriber("Test2");
    while (true)
    {
        int len = subscriber.GetMsg(msg, 1000);
        Loger::Write("Receive Topic Msg:" + string(msg));

        noTopicSub.GetMsg(nomsg, 1000);
        Loger::Write("Receive No Topic Msg:" + string(nomsg));
    }

    return 0;
}