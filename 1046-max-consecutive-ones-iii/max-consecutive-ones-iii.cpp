class Solution {
/*public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
            int maxlen=0 , len;
        for(int i=0;i<n;i++){
                int zeros=0;
            for(int j=i;j<n;j++){
                    if(nums[j] ==0) zeros++;
                    if(zeros <= k){
                         len=j-i+1;
                maxlen=max(maxlen , len);
                    }
            else if(zeros > k){
                    break;
            }
            }
        }
        return maxlen;
    }*/

public:
    int longestOnes(vector<int>& nums, int k) {
            int n=nums.size();
        int l=0 , r=0 , maxlen=0 , len;
        int zeros=0;
        while(r < n){
                if(nums[r]==0) zeros++;
            while(zeros  > k){
                    if(nums[l]==0){
                        zeros--;
                    }
                    l+=1;
                    
            }
            if(zeros <= k ){ len=r-l+1;
            maxlen=max(maxlen , len);
            }
            r+=1;
            
        }
        return maxlen;
    }

};