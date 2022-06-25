#include <iostream>
#include <map>
#include <unordered_map>

class Solution {
    std::map<char, int> map;
public:
    int firstUniqChar(std::string s) {
        std::map<char, int> map;
        for(int i = 0; i < s.size(); i++) {
            map[s[i]]++;
        }
        for(int i = 0; i < s.size(); i++) {
            if(map[s[i]] == 1) return i;
        }
        return -1;
    }
};

int main()
{
    Solution sol;
    std::cout << sol.firstUniqChar("leetcode") << std::endl;
    return 0;
}
