#include <vector>
#include <iostream>

class Solution {
public:
    int maxArea(std::vector<int>&& height) {
        int i, j;
        i = 0;
        j = height.size() - 1;
        int max = 0;
        while (i < j) {
            max = std::max(max, std::min(height[i], height[j]) * (j - i));
            if (height[i] < height[j]) {
                ++i;
            } else {
                --j;
            }
        }

        return max;
    }
};

int main() {
    Solution s;
    std::cout << s.maxArea({1, 1}) << std::endl;
    return 0;
}