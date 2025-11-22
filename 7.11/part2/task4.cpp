#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  float distance, time, speed, seconds;
  cout << "Вычисление скорости бега" << "\n";
  cout << "Введите длину дистанции (метров) = ";
  cin >> distance;
  cout << "Введите время (мин.сек) = ";
  cin >> time;
  cout << "Дистанция: " << distance << "\n";
  int time_min = (int)time;
  float time_sec = (time - time_min) * 100;
  seconds = time_min * 60 + time_sec;
  cout << "Время: " << time_min << " мин " << time_sec << " " << "сек" << " " << "=" << " " << seconds << " " << "сек" << "\n";
  speed = round(distance / seconds * 3.6 * 100) / 100;
  cout << "Вы бежали со скоростью " << speed << " км/ч" << endl; 
  
  return 0;
}