class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> numset;

        for(int n:nums){
            if(numset.find(n)!=numset.end()){
                return true;
            }
            numset.insert(n);
        }
        return false;
    }
};