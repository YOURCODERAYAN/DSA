class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        unordered_set<int> HashSet(friends.begin(),friends.end());

        vector<int> result;
        for(int x: order){
            if(HashSet.find(x)!=HashSet.end()){
                    result.push_back(x);
            }

        }
        return result;
        

    }
};