#include <vector>
#include <map>
#include <unordered_map>
#include <iostream>

class Solution {
public:
    std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::vector<int> result;
        
        std::unordered_map<int, int> nums1_map;
        std::unordered_map<int, int> nums2_map;

        for (const auto& num : nums1) {
            ++nums1_map[num];
        }

        for (const auto& num : nums2) {
            ++nums2_map[num];
        }

        for (const auto& [num, count] : nums1_map) {
            if (nums2_map.count(num) > 0) {
                int len = std::min(nums2_map[num], count);
                result.insert(result.begin(), len, num);
            }
        }

        return result;
    }
};

int main() {
    std::cout << "Hello, World" << std::endl;
    return 0;
}
