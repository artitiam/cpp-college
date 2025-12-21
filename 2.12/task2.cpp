#include <iostream>
#include <string>
using namespace std;

void removeByIndex(string &s, int index)
{
  if (index >= 0 && index < s.length())
    s.erase(index, 1);
}

void removeByChar(string &s, char c)
{
  for (int i = 0; i < s.length();)
  {
    if (s[i] == c)
      s.erase(i, 1);
    else
      i++;
  }
}

void insertChar(string &s, char c, int index)
{
  if (index >= 0 && index <= s.length())
    s.insert(index, 1, c);
}

void replaceDots(string &s)
{
  for (char &c : s)
    if (c == '.')
      c = '!';
}

int countChar(const string &s, char c)
{
  int count = 0;
  for (char x : s)
    if (x == c)
      count++;
  return count;
}

void countTypes(const string &s, int &letters, int &digits, int &others)
{
  letters = digits = others = 0;
  for (char c : s)
  {
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
      letters++;
    else if (c >= '0' && c <= '9')
      digits++;
    else
      others++;
  }
}

int main()
{
  string s;
  cout << "Введите строку: ";
  getline(cin, s);

  int index;
  cout << "Введите номер символа для удаления: ";
  cin >> index;
  removeByIndex(s, index);
  cout << "Результат: " << s << endl;

  char ch;
  cout << "Введите символ для удаления: ";
  cin >> ch;
  removeByChar(s, ch);
  cout << "Результат: " << s << endl;

  cout << "Введите символ и позицию для вставки: ";
  cin >> ch >> index;
  insertChar(s, ch, index);
  cout << "Результат: " << s << endl;

  replaceDots(s);
  cout << "Замена точек на '!': " << s << endl;

  cout << "Введите символ для подсчёта: ";
  cin >> ch;
  cout << "Количество вхождений: " << countChar(s, ch) << endl;

  int letters, digits, others;
  countTypes(s, letters, digits, others);
  cout << "Буквы: " << letters << endl;
  cout << "Цифры: " << digits << endl;
  cout << "Остальные символы: " << others << endl;

  return 0;
}
