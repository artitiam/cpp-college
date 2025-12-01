#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  int sumNums = 0;
  cout << "Введите целое число A: ";
  int a;
  cin >> a;
  int copy = abs(a);

  for (int i = 1; 0 < copy; i++)
  {
    sumNums += copy % 10;
    copy /= 10;
  }

  if ((a * a) == (sumNums * sumNums * sumNums))
  {
    cout << "Куб суммы цифр числа " << a << " и его квадрат равны" << endl;
  }
  else
  {
    cout << "Куб суммы цифр числа " << a << " и его квадрат НЕ равны" << endl;
  }

  return 0;
}