#ifndef DATAPUBLISHER_H
#define DATAPUBLISHER_H

#include <string>
#include "zmq.h"
#include <gflags/gflags.h>

namespace HZP {
using namespace std;

class DataPublisher {

private:
  static DataPublisher *ptrInstance;
  void *ctx;
  void *publisher;
  DataPublisher();

public:
  static DataPublisher *GetInstance();
  void SendMsg(char *data, int length, string topic);
  ~DataPublisher();
};

} // namespace ZmqMessager
#endif
