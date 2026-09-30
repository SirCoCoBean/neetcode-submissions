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
    unordered_map<Node*, Node*> copies;

    Node* dfs(Node* node) {
        if(copies.find(node) != copies.end()) { // if it already exist, just return itself
            return copies[node];
        }
        // make new copies then insert into map
        Node* copy = new Node(node->val);
        copies[node] = copy;

        for (auto neighbor : node->neighbors) {
            Node* clonedNeighbor = dfs(neighbor);

            copy->neighbors.push_back(clonedNeighbor); //recreating original graph edges
        }

        return copy;

    }
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }

        return dfs(node);
    }
};
