#include <QTextStream>
#include <QtCore>
#include <QtWidgets>

int main(int argc, char ** argv)
{
  QTextStream out(stdout);
  out << "Qt version: " << qVersion() << Qt::endl;

  // main window
  QApplication app(argc, argv);
  QWidget window;
  window.resize(1080, 920);
  window.setWindowTitle("Watch");
  window.show();

  // label
  QLabel label("<center>Welcome to my first Qt</center>", &window);
  QFont font;
  font.setBold(true);
  int size =
    label.size().width() < label.size().height() ? label.size().width() : label.size().height();
  font.setPixelSize(size * 2);
  label.setFont(font);

  // button to exit
  QPushButton button("Exit", &window);
  QObject::connect(&button, SIGNAL(clicked(bool)), &window, SLOT(close()));

  // layout
  QVBoxLayout layout(&window);
  layout.addWidget(&label);
  layout.addWidget(&button);

  return app.exec();
}