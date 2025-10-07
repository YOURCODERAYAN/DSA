class Solution {
public:
    const int M=1e9+7;
    long long  findpower(long long a , long long b){
        if(b==0) return 1;
        long long half=findpower(a,b/2);
            long long res=(half*half) % M;
        if(b % 2==1){
            res=(a*res)%M;
        }
         return res;
    }
    int countGoodNumbers(long long n) {
        return findpower(5, (n+1)/2) * findpower(4, n/2) % M;
    }
};