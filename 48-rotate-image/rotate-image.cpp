class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        // for transposing the matrix
        for(int i=0;i<=n-2;i++){
            for(int j=i+1;j<=n-1;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        //now reversing part
        for(int i=0;i<n;i++){
            // reverse row we are taking as matrix[i]
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};