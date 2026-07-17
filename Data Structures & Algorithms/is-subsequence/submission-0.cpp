class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m=s.size(),n=t.size();
        if(m>n) return false;
        int lastSeenPosition=0,cut;
        string_view search = string_view(t).substr(0,n);
        for(int i=0;i<m;i++){
            size_t pos = search.find(s[i]);
            if(pos == string::npos)return false;
            cut = pos+1+lastSeenPosition;
            search = string_view(t).substr(cut,n-cut);
            lastSeenPosition=cut;
        };
        return true;
    }
};