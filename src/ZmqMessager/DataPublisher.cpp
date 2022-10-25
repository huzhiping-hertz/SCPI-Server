#include "DataPublisher.h"
#include <iostream>
#include <iomanip>
#include "zmq.h"
#include <gflags/gflags.h>

DECLARE_string(zmq_address);

namespace ZmqMessager {

DataPublisher *DataPublisher::ptrInstance = NULL;

DataPublisher *DataPublisher::GetInstance() {
  if (!ptrInstance) {
	  cout << "Create New publisher instance" << endl;
    ptrInstance = new DataPublisher();
  }
  return ptrInstance;
}

DataPublisher::DataPublisher() {

	ctx = zmq_ctx_new();
    publisher = zmq_socket(ctx, ZMQ_PUB);
  
  int rc=zmq_bind(publisher, FLAGS_zmq_address.c_str());
  if (rc != 0)
  {
	  cout << "can not bind 6666 port" << endl;
  }
}

void DataPublisher::SendMsg(char *data, int length) {
	
	//if (length > 12800)
	//{
	//	cout << "\nSendData:" << std::hex;
	//	for (int i = 0; i < length; i++)
	//	{
	//		printf("%i ", data[i]);
	//	}
	//	cout << endl;
	//}

	zmq_send(publisher, data, length, 0);
}

DataPublisher::~DataPublisher() {
	zmq_close(publisher);
	zmq_ctx_destroy(ctx);
	delete ptrInstance;
}
} // namespace ZmqMessager
