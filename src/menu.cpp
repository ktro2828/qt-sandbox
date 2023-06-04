#include <QApplication>
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QStatusBar>

class SimpleMenu : public QMainWindow
{
  Q_OBJECT
public:
  SimpleMenu(QWidget * parent = nullptr) : QMainWindow(parent)
  {
    QPixmap newpix("icons/new.png");
    QPixmap openpix("icons/open.png");
    QPixmap quitpix("icons/quit.png");

    auto * new_act = new QAction(newpix, "&New", this);
    auto * open = new QAction(openpix, "&Open", this);
    auto * quit = new QAction(quitpix, "&Quit", this);
    quit->setShortcut(tr("CTRL+Q"));

    QMenu * file = menuBar()->addMenu("&File");
    file->addAction(new_act);
    file->addAction(open);
    file->addSeparator();
    file->addAction(quit);

    viewst = new QAction("&View statusbar", this);
    viewst->setCheckable(true);
    viewst->setChecked(true);
    QMenu * edit = menuBar()->addMenu("&Edit");
    edit->addAction(viewst);

    statusBar();

    qApp->setAttribute(Qt::AA_DontShowIconsInMenus, false);
    connect(quit, &QAction::triggered, qApp, &QApplication::quit);
    connect(viewst, &QAction::triggered, this, &SimpleMenu::toggleStatusBar);
  }

private slots:
  void toggleStatusBar()
  {
    if (viewst->isChecked()) {
      statusBar()->show();
    } else {
      statusBar()->hide();
    }
  }

private:
  QAction * viewst;

};  // class SimpleMenu

#include "menu.moc"

int main(int argc, char ** argv)
{
  QApplication app(argc, argv);

  SimpleMenu window;
  window.resize(350, 250);
  window.setWindowTitle("Simple menu");
  window.show();

  return app.exec();
}