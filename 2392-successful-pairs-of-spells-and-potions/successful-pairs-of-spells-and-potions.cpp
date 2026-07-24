class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        vector<int> result;
        for(int spell:spells){
            long long minpotion=(success+spell-1)/spell;
            auto it=lower_bound(potions.begin(),potions.end(),minpotion);
            result.push_back(distance(it,potions.end()));
        }
        return result;
    }
};