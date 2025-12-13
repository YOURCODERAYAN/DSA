class Solution {
/*public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            int sum=0;
                for(int j=i;j<n;j++){
                         sum+=nums[j];
                if(sum == goal)
                    cnt+=1;
                }
            }
        return cnt;

    }*/
public:
    int numSubarraysWithSum(vector<int>& nums, int goal){
            return atmost(nums , goal) - atmost(nums , goal-1);
    }


private:
    int atmost(vector<int>& nums, int k) {
        int l=0 , r=0 , cnt=0 , sum=0;
        if(k < 0) return 0;
    while(r < nums.size()){
            sum=sum+nums[r];
        while( sum > k){
                sum=sum-nums[l];
                l=l+1;
        }
        cnt=cnt+(r-l+1);
        r=r+1;
    }
    return cnt;
    }
};