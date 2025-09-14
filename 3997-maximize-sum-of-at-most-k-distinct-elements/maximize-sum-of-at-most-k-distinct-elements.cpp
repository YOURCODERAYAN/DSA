class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
            
        sort(nums.rbegin(),nums.rend());

            vector<int> ans;
            for(int i=0;i<nums.size();i++){
                if(k>0&&(i==0||nums[i]!=nums[i-1])){
                    ans.push_back(nums[i]);
                    k--;
                }
            }
            return ans;
        }
    };