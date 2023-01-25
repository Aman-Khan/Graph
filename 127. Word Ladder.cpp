    bool changeable(string a, string b){
        int sz = a.length();
        int cnt=0;
        for(int i=0; i<sz; i++){
            if(a[i]!=b[i]) cnt++;
            if(cnt>1) return false;
        }
        return true;
    }
    void adj(vector<string>& wordList, map<string, vector<string>>& conMap, string beginWord){
        for(int i=0; i<wordList.size(); i++){
            for(int j=i+1; j<wordList.size(); j++){
                if(changeable(wordList[i], wordList[j])){
                    conMap[wordList[i]].push_back(wordList[j]);
                    conMap[wordList[j]].push_back(wordList[i]);
                }
            }
        }
        for(int i=0; i<wordList.size(); i++){
            if(beginWord!=wordList[i] && changeable(beginWord, wordList[i])){
                conMap[wordList[i]].push_back(beginWord);
                conMap[beginWord].push_back(wordList[i]);
            }
        }
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        map<string, vector<string>> conMap;
        adj(wordList, conMap, beginWord);
        set<string> sSet;

        for(auto i:wordList){
            sSet.insert(i);
        }

        if(sSet.find(beginWord)!=sSet.end()){
            sSet.erase(sSet.find(beginWord));
        }
        
        queue<pair<string, int>> q;
        q.push({beginWord, 0});
        
        while(!q.empty()){
            string s = q.front().first;
            int lvl = q.front().second;
            q.pop();
            if(s==endWord) return lvl+1;
            for(auto i:conMap[s]){
                if(sSet.find(i)!=sSet.end()){
                    q.push({i, lvl+1});
                    sSet.erase(sSet.find(i));
                }   
            }
        }
        return 0;
    }
