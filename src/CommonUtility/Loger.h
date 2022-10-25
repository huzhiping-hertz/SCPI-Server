#ifndef LOGER_H
#define LOGER_H

#include <string>
#include <iostream>
#include <map>
#include "Poco/MD5Engine.h"
#include "Poco/DigestStream.h"

namespace RS
{
	using namespace std;

	class Loger
	{
		Loger();

	public:
		static Loger *getInstance();
		~Loger();
	};
}
#endif
