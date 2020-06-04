#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "multiplyDialog.h"
#include "webmapDialog.h"
#include "Mylog.h"

#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	LOG_DEBUG("MainWindow Constructed");
	ui->setupUi(this);
	QObject::connect(ui->pushButton_multiply, &QPushButton::clicked, this, &MainWindow::openMultiply);
	QObject::connect(ui->pushButton_webMap, &QPushButton::clicked, this, &MainWindow::openMap);
}

MainWindow::~MainWindow()
{
	LOG_DEBUG("MainWindow Destoryed");
	delete ui;
}

void MainWindow::openMultiply()
{
	multiplyDialog* mul = new multiplyDialog(this);
	std::cout << "in open" << std::endl;
	mul->show();
}

void MainWindow::openMap()
{
	webmapDialog* map = new webmapDialog(this);
	map->show();
}