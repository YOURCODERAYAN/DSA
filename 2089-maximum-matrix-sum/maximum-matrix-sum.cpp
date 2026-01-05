class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
    
    long long n=matrix.size();
    long long m=matrix[0].size();

            long long negatives=0;
             int mini=INT_MAX;
            long long sum=0;

    for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                    if(matrix[i][j] < 0){
                            negatives++;
                    }
                mini=min(abs(matrix[i][j]) , mini);
                sum+=abs(matrix[i][j]);
            }
        }

        if(negatives % 2==0){
                return sum;
        }
        else{
                return sum - 2*abs(mini);
        }
    }
    
};