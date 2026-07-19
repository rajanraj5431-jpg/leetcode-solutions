class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        long long ans=s;
        if(n==1){
            return ans;
        }
        long long b=(n/2);
        long long c=(m-1);
        long long a=b*c;
        ans+=a+1;
        return ans;
    }
};