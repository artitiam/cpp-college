#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

int main()
{
  int direction, speed;
  int speedValue;

  while (true)
  {

    cout << "1. Нарисовать линию" << "\n";
    cout << "2. Выйти" << "\n";
    cout << "Выберите действие: ";

    int choice;
    cin >> choice;

    if (choice == 2)
    {
      break;
    }

    if (choice == 1)
    {

      char symbol;
      cout << "Введите символ для рисования: ";
      cin >> symbol;

      cout << "Выберите направление:" << "\n";
      cout << "1. Горизонтальная" << "\n";
      cout << "2. Вертикальная" << "\n";
      cout << "Ваш выбор: ";
      cin >> direction;

      cout << "Выберите скорость:" << "\n";
      cout << "1. Быстро (100 мс)" << "\n";
      cout << "2. Нормально (300 мс)" << "\n";
      cout << "3. Медленно (500 мс)" << "\n";
      cout << "Ваш выбор: ";
      cin >> speed;

      switch (speed)
      {
      case 1:
        speedValue = 100;
        break;
      case 2:
        speedValue = 300;
        break;
      case 3:
        speedValue = 500;
        break;
      default:
        speedValue = 300;
        break;
      }

      cout << "Рисую линию..." << "\n";

      if (direction == 1)
      {
        for (int i = 0; i < 10; i++)
        {
          cout << symbol;
          cout.flush();
          this_thread::sleep_for(chrono::milliseconds(speedValue));
        }
        cout << "\n";
      }
      else
      {
        for (int i = 0; i < 10; i++)
        {
          cout << symbol << "\n";
          cout.flush();
          this_thread::sleep_for(chrono::milliseconds(speedValue));
        }
      }
    }
  }

  return 0;
}