#include "DataSubscriber.h"

#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <zmq.h>
#include "CommonUtility/Loger.h"

DECLARE_string(zmq_address);

using namespace std;
using namespace HZP;

DataSubscriber::DataSubscriber(string topic) {
	ctx = zmq_ctx_new();
	subscriber = zmq_socket(ctx, ZMQ_SUB);
	//set socket type
	int rc = zmq_setsockopt(subscriber, ZMQ_SUBSCRIBE, topic.c_str(), topic.length());

	//set hight water mark unlimited
	int highwatermark = 0;
	rc = zmq_setsockopt(subscriber, ZMQ_RCVHWM, &highwatermark, sizeof(highwatermark));

	rc = zmq_connect(subscriber, FLAGS_zmq_address.c_str());
	if (rc != 0)
	{
		Loger::Error("!!!Subscriber can not connect to Publisher");
	}
}

DataSubscriber::~DataSubscriber() {
	zmq_close(subscriber);
	zmq_ctx_destroy(ctx);
}



int DataSubscriber::GetMsg(char* bufData, int bufLen) {

	int more;
	size_t more_size = sizeof(more);
	int rslen = 0;
	do {
		memset(bufData,'\0', bufLen);
		int msg_size=zmq_recv(subscriber, bufData, bufLen, 0);
		int rc = zmq_getsockopt(subscriber, ZMQ_RCVMORE, &more, &more_size);
		if (msg_size < 0)
		{
			int error_code = zmq_errno();
			Loger::Error("Subscirber Get Msg Error");
		}
		rslen = msg_size;

	} while (more);
	return rslen;

}

