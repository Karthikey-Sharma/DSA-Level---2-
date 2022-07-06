#include<bits/stdc++.h>
using namespace std;

unordered_map<string,string>parent;
unordered_map<string,int>ranker;

string find(string x) {
    if(parent[x] == x){
        return x;
    }else {
        parent[x] = find(parent[x]);
        return parent[x];
    }
}
void Union(string xl , string yl){
    if(ranker[xl] < ranker[yl]){
        parent[xl] = yl;
    }else if(ranker[yl] < ranker[xl]){
        parent[yl] = xl;
    }else {
        parent[xl] = yl;
        ranker[yl]++;
    }
}
bool areSentencesSimilarTwo(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>&pairs){
    for(vector<string> pair : pairs){
        parent[pair[0]] = pair[0];
        parent[pair[1]] = pair[1];
        ranker[pair[0]] = 0;
        ranker[pair[1]] = 0;
    }
    for(vector<string> pair : pairs){
        string w1 = pair[0];
        string w2 = pair[1];

        string w1lead = find(w1);
        string w2lead = find(w2);
        if(w1lead != w2lead) {
            Union(w1lead , w2lead);
        }
    }

    for(int i = 0 ; i < sentence1.size() ; i++){
        string word1 = sentence1[i];
        string word2 = sentence2[i];
        if(word1 == word2){
            continue;
        }else if(parent.find(word1) == parent.end() || parent.find(word2) == parent.end()){
            return false;
        }
        string w1l = find(word1);
        string w2l = find(word2);
        if(w1l != w2l){
            return false;
        }
    }
    return true;
}

int main(){
    int n,m;
    cin>>n;
    
    vector<string> sentence1;
    vector<string>sentence2;
    for(int i=0;i<n;i++){
        string x;
        cin>>x;
        sentence1.push_back(x);
    }
    
    for(int i=0;i<n;i++){
        string x;
        cin>>x;
        sentence2.push_back(x);
    }
    cin>>m;
    vector<vector<string>>pairs(m,vector<string>(2));
    
    for(int i=0;i<m;i++){
        cin>>pairs[i][0];
        cin>>pairs[i][1];
    }
    
    
    if(areSentencesSimilarTwo(sentence1, sentence2, pairs))
        cout<<"true";
    else cout<<"false";
}
