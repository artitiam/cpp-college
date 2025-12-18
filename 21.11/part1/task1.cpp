#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

float power(float base, int exp)
{
  float result = 1.0;
  int absExp = (exp < 0) ? -exp : exp;

  for (int i = 0; i < absExp; i++)
  {
    result *= base;
  }

  return (exp < 0) ? 1.0 / result : result;
}

int sumInRange(int a, int b)
{
  int start = (a < b) ? a : b;
  int end = (a < b) ? b : a;
  int sum = 0;
  for (int i = start; i <= end; i++)
  {
    sum += i;
  }
  return sum;
}

bool isPerfect(int num)
{
  if (num <= 0)
    return false;
  int sum = 0;
  for (int i = 1; i < num; i++)
  {
    if (num % i == 0)
      sum += i;
  }
  return sum == num;
}

void findPerfectNumbers(int start, int end)
{
  bool found = false;
  for (int i = start; i <= end; i++)
  {
    if (isPerfect(i))
    {
      cout << i << " ";
      found = true;
    }
  }
  if (!found)
    cout << "Совершенных чисел нет.";
  cout << endl;
}

void drawCard(string rank, string suit)
{
  cout << " ---------- " << endl;
  cout << "| " << left << setw(2) << rank << "       |" << endl;
  cout << "|          |" << endl;
  cout << "|          |" << endl;
  cout << "|    " << suit << "     |" << endl;
  cout << "|          |" << endl;
  cout << "|          |" << endl;
  cout << "|       " << right << setw(2) << rank << " |" << endl;
  cout << " ---------- " << endl;
}

bool isLuckyTicket(int num)
{
  if (num < 100000 || num > 999999)
    return false;

  int firstHalf = num / 1000;
  int secondHalf = num % 1000;

  auto sumDigits = [](int n)
  {
    int s = 0;
    while (n > 0)
    {
      s += n % 10;
      n /= 10;
    }
    return s;
  };

  return sumDigits(firstHalf) == sumDigits(secondHalf);
}

int main()
{

  cout << "Задание 1 (Степень 2^10): " << power(2, 10) << endl;

  cout << "Задание 2 (Сумма от 1 до 10): " << sumInRange(1, 10) << endl;

  cout << "Задание 3 (Совершенные числа от 1 до 500): ";
  findPerfectNumbers(1, 500);

  cout << "Задание 4 (Вывод карты):" << endl;
  drawCard("A", "♥");

  int ticket = 123321;
  cout << "Задание 5 (Число " << ticket << " счастливое?): " << (isLuckyTicket(ticket) ? "Да" : "Нет") << endl;

  return 0;
}