class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long sum=0;
        int m=batteries.size();
        for(int i=0;i<m;i++)
            sum+=batteries[i];
    
    long long low=1 , high=sum/n;

        while(low < high){
                long long mid=high-(high-low)/2;
        long long ans=0;
            for(int i=0;i<m;i++)
                ans+=min((long long)batteries[i] , mid);
        if(ans >= (long long) n*mid){
                low=mid;
        }
        else{
            high=mid-1;
        }
        }
        return low;
    }
};