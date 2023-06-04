#include <QApplication>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QWidget>

class PlusMinusButton : public QWidget
{
  // Q_OBJECT macro must be included in classes that declare their own signals and slots.
  Q_OBJECT
public:
  PlusMinusButton(QWidget * parent = nullptr) : QWidget(parent)
  {
    auto * quit_button = new QPushButton("Quit", this);
    quit_button->setGeometry(50, 40, 75, 30);

    auto * plus_button = new QPushButton("+", this);
    auto * minus_button = new QPushButton("-", this);
    label = new QLabel("0", this);

    auto * grid = new QGridLayout(this);
    grid->addWidget(plus_button, 0, 0);
    grid->addWidget(minus_button, 0, 1);
    grid->addWidget(label, 1, 1);

    setLayout(grid);
    connect(quit_button, &QPushButton::clicked, qApp, &QApplication::quit);
    connect(plus_button, &QPushButton::clicked, this, &PlusMinusButton::onPlus);
    connect(minus_button, &QPushButton::clicked, this, &PlusMinusButton::onMinus);
  }

private slots:
  void onPlus()
  {
    int val = label->text().toInt();
    ++val;
    label->setText(QString::number(val));
  }

  void onMinus()
  {
    int val = label->text().toInt();
    --val;
    label->setText(QString::number(val));
  }

private:
  QLabel * label;
};  // class PlusMinusButton

#include "button.moc"

int main(int argc, char ** argv)
{
  QApplication app(argc, argv);

  PlusMinusButton window;
  window.resize(250, 150);
  window.setWindowTitle("Plus Minus");
  window.show();

  return app.exec();
}