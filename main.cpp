#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> matrixReshape(std::vector<std::vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();
        int currentColumn = 0;
        int currentRow = 0;
        std::vector<std::vector<int>> result (r, std::vector<int>(c));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                result[currentRow][currentColumn] = mat[i][j];
                if(currentColumn < c - 1) {
                    currentColumn++;
                } else {
                    currentRow++;
                }
            }
        }
        return result;
    }
};


int main()
{
    Solution sol;
    std::vector<std::vector<int>> v1 = {{1,2}, {3,4}};
    std::vector<std::vector<int>> result = sol.matrixReshape(v1, 1, 4);
    return 0;
}
