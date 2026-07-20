class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<string, char> wordToChar;
        unordered_map<char, string> charToWord;
        
        stringstream ss(s);
        string word;
        int j = 0;
        
        while (ss >> word) {
            if (j >= pattern.size()) return false;
            
            char c = pattern[j];
            
            if (wordToChar.contains(word) && wordToChar[word] != c) return false;
            if (charToWord.contains(c) && charToWord[c] != word) return false;
            
            wordToChar[word] = c;
            charToWord[c] = word;
            
            j++;
        }
        
        return j == pattern.size();
    }
};