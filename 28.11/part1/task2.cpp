#include <iostream>
#include <string>

using namespace std;

void removeCharAt(string &str, int index)
{
  if (index >= 0 && index < str.length())
  {
    str.erase(index, 1);
  }
}

void removeAllOccurrences(string &str, char target)
{
  size_t pos;
  while ((pos = str.find(target)) != string::npos)
  {
    str.erase(pos, 1);
  }
}

void insertCharAt(string &str, int index, char symbol)
{
  if (index >= 0 && index <= str.length())
  {
    str.insert(index, 1, symbol);
  }
}

void replaceDots(string &str)
{
  for (int i = 0; i < str.length(); i++)
  {
    if (str[i] == '.')
    {
      str[i] = '!';
    }
  }
}

int countSymbol(const string &str, char target)
{
  int count = 0;
  for (char c : str)
  {
    if (c == target)
      count++;
  }
  return count;
}

void analyzeString(const string &str)
{
  int letters = 0, digits = 0, others = 0;
  for (char c : str)
  {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
    {
      letters++;
    }
    else if (c >= '0' && c <= '9')
    {
      digits++;
    }
    else
    {
      others++;
    }
  }
  cout << "Букв: " << letters << endl;
  cout << "Цифр: " << digits << endl;
  cout << "Остальных символов: " << others << endl;
}

int main()
{
  setlocale(LC_ALL, "Russian");

  string text;
  char symbol;
  int pos;

  cout << "Введите строку: ";
  getline(cin, text);

  cout << "Задание 1. Индекс для удаления: ";
  cin >> pos;
  string s1 = text;
  removeCharAt(s1, pos);
  cout << "Результат: " << s1 << endl;

  cout << "\nЗадание 2. Символ для удаления: ";
  cin >> symbol;
  string s2 = text;
  removeAllOccurrences(s2, symbol);
  cout << "Результат: " << s2 << endl;

  cout << "\nЗадание 3. Индекс и символ для вставки: ";
  cin >> pos >> symbol;
  string s3 = text;
  insertCharAt(s3, pos, symbol);
  cout << "Результат: " << s3 << endl;

  string s4 = text;
  replaceDots(s4);
  cout << "\nЗадание 4. Замена точек: " << s4 << endl;

  cout << "\nЗадание 5. Символ для поиска: ";
  cin >> symbol;
  cout << "Встречается раз: " << countSymbol(text, symbol) << endl;

  cout << "\nЗадание 6. Анализ строки:" << endl;
  analyzeString(text);

  return 0;
}