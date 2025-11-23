#include <iostream>
using namespace std;

int main()
{
  int num, num1, num2, num3, sum1, num4, num5, num6, sum2;
  cout << "Введи шестизначное число, чтобы узнать счастливое оно или нет: ";
  cin >> num;
  if (num < 100000 || num > 999999)
  {
    cout << "Число НЕ шестизначное" << endl;

    return 1;
  }
  num1 = (num - num % 100000) / 100000;
  num2 = (num - num % 10000) / 10000 % 10;
  num3 = (num - num % 1000) / 1000 % 100 % 10;
  num4 = (num - num % 100) / 100 % 1000 % 100 % 10;
  num5 = (num - num % 10) / 10 % 10000 % 1000 % 100 % 10;
  num6 = num % 100000 % 10000 % 1000 % 100 % 10;
  sum1 = num1 + num2 + num3;
  sum2 = num4 + num5 + num6;
  if (sum1 == sum2)
  {
    cout << "Число " << num << " счастливое" << endl;
  }
  else
  {
    cout << "Число " << num << " НЕ счастливое" << endl;
  }

  return 0;
}