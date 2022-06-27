#include <iostream>
#include <map>

class Solution {
    std::map<char, int> mapS;
public:
    bool isAnagram(std::string s, std::string t) {
        mapS.clear();
        if(s.size() != t.size()) {
            return false;
        }
        for(int i = 0; i < s.size(); i++) {
            mapS[s[i]]++;
        }
        for(int i = 0; i < s.size(); i++) {
            auto it = mapS.find(t[i]);
            if(it == mapS.end()) {
                return false;
            } else {
                if(it -> second == 0) {
                    return false;
                } else {
                    mapS[t[i]]--;
                }
            }
        }
        return true;
    }
};

int main()
{
    Solution sol;
    std::cout << sol.isAnagram("rat", "car") << std::endl;
    return 0;
}
