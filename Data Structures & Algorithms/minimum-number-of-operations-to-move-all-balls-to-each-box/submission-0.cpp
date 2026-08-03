class Solution {
public:
    vector<int> minOperations(string boxes) {
        int left=0,right=0;
        vector<int> answer(boxes.size(),0);
        for(int i=0;i<boxes.size();i++){
            if(boxes[i]=='1'){
                answer[0]+=i;
                right++;
            };
        }
        for(int i=1;i<boxes.size();i++){
            if(boxes[i-1]=='1'){
                left++;
                right--;
            }
            answer[i]=answer[i-1]+left-right;
        }
        return answer;
    }
};