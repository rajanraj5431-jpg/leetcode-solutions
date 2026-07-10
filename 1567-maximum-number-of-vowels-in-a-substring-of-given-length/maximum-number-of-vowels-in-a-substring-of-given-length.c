bool isVowel(char s){
    if(s=='a'||s=='e'||s=='i'||s=='o'||s=='u'){
        return true;
    }
    return false;
}
int maxVowels(char* s, int k) {
    int count = 0;
        int n=strlen(s);
        for(int i=0;i<k;i++){
            if(isVowel(s[i])){
                count++;
            }
        }
        int max = count;
        for(int i=k;i<n;i++){
            if(isVowel(s[i-k])){
                count--;
            }
            if(isVowel(s[i])){
                count++;
            }
            max = (count>max)?count:max;
        }
        return max;
}