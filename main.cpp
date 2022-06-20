#include <iostream>
#include <vector>
#include <limits>

class Solution {
private:
    int maxsum;
    int currsum = 0;
public:

    int maxSubArray(std::vector<int>& nums)
    {
        maxsum = std::numeric_limits<int>::min();
        currsum = 0;
        for(int i=0;i<nums.size();i++)
        {
            currsum += nums[i];
            if(currsum > maxsum)
            {
                maxsum = currsum;
            }
            if(currsum < 0)
            {
                currsum = 0;
            }
        }
        return maxsum;
    }
};

int main()
{
    std::vector<int> v1 = {-2,1,-3,4,-1,2,1,-5,4};
    Solution sol;
    std::cout << sol.maxSubArray(v1) << std::endl;
    return 0;
}
