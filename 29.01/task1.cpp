#include <iostream>
#include <cmath>
#include <vector>

float f(float x)
{
    return std::abs(2.0f * (std::abs(x) - 1.0f) * (std::abs(x) - 1.0f) - 3.0f);
}

int main()
{
    const float xMin = -4.0f;
    const float xMax = 4.0f;
    const float yMin = 0.0f;
    const float yMax = 8.0f;
    const int width = 80;
    const int height = 25;

    std::vector<std::vector<char>> grid(height, std::vector<char>(width, ' '));

    for (int i = 0; i < width; i++)
    {
        float x = xMin + (xMax - xMin) * static_cast<float>(i) / static_cast<float>(width - 1);
        float y = f(x);
        if (y >= yMin && y <= yMax)
        {
            int row = static_cast<int>((yMax - y) / (yMax - yMin) * static_cast<float>(height - 1));
            grid[row][i] = '*';
        }
    }

    int xAxis = static_cast<int>((yMax - 0.0f) / (yMax - yMin) * static_cast<float>(height - 1));
    for (int i = 0; i < width; i++)
    {
        if (grid[xAxis][i] == ' ')
            grid[xAxis][i] = '-';
    }

    int yAxis = static_cast<int>((0.0f - xMin) / (xMax - xMin) * static_cast<float>(width - 1));
    for (int j = 0; j < height; j++)
    {
        if (grid[j][yAxis] == ' ')
            grid[j][yAxis] = '|';
    }

    for (const auto &line : grid)
    {
        for (char c : line)
        {
            std::cout << c;
        }
        std::cout << '\n';
    }

    std::cout << "\nФункция: f(x) = |2(|x| - 1)^2 - 3|\n";
    std::cout << "Область определения: (-inf, +inf)\n";
    std::cout << "Интервалы монотонности:\n";
    std::cout << "(-inf, -2.225] : убывает\n";
    std::cout << "[-2.225, -1]   : возрастает\n";
    std::cout << "[-1, -0.225]   : убывает\n";
    std::cout << "[-0.225, 0]    : возрастает\n";
    std::cout << "[0, 0.225]     : убывает\n";
    std::cout << "[0.225, 1]     : возрастает\n";
    std::cout << "[1, 2.225]     : убывает\n";
    std::cout << "[2.225, +inf)  : возрастает\n";

    return 0;
}