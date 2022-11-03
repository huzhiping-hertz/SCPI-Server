#ifndef DATASUBSCRIBER_H
#define DATASUBSCRIBER_H

#include <string>
#include "zmq.h"
#include <gflags/gflags.h>

namespace HZP {

using namespace std;

class DataSubscriber {

private:
  void *ctx;
  void *subscriber;
public:
  DataSubscriber(string topic);
  int GetMsg(char *bufData,int bufLen);
  ~DataSubscriber();
};
} // namespace ZmqMessager

#endif
