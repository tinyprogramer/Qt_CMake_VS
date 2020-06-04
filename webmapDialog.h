#ifndef __WEBMAPDIALOG_H__
#define __WEBMAPDIALOG_H__

#include <QDialog>
#include <QWebEngineView>

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

private:
	Ui::webmapDialog *ui;
};


#endif