class Solution {
public:
    #define MOD 1000000007
    int digits(long long a){
        int count=0;
        while(a!=0){
            a=a/10;
            count++;
        }
        return count;
    }
    long long modpow(long long x, long long y) {

        long long ans = 1;

        while (y > 0) {

            if (y % 2 == 1) {
                ans = (ans * x) % MOD;
            }

            x = (x * x) % MOD;
            y /= 2;
        }

        return ans;
    }

    int sumDecoded(vector<long long>& nums) {
        int n=nums.size();
        long long sum=0;
        for(int i=0;i<n;i++){
            int width=nums[i]%10;
            long long d=nums[i]/10;
            long long p = 1;
            for (int j = 0; j < digits(d) - width; j++) {
                p *= 10;
            }
            long long x = d / p;
            long long y = d % p;
            sum=(sum+modpow(x,y))%MOD;
        }
        return (int)sum;    
    }
};