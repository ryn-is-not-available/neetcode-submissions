class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count=0,age;
        for(int i=0;i<details.size();i++){
            age= stoi(details[i].substr(11,2));
            if(age>60)count++;
        }
        return count;
    }
};