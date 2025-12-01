#include <iostream>
using namespace std;

int main()
{
  string userChoice;
  while (true)
  {
    cout << "Выберите фигуру которую хотите вывести \n а) \n б) \n в) \n г) \n д) \n е) \n ж) \n з) \n и) \n к) \n";
    cin >> userChoice;
    if ("а" == userChoice)
    {
      for (int i = 10; i >= 1; i--)
      {
        for (int k = 10 - i; k > 0; k--)
        {
          cout << " ";
        }
        for (int j = i; j > 0; j--)
        {
          cout << "*";
        }
        cout << "\n";
      }
    }
    else if ("б" == userChoice)
    {
      for (int i = 1; i <= 10; i++)
      {
        for (int j = 1; j <= i; j++)
        {
          cout << "* ";
        }
        cout << "\n";
      }
    }
    else if ("в" == userChoice)
    {
      for (int i = 10; i >= 1; i--)
      {
        for (int k = 10 - i; k > 0; k--)
        {
          cout << " ";
        }
        for (int j = i; j > 0; j--)
        {
          cout << "* ";
        }
        cout << "\n";
      }
    }
    else if ("г" == userChoice)
    {
      for (int i = 1; i <= 10; i++)
      {
        for (int k = 10 - i; k > 0; k--)
        {
          cout << " ";
        }
        for (int j = 1; j <= i; j++)
        {
          cout << "* ";
        }
        cout << "\n";
      }
    }
    else if ("д" == userChoice)
    {
      for (int i = 5; i >= 1; i--)
      {
        for (int k = 5 - i; k > 0; k--)
        {
          cout << " ";
        }
        for (int j = i; j > 0; j--)
        {
          cout << "* ";
        }
        cout << "\n";
      }
      for (int i = 1; i <= 5; i++)
      {
        for (int k = 5 - i; k > 0; k--)
        {
          cout << " ";
        }
        for (int j = 1; j <= i; j++)
        {
          cout << "* ";
        }
        cout << "\n";
      }
    }
    else if ("е" == userChoice)
    {

      for (int i = 1; i <= 5; i++)
      {
        for (int j = 1; j <= i; j++)
          cout << ("*");
        for (int k = 1; k <= 2 * (5 - i); k++)
          cout << (" ");
        for (int l = 1; l <= i; l++)
          cout << ("*");
        cout << "\n";
      }

      for (int i = 5 - 1; i >= 1; i--)
      {
        for (int j = 1; j <= i; j++)
          cout << ("*");
        for (int k = 1; k <= 2 * (5 - i); k++)
          cout << (" ");
        for (int l = 1; l <= i; l++)
          cout << ("*");
        cout << "\n";
      }
    }
    else if ("ж" == userChoice)
    {
      for (int i = 1; i <= 10; i++)
      {
        for (int j = 1; j <= i; j++)
          cout << ("*");
        cout << "\n";
      }
      for (int i = 10 - 1; i >= 1; i--)
      {
        for (int j = 1; j <= i; j++)
          cout << ("*");
        cout << "\n";
      }
    }
    else if ("з" == userChoice)
    {
      for (int i = 1; i <= 5; i++)
      {
        for (int k = 1; k <= (5 - i); k++)
          cout << (" ");
        for (int l = 1; l <= i; l++)
          cout << ("*");
        cout << "\n";
      }

      for (int i = 5 - 1; i >= 1; i--)
      {
        for (int k = 1; k <= (5 - i); k++)
          cout << (" ");
        for (int l = 1; l <= i; l++)
          cout << ("*");
        cout << "\n";
      }
    }
    else if ("и" == userChoice)
    {
      for (int i = 10; i >= 1; i--)
      {
        for (int j = i; j > 0; j--)
        {
          cout << "* ";
        }
        cout << endl;
      }
    }
    else if ("к" == userChoice)
    {
      for (int i = 1; i <= 10; i++)
      {
        for (int k = 10 - i; k > 0; k--)
          cout << " ";
        for (int j = 1; j <= i; j++)
        {
          cout << "*";
        }
        cout << endl;
      }
    }
    else
    {
      cout << "Неправильно выбранный вариант";
    }
  }
}