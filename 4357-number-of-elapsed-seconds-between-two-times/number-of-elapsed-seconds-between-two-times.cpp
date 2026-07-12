class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        int sh,sm,ss,eh,em,es;
        sscanf(startTime.c_str(), "%d:%d:%d",&sh,&sm,&ss);
        sscanf(endTime.c_str(), "%d:%d:%d",&eh,&em,&es);
        long long st=sh*3600+sm*60+ss;
        long long et=eh*3600+em*60+es;
        long long ans=et-st;
        return (int )ans;
    }
};