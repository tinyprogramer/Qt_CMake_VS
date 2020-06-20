#ifndef __WEBMAPDIALOG_H__
#define __WEBMAPDIALOG_H__

#include <QDialog>
#include <QWebEngineView>
#include "myChannel.h"

namespace Ui {
	class webmapDialog;
}

class webmapDialog : public QDialog
{
	Q_OBJECT

public:
	explicit webmapDialog(QWidget *parent = nullptr);
	~webmapDialog();
	//void multiply();

	void setCity();

private:
	Ui::webmapDialog *ui;
	myChannel * _myChannel;
};


#endif