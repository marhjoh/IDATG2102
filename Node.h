#ifndef NODE_H
#define NODE_H

struct Node {
    int ID;
    Node* left;
    Node* right;
    Node* prev_left;
    Node* next_right;
    Node (int id, Node* left, Node* right) //Constructor:
    {ID = id; left = left; right = right;}
};

Node* root = nullptr;
Node* z = new Node{0, NULL, NULL}; // z-node (ID = 0)

#endif // NODE_H
