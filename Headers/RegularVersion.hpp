#pragma once
#include "MethodAlgorithm.hpp"

class RegularVersion : public MethodAlgorithm
{
private:
    std::vector<std::pair<int, int>> _sizeOfItems_P;
    void setSizeOfItems_P(std::vector<int>);
public:
    RegularVersion(TaskGenerator *);
    ~RegularVersion() = default;

    std::vector<int> getSizeOfItems_P() const; 
    int DoAlgorithm(std::vector<int> &) override;
};

