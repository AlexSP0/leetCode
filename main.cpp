#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> matrixReshape(std::vector<std::vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();
        int elements = m * n;
        int newRows = elements / c;
        if(r * c != m * n) {
            return mat;
        }
        std::vector<std::vector<int>> result (newRows, std::vector<int>(c));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int oneDimensionIndex = i * n + j;
                int twoDimensionRow = oneDimensionIndex / c;
                int twoDimensionColumn = oneDimensionIndex % c;
                result[twoDimensionRow][twoDimensionColumn] = mat[i][j];
            }
        }
        return result;
    }
};


int main()
{
    Solution sol;
    std::vector<std::vector<int>> v1 = {{1,2},{3,4}};
    std::vector<std::vector<int>> result = sol.matrixReshape(v1, 1, 4);
    return 0;
}
