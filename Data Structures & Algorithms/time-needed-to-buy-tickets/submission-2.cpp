class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int neededTime=0,n=tickets[k];

        for(int i=0;i<tickets.size();i++){
            if(i<k){
                neededTime+= min(tickets[i],n);
            }else if(i>k){
                neededTime+= min (tickets[i],n-1);
            }
        }
        return neededTime+n;
    }
};