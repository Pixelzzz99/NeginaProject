#pragma once
#include <vector>
#include <cstdlib>
#include "MethodAlgorithm.hpp"
#include <set>

class OptimizedVersion : public MethodAlgorithm
{
private:
    std::vector<int> _sizeOfItems_P;
    void setSizeOfItems_P(std::vector<int> , int);
public:
    OptimizedVersion(TaskGenerator *);
    ~OptimizedVersion() = default;

    std::vector<int> getSizeOfItems_P() const;
    int DoAlgorithm(std::vector<int> &) override;
};





