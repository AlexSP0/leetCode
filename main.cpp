#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::vector<int> solution;
    int size = nums.size();
    for(int i = 0; i < size; i++) {
        for (int d=i+1; d < size; d++) {
            if(nums[i] + nums[d] == target) {
                solution.push_back(i);
                solution.push_back(d);
                return solution;
            }
        }
    }
    return solution;
    }
};


int main()
{
    Solution sol;
    std::vector<int> v1 = {2,7,11,15};
    sol.twoSum(v1, 9);
    return 0;
}
