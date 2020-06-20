#include "myChannel.h"
#include "Mylog.h"

void myChannel::cityChangeResult(QString result)
{
	LOG_DEBUG("result:" + result.toStdString());
	emit setCityLable(result);
}

void myChannel::getSearchResult(QString result)
{
	LOG_DEBUG("result:" + result.toStdString());
}

void myChannel::getAutocomplete(QString result)
{
	LOG_DEBUG("result:" + result.toStdString());
}

void myChannel::setCity(QString city)
{
	emit cityChanged(city);
}