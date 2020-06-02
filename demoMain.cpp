#include <QApplication>
#include <iostream>
#include "mainwindow.h"
#include "Mylog.h"


int main(int argc, char *argv[]) {
	log4cplus::Initializer initializer;
	LOG_DEBUG("init in main");

	QApplication app(argc,argv);
	MainWindow mainWindow;
	mainWindow.show();
	std::cout << "in func main" << std::endl;
	return app.exec();
}