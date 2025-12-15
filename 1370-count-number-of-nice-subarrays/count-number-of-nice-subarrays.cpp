class Solution {
/*public:
    int numberOfSubarrays(vector<int>& nums, int k) {
            int n=nums.size();
            int cnt=0;
        for(int i=0;i<n;i++){
                int odd_cnt=0;
                for(int j=i;j<n;j++){

                    if(nums[j]%2==1)
                        odd_cnt+=1;
                    
                    if(odd_cnt==k)
                        cnt+=1;
                    
                }
        }
        return cnt;
    }*/


public:
    int numberOfSubarrays(vector<int>& nums, int k){
        return atm(nums , k) - atm(nums , k-1);
    }
private:
    int atm(vector<int>&nums , int goal){
        if(goal < 0) return 0;
        int l=0 , r=0 , sum=0 , cnt=0;
    while(r < nums.size()){
            sum=sum+(nums[r]%2);
        while( sum > goal){
                sum=sum-(nums[l]%2);
                l=l+1;
        }
        cnt=cnt+(r-l+1);
        r=r+1;
    }
    return cnt;
    }

};