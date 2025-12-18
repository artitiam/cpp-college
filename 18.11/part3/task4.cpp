#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

long long bubbleSort(vector<int> arr)
{
  int n = arr.size();
  long long swaps = 0; // Счётчик перестановок (может быть большим)

  for (int i = 0; i < n - 1; i++)
  {
    int currentPassSwaps = 0; // Перестановки на текущем проходе

    for (int j = 0; j < n - 1 - i; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        swap(arr[j], arr[j + 1]);
        swaps++;
        currentPassSwaps++;
      }
    }

    if (currentPassSwaps == 0)
    { // Если за проход ни одной перестановки — массив отсортирован
      break;
    }
  }

  return swaps;
}

// Функция: сортировка выбором, возвращает число перестановок
long long selectionSort(vector<int> arr)
{
  int n = arr.size();
  long long swaps = 0;

  for (int i = 0; i < n - 1; i++)
  {
    int minIdx = i;
    // Находим индекс минимального элемента в оставшейся части
    for (int j = i + 1; j < n; j++)
    {
      if (arr[j] < arr[minIdx])
      {
        minIdx = j;
      }
    }
    // Меняем местами текущий элемент и найденный минимум
    if (minIdx != i)
    {
      swap(arr[i], arr[minIdx]);
      swaps++;
    }
  }

  return swaps;
}

int main()
{
  const int array_size = 1000; // Размер каждого массива
  const int test_count = 10;   // Количество тестовых массивов

  srand(time(nullptr)); // Инициализация генератора случайных чисел

  long long totalBubbleSwaps = 0;    // Общее число перестановок для пузырька
  long long totalSelectionSwaps = 0; // Общее число перестановок для выбора

  cout << "Выполняется тестирование " << test_count << " массивов по "
       << array_size << " элементов...\n\n";

  for (int test = 0; test < test_count; test++)
  {
    // Генерируем исходный массив
    vector<int> original(array_size);
    for (int i = 0; i < array_size; i++)
    {
      original[i] = rand(); // Генерируем случайное число (0 до RAND_MAX)
    }

    // Сортируем копию методом пузырька и считаем перестановки
    long long bubbleSwaps = bubbleSort(original);
    totalBubbleSwaps += bubbleSwaps;

    // Сортируем копию методом выбора и считаем перестановки
    long long selectionSwaps = selectionSort(original);
    totalSelectionSwaps += selectionSwaps;

    cout << "Тест " << (test + 1) << ":\n";
    cout << "  Пузырёк: " << bubbleSwaps << " перестановок\n";
    cout << "  Выбор:   " << selectionSwaps << " перестановок\n\n";
  }

  // Вычисляем средние значения
  float avgBubble = static_cast<float>(totalBubbleSwaps) / test_count;
  float avgSelection = static_cast<float>(totalSelectionSwaps) / test_count;

  cout << "Итоговые результаты\n";
  cout << "Среднее число перестановок (Пузырёк): " << avgBubble << "\n";
  cout << "Среднее число перестановок (Выбор): " << avgSelection << "\n";

  // Сравнение
  if (avgBubble < avgSelection)
  {
    cout << "\nМетод пузырька в среднем делает меньше перестановок.\n";
  }
  else if (avgSelection < avgBubble)
  {
    cout << "\nМетод выбора в среднем делает меньше перестановок.\n";
  }
  else
  {
    cout << "\nОба метода делают в среднем одинаковое число перестановок.\n";
  }

  return 0;
}