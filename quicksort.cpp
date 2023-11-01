#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>


int partition(std::vector<int>& vec, int from, int to) {
    int pivot_val, pivot_index = 0;
    pivot_val = vec[from];
    std::vector<int> new_order;

    for (int i = from + 1; i < to; i++) {
        if (vec[i] <= pivot_val) {
            new_order.push_back(vec[i]);
            pivot_index++;
        }
    }
    new_order.push_back(pivot_val);
    for (int i = from + 1; i < to; i++) {
        if (vec[i] > pivot_val) {
            new_order.push_back(vec[i]);
        }
    }

    int n = new_order.size();
    for (int i = 0; i < n; i++) {
        vec[from + i] = new_order[i];
    }

    return from + pivot_index;
}


void quicksort(std::vector<int>& vec, int from=0, int to=-1) {
    if (to == -1) {
        to = vec.size();
    }
    if (from < to) {
        int pivot_index = partition(vec, from, to);
        quicksort(vec, from, pivot_index);
        quicksort(vec, pivot_index + 1, to);
    }
}