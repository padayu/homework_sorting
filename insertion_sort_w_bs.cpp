#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>


void insertion_sort(std::vector<int>& vec) {
    int n = vec.size();
    for (int i = 0; i < n; i++) {
        int j = i;

        int l = 0, r = j, m;
        while (r != l) {
            m = l + (r - l) / 2;
            if (vec[m] > vec[j]) {
                r = m;
            } else {
                l = m + 1;
            }
        }

        for (int h = j; h > l; h--) {
            std::swap(vec[h], vec[h - 1]);
        }

    }
}
