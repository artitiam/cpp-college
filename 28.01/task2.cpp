#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <string>
#include <iomanip>

using namespace std;

time_t makeDate(int year, int month, int day)
{
    tm t = {};
    t.tm_year = year - 1900;
    t.tm_mon = month - 1;
    t.tm_mday = day;
    return mktime(&t);
}

int main()
{
    srand(time(nullptr));

    vector<string> holidayNames = {
        "День Пиццы",
        "День Кота",
        "День Программиста",
        "День Шоколада",
        "День Лени",
        "День Сна",
        "День Улыбки"};

    time_t now = time(nullptr);
    tm *nowTm = localtime(&now);
    int currentYear = nowTm->tm_year + 1900;

    for (int i = 0; i < 5; i++)
    {
        string name = holidayNames[rand() % holidayNames.size()];

        int month = rand() % 12 + 1;
        int day = rand() % 28 + 1; 

        time_t holidayDate = makeDate(currentYear, month, day);

        double secondsDiff = difftime(holidayDate, now);
        int daysDiff = static_cast<int>(secondsDiff / (60 * 60 * 24));

        cout << left << setw(20) << name
             << " Дата: "
             << setw(1) << day << "."
             << setw(2) << month << " | ";

        if (daysDiff >= 0)
            cout << "Через " << daysDiff << " дней\n";
        else
            cout << "Был " << -daysDiff << " дней назад\n";
    }

    return 0;
}
