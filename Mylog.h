#ifndef __MYLOG_H__
#define __MYLOG_H__

#ifdef WIN32
#pragma comment(lib, "Ws2_32.lib")
#endif

#include <log4cpp/Category.hh>
#include <string>

using std::string;

class Mylog
{
public:
	static Mylog*  getInstance();
	static Mylog* myLogger;

	static void destroy();

	void error(string& msg);
	void warn(string& msg);
	void debug(string& msg);
	void info(string& msg);

private:
	Mylog();
	void init();

	static Mylog * _mLogger;

	log4cpp::Category* _mCate;
};

#define postfix(msg)  (std::string(msg).append(" ## ")\
	.append(__FILE__).append(":").append(__func__)\
	.append(":").append(std::to_string(__LINE__)).append(" ## "))


#define LOG_ERROR(msg) Mylog::myLogger->error(postfix(msg)) 
#define LOG_WARN(msg)  Mylog::myLogger->warn(postfix(msg))
#define LOG_INFO(msg)  Mylog::myLogger->info(postfix(msg))
#define LOG_DEBUG(msg) Mylog::myLogger->debug(postfix(msg))


#endif