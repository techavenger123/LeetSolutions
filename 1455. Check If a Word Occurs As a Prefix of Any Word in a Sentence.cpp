class Solution {
public:
    vector<int> lps;
    void preKMP(const string& pattern){
        int len=0;
        const int n=pattern.size();
        lps.assign(n, 0);
        for(int i=1; i<n; i++){
            while(len>0 && pattern[i]!=pattern[len])
                len=lps[len-1];
            lps[i]=(pattern[i]==pattern[len])?++len:len;
        }
    }
    int KMPfind(const string& s, const string& pattern){
        preKMP(pattern);
        const int sz=s.size(), pz=pattern.size();
        for(int i=0, j=0; i<sz; i++){
            while(j!=0 && s[i]!=pattern[j]) 
                j=lps[j-1];
            if (s[i]==pattern[j]) j++;
            if (j==pz) return i-j+1;// the index found
        }
        return -1;// no found
    }
    int isPrefixOfWord(string& sentence, string& searchWord) {
        string s=" "+sentence, t=" "+searchWord;
        int n=s.size();
        int m=KMPfind(s, t);
        if (m==-1) return -1;
        return 1+count(s.begin(), s.begin()+m, ' ');
    }
};
