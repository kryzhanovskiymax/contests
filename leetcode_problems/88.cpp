#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        std::vector<int> tmp = nums1;
        int i, j, k;
        i = j = k = 0;
        while (i + j != m + n) {
            if (i < m && j < n && tmp[i] < nums2[j]) {
                nums1[k] = tmp[i];
                ++i;
            } else if (j < n) {
                nums1[k] = nums2[j];
                ++j;
            } else if (i < m) {
                nums1[k] = tmp[i];
                ++i;
            }
            ++k;
        }
    }
};

int main() {
    Solution s;
    std::vector<int> v1{0};
    std::vector<int> v2{1};
    s.merge(v1, 0, v2, 1);
    for (const auto& elem : v1) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
    return 0;
}