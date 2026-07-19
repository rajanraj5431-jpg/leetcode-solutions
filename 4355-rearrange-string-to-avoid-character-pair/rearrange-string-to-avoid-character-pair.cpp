class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        int l=0, r=s.length()-1;
        while(l<r){
            if(s[l]==x&&s[r]==y){
                swap(s[l],s[r]);
                l++;
                r--;
            }
            else if(s[l]==x){
                r--;
            }
            else if(s[r]==y){
                l++;
            }
            else{
                l++;
                r--;
            }
        }
        return s;
    }
};