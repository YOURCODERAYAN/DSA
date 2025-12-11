class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
            unordered_map<int , pair<int , int>> y_map;
            unordered_map<int , pair<int,int>>  x_map;

    for(auto &i:buildings){
            int x=i[0];
            int y=i[1];
        if(!y_map.count(y))
            y_map[y]={INT_MAX , INT_MIN};
        if(!x_map.count(x))
            x_map[x]={INT_MAX , INT_MIN};
        
        y_map[y].first=min(y_map[y].first , x);
        y_map[y].second=max(y_map[y]. second , x);

        x_map[x].first=min(x_map[x].first , y);
        x_map[x].second=max(x_map[x].second , y);
    }

    int res=0;
        for(auto &i:buildings){
                int x=i[0];
                int y=i[1];

        auto &xr=y_map[y];
        auto &yr=x_map[x];
                if(xr.first < x && x< xr.second  && yr.first < y && y < yr.second){
                        res++;
                }
        }
        return res;
    }
};