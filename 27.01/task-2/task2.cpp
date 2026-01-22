#include <iostream>
#include <fstream>
#include <string>

void toLower(std::string &s)
{
  for (int i = 0; i < s.length(); i++)
  {
    if (s[i] >= 'A' && s[i] <= 'Z')
    {
      s[i] = s[i] - 'A' + 'a';
    }
  }
}

bool containsWord(std::string sentence, std::string word)
{
  toLower(sentence);
  toLower(word);
  return sentence.find(word) != std::string::npos;
}

int main()
{
  std::ifstream fin("text.txt");

  std::string text = "";
  char c;
  while (fin.get(c))
  {
    text += c;
  }
  fin.close();

  std::string word;
  std::cout << "Введите слово: ";
  std::cin >> word;

  std::string sentence = "";
  for (int i = 0; i < text.length(); i++)
  {
    sentence += text[i];
    char ch = text[i];
    if (ch == '.' || ch == '!' || ch == '?')
    {
      if (containsWord(sentence, word))
      {
        std::cout << sentence << "\n";
      }
      sentence = "";
    }
  }

  return 0;
}