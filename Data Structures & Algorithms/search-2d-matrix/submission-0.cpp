class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int leftColumn=0,rightColumn=matrix.size()-1,midColumn;
        int left=0,right=matrix[0].size()-1;
        if(target < matrix[leftColumn][left] || target > matrix[rightColumn][right]) return false;
        while (leftColumn<=rightColumn) {
            midColumn = (leftColumn+rightColumn)/2;
            if(target <=matrix[midColumn][right] && target >=matrix[midColumn][left]){
                break;
            }
            else if (target >matrix[midColumn][right]) leftColumn = midColumn+1;
            else rightColumn=midColumn-1;
        }

        while(left<=right){
            int mid=(left+right)/2;
            if(matrix[midColumn][mid]==target) return true;
            else if (matrix[midColumn][mid] < target) left = mid + 1;
            else right = mid - 1 ;
        }
        return false;


    }
};
