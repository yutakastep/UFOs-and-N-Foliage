#include <iostream>
#include <iomanip>
#include <ctime>
#include <queue>
#include <stack>

using namespace std;

pair<vector<Node*>, double> BFS(Node* root, unsigned maxChildren = 10) {
    clock_t start = clock(); // record the start time
    vector<Node*> children;
    queue<Node*> queue;
    int levelNum = 1;
    if (root == nullptr) return {children, 0}; // returns empty if root is empty
    queue.push(root);

    while (!queue.empty()) {
        int size = queue.size();
        vector<int> level;

        for (int i = 0; i < size; i++) {
            Node* node = queue.front();
            level.push_back(node->val);
            queue.pop();
            for (Node* child : node->children) {
                if (child != nullptr) {
                    queue.push(child);
                    if (children.size() < maxChildren) // collect up to maxChildren nodes to print out
                        children.push_back(child);
                }
            }
        }
        levelNum++;
    }
    clock_t end = clock(); // record the end time
    double elapsed = double(end - start) / CLOCKS_PER_SEC; // calculate elapsed time

    return {children, elapsed};
}

void dfsRecursion(Node* node, vector<Node*>& children, unsigned maxChildren) {
    if (node == nullptr) return;

    if (children.size() < maxChildren) children.push_back(node);

    for (Node* child : node->children) {
        dfsRecursion(child, children, maxChildren);
    }
}

pair<vector<Node*>, double> DFS(Node* root, unsigned maxChildren = 10) {
    clock_t start = clock(); // record the start time

    vector<Node*> children;
    dfsRecursion(root, children, maxChildren); // recursive DFS function

    clock_t end = clock(); // record the end time
    double elapsed = double(end - start) / CLOCKS_PER_SEC; // calculate elapsed time

    return {children, elapsed};
}

void printNodes(const vector<Node*>& nodes) {
    cout << "Children nodes: ";
    for (const Node* node : nodes) {
        cout << node->val << " ";
    }
    cout << endl;
}
