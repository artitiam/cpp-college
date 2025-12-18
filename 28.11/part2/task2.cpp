#include <iostream>

using namespace std;

int *allocateMemory(int size)
{
  return new int[size];
}

void initArray(int *arr, int size)
{
  for (int i = 0; i < size; i++)
  {
    arr[i] = i + 1;
  }
}

void printArray(int *arr, int size)
{
  if (size <= 0)
  {
    cout << "Массив пуст" << endl;
    return;
  }
  for (int i = 0; i < size; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}

void deleteArray(int *&arr)
{
  delete[] arr;
  arr = nullptr;
}

void addToEnd(int *&arr, int &size, int value)
{
  int *temp = new int[size + 1];
  for (int i = 0; i < size; i++)
  {
    temp[i] = arr[i];
  }
  temp[size] = value;
  delete[] arr;
  arr = temp;
  size++;
}

void insertAtIndex(int *&arr, int &size, int index, int value)
{
  if (index < 0 || index > size)
    return;
  int *temp = new int[size + 1];
  for (int i = 0; i < index; i++)
  {
    temp[i] = arr[i];
  }
  temp[index] = value;
  for (int i = index; i < size; i++)
  {
    temp[i + 1] = arr[i];
  }
  delete[] arr;
  arr = temp;
  size++;
}

void removeAtIndex(int *&arr, int &size, int index)
{
  if (index < 0 || index >= size)
    return;
  int *temp = new int[size - 1];
  for (int i = 0, j = 0; i < size; i++)
  {
    if (i == index)
      continue;
    temp[j++] = arr[i];
  }
  delete[] arr;
  arr = temp;
  size--;
}

bool isPrime(int n)
{
  if (n < 2)
    return false;
  for (int i = 2; i * i <= n; i++)
  {
    if (n % i == 0)
      return false;
  }
  return true;
}

int *removePrimes(int *&arr, int &size)
{
  int newSize = 0;
  for (int i = 0; i < size; i++)
  {
    if (!isPrime(arr[i]))
      newSize++;
  }

  int *newArr = new int[newSize];
  for (int i = 0, j = 0; i < size; i++)
  {
    if (!isPrime(arr[i]))
    {
      newArr[j++] = arr[i];
    }
  }

  delete[] arr;
  size = newSize;
  return newArr;
}

void distributeElements(int *staticArr, int staticSize)
{
  int posSize = 0, negSize = 0, zeroSize = 0;

  for (int i = 0; i < staticSize; i++)
  {
    if (staticArr[i] > 0)
      posSize++;
    else if (staticArr[i] < 0)
      negSize++;
    else
      zeroSize++;
  }

  int *posArr = new int[posSize];
  int *negArr = new int[negSize];
  int *zeroArr = new int[zeroSize];

  int p = 0, n = 0, z = 0;
  for (int i = 0; i < staticSize; i++)
  {
    if (staticArr[i] > 0)
      posArr[p++] = staticArr[i];
    else if (staticArr[i] < 0)
      negArr[n++] = staticArr[i];
    else
      zeroArr[z++] = staticArr[i];
  }

  cout << "\nПоложительные: ";
  printArray(posArr, posSize);
  cout << "Отрицательные: ";
  printArray(negArr, negSize);
  cout << "Нулевые: ";
  printArray(zeroArr, zeroSize);

  delete[] posArr;
  delete[] negArr;
  delete[] zeroArr;
}

int main()
{

  int size = 5;
  int *myArr = allocateMemory(size);
  initArray(myArr, size);

  cout << "Задание 1. Начальный массив: ";
  printArray(myArr, size);

  addToEnd(myArr, size, 10);
  insertAtIndex(myArr, size, 2, 99);
  removeAtIndex(myArr, size, 0);
  cout << "После изменений (добавление, вставка, удаление): ";
  printArray(myArr, size);

  cout << "\nЗадание 2. Удаление простых чисел из: ";
  printArray(myArr, size);
  myArr = removePrimes(myArr, size);
  cout << "Результат: ";
  printArray(myArr, size);

  cout << "\nЗадание 3.";
  int staticArr[] = {5, -2, 0, 10, -8, 0, 3};
  int staticSize = sizeof(staticArr) / sizeof(staticArr[0]);
  cout << " Исходный статический массив: ";
  for (int i : staticArr)
    cout << i << " ";
  distributeElements(staticArr, staticSize);

  deleteArray(myArr);
  return 0;
}