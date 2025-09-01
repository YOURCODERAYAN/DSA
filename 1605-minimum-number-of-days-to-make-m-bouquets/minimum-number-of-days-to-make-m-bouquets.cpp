class Solution {
public:
    int possible(vector<int>& bloomDay , int day , int m ,int k){
        int n=bloomDay.size();
        int cnt=0, noofB=0;
            for(int i=0;i<n;i++){
        if(bloomDay[i] <= day){
            cnt++;
        }
        else{
            noofB+=(cnt/k);
            cnt=0;
        }
        }
        noofB+=(cnt/k);
        return noofB>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val=m*1ll*k*1ll;
        int n=bloomDay.size();
        if(val > n) return -1;
        int mini=INT_MAX,  maxi=INT_MIN;
        for(int i=0;i<n;i++){
            mini=min(mini,bloomDay[i]);
            maxi=max(maxi,bloomDay[i]);
        }

    // Apply binary search algorithm 
        int low=mini,high=maxi;
        while(low<=high){
            int mid=(low+high)/2;
        if(possible(bloomDay,mid,m,k)){
            high=mid-1;
        }
        else
            low=mid+1;
        }
        return low;
    }

};