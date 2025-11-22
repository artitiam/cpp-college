#include <iostream>
using namespace std;

int main()
{
  int sec, hour, min, sec1;
  cout << "Введите время в секундах для перевода в часы, минуты и секунды: ";
  cin >> sec, hour, min, sec1;
  hour = sec / 3600;
  min = sec % 3600 / 60;
  sec1 = sec % 60;
  cout << "Часы: " << hour << "\n";
  cout << "Минуты: " << min << "\n";
  cout << "Секунды: " << sec1 << "\n";

  return 0;
}