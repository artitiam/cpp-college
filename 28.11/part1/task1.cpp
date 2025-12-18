#include <iostream>

using namespace std;

float getMax(const int *a, int sizeA, const int *b, int sizeB)
{
  int maxVal = *a;
  for (int i = 0; i < sizeA; i++)
  {
    if (*(a + i) > maxVal)
      maxVal = *(a + i);
  }
  for (int i = 0; i < sizeB; i++)
  {
    if (*(b + i) > maxVal)
      maxVal = *(b + i);
  }
  return (float)maxVal;
}

float getMin(const int *a, int sizeA, const int *b, int sizeB)
{
  int minVal = *a;
  for (int i = 0; i < sizeA; i++)
  {
    if (*(a + i) < minVal)
      minVal = *(a + i);
  }
  for (int i = 0; i < sizeB; i++)
  {
    if (*(b + i) < minVal)
      minVal = *(b + i);
  }
  return (float)minVal;
}

float getAvg(const int *a, int sizeA, const int *b, int sizeB)
{
  float sum = 0;
  for (int i = 0; i < sizeA; i++)
    sum += *(a + i);
  for (int i = 0; i < sizeB; i++)
    sum += *(b + i);
  return sum / (sizeA + sizeB);
}

float Action(int *a, int sizeA, int *b, int sizeB, float (*func)(const int *, int, const int *, int))
{
  return func(a, sizeA, b, sizeB);
}

int main()
{
  setlocale(LC_ALL, "Russian");

  int arrA[] = {10, 20, 30, 40, 50};
  int arrB[] = {5, 15, 25, 99, 1};
  int sizeA = sizeof(arrA) / sizeof(arrA[0]);
  int sizeB = sizeof(arrB) / sizeof(arrB[0]);

  cout << "Меню заданий\n";
  cout << "1. Найти максимум (max)\n";
  cout << "2. Найти минимум (min)\n";
  cout << "3. Найти среднее (avg)\n";
  cout << "Ваш выбор: ";

  int choice;
  cin >> choice;

  float result = 0;

  if (choice == 1)
  {
    result = Action(arrA, sizeA, arrB, sizeB, getMax);
  }
  else if (choice == 2)
  {
    result = Action(arrA, sizeA, arrB, sizeB, getMin);
  }
  else if (choice == 3)
  {
    result = Action(arrA, sizeA, arrB, sizeB, getAvg);
  }
  else
  {
    cout << "Ошибка выбора" << endl;
    return 1;
  }

  cout << "Результат: " << result << endl;

  return 0;
}