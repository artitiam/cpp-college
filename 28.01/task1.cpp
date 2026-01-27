#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    srand(time(nullptr));

    int lotteryNum = 5;
    int maxNum = 50;

    vector<int> lotteryNumbers;
    vector<int> userNumbers;

    for (int i = 0; i < lotteryNum; i++)
    {
        int num = rand() % maxNum + 1;
        lotteryNumbers.push_back(num);
    }

    cout << "Введите " << lotteryNum << " чисел (от 1 до " << maxNum << "):\n";
    for (int i = 0; i < lotteryNum; i++)
    {
        int x;
        cin >> x;
        userNumbers.push_back(x);
    }

    int matches = 0;
    for (int u : userNumbers)
    {
        for (int l : lotteryNumbers)
        {
            if (u == l)
            {
                matches++;
            }
        }
    }

    cout << "Числа лотереи: ";
    for (int n : lotteryNumbers)
    {
        cout << n << " ";
    }
    cout << "\n";

    cout << "Совпадений: " << matches << "\n";
    if (matches >= 3)
    {
        cout << "Вы выиграли";
    }
    else
    {
        cout << "Повезёт в следующий раз";
    }
    return 0;
}
