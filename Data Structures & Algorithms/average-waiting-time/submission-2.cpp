class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int currentTime=customers[0][0];
        double total=0,n=customers.size();
        for(auto customer:customers){
            if(currentTime>customer[0]){
                currentTime+=customer[1];
                total+= currentTime-customer[0];
            }
            else {
                total+=customer[1];
                currentTime= customer[0]+customer[1];
            }
        }
        return total/n;
    }
};