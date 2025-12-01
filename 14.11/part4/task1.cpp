#include <iostream>
using namespace std;

int main()
{
  cout << "Введите целое число: ";
  int num;
  int countNum = 0;
  int sum = 0;
  int countZero = 0;
  cin >> num;

  while (true)
  {
    if (num > 0)
    {
      if (num % 10 == 0)
      {
        countZero++;
      }
      countNum++;
      sum += num % 10;
      num = num / 10;
    }
    else
    {
      break;
    }
  }
  float avg = static_cast<float>(sum) / static_cast<float>(countNum);
  cout << "Количество цифр: " << countNum << "\n";
  cout << "Сумма цифр числа: " << sum << "\n";
  cout << "Среднее арифметическое цифр числа: " << avg << "\n";
  cout << "Количесто нулей в числе: " << countZero << "\n";

  return 0;
}
