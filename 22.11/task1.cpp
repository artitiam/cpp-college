#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <ctime>
#include <set>

using namespace std;

typedef vector<vector<int>> Matrix;

void printVector(const vector<int> &v)
{
  for (int x : v)
    cout << x << " ";
  cout << endl;
}

void printMatrix(const Matrix &m)
{
  for (const auto &row : m)
  {
    for (int x : row)
      cout << x << "\t";
    cout << endl;
  }
}

void task1()
{
  vector<int> vec(10);
  for (int &i : vec)
    i = rand() % 100 + 1;
  cout << "Вектор: ";
  printVector(vec);
  int sum = accumulate(vec.begin(), vec.end(), 0);
  cout << "Сумма: " << sum << ", Среднее: " << (double)sum / vec.size() << endl;
}

int task2(const vector<int> &v, int target)
{
  for (int i = 0; i < v.size(); i++)
    if (v[i] == target)
      return i;
  return -1;
}

vector<int> task3(const vector<int> &v, int threshold)
{
  vector<int> res;
  for (int x : v)
    if (x % 2 == 0 && x > threshold)
      res.push_back(x);
  return res;
}

bool task4(const vector<int> &v)
{
  for (int i = 0; i < v.size() / 2; i++)
    if (v[i] != v[v.size() - 1 - i])
      return false;
  return true;
}

Matrix task5(const Matrix &A, const Matrix &B)
{
  Matrix C(A.size(), vector<int>(B[0].size(), 0));
  for (int i = 0; i < A.size(); i++)
    for (int j = 0; j < B[0].size(); j++)
      for (int k = 0; k < A[0].size(); k++)
        C[i][j] += A[i][k] * B[k][j];
  return C;
}

void task6(const Matrix &m)
{
  int mx = m[0][0], mn = m[0][0], rMx = 0, cMx = 0, rMn = 0, cMn = 0;
  for (int i = 0; i < m.size(); i++)
    for (int j = 0; j < m[0].size(); j++)
    {
      if (m[i][j] > mx)
      {
        mx = m[i][j];
        rMx = i;
        cMx = j;
      }
      if (m[i][j] < mn)
      {
        mn = m[i][j];
        rMn = i;
        cMn = j;
      }
    }
  cout << "Max: " << mx << " [" << rMx << "," << cMx << "], Min: " << mn << " [" << rMn << "," << cMn << "]" << endl;
}

bool task7(const Matrix &m) { return !m.empty() && m.size() == m[0].size(); }

void task8(vector<int> &v)
{
  set<int> s(v.begin(), v.end());
  v.assign(s.begin(), s.end());
}

void task9(vector<int> &v, int k)
{
  reverse(v.begin(), v.end());
  k %= v.size();
  rotate(v.rbegin(), v.rbegin() + k, v.rend());
}

void task10(const vector<int> &v1, const vector<int> &v2)
{
  for (int x : v1)
    for (int y : v2)
      if (x == y)
        cout << x << " ";
  cout << endl;
}

int task11(const vector<int> &v)
{
  int m_so_far = v[0], cur_m = v[0];
  for (size_t i = 1; i < v.size(); i++)
  {
    cur_m = max(v[i], cur_m + v[i]);
    m_so_far = max(m_so_far, cur_m);
  }
  return m_so_far;
}

void task12(vector<int> &v, int val)
{
  for (int &x : v)
    if (x < 0)
      x = val;
}

void task13(const Matrix &m)
{
  if (m.empty() || m[0].empty())
    return;

  int top = 0;
  int bottom = m.size() - 1;
  int left = 0;
  int right = m[0].size() - 1;

  cout << "Спиральный вывод: ";
  while (top <= bottom && left <= right)
  {
    for (int i = left; i <= right; ++i)
    {
      cout << m[top][i] << " ";
    }
    top++; 

    for (int i = top; i <= bottom; ++i)
    {
      cout << m[i][right] << " ";
    }
    right--; 

    if (top <= bottom)
    {
      for (int i = right; i >= left; --i)
      {
        cout << m[bottom][i] << " ";
      }
      bottom--; 
    }

    if (left <= right)
    {
      for (int i = bottom; i >= top; --i)
      {
        cout << m[i][left] << " ";
      }
      left++; 
    }
  }
  cout << endl;
}

int task14(const Matrix &m)
{
  int R = m.size(), C = m[0].size(), maxS = -1e9;
  for (int i = 0; i < R; i++)
  {
    vector<int> colSum(C, 0);
    for (int j = i; j < R; j++)
    {
      for (int k = 0; k < C; k++)
        colSum[k] += m[j][k];
      maxS = max(maxS, task11(colSum));
    }
  }
  return maxS;
}

Matrix rotate90(const Matrix &m)
{
  int R = m.size(), C = m[0].size();
  Matrix res(C, vector<int>(R));
  for (int i = 0; i < R; i++)
    for (int j = 0; j < C; j++)
      res[j][R - 1 - i] = m[i][j];
  return res;
}

int main()
{
  srand(time(0));

  vector<int> v = {10, 20, -5, 30, 20, 10, 40};
  Matrix M1 = {{1, 2}, {3, 4}};
  Matrix M2 = {{5, 6}, {7, 8}};
  Matrix bigM = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

  cout << "1. Заполнение, сумма, среднее:" << endl;
  task1();

  cout << "\n2. Поиск числа 30: индекс = " << task2(v, 30) << endl;

  cout << "\n3. Фильтрация (четные > 15): ";
  vector<int> filtered = task3(v, 15);
  printVector(filtered);

  cout << "\n4. Является ли {1,2,1} палиндромом? " << (task4({1, 2, 1}) ? "Да" : "Нет") << endl;

  cout << "\n5. Умножение матриц M1 и M2:" << endl;
  printMatrix(task5(M1, M2));

  cout << "\n6. Поиск Max/Min в матрице:" << endl;
  task6(bigM);

  cout << "\n7. Матрица квадратная? " << (task7(bigM) ? "Да" : "Нет") << endl;

  cout << "\n8. Удаление дубликатов из вектора: ";
  task8(v);
  printVector(v);

  cout << "\n9. Инверсия и сдвиг вправо на 2: ";
  task9(v, 2);
  printVector(v);

  cout << "\n10. Совпадения между {1,2,3} и {2,3,4}: ";
  task10({1, 2, 3}, {2, 3, 4});

  cout << "\n11. Макс. сумма подвектора в {1,-2,3,4,-1}: " << task11({1, -2, 3, 4, -1}) << endl;

  cout << "\n12. Замена отрицательных в {-1, 5, -3} на 0: ";
  vector<int> negVec = {-1, 5, -3};
  task12(negVec, 0);
  printVector(negVec);

  cout << "\n13. Вывод матрицы по спирали: ";
  task13(bigM);

  cout << "\n14. Макс. сумма подматрицы: " << task14(bigM) << endl;

  cout << "\n15. Повороты матрицы на 90, 180, 270:" << endl;
  Matrix m90 = rotate90(bigM);
  cout << "90 градусов:" << endl;
  printMatrix(m90);
  Matrix m180 = rotate90(m90);
  cout << "180 градусов:" << endl;
  printMatrix(m180);
  Matrix m270 = rotate90(m180);
  cout << "270 градусов:" << endl;
  printMatrix(m270);

  return 0;
}