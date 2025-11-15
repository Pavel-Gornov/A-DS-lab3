#include <iostream>
#include "functions.h"

void setup_io() {
    #ifdef _WIN32
        system("chcp 65001 > nul");
    #endif
    std::ios::sync_with_stdio(false);
}

int main() {
    setup_io();
    stats res;

    LinkedList<float> fl({7, 1, 5, 4, 8, 2, 0});
    res = insertion_sort(fl);
    std::cout << res << " [ " << fl << "]\n";

    LinkedList<float> fl2({});
    res = insertion_sort(fl2);
    std::cout << res << " [ " << fl2 << "]\n";

    std::vector<int> v({1, 2, 3, 4, 6, 5, 7, 8, 9, 10, 11, 12, 13});
    res = shaker_sort(v);
    std::cout << res << " [ ";
    for (auto& el: v) std::cout << el << " "; 
    std::cout << "]\n";
}