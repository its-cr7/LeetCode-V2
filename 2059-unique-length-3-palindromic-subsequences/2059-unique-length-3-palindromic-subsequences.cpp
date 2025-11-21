class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n=s.size();
        vector<int> first(26,-1), last(26,-1);
        int ans=0;
        for(int i=0;i<n;i++){
            int ch=s[i]-'a';

            if(first[ch]==-1) first[ch]=i;

            last[ch]=i;
        }

        for(int i=0;i<26;i++){
            int l=first[i];
            int r=last[i];
            if(l==-1 || l>=r){
            continue;
            }

            unordered_set<char>mid;
            for(int i=l+1;i<r;i++){
                mid.insert(s[i]);
            }
        ans+=mid.size();
        }
        return ans;
    }
};