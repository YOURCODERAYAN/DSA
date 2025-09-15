class Solution {
public:
    int maxXorSubsequences(vector<int>& nums) {
        int n=nums.size();
        vector<int> vec(32);

        for(int i=0;i<n;i++){
            int mask=nums[i];
            for(int j=31;j>=0;j--){
                if(!(1&(mask>>j))) continue;
                if(!vec[j]){
                    vec[j]=mask;
                    break;
                }
                mask^=vec[j];
            }
        }
        int ans=0;
        for(int i=31;i>=0;i--){
            if(1&(ans>>i)) continue;
            ans^=vec[i];
        }
        return ans;
    }
};