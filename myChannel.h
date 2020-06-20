#ifndef __MYCHANNEL_H__
#define __MYCHANNEL_H__

#include <QWebChannel>

class myChannel :public QObject 
{
	Q_OBJECT
public:
	explicit myChannel(QObject* parent=nullptr){}

	void setCity(QString city);

public slots:

	void getSearchResult(QString result);
	void getAutocomplete(QString result);
	void cityChangeResult(QString result);

signals:
	void cityChanged(QString city);
	void inputChanged(QString input);

	void setCityLable(QString city);

};


#endif