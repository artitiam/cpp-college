#include <iostream>
using namespace std;

int main()
{
  int num, num1, num2, num3, num4;
  cout << "Введите число: ";
  cin >> num;
  if (num < 1000 || num > 9999)
  {
    cout << "Число НЕ четырехзначное" << endl;

    return 1;
  }
  num1 = num / 1000 * 100;
  num2 = num / 100 % 10 * 1000;
  num3 = num / 10 % 10;
  num4 = num % 10 * 10;
  num = num1 + num2 + num3 + num4;
  cout << num << endl;

  return 0;
}