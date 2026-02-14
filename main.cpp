#include <list>
#include "mergeSort.h"
#include <iostream>

int main() {
    std::cout << "Unsorted array:" << std::endl;
    std::list<int> toSort = {11, 21, 3, 54, 76, 43, 67, 64, 54, 100 };
    for (int i : toSort) {
        std::cout << "[" << i << "]-";
    }
    std::cout << std::endl << "Sorted array" << std::endl;
    std::list<int> sorted {mergeSort(toSort)};
    for (int i : sorted) {
        std::cout << "[" << i << "]-";
    }
}