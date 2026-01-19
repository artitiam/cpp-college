#include <iostream>
using namespace std;

int main()
{
    int athletes = 5;
    int attempts = 3;

    float results[athletes][attempts];

    cout << "Введите результаты прыжков (5 спортсменов, 3 попытки): ";
    for (int i = 0; i < athletes; i++)
    {
        for (int j = 0; j < attempts; j++)
        {
            cin >> results[i][j];
        }
    }

    float maxResult = results[0][0];
    int bestAthlete = 0;
    int bestAttempt = 0;

    for (int i = 0; i < athletes; i++)
    {
        for (int j = 0; j < attempts; j++)
        {
            if (results[i][j] > maxResult)
            {
                maxResult = results[i][j];
                bestAthlete = i;
                bestAttempt = j;
            }
        }
    }

    cout << "Лучший результат: " << maxResult << endl;
    cout << "Спортсмен: " << bestAthlete + 1 << endl;
    cout << "Попытка: " << bestAttempt + 1 << endl;

    return 0;
}
