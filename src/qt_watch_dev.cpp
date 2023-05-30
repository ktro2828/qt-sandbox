#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QtWidgets>

#include <iostream>

class TimerWidget : public QWidget
{
  Q_OBJECT
  QTimer * timer;
  QVBoxLayout * layout;
  QLabel * label;
  QPushButton * button;

public:
  TimerWidget()
  {
    this->resize(1080, 920);
    this->setWindowTitle("Watch");

    timer = new QTimer(this);
    layout = new QVBoxLayout(this);
    label = new QLabel("<center>Welcome to my first Qt</center>", this);

    button = new QPushButton(QApplication::translate("parent", "Exit"), this);
    QObject::connect(button, SIGNAL(clicked(bool)), this, SLOT(close()));
    button->move(980, 880);

    layout->addWidget(label);
    layout->addWidget(button);

    connect(timer, &QTimer::timeout, this, &TimerWidget::timerSlot);
  }
  void timerSlot() { label->setText(QTime::currentTime().toString()); }
};

int main(int argc, char ** argv)
{
  QApplication app(argc, argv);

  TimerWidget window;
  window.show();

  return app.exec();
}