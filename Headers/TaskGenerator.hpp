#pragma once
#include <vector>
#include <ctime>
#include <cstdlib>

class TaskGenerator
{
private:
    int MIN_COUNT = 1;
    int MAX_COUNT = 50;
    int _countOfItems_N;
    int _countOfBoxes_S;
    int _sizeOfBoxes_V;
    std::vector<int> _sizeOfItems_P;
    int Randomization(int minRandom, int maxRandom);
    std::vector<int> generateSizeOfItems_P(int countOfItems);

public:
    TaskGenerator(int minRandom, int maxRandom);
    TaskGenerator(int count_N, int count_S, int size_V);
    ~TaskGenerator() = default;

    int getCountOfItems_N() const;
    int getCountOfBoxes_S() const;
    int getSizeOfBoxes_V() const;
    std::vector<int> getGenerateSizeOfItems_P() const;
};
