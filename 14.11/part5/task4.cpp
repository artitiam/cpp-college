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

void drawHeader(int level, int round, int playerScore, int computerScore)
{
  cout << "Guess My Number - Уровень " << level << " - Раунд " << round << "\n";
  cout << "Игрок: " << playerScore << " | Компьютер: " << computerScore << "\n";
}

void typeText(string text, int delay = 25)
{
  for (char c : text)
  {
    cout << c << flush;
    this_thread::sleep_for(chrono::milliseconds(delay));
  }
}

int playRound(int levelNum, int roundNum, int minNumber, int maxNumber, int maxLives, int multiplier, int playerScore, int computerScore)
{

  drawHeader(levelNum, roundNum, playerScore, computerScore);

  int secretNumber = rand() % (maxNumber - minNumber + 1) + minNumber;
  int lives = maxLives;

  typeText("Раунд " + to_string(roundNum) + "\n");
  typeText("Диапазон: " + to_string(minNumber) + " - " + to_string(maxNumber) + "\n");
  typeText("Жизней в раунде: " + to_string(lives) + "\n");
  typeText("Загадано число\n\n");

  int roundResult = 0;

  while (lives > 0 && roundResult == 0)
  {
    drawPlayerStatus(lives, maxLives);

    int guess;
    cout << "Ваша догадка: ";
    cin >> guess;

    if (guess < minNumber || guess > maxNumber)
    {
      typeText("Число должно быть от " + to_string(minNumber) + " до " + to_string(maxNumber) + "!\n\n");
      continue;
    }

    if (guess == secretNumber)
    {
      typeText("Вы угадали в раунде " + to_string(roundNum) + "!\n");
      playerScore += lives * multiplier;
      roundResult = 1;
    }
    else
    {
      lives--;
      typeText("Не угадали! ");

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
        typeText("Вы проиграли раунд " + to_string(roundNum) + "!\n");
        typeText("Загаданное число было: " + to_string(secretNumber) + "\n");
        computerScore += maxLives * multiplier;
        roundResult = -1;
      }
    }
    cout << "\n";
  }

  if (roundResult == 1)
  {
    return playerScore;
  }
  else
  {
    return -computerScore;
  }
}

void showIntermediateResults(int levelNum, int roundNum, int totalRounds, int playerScore, int computerScore, bool levelComplete = false)
{

  cout << "Промежуточные итоги" << "\n";

  if (levelComplete)
  {
    cout << "Уровень " << levelNum << " завершен!" << "\n";
  }
  else
  {
    cout << "Уровень " << levelNum << " | Раунд " << roundNum << "/" << totalRounds << " завершен" << "\n";
  }

  cout << "Игрок:      " << playerScore << " очков" << "\n";
  cout << "Компьютер:  " << computerScore << " очков" << "\n";

  if (playerScore > computerScore)
  {
    cout << "Игрок лидирует на " << (playerScore - computerScore) << " очков!" << "\n";
  }
  else if (computerScore > playerScore)
  {
    cout << "Компьютер лидирует на " << (computerScore - playerScore) << " очков!" << "\n";
  }
  else
  {
    cout << "Ничья" << "\n";
  }
}

int main()
{
  srand(time(0));

  char playAgain;

  do
  {
    int playerTotalScore = 0;
    int computerTotalScore = 0;
    bool level1Passed = false;

    cout << "Начало уровня 1" << "\n";
    typeText("Уровень 1: 3 раунда, числа от 1 до 10\n");
    typeText("5 жизней в каждом раунде, множитель x5\n");
    typeText("Для перехода на уровень 2 нужно выиграть все раунды!\n\n");

    bool level1Success = true;

    for (int round = 1; round <= 3; round++)
    {
      int result = playRound(1, round, 1, 10, 5, 5, playerTotalScore, computerTotalScore);

      if (result > 0)
      {
        playerTotalScore = result;
      }
      else
      {
        computerTotalScore = -result;
        level1Success = false;
      }

      showIntermediateResults(1, round, 3, playerTotalScore, computerTotalScore);

      if (!level1Success && round < 3)
      {
        typeText("Вы проиграли раунд, Уровень 1 не пройден.\n");
        break;
      }
    }

    showIntermediateResults(1, 3, 3, playerTotalScore, computerTotalScore, true);

    if (level1Success)
    {
      level1Passed = true;
      typeText("Вы прошли уровень 1\n\n");

      char continueChoice;
      cout << "Хотите перейти на уровень 2? (y/n): ";
      cin >> continueChoice;

      if (continueChoice == 'y' || continueChoice == 'Y')
      {

        cout << "Начало уровня 2" << "\n";
        typeText("Уровень 2: 2 раунда, числа от 10 до 100\n");
        typeText("23 жизни в каждом раунде, множитель x10\n");

        bool level2Success = true;

        for (int round = 1; round <= 2; round++)
        {
          int result = playRound(2, round, 10, 100, 23, 10, playerTotalScore, computerTotalScore);

          if (result > 0)
          {
            playerTotalScore = result;
          }
          else
          {
            computerTotalScore = -result;
            level2Success = false;
          }

          showIntermediateResults(2, round, 2, playerTotalScore, computerTotalScore);

          if (!level2Success)
          {
            typeText("Вы проиграли раунд, Уровень 2 не пройден.\n");
            break;
          }
        }

        showIntermediateResults(2, 2, 2, playerTotalScore, computerTotalScore, true);

        if (level2Success)
        {
          typeText("Вы прошли оба уровня\n");
        }
        else
        {
          typeText("Вы прошли только уровень 1. Уровень 2 не пройден.\n");
        }
      }
    }
    else
    {
      typeText("Вы не прошли уровень 1. Попробуйте еще раз!\n");
    }

    cout << "Финальные результаты" << "\n";
    cout << "Игрок:      " << playerTotalScore << " очков" << "\n";
    cout << "Компьютер:  " << computerTotalScore << " очков" << "\n";

    if (playerTotalScore > computerTotalScore)
    {
      cout << "Вы выиграли игру" << "\n";
    }
    else if (computerTotalScore > playerTotalScore)
    {
      cout << "Компьютер выиграл игру" << "\n";
    }
    else
    {
      cout << "Ничья!" << "\n";
    }

    cout << "------------------------------" << "\n\n";

    cout << "Хотите сыграть еще раз? (y/n): ";
    cin >> playAgain;
    cin.ignore();

  } while (playAgain == 'y' || playAgain == 'Y');

  return 0;
}