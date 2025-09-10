class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>> jobs;
    for(int i=0;i<difficulty.size();i++){
        jobs.push_back({difficulty[i],profit[i]});
    }

    // now we have to sort the pair to maintain the correct sequence
    sort(jobs.begin(),jobs.end());

    // now we  have to compute the max profit 
    vector<int> maxProfit(jobs.size());
    int currentMax=0;
    for(int i=0;i<jobs.size();i++){
    if(jobs[i].second > currentMax)
        currentMax=jobs[i].second;
    
    maxProfit[i]=currentMax;
    }

    int Totalprofit=0;
    for(int worker : worker){
        int low=0 , high=jobs.size()-1;
        int index=-1;

        while(low<=high){
            int mid =  (low+high)/2;
        if(jobs[mid].first <= worker){
            index=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
        }
        if(index!=-1){
           Totalprofit+=maxProfit[index];
        } 
        }
        return Totalprofit;
    }

};