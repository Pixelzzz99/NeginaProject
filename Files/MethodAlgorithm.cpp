#include "MethodAlgorithm.hpp"

int MethodAlgorithm::getCountOfItems_N() const { return _countOfItems_N; };

void MethodAlgorithm::setCountOfItems_N(int count_n) { _countOfItems_N = count_n; };

int MethodAlgorithm::getCountOfBoxes_S() const { return _countOfBoxes_S; };
void MethodAlgorithm::setCountOfBoxes_S(int count_s) { _countOfBoxes_S = count_s; };

int MethodAlgorithm::getSizeOfBoxes_V() const { return _sizeOfBoxes_V; };
void MethodAlgorithm::setSizeOfBoxes_V(int size_v) { _sizeOfBoxes_V = size_v; };

int MethodAlgorithm::getCountUsedBoxes() const { return id; };

void MethodAlgorithm::setCountUsedBoxes(int id) { this->id = id; };