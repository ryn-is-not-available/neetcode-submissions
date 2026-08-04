struct PairHash {
    size_t operator()(const std::pair<int, int>& p) const {
        
        return std::hash<int>{}(p.first) ^ (std::hash<int>{}(p.second) << 1);
    }
};
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> Rows(9);
        vector<unordered_set<char>> Cols(9);
        unordered_map<pair<int,int>,unordered_set<char>,PairHash> Boxes;
        int indexRow,indexCol;
        char currentChar;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                indexRow=i/3;
                indexCol=j/3;
                currentChar=board[i][j];
                
                if(currentChar=='.')continue;                if(Rows[i].contains(currentChar)||Cols[j].contains(currentChar)||Boxes[{indexRow,indexCol}].contains(currentChar))return false;
                else{
                    Rows[i].insert(currentChar);
                    Cols[j].insert(currentChar);
                    Boxes[{indexRow,indexCol}].insert(currentChar);
                }
            }
        }
        return true;
    }
};
