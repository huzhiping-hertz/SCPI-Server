#ifndef DATASUBSCRIBER_H
#define DATASUBSCRIBER_H

#include <string>
#include "zmq.h"

namespace ZmqMessager {

using namespace std;

class DataSubscriber {

private:
  void *ctx;
  void *subscriber;
public:
  DataSubscriber();
  int GetMsg(char *data);
  ~DataSubscriber();
};
} // namespace ZmqMessager

#endif
