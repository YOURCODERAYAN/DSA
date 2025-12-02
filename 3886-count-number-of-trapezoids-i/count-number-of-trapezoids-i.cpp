class Solution {
public:
    const int mod=1e9+7;
    int countTrapezoids(vector<vector<int>>& points) {
            long long ans=0;

    unordered_map<int , int> mp;
    for(auto i : points){
        mp[i[1]]++;
    }
        long long edge_sum=0;
            for(auto i:mp){
                    long long edges=(i.second * 1ll*(i.second-1))/2;
                ans=(ans+edges*edge_sum)%mod;
                edge_sum+=edges;
            }
            return ans;
    }
};