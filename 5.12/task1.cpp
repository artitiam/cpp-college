#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
  setlocale(LC_ALL, "Russian");

  const int size = 20;
  int numbers[size];

  for (int i = 0; i < size; i++)
  {
    numbers[i] = 1 + (i * 2);
  }

  int *ptr = numbers;

  cout << "Вывод в прямом порядке (по 5 в строку):" << endl;
  for (int i = 0; i < size; i++)
  {
    cout << setw(4) << *ptr;

    if ((i + 1) % 5 == 0)
    {
      cout << endl;
    }

    if (i < size - 1)
    {
      ptr++;
    }
  }

  cout << "\nВывод в обратном порядке (по 5 в строку):" << endl;
  for (int i = 0; i < size; i++)
  {
    cout << setw(4) << *ptr;

    if ((i + 1) % 5 == 0)
    {
      cout << endl;
    }

    if (i < size - 1)
    {
      ptr--;
    }
  }

  return 0;
}