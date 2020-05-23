#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "multiplyDialog.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	QObject::connect(ui->pushButton_multiply, &QPushButton::clicked, this, &MainWindow::openMultiply);
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::openMultiply()
{
	multiplyDialog* mul = new multiplyDialog(this);
	std::cout << "in open" << std::endl;
	mul->show();
}