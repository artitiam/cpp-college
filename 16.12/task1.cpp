#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Student
{
  string name;
  int group;
  int ses[5];
};

void task1()
{
  const int size = 10;
  vector<Student> students(size);

  cout << "\nЗадание 1. Студенты. Ввод данных для 10 студентов\n";
  for (int i = 0; i < size; ++i)
  {
    cout << "Студент " << i + 1 << ":\n";
    cout << "Фамилия и инициалы: ";
    cin.ignore();
    getline(cin, students[i].name);
    cout << "Номер группы: ";
    cin >> students[i].group;
    cout << "Оценки (5 чисел): ";
    for (int k = 0; k < 5; ++k)
      cin >> students[i].ses[k];
  }

  sort(students.begin(), students.end(), [](const Student &a, const Student &b)
       { return a.group < b.group; });

  cout << "\nСтуденты со средним баллом > 4.0\n";
  bool found = false;
  for (const auto &s : students)
  {
    double sum = 0;
    for (int k = 0; k < 5; ++k)
      sum += s.ses[k];
    if (sum / 5.0 > 4.0)
    {
      cout << "Фамилия: " << s.name << ", Группа: " << s.group << endl;
      found = true;
    }
  }
  if (!found)
    cout << "Таких студентов нет.\n";
}

struct Aeroflot
{
  string nazn;
  int numr;
  string tip;
};

void task2()
{
  const int size = 7;
  vector<Aeroflot> airport(size);

  cout << "\nЗадание 2. Аэрофлот. Ввод данных для 7 рейсов\n";
  for (int i = 0; i < size; ++i)
  {
    cout << "Рейс " << i + 1 << ":\n";
    cout << "Пункт назначения: ";
    cin.ignore();
    getline(cin, airport[i].nazn);
    cout << "Номер рейса: ";
    cin >> airport[i].numr;
    cout << "Тип самолета: ";
    cin.ignore();
    getline(cin, airport[i].tip);
  }

  sort(airport.begin(), airport.end(), [](const Aeroflot &a, const Aeroflot &b)
       { return a.numr < b.numr; });

  string searchNazn;
  cout << "\nВведите пункт назначения для поиска: ";
  getline(cin, searchNazn);

  bool found = false;
  for (const auto &a : airport)
  {
    if (a.nazn == searchNazn)
    {
      cout << "Рейс: " << a.numr << ", Тип: " << a.tip << endl;
      found = true;
    }
  }
  if (!found)
    cout << "Рейсов в этот пункт нет.\n";
}

struct Worker
{
  string name;
  string pos;
  int year;
};

void task3()
{
  const int size = 10;
  vector<Worker> table(size);

  cout << "\nЗадание 3. Работники. Ввод данных для 10 работников\n";
  for (int i = 0; i < size; ++i)
  {
    cout << "Работник " << i + 1 << ":\n";
    cout << "Фамилия и инициалы: ";
    cin.ignore();
    getline(cin, table[i].name);
    cout << "Должность: ";
    getline(cin, table[i].pos);
    cout << "Год поступления: ";
    cin >> table[i].year;
  }

  sort(table.begin(), table.end(), [](const Worker &a, const Worker &b)
       { return a.name < b.name; });

  int minExp, currentYear = 2025;
  cout << "\nВведите минимальный стаж (лет): ";
  cin >> minExp;

  bool found = false;
  for (const auto &w : table)
  {
    if ((currentYear - w.year) > minExp)
    {
      cout << w.name << endl;
      found = true;
    }
  }
  if (!found)
    cout << "Таких работников нет.\n";
}

struct Train
{
  string nazn;
  int numr;
  string time;
};

void task4()
{
  const int size = 8;
  vector<Train> rasp(size);

  cout << "\nЗадание 4. Поезда. Ввод данных для 8 поездов\n";
  for (int i = 0; i < size; ++i)
  {
    cout << "Поезд " << i + 1 << ":\n";
    cout << "Пункт назначения: ";
    cin.ignore();
    getline(cin, rasp[i].nazn);
    cout << "Номер поезда: ";
    cin >> rasp[i].numr;
    cout << "Время (ЧЧ:ММ): ";
    cin >> rasp[i].time;
  }

  sort(rasp.begin(), rasp.end(), [](const Train &a, const Train &b)
       { return a.nazn < b.nazn; });

  string searchTime;
  cout << "\nВведите время (ЧЧ:ММ), после которого искать: ";
  cin >> searchTime;

  bool found = false;
  for (const auto &t : rasp)
  {
    if (t.time > searchTime)
    {
      cout << "Поезд " << t.numr << " в " << t.nazn << " отправляется в " << t.time << endl;
      found = true;
    }
  }
  if (!found)
    cout << "Таких поездов нет.\n";
}

