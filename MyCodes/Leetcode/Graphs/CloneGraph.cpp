/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        
        if(node!=nullptr){
            Node* newList = new Node;

            queue<Node*>q;
            vector<Node*>visited(101, nullptr);

            q.push(node);

            visited[node->val] = newList;
            newList->val = node->val;

            while(!q.empty()){
                Node* curr = q.front();
                q.pop();
                Node* duplicate = visited[curr->val];

                // cout<<duplicate->val<<": ";
                for(Node* capsule: curr->neighbors){
                    if(visited[capsule->val]==nullptr){

                        Node* newNode = new Node;
                        newNode->val = capsule->val;

                        visited[capsule->val] = newNode;

                        duplicate->neighbors.push_back(newNode);
                        newNode->neighbors.push_back(duplicate);

                        q.push(capsule);

                        // cout<<capsule->val<<" ";
                    }
                    else{
                        bool flag = false;
                        for(Node* itr:duplicate->neighbors){
                            if(itr->val==capsule->val){
                                flag =true;
                                break;
                            }
                        }
                        if(!flag){
                            duplicate->neighbors.push_back(visited[capsule->val]);
                            visited[capsule->val]->neighbors.push_back(duplicate);

                            // cout<<capsule->val<<" ";
                        }
                    }
                }
                // cout<<endl;
            }
            return newList;    
        }
        return node;
    }
};