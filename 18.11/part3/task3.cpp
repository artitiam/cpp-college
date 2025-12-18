#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Функция переворота первых k элементов стопки (k — количество блинов сверху)
void flip(vector<int> &pancakes, int k)
{
  reverse(pancakes.begin(), pancakes.begin() + k);
  cout << "Переворот первых " << k << " оладий: ";
  for (int x : pancakes)
    cout << x << " ";
  cout << "\n";
}

// Поиск индекса максимального элемента в первых n элементах
int findMaxIndex(const vector<int> &pancakes, int n)
{
  int maxIdx = 0;
  for (int i = 1; i < n; i++)
  {
    if (pancakes[i] > pancakes[maxIdx])
    {
      maxIdx = i;
    }
  }
  return maxIdx;
}

int main()
{
  int n;
  cout << "Введите количество оладий: ";
  cin >> n;

  vector<int> pancakes(n);
  cout << "Введите радиусы оладий (сверху вниз): ";
  for (int i = 0; i < n; i++)
  {
    cin >> pancakes[i];
  }

  cout << "\nИсходная стопка (сверху вниз): ";
  for (int x : pancakes)
    cout << x << " ";
  cout << "\n\n";

  // Сортируем так, чтобы в итоге массив был возрастанию 
  int flipsCount = 0;

  // Проходим от конца массива к началу (размер неотсортированной части = currSize)
  for (int currSize = n; currSize > 1; currSize--)
  {
    // Находим индекс самого большого в неотсортированной части
    int maxIdx = findMaxIndex(pancakes, currSize);

    // Если максимум уже на своём месте (внизу неотсортированной части), пропускаем
    if (maxIdx == currSize - 1)
    {
      continue;
    }

    // Если максимум не наверху — переворачиваем до него, чтобы поднять наверх
    if (maxIdx != 0)
    {
      flip(pancakes, maxIdx + 1); // +1, потому что flip принимает количество элементов
      flipsCount++;
    }

    // Теперь максимум наверху — переворачиваем всю неотсортированную часть,
    // чтобы опустить его вниз (на позицию currSize - 1)
    flip(pancakes, currSize);
    flipsCount++;
  }

  cout << "\nОтсортированная стопка (сверху вниз): ";
  for (int x : pancakes)
  {
    cout << x << " ";
  }
  cout << "\n";
  cout << "Всего переворотов: " << flipsCount << "\n";
  cout << "Теперь снизу вверх радиусы убывают: ";
  // Вывод снизу вверх
  for (int i = n - 1; i >= 0; i--)
  {
    cout << pancakes[i] << " ";
  }
  cout << "\n";

  return 0;
}