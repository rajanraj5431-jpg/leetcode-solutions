class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int n=text.length();
        unordered_map <int, int> map;
        for(int i=0;i<n;i++){
            map[text[i]]++;
        }
        int ans=0;
        while(map['b']>0&&map['a']>0&&map['l']>1&&map['o']>1&&map['n']>0){
            ans+=1;
            map['b']--;
            map['a']--;
            map['l']-=2;
            map['o']-=2;
            map['n']--;
        }
        return ans;
    }
};