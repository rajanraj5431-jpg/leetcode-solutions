int largestAltitude(int* gain, int gainSize) {
    int* res = (int*)calloc((gainSize+1), sizeof(int));
    for(int i=0;i<gainSize;i++){
        res[i+1] += gain[i] + res[i];
    }
    int high=0;
    for(int i=0;i<gainSize+1;i++){
        int max = res[i];
        if(max>high){
            high = max;
        }
    }
    return high;
}