#include "BackPackMain.hpp"

BackPackMain::BackPackMain(MethodAlgorithm *method)
{
    this->_method = method;
}

BackPackMain::~BackPackMain()
{
    delete this->_method;
}

void BackPackMain::setMethod(MethodAlgorithm *method)
{
    delete this->_method;
    this->_method = method;
}

int BackPackMain::getCountOfItems_N()
{
    return this->_method->getCountOfItems_N();
}

int BackPackMain::getCountOfBoxes_S()
{
    return this->_method->getCountOfBoxes_S();
}

int BackPackMain::getSizeOfBoxes_V()
{
    return this->_method->getSizeOfBoxes_V();
}

int BackPackMain::DoSolve(std::vector<int> &roster) const
{
    return this->_method->DoAlgorithm(roster);
}

