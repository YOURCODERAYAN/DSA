class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subsets;

        create(nums,0,res,subsets);
            return res;

    }

    void create(vector<int>& nums, int ind,vector<vector<int>> &res , vector<int> subsets){

        // base condition 
        if(ind==nums.size()){
            res.push_back(subsets);
            return;
        }

        subsets.push_back(nums[ind]);
        create(nums,ind+1,res,subsets);

        subsets.pop_back();
        create(nums,ind+1,res,subsets);
    }
};