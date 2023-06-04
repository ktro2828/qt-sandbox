#include <QApplication>
#include <QDateTime>
#include <QHBoxLayout>
#include <QLabel>
#include <QTime>
#include <QWidget>

class Timer : public QWidget
{
public:
  Timer(QWidget * parent = nullptr) : QWidget(parent)
  {
    QHBoxLayout * hbox = new QHBoxLayout(this);
    hbox->setSpacing(5);

    label = new QLabel("", this);
    hbox->addWidget(label, 0, Qt::AlignHCenter | Qt::AlignVCenter);

    QString msec = QTime::currentTime().toString("zzz");
    uint datetime = QDateTime::currentDateTime().toTime_t();
    QString text = QString("%1.%2").arg(datetime).arg(msec);
    label->setText(text);

    startTimer(1);
  }

protected:
  void timerEvent(QTimerEvent * e)
  {
    Q_UNUSED(e);
    QTime now = QTime::currentTime();
    QDateTime datetime = QDateTime::currentDateTime();
    QString text = QString("%1.%2").arg(datetime.toTime_t()).arg(now.toString("zzz"));
    label->setText(text);
  }

private:
  QLabel * label;
};

int main(int argc, char ** argv)
{
  QApplication app(argc, argv);

  Timer window;
  window.resize(640, 480);
  window.setWindowTitle("Timer");
  window.show();

  return app.exec();
}