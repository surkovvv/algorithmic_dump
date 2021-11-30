#include <iostream>
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
    Node* cloneGraph(Node* node) {
        if (!node)
            return node;
        if (!hash[node]){
            hash[node] = new Node(node->val);
            for (auto x : node->neighbors)
                hash[node]->neighbors.push_back(cloneGraph(x));
        }
        return hash[node];
    }
private:
    unordered_map<Node*, Node*> hash;
};

int main() {
    Node* first = new Node(1),
    *second = new Node(2),
    *third = new Node(3);
    first->neighbors = {third};
    third->neighbors = {first, second};
    second->neighbors = {third};
    Node* copy;
    Solution solution;
    copy = solution.cloneGraph(first);
    return 0;
}
