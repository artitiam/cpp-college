#include <iostream>
using namespace std;

int main()
{
  int from, to;
  float minutes;
  float price_per_min = 0.0;

  cout << "Введите длительность разговора (в минутах), исходного оператора(1 или 2) и оператора назначения(1 или 2): ";
  cin >> minutes >> from >> to;

  if (from == 1 && to == 1)
  {
    price_per_min = 0.5;
  }
  else if (from == 1 && to == 2)
  {
    price_per_min = 0.7;
  }
  else if (from == 2 && to == 1)
  {
    price_per_min = 0.6;
  }
  else if (from == 2 && to == 2)
  {
    price_per_min = 0.4;
  }
  else
  {
    cout << "Неверно выбран оператор!" << endl;
    return 0;
  }

  float cost = minutes * price_per_min;

  cout << "\nСтоимость разговора: " << cost << "$" << endl;

  return 0;
}
