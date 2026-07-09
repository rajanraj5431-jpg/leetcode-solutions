int largestRectangleArea(int* heights, int heightsSize) {
    int stack[heightsSize +1];
    int top = -1;
    int maxarea=0;
    for(int i=0;i<=heightsSize;i++){
        int currheight;
        if(i==heightsSize){
            currheight=0;
        }
        else
            currheight = heights[i];
        while(top != -1 &&
              heights[stack[top]] > currheight){
            int h = heights[stack[top--]];
            int width;
            if(top == -1){
                width=i;
            }
            else{
                width=i-stack[top]-1;
            }
            int area = h * width;
            if(area>maxarea){
                maxarea = area;
            }
        }
        stack[++top]=i; 
    }
    return maxarea;
}