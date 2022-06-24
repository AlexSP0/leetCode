#include <iostream>
#include <vector>

class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i = 0; i < m; i++) {
            if(target <= matrix[i][n-1]) {
                return binarySearch(matrix[i], target);
            }
        }
        return false;
    }

    bool binarySearch(std::vector<int> &line, int target) {
        bool flag = false;
        int left = 0;
        int right = line.size()-1;
        int middle = -1;
        while((left <= right) && (flag != true)) {
            middle = (left + right) / 2;
            if(line[middle] == target) flag = true;
            if(line[middle] > target) right = middle - 1;
            else left = middle + 1;
        }
        return flag;
    }
};

int main()
{
    std::vector<std::vector<int>> matrix = {{1 ,3 ,5 ,7},
                                            {10,11,16,20},
                                            {23,30,34,60}};
    Solution sol;
    std::cout << sol.searchMatrix(matrix, 34) << std::endl;
    return 0;
}
