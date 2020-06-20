#include "webmapDialog.h"
#include "ui_webmapDialog.h"
#include "Mylog.h"

#include <iostream>
#include <QString>
#include <QFileInfo>

webmapDialog::webmapDialog(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::webmapDialog)
{
	ui->setupUi(this);
	this->setAttribute(Qt::WA_DeleteOnClose);
	ui->label_city->setText(QString::fromLocal8Bit("当前城市:"));
	
	_myChannel = new myChannel(this);

	QWebChannel* web_channel = new QWebChannel(this);
	web_channel->registerObject("qtChannel",_myChannel);
	ui->mapWebEngineView->page()->setWebChannel(web_channel);
	ui->mapWebEngineView->load(QUrl(QFileInfo("./smap/mymap_ba.html").absoluteFilePath()));
	
	QObject::connect(ui->pushButton_setCity, &QPushButton::clicked, this, &webmapDialog::setCity);
	QObject::connect(_myChannel, &myChannel::setCityLable, [this](QString city) {
		LOG_DEBUG("set city lable:" + city.toStdString());
		ui->label_city->setText(QString::fromLocal8Bit("当前城市:") + city);
	});
	//QObject::connect(ui->pushButton_multiply, &QPushButton::clicked, this, &webmapDialog::multiply);
}

webmapDialog::~webmapDialog()
{
	std::cout << "webmapDialog destroyed" << std::endl;
	delete ui;
}

//void webmapDialog::getAutocomplete(QString result)
//{
//	LOG_INFO(result.toStdString());
//}
//
//void webmapDialog::getSearchResult(QString result)
//{
//	LOG_INFO(result.toStdString());
//	ui->textBrowser_test->setText(result);
//}

void webmapDialog::setCity()
{
	QString city = ui->lineEdit_setCity->text().trimmed();
	if (city.size() == 0)
	{
		ui->textBrowser_test->setText("please enter a city!");
		return;
	}
	_myChannel->setCity(city);
	LOG_DEBUG("call mychannel.setcity:"+city.toStdString());
}
