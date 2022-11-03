#ifndef LOGER_H
#define LOGER_H

#include <iostream>
#include <string>
#include "Poco/Logger.h"
#include "Poco/SimpleFileChannel.h"
#include "Poco/WindowsConsoleChannel.h"
#include "Poco/SplitterChannel.h"
#include "Poco/AutoPtr.h"
#include "Poco/FormattingChannel.h"
#include "Poco/PatternFormatter.h"
#include <gflags/gflags.h>

using namespace std;
using Poco::Logger;
using Poco::SimpleFileChannel;
using Poco::WindowsConsoleChannel;
using Poco::SplitterChannel;
using Poco::FormattingChannel;
using Poco::PatternFormatter;
using Poco::AutoPtr;

namespace HZP
{
	class Loger
	{
	private:
		Loger() {}

	public:
		static void Init(string logName, string logType="both");
		static void Trace(string msg);
		static void Error(string msg);
	};
}
#endif
