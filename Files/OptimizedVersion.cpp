#include "OptimizedVersion.hpp"

OptimizedVersion::OptimizedVersion(TaskGenerator *task)
{
    setCountOfItems_N(task->getCountOfItems_N());
    setCountOfBoxes_S(task->getCountOfBoxes_S());
    setSizeOfBoxes_V(task->getSizeOfBoxes_V());
    setSizeOfItems_P(task->getGenerateSizeOfItems_P(), getCountOfItems_N());
}

void OptimizedVersion::setSizeOfItems_P(std::vector<int> sizeItemsRoster, int n)
{
    _sizeOfItems_P.resize(n);
    for (int i = 0; i < n; i++)
        _sizeOfItems_P[i] = sizeItemsRoster[i];
}

std::vector<int> OptimizedVersion::getSizeOfItems_P() const
{
    return _sizeOfItems_P;
}

int OptimizedVersion::DoAlgorithm(std::vector<int> &roster)
{
    int countBoxes = getCountOfBoxes_S();
    std::vector<int> answer(getCountOfItems_N(), -1);
    std::set<std::pair<int, int>> st;

    for (int i = 0; i < getCountOfItems_N(); i++)
    {
        st.insert({-_sizeOfItems_P[i], i});
    }
    int id = 0;
    while ((int)st.size() > 0 && countBoxes > 0)
    {
        int V = getSizeOfBoxes_V();
        id++;
        while ((int)st.size() > 0 && V > 0)
        {
            auto pos = *st.lower_bound({-V, 0});
            if (st.find(pos) == st.end())
                break;
            if (-pos.first > V)
                break;
            st.erase(pos);
            V += pos.first;
            answer[pos.second] = id;
        }
        countBoxes--;
    }
    
    setCountUsedBoxes(id);

    int allGoodPut = 0;
    for (int element : answer)
    {
        roster.push_back(element);
        if (element > 0)
            allGoodPut++;
    }
    return allGoodPut;
}