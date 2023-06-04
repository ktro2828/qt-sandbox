#include <QDir>
#include <QFileInfo>
#include <QTextStream>

int main(int argc, char ** argv)
{
  QTextStream out(stdout);

  if (argc != 2) {
    qWarning("Usage: ./build/dir <DIRECTORY>");
    return 1;
  }

  QString directory = argv[1];

  QDir dir{directory};

  if (!dir.exists()) {
    qWarning("No such directory exists: %s", directory.toStdString().c_str());
    return 1;
  }

  dir.setFilter(QDir::Files | QDir::AllDirs);
  dir.setSorting(QDir::Size | QDir::Reversed);

  QFileInfoList list = dir.entryInfoList();

  int max_size = std::max_element(
                   list.begin(), list.end(),
                   [&](const QFileInfo & info1, const QFileInfo & info2) {
                     int size1 = info1.fileName().size();
                     int size2 = info2.fileName().size();
                     return size1 < size2;
                   })
                   ->fileName()
                   .size();

  out << QString("Filename").leftJustified(max_size + 2).append("Bytes") << Qt::endl;
  for (int i = 0; i < list.size(); ++i) {
    QFileInfo fileInfo = list.at(i);
    QString msg = fileInfo.fileName().leftJustified(max_size + 2);
    msg.append(QString("%1").arg(fileInfo.size()));
    out << msg << Qt::endl;
  }
}