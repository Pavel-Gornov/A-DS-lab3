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

    LinkedList<float> fl({7, 1, 5, 4, 8, 2});
    stats res = insertion_sort(fl);

    std::cout << res << " [ " << fl << "]\n";
}