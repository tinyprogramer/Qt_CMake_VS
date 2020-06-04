#include "webmapDialog.h"
#include "ui_webmapDialog.h"
//#include "Mylog.h"

#include <iostream>
#include <QString>

webmapDialog::webmapDialog(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::webmapDialog)
{
	ui->setupUi(this);
	this->setAttribute(Qt::WA_DeleteOnClose);
	ui->mapWebEngineView->load(QUrl("https://www.baidu.com"));
	//QObject::connect(ui->pushButton_multiply, &QPushButton::clicked, this, &webmapDialog::multiply);
}

webmapDialog::~webmapDialog()
{
	std::cout << "webmapDialog destroyed" << std::endl;
	delete ui;
}
