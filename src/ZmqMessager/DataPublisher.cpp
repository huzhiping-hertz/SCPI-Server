#include "DataPublisher.h"
#include <iostream>
#include <iomanip>
#include "zmq.h"
#include "CommonUtility/Loger.h"

DECLARE_string(zmq_address);
using namespace HZP;

DataPublisher* DataPublisher::ptrInstance = NULL;

DataPublisher* DataPublisher::GetInstance() {
	if (!ptrInstance) {
		ptrInstance = new DataPublisher();
	}
	return ptrInstance;
}

DataPublisher::DataPublisher() {

	ctx = zmq_ctx_new();
	publisher = zmq_socket(ctx, ZMQ_PUB);

	int rc = zmq_bind(publisher, FLAGS_zmq_address.c_str());
	if (rc != 0)
	{
		Loger::Write("Can not connected:" + FLAGS_zmq_address);
	}
}

/*
* Notice: 
*1. If topic is empty string ,then all subscriber can get message
*2. If topicA name contain topicB name ,then subscriber B can get topicA message
*   so absolute different topic name is very important 
*/
void DataPublisher::SendMsg(char* data, int length, string topic) {
	if (topic != "")
	{
		zmq_send(publisher, topic.c_str(), topic.length(), ZMQ_SNDMORE);
	}
	zmq_send(publisher, data, length, 0);
}

DataPublisher::~DataPublisher() {
	zmq_close(publisher);
	zmq_ctx_destroy(ctx);
	delete ptrInstance;
}

