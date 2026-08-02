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
    unordered_map<Node*, Node*> mp;

    Node* Solve(Node* node){
        Node* newNode = new Node(node -> val);
        mp[node] = newNode; 
        for(auto nd : node -> neighbors){
            if(mp.find(nd) == mp.end()){
                (newNode-> neighbors).push_back(Solve(nd));
            }
            else{
                (newNode-> neighbors).push_back(mp[nd]);
            }
        }
        return newNode;

    }
    Node* cloneGraph(Node* node) {


        if(node == nullptr){
            return nullptr;
        }


        return Solve(node);

    }
};
