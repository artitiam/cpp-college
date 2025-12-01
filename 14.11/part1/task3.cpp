#include <iostream>
using namespace std;

int main()
{
  int a = 1000;
  int sum = 0;
  for (int i = 1; i <= a; i++)
  {
    sum += i;
  }

  float avg = sum / 1000.0;

  cout << "Среднее арифметическое от 1 до 1000 равно: " << avg << endl;

  return 0;
}