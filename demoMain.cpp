#include <QApplication>
#include <iostream>
#include "mainwindow.h"
#include "log4cpp/Category.hh"


int main(int argc, char *argv[]) {
	QApplication app(argc,argv);
	MainWindow mainWindow;
	mainWindow.show();
	std::cout << "in func main" << std::endl;
	return app.exec();
}