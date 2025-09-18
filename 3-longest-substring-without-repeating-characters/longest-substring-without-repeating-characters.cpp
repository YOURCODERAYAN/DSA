class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0;
        int maxlen=0;

        unordered_set<char> char_set;

    for(int right=0;right<s.length();right++){
        while(char_set.find(s[right])!=char_set.end()){
                char_set.erase(s[left]);
                left++;
        }

        char_set.insert(s[right]);
        maxlen=max(maxlen,right-left+1);
        }
    return maxlen;
    }
};