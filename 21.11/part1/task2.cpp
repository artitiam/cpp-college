#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int linearSearch(const vector<int> &arr, int key)
{
  for (int i = 0; i < arr.size(); i++)
  {
    if (arr[i] == key)
      return i;
  }
  return -1;
}

int binarySearch(const vector<int> &arr, int key)
{
  int left = 0;
  int right = arr.size() - 1;

  while (left <= right)
  {
    int mid = left + (right - left) / 2;

    if (arr[mid] == key)
      return mid;
    if (arr[mid] < key)
      left = mid + 1;
    else
      right = mid - 1;
  }
  return -1;
}

int binaryToDecimal(long long binary)
{
  int decimal = 0;
  int power = 0;
  while (binary > 0)
  {
    int lastDigit = binary % 10;
    decimal += lastDigit * pow(2, power);
    binary /= 10;
    power++;
  }
  return decimal;
}

int main()
{
  vector<int> data = {12, 45, 2, 8, 33, 70, 1, 15};
  int key = 33;

  cout << "--- Задания 1 и 2: Поиск ---" << endl;
  cout << "Исходный массив: ";
  for (int x : data)
    cout << x << " ";
  cout << "\nИщем число: " << key << endl;

  int linIdx = linearSearch(data, key);
  cout << "Линейный поиск: индекс = " << linIdx << endl;

  sort(data.begin(), data.end());
  cout << "Отсортированный массив (для бинарного поиска): ";
  for (int x : data)
    cout << x << " ";
  cout << endl;

  int binIdx = binarySearch(data, key);
  cout << "Бинарный поиск: индекс в отсортированном массиве = " << binIdx << endl;

  cout << "\n--- Задание 3: Перевод систем счисления ---" << endl;
  long long binNum = 110101;
  cout << "Двоичное число: " << binNum << endl;
  cout << "Десятичное представление: " << binaryToDecimal(binNum) << endl;

  return 0;
}