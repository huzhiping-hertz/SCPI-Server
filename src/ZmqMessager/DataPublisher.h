#ifndef DATAPUBLISHER_H
#define DATAPUBLISHER_H

#include <string>
#include "zmq.h"

namespace ZmqMessager {
using namespace std;

class DataPublisher {

private:
  static DataPublisher *ptrInstance;
  void *ctx;
  void *publisher;
  zmq_msg_t msg;
  DataPublisher();

public:
  static DataPublisher *GetInstance();
  void SendMsg(char *data, int length);
  ~DataPublisher();
};

} // namespace ZmqMessager
#endif
