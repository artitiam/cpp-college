#include <iostream>

using namespace std;

void printArray(int *arr, int size)
{
  for (int i = 0; i < size; i++)
  {
    cout << *(arr + i) << " ";
  }
  cout << endl;
}

int main()
{
  setlocale(LC_ALL, "Russian");

  const int size = 5;
  int source[size] = {10, 20, 30, 40, 50};
  int destination[size];

  int *ptrSource = source;
  int *ptrDest = destination;

  for (int i = 0; i < size; i++)
  {
    *(ptrDest + i) = *(ptrSource + i);
  }

  cout << "Задание 1. Скопированный массив: ";
  printArray(destination, size);

  int *start = source;
  int *end = source + size - 1;

  while (start < end)
  {
    int temp = *start;
    *start = *end;
    *end = temp;

    start++;
    end--;
  }

  cout << "\nЗадание 2. Исходный массив после реверса: ";
  printArray(source, size);

  int *pSrc = source;
  int *pDst = destination + size - 1;

  for (int i = 0; i < size; i++)
  {
    *(pDst - i) = *(pSrc + i);
  }

  cout << "\nЗадание 3. Массив destination (копия в обратном порядке): ";
  printArray(destination, size);

  return 0;
}