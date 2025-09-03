class Solution {
public:
    int canweplace(vector<int>& position,int distance,int Balls){
        int n=position.size();
        int cntBalls=1;
        int last=position[0];

    for(int i=1;i<n;i++){
        if(position[i]-last >= distance){
            cntBalls++;
            last=position[i];
        }
        if(cntBalls >= Balls) return true;
        }
        return false;       
    }
    int maxDistance(vector<int>& position, int m) {
        int n=position.size();
        sort(position.begin(),position.end());

        int low=1, high=position[n-1] - position[0];

        while(low<=high){
            int mid=(low+high)/2;
        
        if(canweplace(position,mid,m) == true){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
        }
        return high;
    }
};