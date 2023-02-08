#include <vector>
#include <iostream>

class Solution {
public:
    std::vector<std::vector<int>> generate(int numRows) {
        std::vector<std::vector<int>> answer;
        answer.resize(numRows, {});
        
        for (int i = 0; i < answer.size(); ++i) {
            answer[i].resize(i + 1, 1);
        }

        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < answer[i].size(); ++j) {
                if (j == 0 || j == answer[i].size() - 1) {
                    answer[i][j] = 1;
                } else {
                    answer[i][j] = answer[i - 1][j - 1] + answer[i - 1][j];
                }
            }
        }

        return answer;
    }
};

int main() {
    Solution s;
    auto triangle = s.generate(1);
    for (const auto& line : triangle) {
        for (const auto& num : line) {
            std::cout << num << " ";
        }
        std::cout << std::endl; 
    }

    return 0;
}