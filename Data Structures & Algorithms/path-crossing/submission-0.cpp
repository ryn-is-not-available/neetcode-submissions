class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_set<string> visited;
        int currentX=0,currentY=0;
        visited.insert(to_string(currentX)+"|"+to_string(currentY));
        for(int i=0;i<path.size();i++){
            switch(path[i]){
                case 'N': 
                    currentY++;
                    break;
                case 'E':
                    currentX++;
                    break;
                case 'S':
                    currentY--;
                    break;
                case 'W':
                    currentX--;
                    break;
            }
            string s= to_string(currentX)+"|"+to_string(currentY);
            if(visited.contains(s))return true;
            visited.insert(s);
        }
        return false;
    }
};