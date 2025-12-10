class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        int n=complexity.size();
    if(n==0){
            return 0;
    }

    const int mod=1e9+7;
        int base_complexity=complexity[0];

    for(int i=1;i<n;i++){
            if(complexity[i] <= base_complexity){
                return 0;
    }
    }

    long long res=1;
        for(int i=1;i<n;i++){
                res=(res*i)%mod;
        }
        return res;
    }
};