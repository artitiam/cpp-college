#include <iostream>
#include <iomanip>

class AlarmClock
{
private:
    int currentHour;
    int currentMinute;
    int alarmHour;
    int alarmMinute;
    bool alarmEnabled;

public:
    AlarmClock() : currentHour(0), currentMinute(0), alarmHour(0), alarmMinute(0), alarmEnabled(false) {}

    void setCurrentTime(int hour, int minute)
    {
        if (hour >= 0 && hour < 24 && minute >= 0 && minute < 60)
        {
            currentHour = hour;
            currentMinute = minute;
        }
    }

    void setAlarm(int hour, int minute)
    {
        if (hour >= 0 && hour < 24 && minute >= 0 && minute < 60)
        {
            alarmHour = hour;
            alarmMinute = minute;
            alarmEnabled = true;
        }
    }

    void disableAlarm()
    {
        alarmEnabled = false;
    }

    void tick()
    {
        currentMinute++;
        if (currentMinute == 60)
        {
            currentMinute = 0;
            currentHour = (currentHour + 1) % 24;
        }

        std::cout << "Текущее время: "
                  << std::setw(2) << std::setfill('0') << currentHour << ":"
                  << std::setw(2) << std::setfill('0') << currentMinute << "\n";

        if (alarmEnabled && currentHour == alarmHour && currentMinute == alarmMinute)
        {
            std::cout << "Будильник сработал \n";
            alarmEnabled = false;
        }
    }
};

int main()
{
    AlarmClock clock;
    clock.setCurrentTime(6, 58);
    clock.setAlarm(7, 0);

    for (int i = 0; i < 5; ++i)
    {
        clock.tick();
    }

    return 0;
}