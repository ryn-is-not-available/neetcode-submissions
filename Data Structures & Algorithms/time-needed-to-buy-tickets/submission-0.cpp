class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int i=0,neededTime=0,n=tickets.size();
        while(tickets[k]){
            if(tickets[i]>0){
                tickets[i]--;
                neededTime++;
            }
            i++;
            i%=n;
        }
        return neededTime;
    }
};