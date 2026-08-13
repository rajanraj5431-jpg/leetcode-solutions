class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0;
        int count=0;
        unordered_map<int, int> freq;
        int n=s.length();
        if(n==1){
            return 1;
        }
        for(int i=0;i<n;i++){
            freq[s[i]]+=1;
             while (freq[s[i]] > 1) {
                freq[s[count]]--;
                count++;
            }

            ans = max(ans, i-count + 1);
        }
        return ans;
    }
};