#ifndef NODE_H
#define NODE_H

struct Node {
    int ID;
    Node* left;
    Node* right;
    Node* prev_left;
    Node* next_right;
};

Node* root = nullptr;

#endif // NODE_H
