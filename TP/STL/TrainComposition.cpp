#include <stdexcept>
#include <iostream>
#include <list>

class TrainComposition
{
public:
   std::list<int> wagons;

    void attachWagonFromLeft(int wagonId)
    {
        wagons.insert(wagons.begin(), wagonId);
    }

    void attachWagonFromRight(int wagonId)
    {
        wagons.push_back(wagonId);
    }

    int detachWagonFromLeft()
    {
        int ret = wagons.front();
        wagons.erase(wagons.begin());
        return ret;
    }

    int detachWagonFromRight()
    {
        int ret = wagons.back();
        wagons.pop_back();
        return ret;
    }
};

#ifndef RunTests
int main()
{
    TrainComposition tree;
    tree.attachWagonFromLeft(7);
    tree.attachWagonFromLeft(13);
    std::cout << tree.detachWagonFromRight() << "\n"; // 7 
    std::cout << tree.detachWagonFromLeft(); // 13
}
#endif
