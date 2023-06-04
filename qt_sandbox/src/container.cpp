#include <QList>
#include <QMap>
#include <QSet>
#include <QTextStream>
#include <QVector>

#include <algorithm>

template <typename T>
QTextStream & operator<<(QTextStream & out, const QVector<T> & values)
{
  out << "Elements: ";
  for (const T & v : values) {
    out << v << " ";
  }
  return out;
}

template <typename T>
QTextStream & operator<<(QTextStream & out, const QList<T> & values)
{
  out << "Elements: ";
  for (int i = 0; i < values.size(); ++i) {
    out << values.at(i) << " ";
  }
  return out;
}

QTextStream & operator<<(QTextStream & out, const QStringList & values)
{
  out << "Elements: \n";
  QStringListIterator iter(values);
  while (iter.hasNext()) {
    out << iter.next().trimmed() << "\n";
  }
  return out;
}

template <typename T>
QTextStream & operator<<(QTextStream & out, const QSet<T> & values)
{
  out << "Elements: ";
  for (const T & v : values) {
    out << v << " ";
  }
  return out;
}

template <typename K, typename V>
QTextStream & operator<<(QTextStream & out, const QMap<K, V> & items)
{
  QMapIterator<K, V> iter(items);
  out << "Items: ";
  while (iter.hasNext()) {
    iter.next();
    out << iter.key() << ": " << iter.value() << " ";
  }
  return out;
}

int main()
{
  QTextStream out(stdout);

  QVector<int> values = {1, 2, 3, 4, 5};
  out << "Ths size of the vector is: " << values.size() << Qt::endl;
  out << values << Qt::endl;

  QList<QString> authors = {"Balzac", "Tolstoy", "Gulbranssen", "London"};
  out << authors << Qt::endl;
  std::sort(authors.begin(), authors.end());
  out << authors << Qt::endl;

  QString string = "coin, book, cup, pencil, clock, bookmark";
  QStringList items = string.split(",");
  out << items << Qt::endl;

  QSet<QString> set1 = {"yellow", "red", "blue"};
  QSet<QString> set2 = {"blue", "pink", "orange"};
  out << "set1: " << set1 << Qt::endl;
  out << "set2: " << set2 << Qt::endl;

  set1.unite(set2);
  out << "unite: " << set1 << Qt::endl;

  QMap<QString, int> hash = {{"coins", 5}, {"books", 3}};
  hash.insert("bottles", 7);
  out << hash << Qt::endl;
}