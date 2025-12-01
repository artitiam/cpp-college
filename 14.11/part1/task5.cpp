#include <iostream>
using namespace std;

int main()
{
  cout << "Введите для какой цифры хотите вывести таблицу умножения: ";
  int a;
  cin >> a;
  for (int i = 1; i <= 10; i++)
  {
    cout << a << " * " << i << " = " << a * i << "\n";
  }

  return 0;
}