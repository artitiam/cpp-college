#include <iostream>
using namespace std;

int main()
{
  int a = 100;
  int b = 999;
  int count = 0;
  for (int i = a; i <= b; i++)
  {
    if ((i / 100 == i % 100 / 10) || (i / 100 == i % 10) || (i % 100 / 10 == i % 10))
    {
      count++;
    }
  }

  cout << count << " чисел у которых есть минимум две одинаковые цифры" << endl;

  return 0;
}