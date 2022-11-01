#include "NetUtility.h"
#include <Poco/Net/ICMPClient.h>

using namespace HZP;
using Poco::Net::ICMPClient;
using Poco::Net::IPAddress;

bool NetUtility::Ping(string ipAddress)
{
	ICMPClient icmp(IPAddress::IPv4);
	int rs = icmp.ping(ipAddress);
	return rs > 0; 
}
