#include <iostream>

using namespace std;

float power(float base, int exp)
{
  float result = 1.0;
  int absExp = (exp < 0) ? -exp : exp;

  for (int i = 0; i < absExp; i++)
  {
    result *= base;
  }

  if (exp < 0)
  {
    return 1.0 / result;
  }

  return result;
}

int main()
{
  float num;
  int p;

  cout << "Введите число: ";
  cin >> num;
  cout << "Введите степень: ";
  cin >> p;

  cout << "Результат: " << power(num, p) << endl;

  return 0;
}