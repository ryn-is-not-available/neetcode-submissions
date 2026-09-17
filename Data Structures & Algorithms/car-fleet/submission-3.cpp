class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // custom Heap Sort 
        // building the heap 
        int n = speed.size();
        for (int i = (n-1)/2 ; i >=0 ; i--) {
            int currentNode = i;
            while (true) {
                int leftChild = 2*currentNode + 1;
                int rightChild = leftChild + 1;
                int maxNode = currentNode;
                if (leftChild < n && position[leftChild] > position[maxNode]) maxNode = leftChild;
                if (rightChild < n && position[rightChild] > position[maxNode]) maxNode = rightChild;
                if (maxNode == currentNode) break;
                swap(position[currentNode],position[maxNode]);
                swap(speed[currentNode],speed[maxNode]);
                currentNode = maxNode; 
            }
        }
        // Sorting the heap

        for (int i=0 ; i<n ; i++) {
            int heapSize = n - 1 - i;
            int currentNode = 0;
            swap(position[currentNode],position[heapSize]);
            swap(speed[currentNode],speed[heapSize]);
            
            while (true) {
                int leftChild = currentNode*2+1;
                int rightChild = leftChild +1;
                int maxNode = currentNode;
                if (leftChild < heapSize && position[leftChild] > position[maxNode]) maxNode = leftChild;
                if (rightChild < heapSize && position[rightChild] > position[maxNode]) maxNode = rightChild;
                if (maxNode == currentNode) break;
                swap(position[currentNode],position[maxNode]);
                swap(speed[currentNode],speed[maxNode]);
                currentNode = maxNode; 
            }
        }

        
            int fleetCount = 1 ;
            double lastTime = (double) (target-position[n-1]) / speed[n-1];
            
            for (int i = n-2 ; i>=0 ; i--) {
                double currentTime =(double) (target-position[i]) / speed[i];
                if(currentTime > lastTime) {
                    fleetCount++;
                    lastTime = currentTime ;
                }
            }
            return fleetCount;
    }
};
