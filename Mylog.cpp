#include <exception>

#include "Mylog.h"
#include <log4cpp/PropertyConfigurator.hh>

Mylog* Mylog::_mLogger = Mylog::getInstance();
Mylog* Mylog::myLogger = Mylog::getInstance();

Mylog* Mylog::getInstance()
{
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
	try
	{
		log4cpp::PropertyConfigurator::configure("Mylog.conf");
	}
	catch (log4cpp::ConfigureFailure & f)
	{
		std::cerr << "configure problem " << f.what() << std::endl;
	}
	_mCate = &log4cpp::Category::getInstance("rollingFile");
	_mCate->info("myLogger init");
}

void Mylog::error(string& msg)
{
	_mCate->error(msg);
}

void Mylog::warn(string& msg)
{
	_mCate->warn(msg);
}

void Mylog::debug(string& msg)
{
	_mCate->debug(msg);
}

void Mylog::info(string& msg)
{
	_mCate->info(msg);
}

void Mylog::destroy()
{
	if (_mLogger)
	{
		_mLogger->_mCate->info("Mylog destroyed");
		_mLogger->_mCate->shutdown();
		delete _mLogger;
		_mLogger = nullptr;
	}
}

