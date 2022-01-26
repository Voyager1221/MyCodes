#include <iostream>

using namespace std;

struct Node{

    Node *links[26];
    bool flag = false;

    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }
    void put(char ch, Node *node){
        links[ch-'a'] = node;
    }

    Node* get(char ch){
        return links[ch-'a'];
    }

    void setEnd(){
        flag = true;
    }

    bool isEnd(){
        return flag;
    }
};

class Trie{
    private:
        Node * root;

    public:
        Trie(){
            root  = new Node();
        }

        void Insert(string word);
        bool Search(string word);
        bool StartsWith(string prefix);
};

void Trie::Insert(string word){
    Node *node = root;
    for(int i=0; i<word.length(); i++){
        if(!node->containsKey(word[i])){
            node->put(word[i], new Node());
        }
        node = node->get(word[i]);
    }
    node->setEnd();
}

bool Trie::Search(string word){
    Node *node = root;
    for(int i=0; i<word.length(); i++){
        if(!node->containsKey(word[i])){
            return false;
        }
        node = node->get(word[i]);
    }
    return node->isEnd();
}

bool Trie::StartsWith(string word){
    Node *node = root;
    for(int i=0; i<word.length(); i++){
        if(!node->containsKey(word[i])){
            return false;
        }
        node = node->get(word[i]);
    }
    return true;
}

int main(){
    Trie obj1;
    obj1.Insert("hello");
    obj1.Insert("world");
    cout<<obj1.Search("hello")<<endl;
    cout<<obj1.Search("hell")<<endl;
    cout<<obj1.StartsWith("he")<<endl;
    cout<<obj1.StartsWith("wor")<<endl;
    cout<<obj1.StartsWith("or")<<endl;
}