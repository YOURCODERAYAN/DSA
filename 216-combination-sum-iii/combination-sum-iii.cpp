class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> subset;
        vector<vector<int>> ans;
            gethelp(1 , k ,0 , n , subset , ans);
    return ans;
    }


    void gethelp(int i , int k , int sumtillnow , int n , vector<int>&subset , vector<vector<int>> & ans){

        if(sumtillnow > n)
            return ;
        
        if(k==0){

            if(sumtillnow==n){
                ans.push_back(subset);
            }
            return ;
        }
        if(i==10)
            return;

        


    //pick the element;
    sumtillnow+=i;
    subset.push_back(i);
    gethelp(i+1 , k-1 , sumtillnow , n , subset , ans);
    sumtillnow-=i;
    subset.pop_back();

    gethelp(i+1 , k , sumtillnow , n , subset , ans);
    }
};