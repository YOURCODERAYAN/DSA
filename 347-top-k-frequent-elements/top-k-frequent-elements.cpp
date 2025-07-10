class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      using namespace std;
    // at first declaring unordered map 
      unordered_map<int,int>freq;
      for(int i=0;i<nums.size();i++){
      freq[nums[i]]++;
      }
      //move map elements in prority queue
      priority_queue<pair<int,int>>pq;
      for(auto&p:freq){
      pq.push({p.second,p.first});
      }
//we have to take k elements
vector<int>result;
for(int i=0;i<k;i++){
result.push_back(pq.top().second);
pq.pop();
 }
 return result;
} 
};
