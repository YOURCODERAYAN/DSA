class Solution {
public:
    int earliestTime(vector<vector<int>>& tasks) {
       if(tasks.empty()) return 0;

        int sum1=INT_MAX;
        for(int row=0;row<tasks.size();row++){
            if(tasks[row].size() <2) {
                return -1;
            }
            int sum=tasks[row][0]+tasks[row][1];
            if(sum1 > sum){
                sum1=sum;
            }
        }
        return sum1;      
    }
};