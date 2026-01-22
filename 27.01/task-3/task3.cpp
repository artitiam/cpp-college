#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main()
{
  std::ifstream fin("words.txt");
  std::vector<std::string> words;
  std::string w;
  while (fin >> w)
  {
    words.push_back(w);
  }
  fin.close();

  for (int i = 0; i + 1 < words.size(); i += 2)
  {
    std::string tmp = words[i];
    words[i] = words[i + 1];
    words[i + 1] = tmp;
  }

  for (int i = 0; i < words.size(); ++i)
  {
    if (i)
      std::cout << " ";
    std::cout << words[i];
  }
  std::cout << "\n";
  return 0;
}