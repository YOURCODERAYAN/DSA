class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int zeros=0;
        int n=arr.size();
        
        for(int i=0;i<n;i++){
            if(arr[i]==0) zeros++;
        }
        int i=n-1;
        int j=n+zeros-1;
        while(i<j){
            if(j<n)arr[j]=arr[i];

            if(arr[i]==0){
                j--;
                if(j<n) arr[j]=0;
            }
            i--;
            j--;
    }
    }
};