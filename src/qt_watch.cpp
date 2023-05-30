#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QtWidgets>

#include <iostream>

int main(int argc, char ** argv)
{
  QApplication app(argc, argv);
  TimerWidget window;
  window.show();
  return app.exec();
}
