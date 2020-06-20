#ifndef __MYLOG_H__
#define __MYLOG_H__

#include <log4cplus/initializer.h>
#include <log4cplus/logger.h>
#include <log4cplus/configurator.h>
#include <log4cplus/helpers/stringhelper.h>
#include <log4cplus/loggingmacros.h>
#include <log4cplus/log4cplus.h>

#include <iostream>
#include <string>

using std::string;

class Mylog
{
public:
	static Mylog*  getInstance();
	static Mylog* myLogger;

	void error(string& msg);
	void warn(string& msg);
	void debug(string& msg);
	void info(string& msg);

private:
	Mylog();
	void init();
	static Mylog* _mLogger;
	static log4cplus::Logger _mCate;
	
};

#define postfix(msg)  (std::string(msg).append(" [ ")\
	.append(__FILE__).append(":").append(__func__)\
	.append(":").append(std::to_string(__LINE__)).append(" ] "))


#define LOG_ERROR(msg) Mylog::myLogger->error(postfix(msg)) 
#define LOG_WARN(msg)  Mylog::myLogger->warn(postfix(msg))
#define LOG_INFO(msg)  Mylog::myLogger->info(postfix(msg))
#define LOG_DEBUG(msg) Mylog::myLogger->debug(postfix(msg))


#endif