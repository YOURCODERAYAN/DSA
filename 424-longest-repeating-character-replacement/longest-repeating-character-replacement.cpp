class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0 , r=0 , maxlen=0 , maxfreq=0;
            vector<int> freq(26,0);
        while(r < s.size()){
                freq[s[r]-'A']++;
        maxfreq=max(maxfreq , freq[s[r]-'A']);
            
            while( (r-l+1) -maxfreq  > k){
                    freq[s[l]-'A']--;
            maxfreq=0;
            for(int i=0;i<26;i++)
                maxfreq=max(maxfreq  , freq[i]);
            l+=1;
            }
            if( (r-l+1) -maxfreq <= k)
                    maxlen=max(maxlen , r-l+1);
            r+=1;
        }
        return maxlen;
    }
};