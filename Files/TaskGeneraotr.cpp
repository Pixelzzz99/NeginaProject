#include "TaskGenerator.hpp"

TaskGenerator::TaskGenerator(int minRandom, int maxRandom)
{
    srand(time(nullptr));
    this->MIN_COUNT = minRandom;
    this->MAX_COUNT = maxRandom;
    _countOfItems_N = Randomization(MIN_COUNT, MAX_COUNT);
    _countOfBoxes_S = Randomization(MIN_COUNT, MAX_COUNT);
    _sizeOfBoxes_V = Randomization(MIN_COUNT, MAX_COUNT);
    _sizeOfItems_P = generateSizeOfItems_P(_countOfItems_N);
}

TaskGenerator::TaskGenerator(int count_N, int count_S, int size_V)
{
    srand(time(nullptr));
    _countOfItems_N = count_N;
    _countOfBoxes_S = count_S;
    _sizeOfBoxes_V = size_V;
    _sizeOfItems_P = generateSizeOfItems_P(_countOfItems_N);
}

int TaskGenerator::Randomization(int minRandom, int maxRandom)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    return static_cast<int>(rand() * fraction * (maxRandom - minRandom + 1) + minRandom);
}

std::vector<int> TaskGenerator::generateSizeOfItems_P(int countOfItems)
{   
    std::vector<int> sizeItemsRoster;
    for (int i = 0; i < _countOfItems_N; i++)
    {   
        int size = Randomization(MIN_COUNT, _sizeOfBoxes_V);
        sizeItemsRoster.push_back(size);
    }
    return sizeItemsRoster;
}

int TaskGenerator::getCountOfItems_N() const
{
    return _countOfItems_N;
}

int TaskGenerator::getCountOfBoxes_S() const
{
    return _countOfBoxes_S;
}

int TaskGenerator::getSizeOfBoxes_V() const
{
    return _sizeOfBoxes_V;
}

std::vector<int> TaskGenerator::getGenerateSizeOfItems_P() const
{
    return _sizeOfItems_P;
}