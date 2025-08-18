#include<bits/stdc++.h>
using namespace std;

class TrieNode{
   public:
     char val;
     unordered_map<int,TrieNode*>children;
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
   if(root->children.find(ch-'a')!=root->children.end()){
     child=root->children[ch-'a'];
   }
   else{
     child=new TrieNode(ch); 
     root->children[ch-'a']=child;
   }
   insertTrie(child,word.substr(1));
}

bool search(TrieNode* root,string word){
   if(word.size()==0){
     return root->isTerminal;
   } 
  char ch=word[0];
  TrieNode* child;
  if(root->children.find(ch-'a')!=root->children.end()){
    child=root->children[ch-'a'];
  }
  else{
    return false;
  }
  return search(child,word.substr(1));
}

void deleteWord(TrieNode* root,string word){
  if(word.size()==0){
     root->isTerminal=false;
     return;
   } 
  char ch=word[0];
  TrieNode* child;
  if(root->children.find(ch-'a')!=root->children.end()){
    child=root->children[ch-'a'];
  }
  else{
    return;
  }
  deleteWord(child,word.substr(1));
}


int main(){
   TrieNode* root=new TrieNode('-');
   insertTrie(root,"amit");
   insertTrie(root,"ami");
   insertTrie(root,"sudip");
   insertTrie(root,"sukumar");
   insertTrie(root,"hritam");
   insertTrie(root,"pritam");
   insertTrie(root,"hridoy");

   cout<<search(root,"ami")<<endl;
   deleteWord(root,"ami");
   cout<<search(root,"ami")<<endl;
    return 0;
}