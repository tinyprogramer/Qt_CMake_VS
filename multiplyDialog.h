#ifndef MULTIPLYDialog_H
#define MULTIPLYDialog_H

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