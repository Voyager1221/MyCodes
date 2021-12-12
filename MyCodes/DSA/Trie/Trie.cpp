#include <iostream>

using namespace std;

//Using struct for defining node
//We can also create class for defining the node of a Trie; 
struct Node{
    Node * links[26];
    bool flag = false;

    //Checks if 
    bool containsKey(char ch){
        return links[ch - 'a'] != NULL;
    }

    //Creating a reference to a character in particular Trie-Node.
    void put(char ch, Node * node){
        links[ch - 'a'] = node;
    }

    //Returning the address of Trie-Node that is referenced by an alphabet.
    Node * get(char ch){
        return links[ch - 'a'];
    }

    //To mark completion of a word during insertion.
    void setEnd(){
        flag = true;
    }

    //To check if the word is complete or not.
    bool isEnd(){
        return flag;
    }
};

class Trie{
private:
    Node * root;

public:
    Trie(){
        root = new Node();
    }

    void insert(string word);
    bool search(string word);
    bool startsWith(string prefix);

};

    void Trie::insert(string word){
        Node *node = root;
        for(int i=0; i<word.length(); i++){
            if(!node->containsKey(word[i])){
                node->put(word[i], new Node());            
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    bool Trie::search(string word){
        Node *node = root;
        for(int i=0; i<word.length(); i++){
            if(!node->containsKey(word[i])){
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isEnd();
    }

    bool Trie::startsWith(string prefix){
        Node *node = root;
        for(int i=0; i<prefix.length(); i++){
            if(!node->containsKey(prefix[i])){
                return false;
            }
            node = node->get(prefix[i]);
        }
        return true;
    }
int main(){
    Trie obj1;
    obj1.insert("Hello");
    obj1.insert("World");
    cout<<obj1.search("Hello")<<endl;
    cout<<obj1.search("Hell")<<endl;
    cout<<obj1.startsWith("He")<<endl;
    cout<<obj1.startsWith("Wor")<<endl;
    cout<<obj1.startsWith("Or")<<endl;
    return 0;
}