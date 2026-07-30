class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        //building a heap 
        int n=heights.size();
        int leftChild,rightChild,minIndex,curr,maxLength;
        for(int i=n/2;i>=0;i--){
            curr = i;
            while(true){
                leftChild=2*curr+1;
                rightChild=2*curr+2;
                minIndex=curr;
                if(leftChild<n && heights[minIndex]>heights[leftChild])minIndex=leftChild;
                if(rightChild<n && heights[minIndex]>heights[rightChild])minIndex=rightChild;
                if(minIndex==curr)break;
                swap(heights[curr],heights[minIndex]);
                swap(names[curr],names[minIndex]);
                curr=minIndex;
            }
        }

        // sorting it

        for(int i=0;i<n;i++){
            int maxLength=n-1-i;
            swap(heights[0],heights[maxLength]);
            swap(names[0],names[maxLength]);
            curr = 0;
            while(true){
                leftChild=2*curr+1;
                rightChild=2*curr+2;
                minIndex=curr;
                if(leftChild<maxLength && heights[minIndex]>heights[leftChild])minIndex=leftChild;
                if(rightChild<maxLength && heights[minIndex]>heights[rightChild])minIndex=rightChild;
                if(minIndex==curr)break;
                swap(heights[curr],heights[minIndex]);
                swap(names[curr],names[minIndex]);
                curr=minIndex;
            }
        }
        return names;
    }
};