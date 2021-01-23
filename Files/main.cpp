#include <iostream>
#include "BackPackMain.hpp"
#include "RegularVersion.hpp"
#include "OptimizedVersion.hpp"
#include "TaskGenerator.hpp"
#include <fstream>

TaskGenerator *test1 = new TaskGenerator(4, 2, 3);

int RegularVersionTests()
{
    BackPackMain *regularV = new BackPackMain(new RegularVersion(test1));
    std::vector<int> roster;
    std::cout << "Count Of Items: " << regularV->getCountOfItems_N() << std::endl;
    std::cout << "Count of Boxes: " << regularV->getCountOfBoxes_S() << " Size of boxes: " << regularV->getSizeOfBoxes_V() << std::endl;
    std::vector<int> sizeOfBoxes = test1->getGenerateSizeOfItems_P();

    for (int el : sizeOfBoxes)
    {
        std::cout << el << " ";
    }
    std::cout << std::endl;

    unsigned int start = clock();
    int answer = regularV->DoSolve(roster);
    unsigned int end = clock();

    std::cout << "Answer: " << answer << std::endl;
    std::cout << "Time: " << (double)(end - start) / CLOCKS_PER_SEC << std::endl;
    std::cout << std::endl;

    for (int element : roster)
    {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    std::cout << "Test excellent finished" << std::endl;
    delete regularV;
    return 0;
}

int OptimizedVersionTests()
{
    BackPackMain *optimizedV = new BackPackMain(new OptimizedVersion(test1));
    std::vector<int> roster;
    std::cout << "Count Of Items: " << optimizedV->getCountOfItems_N() << std::endl;
    std::cout << "Count of Boxes: " << optimizedV->getCountOfBoxes_S() << " Size of boxes: " << optimizedV->getSizeOfBoxes_V() << std::endl;
    std::vector<int> sizeOfBoxes = test1->getGenerateSizeOfItems_P();

    for (int el : sizeOfBoxes)
    {
        std::cout << el << " ";
    }
    std::cout << std::endl;

    unsigned int start = clock();
    int answer = optimizedV->DoSolve(roster);
    unsigned int end = clock();

    std::cout << "Answer: " << answer << std::endl;
    std::cout << "Time: " << (double)(end - start) / CLOCKS_PER_SEC << std::endl;
    std::cout << std::endl;

    for (int element : roster)
    {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    std::cout << "Test excellent finished" << std::endl;
    return 0;
}

int TestOnBigValues()
{
    int new_n = 100000;
    while (new_n != 1000000)
    {
        TaskGenerator *test2 = new TaskGenerator(new_n, 500, 50);
        BackPackMain *LOL = new BackPackMain(new RegularVersion(test2));
        std::vector<int> roster1;
        std::cout << "Count Of Items: " << LOL->getCountOfItems_N() << std::endl;
        std::cout << "Count of Boxes: " << LOL->getCountOfBoxes_S() << " Size of boxes: " << LOL->getSizeOfBoxes_V() << std::endl;
        std::vector<int> sizeOfBoxes = test1->getGenerateSizeOfItems_P();
        unsigned int start1 = clock();
        int answer = LOL->DoSolve(roster1);
        unsigned int end1 = clock();

        std::cout << "Answer: " << answer << std::endl;
        std::cout << "Time: " << (double)(end1 - start1) / CLOCKS_PER_SEC << std::endl;
        std::cout << std::endl;

        std::vector<int> roster2;
        BackPackMain *KEK = new BackPackMain(new OptimizedVersion(test2));

        unsigned int start2 = clock();
        answer = KEK->DoSolve(roster2);
        unsigned int end2 = clock();

        std::cout << "Answer: " << answer << std::endl;
        std::cout << "Time: " << (double)(end2 - start2) / CLOCKS_PER_SEC << std::endl;
        std::cout << std::endl;

        std::ofstream file1;
        file1.open("D:\\projects\\NeginaProject\\GraphsAndTxtValues\\RegularInfo.txt", std::ios::app);
        if (file1.is_open())
        {
            file1 << new_n << std::endl;
            file1 << (double)(end1 - start1) / CLOCKS_PER_SEC << std::endl;
        }
        std::ofstream file2;
        file2.open("D:\\projects\\NeginaProject\\GraphsAndTxtValues\\OptimizedInfo.txt", std::ios::app);
        if (file2.is_open())
        {
            file2 << new_n << std::endl;
            file2 << (double)(end2 - start2) / CLOCKS_PER_SEC << std::endl;
        }

        delete test2;
        delete LOL;
        delete KEK;
        new_n += 300000;
    }
    std::cout<<"Test finished"<<std::endl;
    return 0;
}

int main()
{
    //RegularVersionTests();
    //OptimizedVersionTests();
    TestOnBigValues();
    system("pause>nul");
    return 0;
}