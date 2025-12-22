class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
            map<int , pair<char,int>> char_map;
        for(size_t i=0; i<s.length();i++){
            char_map[i]={s[i] , cost[i]};
        }
    
    if(char_map.empty()) return 0;

        long long total_cost=0;
    
    map<char , long long> char_per;
    for(auto &it : char_map){
            char c=it.second.first;
            int cost_c=it.second.second;

    total_cost+=cost_c;
        char_per[c]+=cost_c;

    }
    long long max_char_cost = 0;
    for (auto const& [character, total_cost] : char_per) {
        if (total_cost > max_char_cost) {
            max_char_cost = total_cost;
        }
    }
    return total_cost-max_char_cost;
    }
};