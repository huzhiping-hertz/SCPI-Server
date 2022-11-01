#ifndef NETUtility_H
#define NETUtility_H

#include <iostream>
#include <string>

namespace HZP
{
	using namespace std;

	class NetUtility
	{
	private:
		NetUtility() {}

	public:
		static bool Ping(string ipAddress);
	};
}
#endif