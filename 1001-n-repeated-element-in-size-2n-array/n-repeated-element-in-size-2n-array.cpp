class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n=nums.size();
    int x=n/2;
    bool repeat=false;
        int ans=0;
        map<long  , long> freq_map;
        for(int i=0;i<n;i++){
                freq_map[nums[i]]++;
        }
        map<long , long> :: iterator it;
            for(it=freq_map.begin() ; it!=freq_map.end();it++){
                    if(it->second ==x ){
                        repeat=true;
                        ans=it->first;
                    }

            }
            return ans;
    }
};