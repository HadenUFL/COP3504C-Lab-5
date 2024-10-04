#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <algorithm>
#include <iomanip>
#include "stringdata.h"

int linear_search(const std::vector<std::string>& arr, const std::string& x) {
    for (size_t i = 0; i < arr.size(); ++i) {
        if (arr[i] == x) {
            return static_cast<int>(i);
        }
    }
    return -1;
}

int binary_search(const std::vector<std::string>& arr, const std::string& x) {
    int lo = 0;
    int hi = static_cast<int>(arr.size()) - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] == x) {
            return mid;
        } else if (arr[mid] < x) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return -1;
}

int main() {
    std::vector<std::string>& data = getStringData();
    std::sort(data.begin(), data.end());

    std::vector<std::string> words = {"not_here", "mzzzz", "aaaaa"};

    for (const auto& word : words) {
        // Linear search
        auto start = std::chrono::steady_clock::now();
        int idx = linear_search(data, word);
        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsed_seconds = end - start;

        std::cout << "linear search for '" << word << "':" << std::endl;
        std::cout << "Index found: " << idx << std::endl;
        std::cout << "Time taken: " << std::fixed << std::setprecision(10)
                  << elapsed_seconds.count() << " seconds\n" << std::endl;

        // Binary search
        start = std::chrono::steady_clock::now();
        idx = binary_search(data, word);
        end = std::chrono::steady_clock::now();
        elapsed_seconds = end - start;

        std::cout << "binary search for '" << word << "':" << std::endl;
        std::cout << "Index found: " << idx << std::endl;
        std::cout << "Time taken: " << std::fixed << std::setprecision(10)
                  << elapsed_seconds.count() << " seconds\n" << std::endl;
    }

    return 0;
}
