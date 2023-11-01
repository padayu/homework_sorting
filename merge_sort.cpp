#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>


void merge(std::vector<int>& vec, int left, int mid, int right) {
    std::vector<int> result;
    int first = left, second = mid;
    while (first != mid && second != right) {
        if (vec[first] < vec[second]) {
            result.push_back(vec[first]);
            first++;
        } else {
            result.push_back(vec[second]);
            second++;
        }
    }
    while (first != mid) {
        result.push_back(vec[first]);
        first++;
    }
    while (second != right) {
        result.push_back(vec[second]);
        second++;
    }
    for (int i = 0; i < right - left; i++) {
        vec[left + i] = result[i];
    }
}


void merge_sort(std::vector<int>& vec, int from=0, int to=-1) {
    if (to == -1) {
        to = vec.size();
    }
    if (to - from == 1) {
        return;
    } else {
        int mid = (from + to) / 2;
        merge_sort(vec, from, mid);
        merge_sort(vec, mid, to);
        merge(vec, from, mid, to);
        return;
    }
}