#include <vector>
#include <iostream>
#include <unordered_set>

class Solution {
    std::unordered_set<int> numbers;
    public:
    bool containsDuplicate(std::vector<int>& nums) {
        numbers.clear();
        for(int i = 0; i < nums.size(); i++) {
            int number = nums[i];
            if(numbers.find(number) != numbers.end()) {
                return true;
            }
            numbers.insert(number);
        }
        return false;
    }
};

int main()
{
    Solution sol;
    std::vector<int> v1 = {1,2,3,1};
    std::cout << sol.containsDuplicate(v1) << std::endl;
    return 0;
}
