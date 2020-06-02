#include "multiplyDialog.h"
#include "ui_multiplyDialog.h"
#include "Mylog.h"

#include <iostream>
#include <QString>

multiplyDialog::multiplyDialog(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::multiplyDialog)
{
	ui->setupUi(this);
	this->setAttribute(Qt::WA_DeleteOnClose);
	ui->lineEdit_3->setReadOnly(true);
	QObject::connect(ui->pushButton_multiply, &QPushButton::clicked, this, &multiplyDialog::multiply);
}

multiplyDialog::~multiplyDialog()
{
	std::cout << "multiplyDialog destroyed" << std::endl;
	delete ui;
}

void multiplyDialog::multiply()
{
	QString l = ui->lineEdit->text();
	QString r = ui->lineEdit_2->text();
	bool val=true;
	double ln = l.toDouble(&val), rn = r.toDouble(&val);
	if (val)
	{
		double re = ln * rn;
		ui->lineEdit_3->setText(QString::number(re));
	}
	else {
		ui->lineEdit_3->setText("Error");
	}
}