#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
  const int rows = 2; // Количество строк (можно изменить)
  const int cols = 6; // Количество столбцов (по примеру из условия)

  int arr[rows][cols]; // Исходный двумерный массив

  srand(time(nullptr)); // Инициализация генератора случайных чисел

  // Заполнение массива случайными числами от 0 до 9
  cout << "Исходный массив:\n";
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      arr[i][j] = rand() % 10;
      cout << arr[i][j] << " ";
    }
    cout << "\n";
  }

  // Ввод параметров сдвига от пользователя
  int shifts;
  string direction;
  cout << "\nВведите количество сдвигов: ";
  cin >> shifts;
  cout << "Введите направление (left, right, up, down): ";
  cin >> direction;

  // Нормализуем количество сдвигов, чтобы избежать лишних полных оборотов
  if (direction == "left" || direction == "right")
  {
    shifts = shifts % cols; // Для горизонтальных сдвигов модуль по числу столбцов
    if (shifts < 0)
      shifts += cols; // Обработка отрицательных значений (необязательно, но безопасно)
  }
  else if (direction == "up" || direction == "down")
  {
    shifts = shifts % rows; // Для вертикальных сдвигов модуль по числу строк
    if (shifts < 0)
      shifts += rows;
  }

  // Выполнение циклического сдвига
  if (direction == "right")
  {
    // Сдвиг каждой строки вправо на 'shifts' позиций
    for (int i = 0; i < rows; i++)
    {
      int temp[cols];
      // Копируем строку
      for (int j = 0; j < cols; j++)
      {
        temp[j] = arr[i][j];
      }
      // Записываем в исходную строку со сдвигом вправо
      for (int j = 0; j < cols; j++)
      {
        arr[i][j] = temp[(j - shifts + cols) % cols];
      }
    }
  }
  else if (direction == "left")
  {
    // Сдвиг каждой строки влево на 'shifts' позиций
    for (int i = 0; i < rows; i++)
    {
      int temp[cols];
      for (int j = 0; j < cols; j++)
      {
        temp[j] = arr[i][j];
      }
      for (int j = 0; j < cols; j++)
      {
        arr[i][j] = temp[(j + shifts) % cols];
      }
    }
  }
  else if (direction == "down")
  {
    // Сдвиг каждого столбца вниз на 'shifts' позиций
    for (int j = 0; j < cols; j++)
    {
      int temp[rows];
      for (int i = 0; i < rows; i++)
      {
        temp[i] = arr[i][j];
      }
      for (int i = 0; i < rows; i++)
      {
        arr[i][j] = temp[(i - shifts + rows) % rows];
      }
    }
  }
  else if (direction == "up")
  {
    // Сдвиг каждого столбца вверх на 'shifts' позиций
    for (int j = 0; j < cols; j++)
    {
      int temp[rows];
      for (int i = 0; i < rows; i++)
      {
        temp[i] = arr[i][j];
      }
      for (int i = 0; i < rows; i++)
      {
        arr[i][j] = temp[(i + shifts) % rows];
      }
    }
  }
  else
  {
    cout << "Некорректное направление. Поддерживаются: left, right, up, down.\n";
    return 0;
  }

  // Вывод результата
  cout << "\nМассив после сдвига:\n";
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      cout << arr[i][j] << " ";
    }
    cout << "\n";
  }

  return 0;
}