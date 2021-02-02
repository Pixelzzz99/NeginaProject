#pragma once
#include "MethodAlgorithm.hpp"

class BackPackMain
{
private:
    MethodAlgorithm *_method;

public:
    BackPackMain(MethodAlgorithm *method = nullptr);
    ~BackPackMain();

    void setMethod(MethodAlgorithm *);

    int getCountOfItems_N();
    int getCountOfBoxes_S();
    int getSizeOfBoxes_V();
    int getCountUsedBoxes();

    int DoSolve(std::vector<int> &) const;
};

