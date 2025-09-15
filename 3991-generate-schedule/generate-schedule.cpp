class Solution {
public:
    vector<vector<int>> generateSchedule(int n) {
        if(n<=4) return {};

        int size=n*(n-1);
        vector<vector<int>> res;
        unordered_set<string> visited;

    int num1=0 , num2=1;

    string key=to_string(num1)+','+to_string(num2);
    while(res.size()!=size){
        int diff=abs(num2-num1);

        while(!visited.count(key)){
            visited.emplace(key);

            vector<int> match(2);
            match[0]=num1;
            match[1]=num2;
            res.emplace_back(move(match));

            if(diff==1){
                num1=(num1+2)%n;
                num2=(num2+2)%n;
            }
            else{
                num1=(num1+1)%n;
                num2=(num2+1)%n;
            }

            key=to_string(num1)+','+to_string(num2);
        }

        while(
                visited.count(key) ||
                num1==res.back()[0] ||
                num1==res.back()[1] ||
                num2==res.back()[0] ||
                num2==res.back()[1] ||
                num1==num2
             ){
                if(++num2 % n == 0){
                    num2=0;
                    num1++;
                }
                key=to_string(num1)+','+to_string(num2);
             }
        }
        return res;
    }
};