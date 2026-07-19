class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> unique_mail;
        string buffer;
        
        for(auto email : emails){
            buffer.clear();
            int i=0;
            for(;i<email.size();i++){
                if(email[i]=='@')break;
                if(email[i]=='.')continue;
                if(email[i]=='+'){
                    while(email[i]!='@'){
                        i++;
                    }
                    break;
                }
                buffer.push_back(email[i]);
            }

            buffer.append(email,i,email.size()-i);

            unique_mail.insert(buffer);
        }

        return unique_mail.size();
    }
};