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
		static void Init(string log="both") {

			AutoPtr<SimpleFileChannel> fileChannel(new SimpleFileChannel);
			fileChannel->setProperty("path", "scpi.log");
			fileChannel->setProperty("rotation", "1000 K");

			AutoPtr<WindowsConsoleChannel> consoleChannel(new WindowsConsoleChannel());


			AutoPtr<PatternFormatter> pattern(new PatternFormatter);
			pattern->setProperty("pattern", "%Y-%m-%d %H:%M:%S:%i:%c : %t");

			AutoPtr<FormattingChannel> consoleChannelFormat(new FormattingChannel(pattern, consoleChannel));
			AutoPtr<FormattingChannel> fileChannelFormat(new FormattingChannel(pattern, fileChannel));

			AutoPtr<SplitterChannel> pSplitter(new SplitterChannel);
			pSplitter->addChannel(consoleChannelFormat);
			pSplitter->addChannel(fileChannelFormat);
			
			if (log == "file")
			{
				Logger::root().setChannel(fileChannelFormat);
				return;
			}

			if (log == "console")
			{
				Logger::root().setChannel(consoleChannelFormat);
				return;
			}

			Logger::root().setChannel(pSplitter);
		}


		static void Write(string msg) {
			Logger& logger = Logger::get("ScpiLog");
			logger.information(msg);
		};
	};
}
#endif
