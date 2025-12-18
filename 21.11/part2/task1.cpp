#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Задание 1: Разница между датами

// Функция для проверки года на високосность
bool isLeapYear(int year)
{
  return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Вспомогательная функция для получения количества дней в конкретном месяце
int getDaysInMonth(int month, int year)
{
  int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if (month == 2 && isLeapYear(year))
    return 29;
  return days[month - 1];
}

// Функция перевода даты в абсолютное количество дней (от 1 года 1 января)
long long dateToTotalDays(int d, int m, int y)
{
  long long total = 0;
  // Считаем дни в полных годах
  for (int i = 1; i < y; ++i)
  {
    total += isLeapYear(i) ? 366 : 365;
  }
  // Считаем дни в полных месяцах текущего года
  for (int i = 1; i < m; ++i)
  {
    total += getDaysInMonth(i, y);
  }
  // Добавляем дни текущего месяца
  total += d;
  return total;
}

// Основная функция расчета разности между датами
long long getDaysDifference(int d1, int m1, int y1, int d2, int m2, int y2)
{
  long long days1 = dateToTotalDays(d1, m1, y1);
  long long days2 = dateToTotalDays(d2, m2, y2);
  return abs(days1 - days2);
}

// Задание 2: Среднее арифметическое

double calculateAverage(const vector<int> &arr)
{
  if (arr.empty())
    return 0.0;
  double sum = 0;
  for (int num : arr)
  {
    sum += num;
  }
  return sum / arr.size();
}

// Задание 3: Подсчет элементов

void countElements(const vector<int> &arr)
{
  int positive = 0, negative = 0, zero = 0;
  for (int num : arr)
  {
    if (num > 0)
      positive++;
    else if (num < 0)
      negative++;
    else
      zero++;
  }
  cout << "Положительных: " << positive << endl;
  cout << "Отрицательных: " << negative << endl;
  cout << "Нулей: " << zero << endl;
}

int main()
{

  // Тест Задания 1
  int d1 = 1, m1 = 1, y1 = 2023;
  int d2 = 1, m2 = 1, y2 = 2024; 
  cout << "--- Задание 1 ---" << endl;
  cout << "Разница между датами: " << getDaysDifference(d1, m1, y1, d2, m2, y2) << " дней" << endl;

  // Тест Задания 2 и 3
  vector<int> numbers = {10, -5, 0, 20, -30, 0, 5};

  cout << "\n--- Задание 2 ---" << endl;
  cout << "Массив: ";
  for (int n : numbers)
    cout << n << " ";
  cout << "\nСреднее арифметическое: " << calculateAverage(numbers) << endl;

  cout << "\n--- Задание 3 ---" << endl;
  countElements(numbers);

  return 0;
}