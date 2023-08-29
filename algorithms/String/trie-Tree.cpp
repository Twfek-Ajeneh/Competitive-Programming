#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define inf (int)1e9

//TrieTree:
struct TrieTree{
    struct Node{
        char data; // change type of data
        int wordCount;
        int prefixCount;
        map<char , Node*> edge;

        Node(char a){
            this->data = a;
            this->wordCount = 0; 
            this->prefixCount = 0;
        }   
    };
    
    Node* base;
    
    TrieTree(vector<string> a){
        this->base = new Node('*');
        for (int i = 0; i < a.size(); i++)
            addWord(a[i]);
    }

    void addWord(string s){
        Node* cur = base;
        for (int i = 0; i < s.size(); i++)
        {
            if(cur->edge[s[i]]==NULL) cur->edge[s[i]] = new Node(s[i]);
            cur = cur->edge[s[i]];
            cur->prefixCount++;
        }
        cur->wordCount++;
    }

    // delete word count only not prefix count
    void deleteWord(string s){
        Node* cur = base;
        for (int i = 0; i < s.size(); i++){
            if(cur->edge[s[i]]==NULL) return;
            cur = cur->edge[s[i]];
        }
        if(cur->wordCount!=0) 
            cur->wordCount--;
    }

    // return count of word and prefix equal s
    //  word  prefix
    pair<int , int> countWord(string s){
        Node* cur = base;
        for (int i = 0; i < s.size(); i++)
        {
            if(cur->edge[s[i]]==NULL) return {0 , 0};
            cur = cur->edge[s[i]];
        }
        return make_pair(cur->wordCount , cur->prefixCount);
    }

    // return count of all prefix of s;
    int countPrefix(string s){
        Node* cur = base;
        int ans = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if(cur->edge[s[i]]==NULL) return 0;
            cur = cur->edge[s[i]];
            ans += cur->prefixCount;
        }
        return ans;
    }
};


//TrieTree (for delete case):
struct trieNode
{
    struct trieNode *child[2];
    int cnt;
    trieNode(){
        child[0] = child[1] = NULL;
        cnt = 0;
    }
} *Root;

trieNode *remove(trieNode *root, string key, int depth = 0)
{

    root->cnt--;
    if (depth == key.size()){
        if (root->cnt == 0){
            delete (root);
            root = NULL;
        }
        return root;
    }
    int index = key[depth] - '0';
    root->child[index] = remove(root->child[index], key, depth + 1);
    if (root->cnt == 0){
        delete (root);
        root = NULL;
    }
    return root;
}

void Add(string s)
{
    trieNode *Cur = Root;
    for (int i = 0; i < s.size(); i++)
    {
        int idx = s[i] - '0';
        if (!Cur->child[idx])
            Cur->child[idx] = new trieNode;
        Cur = Cur->child[idx];
        Cur->cnt++;
    }
}