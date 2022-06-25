#include <iostream>
#include <map>

class Solution {
public:
        bool canConstruct(std::string ransomNote, std::string magazine) {
            std::map<char, int> map;
            int mSize = magazine.size();
            for(int i = 0; i < mSize; i++) {
                map[magazine[i]]++;
            }
            int rSize = ransomNote.size();
            for(int i = 0; i < rSize; i++) {
                auto it = map.find(ransomNote[i]);
                if(it == map.end() ) {
                    return false;
                } else {
                    if(it->second == 0) {
                        return false;
                    } else {
                        map[ransomNote[i]] = it->second-1;
                    }
                }
            }

            return true;
        }
};

int main()
{
    Solution sol;
    std::cout << sol.canConstruct("abbvve", "abbvgg") << std::endl;
    return 0;
}
