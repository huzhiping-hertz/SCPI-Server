#include "Loger.h"

using namespace HZP;
using namespace std;
DECLARE_bool(log_debug);

void  Loger::Init(string logName, string log) {

	AutoPtr<SimpleFileChannel> fileChannel(new SimpleFileChannel);
	fileChannel->setProperty("path", logName);
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

void Loger::Write(string msg) {
	if (FLAGS_log_debug)
	{
		Logger& logger = Logger::get("Debug");
		logger.information(msg);
	}
};

void Loger::WriteError(string msg)
{
	Logger& logger = Logger::get("Error");
	logger.information(msg);
}