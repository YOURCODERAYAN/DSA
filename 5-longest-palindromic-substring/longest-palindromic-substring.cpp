class Solution {
public:
    string longestPalindrome(string s) {
        int start=0;
        int maxlen=1;
        
        int n=s.length();
    for(int i=1;i<n;i++){
        // just calculate the case if the string is even 

        int left=i-1;
        int right=i;
    while(left >= 0 && right <n && s[left]==s[right]){
        if(right-left+1 > maxlen){
        maxlen=right-left+1;
        start=left;
        }
        left--;
        right++;
        
    }


     // we have to calculate in case of string which is odd
         left=i-1;
         right=i+1;
        while(left >= 0 && right < n && s[left]==s[right]){
            if(right-left+1 > maxlen){
            maxlen=right-left+1;
            start=left;
            }
            left--;
            right++;
    }
    }
    return s.substr(start,maxlen);
    }
};