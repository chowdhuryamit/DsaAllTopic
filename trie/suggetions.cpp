#include<bits/stdc++.h>
using namespace std;

class TrieNode{
   public:
     char val;
     unordered_map<char,TrieNode*>children;
     bool isTerminal;
    TrieNode(char ch){
        this->val=ch;
        this->isTerminal=false;
    } 
};

void insertTrie(TrieNode* root,string word){
    if(word.size()==0){
      root->isTerminal=true;
      return;
    }
   char ch=word[0];
   TrieNode* child;
   if(root->children.find(ch)!=root->children.end()){
     child=root->children[ch];
   }
   else{
     child=new TrieNode(ch);
     root->children[ch]=child;
   }
   insertTrie(child,word.substr(1));
}

void getAns(TrieNode* root,vector<string>&ans,string&temp){
    if(root->isTerminal){
        ans.push_back(temp);
    }

    for(auto i:root->children){
        char ch=i.first;
        TrieNode* child=i.second;
        temp+=ch;
        getAns(child,ans,temp);
        temp.pop_back();
    }
}

void getSuggestion(TrieNode* root,string prefix,vector<string>& ans){
   if(prefix.size()==0){
     string temp="";
     getAns(root,ans,temp);
     return;
   }
   char ch=prefix[0];
   TrieNode* child;
   if(root->children.find(ch)!=root->children.end()){
    child=root->children[ch];
   }
   else{
     return;
   }
   getSuggestion(child,prefix.substr(1),ans);
}

vector<vector<string>> getmultiSuggestion(TrieNode* root, string prefix){
    string s="";
    vector<vector<string>>ans;
    for (int i = 0; i < prefix.size(); i++)
    {
        vector<string>st;
        s+=prefix[i];
        getSuggestion(root,s,st);
        for (int i = 0; i < st.size(); i++)
        {
            string temp=st[i];
            st[i]=s+temp;
        }
        ans.push_back(st);
    }
    return ans;
}

int main(){
    TrieNode* root=new TrieNode('-');
    insertTrie(root,"babbar");
    insertTrie(root,"bob");
    insertTrie(root,"amit");
    insertTrie(root,"baby");
    insertTrie(root,"babu");
    insertTrie(root,"ball");
    insertTrie(root,"babai");

    string prefix="bal";
    // vector<string>ans;
    // getSuggestion(root,prefix,ans);

    // for (int i = 0; i < ans.size(); i++)
    // {
    //     cout<<prefix+ans[i]<<endl;
    // }

    vector<vector<string>>ans =getmultiSuggestion(root,prefix);
    for (int  i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    
    


    return 0;
}