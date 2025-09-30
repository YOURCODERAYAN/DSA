/*class Solution {
public:
    int triangularSum(vector<int>& nums) {
        while(nums.size() >1){
            int n=nums.size();
        vector<int> newnums;
        for(int i=0;i<n-1;i++){
                newnums.push_back((nums[i]+nums[i+1])%10);
        }
            nums=move (newnums);
        }
        return nums[0];
    }
};*/

// but in this approach we are conseridring the O(n2) t.c and space complexity of O(n) 
// because we are considering a extra space for storing the answer 

class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n=nums.size();
        for(int size=n-1;size>=1;size--){
            for(int i=0;i<size;i++){
                nums[i]=((nums[i]+nums[i+1])%10);
            }
        }
     return nums[0];
    }
};
