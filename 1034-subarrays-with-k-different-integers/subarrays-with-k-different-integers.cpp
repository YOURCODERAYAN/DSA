class Solution {
/*public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n=nums.size();
    int cnt=0;
    int MAX_VAL = *std::max_element(nums.begin(), nums.end()) + 1;
        for(int i=0;i<n;i++){
            vector<int> freq(MAX_VAL,0);
                int diff=0;
                for(int j=i;j<n;j++){
                        if(freq[nums[j]]==0){
                                diff++;
                        }
                    freq[nums[j]]++;
                if(diff==k){
                        cnt=cnt+1;
                }
                else if(diff > k){
                        break;
                }
                }
            
            }
            return cnt;
        }*/
public:
    int subarraysWithKDistinct(vector<int>& nums, int k){
            return atmost(nums , k) - atmost(nums,k-1);
    }

private:
        int atmost(vector<int>&nums , int target){
                int n=nums.size();
        int l=0 , r=0 , cnt=0 , dist=0;
        vector<int> freq(n+1, 0);
        while(r < n){  
            
                if(freq[nums[r]]==0){
                        dist++;
                }
            freq[nums[r]]++;
        
        while( dist > target){

                freq[nums[l]]--;
        if(freq[nums[l]]==0){
                dist--;
        }
        l+=1;
        }

            cnt+=(r-l+1);
        r+=1;
    }
    return cnt;
        }
};