struct Marsh
{
  string begst;
  string term;
  int numer;
};

void task5()
{
  const int size = 8;
  vector<Marsh> traffic(size);

  cout << "\nЗадание 5. Маршруты. Ввод данных для 8 маршрутов\n";
  for (int i = 0; i < size; ++i)
  {
    cout << "Маршрут " << i + 1 << ":\n";
    cout << "Начальный пункт: ";
    cin.ignore();
    getline(cin, traffic[i].begst);
    cout << "Конечный пункт: ";
    getline(cin, traffic[i].term);
    cout << "Номер маршрута: ";
    cin >> traffic[i].numer;
  }

  sort(traffic.begin(), traffic.end(), [](const Marsh &a, const Marsh &b)
       { return a.numer < b.numer; });

  int searchNum;
  cout << "\nВведите номер маршрута: ";
  cin >> searchNum;

  bool found = false;
  for (const auto &m : traffic)
  {
    if (m.numer == searchNum)
    {
      cout << "Маршрут: " << m.begst << " -> " << m.term << endl;
      found = true;
    }
  }
  if (!found)
    cout << "Маршрут не найден.\n";
}

struct Note
{
  string name;
  string tele;
  int bday[3];
};

void task6()
{
  const int size = 8;
  vector<Note> blocknote(size);

  cout << "\nЗадание 6. Блокнот. Ввод данных для 8 человек\n";
  for (int i = 0; i < size; ++i)
  {
    cout << "Запись " << i + 1 << ":\n";
    cout << "Фамилия, Имя: ";
    cin.ignore();
    getline(cin, blocknote[i].name);
    cout << "Телефон: ";
    cin >> blocknote[i].tele;
    cout << "День рождения (Д М Г через пробел): ";
    cin >> blocknote[i].bday[0] >> blocknote[i].bday[1] >> blocknote[i].bday[2];
  }

  sort(blocknote.begin(), blocknote.end(), [](const Note &a, const Note &b)
       {
        if (a.bday[2] != b.bday[2]) return a.bday[2] < b.bday[2];
        if (a.bday[1] != b.bday[1]) return a.bday[1] < b.bday[1];
        return a.bday[0] < b.bday[0]; });

  string searchTel;
  cout << "\nВведите телефон для поиска: ";
  cin >> searchTel;

  bool found = false;
  for (const auto &n : blocknote)
  {
    if (n.tele == searchTel)
    {
      cout << "Найдено: " << n.name << ", ДР: "
           << n.bday[0] << "." << n.bday[1] << "." << n.bday[2] << endl;
      found = true;
    }
  }
  if (!found)
    cout << "Запись не найдена.\n";
}

struct Order
{
  string plat;
  string pol;
  double summa;
};

void task7()
{
  const int size = 8;
  vector<Order> spisok(size);

  cout << "\nЗадание 7. Заказы. Ввод данных для 8 заказов\n";
  for (int i = 0; i < size; ++i)
  {
    cout << "Заказ " << i + 1 << ":\n";
    cout << "Счет плательщика: ";
    cin.ignore();
    getline(cin, spisok[i].plat);
    cout << "Счет получателя: ";
    getline(cin, spisok[i].pol);
    cout << "Сумма: ";
    cin >> spisok[i].summa;
  }

  sort(spisok.begin(), spisok.end(), [](const Order &a, const Order &b)
       { return a.plat < b.plat; });

  string searchPlat;
  cout << "\nВведите счет плательщика для поиска: ";
  cin.ignore();
  getline(cin, searchPlat);

  bool found = false;
  for (const auto &o : spisok)
  {
    if (o.plat == searchPlat)
    {
      cout << "Снято: " << o.summa << " руб. (Получатель: " << o.pol << ")\n";
      found = true;
    }
  }
  if (!found)
    cout << "Счет не найден.\n";
}

int main()
{
  int choice;

  do
  {
    cout << "\nМеню заданий\n";
    cout << "1. Студенты (Student)\n";
    cout << "2. Аэрофлот (Aeroflot)\n";
    cout << "3. Работники (Worker)\n";
    cout << "4. Поезда (Train)\n";
    cout << "5. Маршруты (Marsh)\n";
    cout << "6. Блокнот (Note)\n";
    cout << "7. Платежи (Order)\n";
    cout << "0. Выход\n";
    cout << "Выберите номер задания: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
      task1();
      break;
    case 2:
      task2();
      break;
    case 3:
      task3();
      break;
    case 4:
      task4();
      break;
    case 5:
      task5();
      break;
    case 6:
      task6();
      break;
    case 7:
      task7();
      break;
    case 0:
      cout << "Выход...\n";
      break;
    default:
      cout << "Неверный ввод!\n";
    }
  } while (choice != 0);

  return 0;
}