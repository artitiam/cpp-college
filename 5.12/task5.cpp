#include <iostream>
#include <string>

using namespace std;

struct Student
{
  string name;
  int grade;
};

int main()
{
  int count;
  cout << "Введите количество студентов: ";
  cin >> count;

  if (count <= 0)
    return 0;

  Student *students = new Student[count];
  double sum = 0;

  for (int i = 0; i < count; i++)
  {
    cout << "Введите имя " << i + 1 << "-го студента: ";
    cin >> students[i].name;
    cout << "Введите оценку " << i + 1 << "-го студента: ";
    cin >> students[i].grade;
    sum += students[i].grade;
  }

  cout << "\nСписок студентов" << endl;
  for (int i = 0; i < count; i++)
  {
    cout << students[i].name << ": " << students[i].grade << endl;
  }

  cout << "\nСредняя оценка: " << sum / count << endl;

  delete[] students;

  return 0;
}