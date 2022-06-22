#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> generate(int numRows) {
        std::vector<std::vector<int>> result(numRows);
        for(int i = 0; i < numRows; i++) {
            result[i].resize(i + 1);
            result[i][0] = 1;
            for(int j = 1; j <= i; j++) {
                if((j-1) < 0 || (j) > result[i-1].size()-1) {
                    result[i][j] = 1;
                } else {
                    result[i][j] = result [i - 1][ j - 1] + result[i - 1][j];
                }
            }
        }
        return result;
    }
};

int main()
{
    Solution sol;
    sol.generate(50);
    std::cout << "Hello world!" << std::endl;
    return 0;
}
