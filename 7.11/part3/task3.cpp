#include <iostream>
using namespace std;

int main()
{
  int num1, num2, num3, num4, num5, num6, num7, max_num;
  cout << "Введите 7 целых чисел: ";
  cin >> num1 >> num2 >> num3 >> num4 >> num5 >> num6 >> num7;
  if (num1 < num2)
  {
    max_num = num2;
  }
  else
  {
    max_num = num1;
  }
  if (max_num < num3)
  {
    max_num = num3;
  }
  if (max_num < num4)
  {
    max_num = num4;
  }
  if (max_num < num5)
  {
    max_num = num5;
  }
  if (max_num < num6)
  {
    max_num = num6;
  }
  if (max_num < num7)
  {
    max_num = num7;
  }

  cout << "Самое большое число: " << max_num << endl;

  return 0;
}