#ifndef __MULTIPLYDIALOG_H__
#define __MULTIPLYDIALOG_H__

#include <QDialog>

namespace Ui {
	class multiplyDialog;
}

class multiplyDialog : public QDialog
{
	Q_OBJECT

public:
	explicit multiplyDialog(QWidget *parent = nullptr);
	~multiplyDialog();
	void multiply();

private:
	Ui::multiplyDialog *ui;
};

#endif