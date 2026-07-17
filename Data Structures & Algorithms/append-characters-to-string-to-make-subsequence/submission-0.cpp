class Solution {
public:
    int appendCharacters(string s, string t) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int m=t.size(),n=s.size();
        int ptr_s=0,ptr_t=0;
        while(ptr_s<n && ptr_t<m){
            if(t[ptr_t]==s[ptr_s])ptr_t++;
            ptr_s++;
        }
        return m-ptr_t;
    }
};