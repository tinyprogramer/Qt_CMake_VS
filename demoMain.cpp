#include <QApplication>
#include <iostream>
#include <cstdlib>

#include "mainwindow.h"
#include "Mylog.h"


int main(int argc, char *argv[]) {

	Mylog* mLogger = Mylog::getInstance();

	mLogger->debug(std::string("logger init"));

	QApplication app(argc,argv);
	MainWindow mainWindow;
	mainWindow.show();
	std::cout << "in func main" << std::endl;
	app.exec();

	return 0;
}