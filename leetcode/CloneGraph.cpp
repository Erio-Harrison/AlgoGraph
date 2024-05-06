#include <vector>
#include <unordered_map>
using namespace std;
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


class Solution {
public:
    unordered_map<Node*,Node*> cloneNodes;
    Node* cloneNode(Node* node){
        if(cloneNodes.find(node) != cloneNodes.end()){
            return cloneNodes[node];
        }

        Node* clone = new Node(node -> val);
        cloneNodes[node] = clone;

        for(Node* neighbor : node -> neighbors){
            clone -> neighbors.push_back(cloneNode(neighbor));
        }
        return clone;
    }
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        return cloneNode(node);
    }
};