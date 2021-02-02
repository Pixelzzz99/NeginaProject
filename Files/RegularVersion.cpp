#include "RegularVersion.hpp"

RegularVersion::RegularVersion(TaskGenerator *task)
{
    setCountOfItems_N(task->getCountOfItems_N());
    setCountOfBoxes_S(task->getCountOfBoxes_S());
    setSizeOfBoxes_V(task->getSizeOfBoxes_V());
    setSizeOfItems_P(task->getGenerateSizeOfItems_P());
}

void RegularVersion::setSizeOfItems_P(std::vector<int> itemsSizeRoster)
{
    _sizeOfItems_P.resize(getCountOfItems_N());
    for (int i = 0; i < getCountOfItems_N(); i++)
    {
        _sizeOfItems_P[i].first = itemsSizeRoster[i];
        _sizeOfItems_P[i].second = i;
    }
}

int RegularVersion::DoAlgorithm(std::vector<int> &roster)
{
    int countBoxes = getCountOfBoxes_S();
    std::vector<int> answer(getCountOfItems_N(), -1);
    std::vector<bool> used(getCountOfItems_N(), false);
    int id = 0;

    while (countBoxes > 0)
    {
        std::sort(_sizeOfItems_P.begin(), _sizeOfItems_P.end());
        id++;
        int V = getSizeOfBoxes_V();
        for (int i = getCountOfItems_N() - 1; i >= 0; i--)
        {
            if (used[i])
                continue;
            if (_sizeOfItems_P[i].first <= V)
            {
                V -= _sizeOfItems_P[i].first;
                used[i] = true;
                answer[_sizeOfItems_P[i].second] = id;
            }
        }
        countBoxes--;
        bool check = false;
        for (int i = 0; i < getCountOfItems_N(); i++)
        {
            if (!used[i])
                check = true;
        }
        if (!check)
            break;
    }
    bool is_Ok = true;
    int allGoodPut = 0;
    for (int i = 0; i < getCountOfItems_N(); i++)
    {
        if (!used[i])
            is_Ok = false;
        roster.push_back(answer[i]);
        if (answer[i] > 0)
            allGoodPut++;
        
    }
    setCountUsedBoxes(id);
    return allGoodPut;
}

std::vector<int> RegularVersion::getSizeOfItems_P() const
{
    std::vector<int> sizeOfItemsVector;
    if(_sizeOfItems_P.empty()) return sizeOfItemsVector;
    for (std::pair<int, int> item : _sizeOfItems_P)
        sizeOfItemsVector.push_back(item.first);        
    
    return sizeOfItemsVector;
}
