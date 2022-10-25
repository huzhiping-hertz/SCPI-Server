#include "DataSubscriber.h"

#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <zmq.h>

#include <gflags/gflags.h>

DECLARE_string(zmq_address);

namespace ZmqMessager {

using namespace std;

DataSubscriber::DataSubscriber() {
  ctx = zmq_ctx_new();
  subscriber = zmq_socket(ctx, ZMQ_SUB);
  zmq_setsockopt(subscriber, ZMQ_SUBSCRIBE, "", 0);
  int rc=zmq_connect(subscriber, FLAGS_zmq_address.c_str());
  if (rc != 0)
  {
	  cout << "can not connect 6666 port" << endl;
  }
  else
  {
	  cout << "new subscriber coming..." << endl;
  }
}

DataSubscriber::~DataSubscriber() {

	zmq_close(subscriber); 
	zmq_ctx_destroy(ctx);
}



int DataSubscriber::GetMsg(char *data) {
	
	
	int count=zmq_recv(subscriber, data, 102400, 0);
	cout << "Read Data:" << count << endl;
	return count;
}

} // namespace ZmqMessager
