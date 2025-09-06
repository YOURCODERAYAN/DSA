class Solution {
public:
    int getLeastFrequentDigit(int n) {
        int freq[10]={0};
        n=abs(n);

        if(n==0) return 0;
        

        while(n>0){
            int lastdigit=n%10;
            freq[lastdigit]++;
            n=n/10;
        }

        int least_freq=-1;
        int  mini=INT_MAX;
    
    for(int d=0;d<10;d++){
        if(freq[d] > 0 && freq[d] < mini){
            mini=freq[d];
            least_freq=d;
    }
}
return least_freq;
    }
};