/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* exclusiveTime(int n, char** logs, int logsSize, int* returnSize) {
    int *ans = (int*)calloc(n, sizeof(int));
    int stack[logsSize];
    int top = -1;
    int prevtime = 0;
    for(int i=0;i<logsSize;i++){
        int id , time;
        char type[10];
        sscanf(logs[i], "%d:%[^:]:%d", &id,type,&time);
        if(strcmp(type,"start")==0){
            if(top!=-1){
                ans[stack[top]]+=time-prevtime;
            }
            stack[++top]=id;
            prevtime = time;
        }
        else{
            ans[stack[top]]+=time-prevtime+1;
            top--;
            prevtime = time+1;
        }
    }
    *returnSize = n;
    return ans;
}