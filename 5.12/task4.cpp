#include <iostream>

using namespace std;

int main()
{
  int size;
  cout << "Введите размер массива: ";
  cin >> size;

  if (size <= 0)
  {
    return 0;
  }

  int *arr = new int[size];

  for (int i = 0; i < size; i++)
  {
    *(arr + i) = i * i;
  }

  long long sum = 0;
  for (int i = 0; i < size; i++)
  {
    sum += arr[i];
  }

  cout << "Сумма элементов: " << sum << endl;

  delete[] arr;

  return 0;
}