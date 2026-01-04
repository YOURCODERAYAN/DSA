class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int n=nums.size();
        long long total_sum=0;
    
    for(int num:nums){
         vector<int> res;
        for(int i=1;i*i<=num;i++){
                if(num%i==0){
                        res.push_back(i);
                        if((num/i)!=i){
                            res.push_back(num/i);
                        }
                }
                if(res.size() > 4) break;
            }
            if(res.size()==4){
                    long long current_sum=accumulate(res.begin() , res.end() , 0LL);
                total_sum+=current_sum;
            }
            
        }
        return total_sum;
    }
};