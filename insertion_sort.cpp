#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>


void insertion_sort(std::vector<int>& vec) {
    int n = vec.size();
    for (int i = 0; i < n; i++) {
        int j = i;
        while (j > 0 && vec[j] < vec[j - 1]) {
            std::swap(vec[j], vec[j - 1]);
            j--;
        }
    }
}