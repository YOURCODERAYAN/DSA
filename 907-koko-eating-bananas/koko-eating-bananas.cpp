class Solution {
public:
// Find the max element in the given piles[]
    int findMax(vector<int>&piles){
        int n=piles.size();
        int maxi=INT_MIN;
    for(int i=0;i<n;i++){
        maxi=max(maxi,piles[i]);
    }
    return maxi;
}

// Now we have to calculate total hours
long long calculatetotalhours(vector<int>&piles,int hours){
    int n=piles.size();
    long long  TotalH=0;
    for(int i=0;i<n;i++){
        TotalH+=ceil(piles[i]+hours-1) / hours;
    }
    return TotalH;
}
// now the main part where we are implementing the binary search algorithm
int minEatingSpeed(vector<int>& piles, int h) {
        int low=1,high=findMax(piles);

        while(low<=high){
            int mid=low+(high-low)/2;
        long long TotalH=calculatetotalhours(piles,mid);

        if(TotalH <= h){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
        }
        return low;
    }
    
};