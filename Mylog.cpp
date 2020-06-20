#include <exception>

#include "Mylog.h"
#include <log4cplus/configurator.h>
#include <log4cplus/helpers/stringhelper.h>
#include <log4cplus/loggingmacros.h>

Mylog* Mylog::_mLogger = Mylog::getInstance();
Mylog* Mylog::myLogger = Mylog::getInstance();
log4cplus::Logger Mylog::_mCate = log4cplus::Logger::getInstance(LOG4CPLUS_TEXT("rollingFile"));


Mylog* Mylog::getInstance()
{
	std::cout << "in getinstance" << std::endl;
	if (_mLogger == nullptr)
	{
		_mLogger = new Mylog();
	}
	return _mLogger;
}


Mylog::Mylog()
{
	this->init();
}

void Mylog::init()
{
	std::cout << "in init" << std::endl;
	try
	{
		log4cplus::PropertyConfigurator::doConfigure(LOG4CPLUS_TEXT("Mylog.conf"));
	}
	catch (...)
	{
		std::cerr << "configure problem "  << std::endl;
	}
	//_mCate = log4cplus::Logger::getInstance(LOG4CPLUS_TEXT("rollingFile"));
	//LOG4CPLUS_INFO(_mCate, LOG4CPLUS_TEXT("logger init"));
}

void Mylog::error(string& msg)
{
	
	LOG4CPLUS_ERROR(_mCate,LOG4CPLUS_STRING_TO_TSTRING(msg));
}

void Mylog::warn(string& msg)
{
	LOG4CPLUS_WARN(_mCate, LOG4CPLUS_STRING_TO_TSTRING(msg));
}

void Mylog::debug(string& msg)
{
	LOG4CPLUS_DEBUG(_mCate, LOG4CPLUS_STRING_TO_TSTRING(msg));
}

void Mylog::info(string& msg)
{
	LOG4CPLUS_INFO(_mCate, LOG4CPLUS_STRING_TO_TSTRING(msg));
}


