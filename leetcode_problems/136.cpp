#include <vector>
#include <map>
#include <iostream>

class Solution {
public:
    int singleNumber(std::vector<int>&& nums) {
        int answer;
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum = (sum ^ nums[i]);
        }

        return sum;
    }
};

int main() {
    Solution s;
    std::cout << s.singleNumber({4, 1, 2, 1, 2});
    return 0;
}