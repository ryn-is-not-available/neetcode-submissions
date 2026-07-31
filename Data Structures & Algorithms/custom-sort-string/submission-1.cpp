class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int> orders;
        for(int i=0;i<order.size();i++){
            orders[order[i]]=i;
        }
        
        //building a heap from the string
        int n=s.size(),curr,leftChild,rightChild,maxIndex,heapSize;
        for(int i=n/2;i>=0;i--){
            curr=i;
            while(true){
                leftChild=2*curr+1;
                rightChild=2*curr+2;
                maxIndex = curr;
                if(leftChild < n && orders[s[leftChild]]>orders[s[maxIndex]] )maxIndex=leftChild;
                if(rightChild < n && orders[s[rightChild]]>orders[s[maxIndex]] )maxIndex=rightChild;
                if(curr==maxIndex)break;
                swap(s[maxIndex],s[curr]);
                curr=maxIndex;
            }
        }

        //sorting the heap

        for(int i=0;i<n;i++){
            heapSize = n-1-i;
            swap(s[0],s[heapSize]);
            curr = 0;
            while(true){
                leftChild=2*curr+1;
                rightChild=2*curr+2;
                maxIndex = curr;
                if(leftChild < heapSize && orders[s[leftChild]]>orders[s[maxIndex]] )maxIndex=leftChild;
                if(rightChild < heapSize && orders[s[rightChild]]>orders[s[maxIndex]] )maxIndex=rightChild;
                if(curr==maxIndex)break;
                swap(s[maxIndex],s[curr]);
                curr=maxIndex;
            }
        }
        return s;

    }
};