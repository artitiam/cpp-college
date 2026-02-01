#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

void quickSort(std::vector<float> &arr, int low, int high)
{
    if (low < high)
    {
        float pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; j++)
        {
            if (arr[j] <= pivot)
            {
                i++;
                std::swap(arr[i], arr[j]);
            }
        }
        std::swap(arr[i + 1], arr[high]);
        int pi = i + 1;
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

bool binarySearch(const std::vector<float> &sortedData, float target)
{
    int left = 0;
    int right = sortedData.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (sortedData[mid] == target)
        {
            return true;
        }
        if (sortedData[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return false;
}

int main()
{
    int fileSize = 10000;
    int SearchRangeMin = 0;
    int SearchRangeMax = 1000;
    int NumSearches = 500;

    std::vector<float> fileData(fileSize);
    std::vector<float> foundElements;

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_real_distribution<float> distribution(SearchRangeMin,SearchRangeMax);

    for (int i = 0; i < fileSize; i++)
    {
        fileData[i] = distribution(generator);
    }

    std::sort(fileData.begin(), fileData.end());

    std::ofstream outFile("data.txt");
    for (float val : fileData)
    {
        outFile << val << "\n";
    }
    outFile.close();

    for (int i = 0; i < NumSearches; i++)
    {
        float searchValue = distribution(generator);
        if (binarySearch(fileData, searchValue))
        {
            foundElements.push_back(searchValue);
        }
    }

    std::cout << "Найдено элементов: " << foundElements.size() << std::endl;

    if (!foundElements.empty())
    {
        quickSort(foundElements, 0, foundElements.size() - 1);
        std::cout << "Первые 10 отсортированных найденных элементов:\n";
        for (int i = 0; i < std::min(10, static_cast<int>(foundElements.size())); i++)
        {
            std::cout << foundElements[i] << " ";
        }
        std::cout << std::endl;
    }
    else
    {
        std::cout << "Не найдено ни одного элемента." << std::endl;
    }

    return 0;
}