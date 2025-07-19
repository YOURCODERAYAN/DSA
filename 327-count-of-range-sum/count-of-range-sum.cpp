class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n=nums.size();
        vector<long>prefix(n+1,0);
        for(int i=0;i<n;i++){
            prefix[i+1]=prefix[i]+nums[i];
        }
        return merge_sort(prefix,0,n,lower,upper);
    }
    int merge_sort(vector<long> &prefix,int low,int high,int lower,int upper){
        if(low>=high) return 0;
        int mid=(low+high)/2;
        int count=merge_sort(prefix,low,mid,lower,upper)+ merge_sort(prefix,mid+1,high,lower,upper);
        int j=mid+1,k=mid+1;
        for(int i=low;i<=mid;i++){
            while(k<=high&&prefix[k]-prefix[i]<lower)k++;
            while(j<=high&&prefix[j]-prefix[i]<=upper)j++;
            count+=j-k;
        }
   
    vector<long>temp;
    int left=low;
    int right=mid+1;
      while (left <= mid && right <= high) {
        if(prefix[left]<=prefix[right]){
            temp.push_back(prefix[left]);
            left++;
        }
        else{
            temp.push_back(prefix[right]);
            right++;
        }
    }
    while(left<=mid){
        temp.push_back(prefix[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(prefix[right]);
        right++;
    }
    for(int i=low;i<=high;i++){
        prefix[i]=temp[i-low];
    }
    return count;
    }
};