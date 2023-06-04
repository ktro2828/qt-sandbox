#include <QDate>
#include <QDateTime>
#include <QLocale>
#include <QTextStream>
#include <QTime>

int main()
{
  QTextStream out(stdout);

  QDate date1{2020, 4, 12};
  out << "The date is " << date1.toString() << Qt::endl;

  QTime time1{17, 30, 12, 44};
  out << "Ths time is " << time1.toString() << Qt::endl;

  QDate today = QDate::currentDate();
  out << "Current date is " << today.toString() << Qt::endl;

  QTime now = QTime::currentTime();
  out << "Current time is " << now.toString() << Qt::endl;
  out << "Current time is " << now.toString("hh::mm::ss.zzz") << Qt::endl;

  QLocale locale(QLocale("en_US"));
  out << "Today is " << locale.dayName(today.dayOfWeek()) << "!! ["
      << locale.dayName(today.dayOfWeek(), QLocale::ShortFormat) << "]" << Qt::endl;

  out << "There are " << today.daysInMonth() << " days in " << today.toString("MMM") << Qt::endl;

  QDateTime datetime = QDateTime::currentDateTime();
  out << "Universal datetime: " << datetime.toUTC().toString() << Qt::endl;
  out << "Local datetime: " << datetime.toLocalTime().toString() << Qt::endl;
  out << "Unix time: " << datetime.toTime_t() << "." << now.toString("zzz") << Qt::endl;
}