class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int leftsum=0 , rightsum=0 , maxSum=0;
        for(int i=0;i<=k-1;i++)
                leftsum+=cardPoints[i];
            maxSum=leftsum;
        int rightindex=n-1;
        for(int i=k-1;i>=0;i--){
                leftsum-=cardPoints[i];
                rightsum+=cardPoints[rightindex];
                rightindex-=1;
        maxSum=max(maxSum , leftsum+rightsum);
        }
    return maxSum;
}
};