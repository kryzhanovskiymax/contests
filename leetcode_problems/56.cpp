#include <vector>
#include <iostream>

class Solution {
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>&& intervals) {
        std::vector<std::vector<int>> result;
        std::sort(intervals.begin(), intervals.end(), [] (const auto& lhs, const auto& rhs) {
            return lhs[0] < rhs[0];
        });

        int current_right_edge = intervals[0][1];
        int current_left_edge = intervals[0][0];

        for (int i = 1; i < intervals.size(); ++i) {
            if (current_right_edge >= intervals[i][0]) {
                current_right_edge = std::max(current_right_edge, intervals[i][1]);
            } else {
                result.push_back({current_left_edge, current_right_edge});
                current_left_edge = intervals[i][0];
                current_right_edge = intervals[i][1];
            }
        }

        result.push_back({current_left_edge, current_right_edge});

        return result;
    }
};

int main() {
    Solution s;

    auto merged = s.merge({{1, 3}, {2, 6}, {8, 10}, {15, 18}});
    for (const auto& line : merged) {
        for (const auto& elem : line) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

