/*class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int  mod=1e9+7;
        long long n=nums.size();
        long long cnt=0;
            for(long long i=0;i<=n;i++){
                    for(long long j=i+1;j<=n;j++){
                            for(long long k=j+1;k<n;k++){
                                    if((nums[i]==nums[j]*2*1LL)% mod && (nums[k]==nums[j]*2*1LL)%mod){
                                            cnt++;
                            }
                    }
                    
            }
            
    }
    return (int)cnt;

}
};*/
class Solution{
public:
int specialTriplets(vector<int>& nums) {
    const int mod=1e9+7;
        unordered_map<int,int> mp_left;
        unordered_map<int,int> mp_right;
    
    int result=0;
        for(int &num:nums){
                mp_right[num]++;
        }
        for(int &num:nums){
                mp_right[num]--;

        int left=mp_left[num*2];
        int right=mp_right[num*2];
            result=(result+(1LL* left*right))%mod;
                mp_left[num]++;
        }
        return result;
            
    }
};
    
