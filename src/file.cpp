#include <QFileInfo>
#include <QTextStream>

int main(int argc, char ** argv)
{
  QTextStream out(stdout);

  if (argc < 2) {
    qWarning("Usage: ./build/file <FILE_NAME>");
    return 1;
  }

  QString readfile = argv[1];
  QFile rf{readfile};

  if (!rf.exists()) {
    qWarning("No such file is found: %s", readfile.toStdString().c_str());
    return 1;
  }

  QFileInfo file_info{readfile};
  qint64 size = file_info.size();
  QString msg = "The size is: %1 bytes";
  out << msg.arg(size) << Qt::endl;

  out << "Absolute path: " << file_info.absoluteFilePath() << Qt::endl;
  out << "Base name: " << file_info.baseName() << Qt::endl;
  out << "Complete base name: " << file_info.completeBaseName() << Qt::endl;
  out << "File name: " << file_info.fileName() << Qt::endl;
  out << "Suffix: " << file_info.suffix() << Qt::endl;
  out << "Whole suffix: " << file_info.completeSuffix() << Qt::endl;

  if (!rf.open(QIODevice::ReadOnly)) {
    qWarning("Cannot open file for reading");
    return 1;
  }

  // read and display
  QTextStream fin{&rf};
  while (!fin.atEnd()) {
    QString line = fin.readLine();
    out << line << Qt::endl;
  }

  // write
  if (argc != 3) {
    qWarning("Usage: ./build/file <READ_FILE_NAME> <WRITE_FILE_NAME>");
    return 1;
  }

  QString writefile = argv[2];
  QFile wf{writefile};
  if (wf.open(QIODevice::WriteOnly)) {
    QTextStream fout{&wf};
    fout << "Xubuntu" << Qt::endl;
    fout << "Arch" << Qt::endl;
    fout << "Debian" << Qt::endl;
    fout << "Redhat" << Qt::endl;
    fout << "Slackware" << Qt::endl;
  } else {
    qWarning("Could not open file: %s", writefile.toStdString().c_str());
    return 1;
  }

  // copy
  QString dst{"copyout.txt"};
  QFile::copy(readfile, dst);
}