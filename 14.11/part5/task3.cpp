#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <thread>
#include <chrono>
using namespace std;

void drawPlayerStatus(int lives, int maxLives)
{
  cout << "\nЖизни: ";
  for (int i = 0; i < maxLives; i++)
  {
    if (i < lives)
    {
      cout << "♥ ";
    }
    else
    {
      cout << "♡ ";
    }
  }
  cout << "[" << lives << "/" << maxLives << "]" << "\n";
}

void drawHeader()
{
  cout << "GUESS MY NUMBER" << "\n";
}

void typeText(const string text, int delay = 25)
{
  for (char c : text)
  {
    cout << c << flush;
    this_thread::sleep_for(chrono::milliseconds(delay));
  }
}

void playGame()
{
  srand(time(0));

  int level;
  int minNumber, maxNumber;
  int maxLives;
  int multiplier;

  while (true)
  {

    drawHeader();

    cout << "Выберите уровень сложности:" << "\n";
    cout << "1. Легкий (1-10)" << "\n";
    cout << "2. Сложный (10-100)" << "\n";
    cout << "Ваш выбор: ";
    cin >> level;

    if (level == 1)
    {
      minNumber = 1;
      maxNumber = 10;
      maxLives = (maxNumber - minNumber + 1) / 2;
      multiplier = 5;
      break;
    }
    else if (level == 2)
    {
      minNumber = 10;
      maxNumber = 100;
      maxLives = (maxNumber - minNumber + 1) / 4;
      multiplier = 10;
      break;
    }
    else
    {
      typeText("Неверный выбор\n");
      this_thread::sleep_for(chrono::seconds(1));
    }
  }

  int secretNumber = rand() % (maxNumber - minNumber + 1) + minNumber;
  int lives = maxLives;
  int score = 0;

  drawHeader();

  typeText("Компьютер загадал число от " + to_string(minNumber) + " до " + to_string(maxNumber) + "\n");
  typeText("У вас " + to_string(lives) + " жизней\n");
  typeText("Попробуйте угадать число\n\n");

  while (lives > 0)
  {
    drawPlayerStatus(lives, maxLives);

    int guess;
    cout << "Ваша догадка: ";
    cin >> guess;

    if (guess < minNumber || guess > maxNumber)
    {
      typeText("Число должно быть от " + to_string(minNumber) + " до " + to_string(maxNumber) + "\n");
      continue;
    }

    if (guess == secretNumber)
    {
      typeText("Вы угадали \n");
      score = lives * multiplier;
      break;
    }
    else
    {
      lives--;
      typeText("Не угадали ");

      if (lives > 0)
      {
        char hintChoice;
        cout << "Хотите подсказку? (y/n) [стоимость: 1 жизнь]: ";
        cin >> hintChoice;

        if (hintChoice == 'y' || hintChoice == 'Y')
        {
          if (lives > 0)
          {
            lives--;
            if (guess < secretNumber)
            {
              typeText("Загаданное число больше вашего\n");
            }
            else
            {
              typeText("Загаданное число меньше вашего\n");
            }
            drawPlayerStatus(lives, maxLives);
          }
          else
          {
            typeText("Недостаточно жизней для подсказки\n");
          }
        }
        else
        {
          typeText("Продолжайте угадывать\n");
        }
      }

      if (lives == 0)
      {
        typeText("Вы проиграли, Загаданное число было: " + to_string(secretNumber) + "\n");
      }
    }
    cout << "\n";
  }

  cout << "Результаты" << "\n";

  if (lives > 0)
  {
    cout << "Победа" << "\n";
    cout << "Очки: " << score << "\n";
    cout << "Осталось жизней: " << lives << "\n";
    cout << "Множитель: x" << multiplier << "\n";
  }
  else
  {
    cout << "Проигрыш" << "\n";
    cout << "Загаданное число: " << secretNumber << "\n";
  }
}

int main()
{
  char playAgain;

  do
  {
    playGame();

    cout << "\n Хотите сыграть еще раз? (y/n): ";
    cin >> playAgain;

  } while (playAgain == 'y' || playAgain == 'Y');

  return 0;
}