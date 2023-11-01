#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>


void heapify(std::vector<int>& vec, int root, int n) {
    int mx = root;
    int l = root * 2 + 1, r = root * 2 + 2;
    if (l < n && vec[l] > vec[root]) {
        mx = l;
    }
    if (r < n && vec[r] > vec[mx]) {
        mx = r;
    }
    if (mx != root) {
        std::swap(vec[mx], vec[root]);
        heapify(vec, mx, n);
    }
}


void heap_sort(std::vector<int>& vec) {
    int n = vec.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(vec, i, n);
    }
    for (int i = n - 1; i >= 0; i--) {
        std::swap(vec[0], vec[i]);
        heapify(vec, 0, i);
    }
}
