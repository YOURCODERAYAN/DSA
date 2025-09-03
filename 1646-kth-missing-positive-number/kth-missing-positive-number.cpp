/*class Solution {
public:
    vector<int> missingnumber(vector<int> & arr , int k){
        vector<int> ans;
        int expected=1;
        int i=0;

        while(ans.size() < k){
            if(i<arr.size() && arr[i]==expected){
                i++;
            }
            else{
                ans.push_back(expected);
            }
            expected++;
        }
        return ans;
    }
    int findKthPositive(vector<int>& arr, int k) {
        vector<int> ans=missingnumber(arr,k);
        return ans[k-1];
    }
};*/
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
    int low=0,high=n-1;

    while(low<=high){
        int mid=(low+high)/2;
    int missing=arr[mid]-(mid+1);
        if(missing < k){
            low=mid+1;
        }
        else{
            high=mid-1;
       }
    }
return low+k;
 }
};
