#pragma once
#include <vector>
#include <algorithm>
#include "TaskGenerator.hpp"

class MethodAlgorithm
{
private:
    int _countOfItems_N;
    int _countOfBoxes_S;
    int _sizeOfBoxes_V;

    int id;
    
public:
    int getCountOfItems_N() const;
    void setCountOfItems_N(int count_n);

    int getCountOfBoxes_S() const;
    void setCountOfBoxes_S(int count_s);

    int getSizeOfBoxes_V() const;
    void setSizeOfBoxes_V(int size_v);

    int getCountUsedBoxes() const;
    void setCountUsedBoxes(int id);
    
    virtual ~MethodAlgorithm() = default;
    virtual int DoAlgorithm(std::vector<int> &) = 0;
};
