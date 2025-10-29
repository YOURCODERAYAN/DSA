class Solution {
/*public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
    int ones=0 , twos=0;
    for(int i=0;i<n;i++){
        ones=(ones^nums[i]) & ~ twos;
        twos=(twos^nums[i]) & ~ ones;
    }
    return ones;
    }
*/
public:
    int singleNumber(vector<int>& nums){
        int n=nums.size();

        map<int , int > mpp;
        for(int i=0;i<n;i++){

            mpp[nums[i]]++;
        }


        for(auto it: mpp){
            if(it.second==1)
                return it.first;
        }
        return 0;
    }
};