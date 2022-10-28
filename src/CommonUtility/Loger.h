#ifndef LOGER_H
#define LOGER_H

#include <iostream>
#include <string>
#include "Poco/Logger.h"
#include "Poco/SimpleFileChannel.h"
#include "Poco/WindowsConsoleChannel.h"
#include "Poco/SplitterChannel.h"
#include "Poco/AutoPtr.h"

using namespace std;
using Poco::Logger;
using Poco::SimpleFileChannel;
using Poco::WindowsConsoleChannel;
using Poco::SplitterChannel;
using Poco::AutoPtr;

namespace HZP
{
	class Loger
	{
	private:
		Loger() {}

	public:
		static void Init() {

			AutoPtr<SimpleFileChannel> pChannel(new SimpleFileChannel);
			pChannel->setProperty("path", "scpi.log");
			pChannel->setProperty("rotation", "2 K");
			AutoPtr<WindowsConsoleChannel> wChannel(new WindowsConsoleChannel());
			AutoPtr<SplitterChannel> pSplitter(new SplitterChannel);
			pSplitter->addChannel(pChannel);
			pSplitter->addChannel(wChannel);
			Logger::root().setChannel(pSplitter);
		}

		static void Write(string msg) {
			Logger& logger = Logger::get("ScpiLog");
			logger.information(msg);
		};
	};
}
#endif
