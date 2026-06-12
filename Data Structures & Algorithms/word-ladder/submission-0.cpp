class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,int>m,vis;
        for(auto i: wordList) m[i]++;
        int len = beginWord.length();
        //from begin word, let's keep on traversing each letter by replacing one letter each time with one of 26...
        queue<pair<string,int>>q;
        q.push({beginWord,0});
        vis[beginWord]=1;

        while(!q.empty()) {
            pair<string,int>fro = q.front();
            q.pop();
            string curr = fro.first; int moves = fro.second;

            if(curr==endWord) return moves+1;

            for(int i=0; i<len; i++) {
                for(char c='a'; c<='z'; c++) {
                    string dup = curr;
                    dup[i]=c;

                    if(!vis[dup] && m[dup]) {
                        vis[dup]=1;
                        q.push({dup,moves+1});
                    }
                }
            }
        }
        return 0;
    }
};
