#include <iostream>

using namespace std;

// Define a structure for a binary tree node
struct Node {
    int ID;         // Unique identifier for the node
    Node* left;     // Pointer to the left child node
    Node* right;    // Pointer to the right child node

    // Constructor to initialize the node
    Node(int id, Node* l, Node* r) { ID = id; left = l; right = r; }
};

Node* z = new Node(0, NULL, NULL);  // Initialize a sentinel node
Node* rot = z;                      // Initialize the root of the tree

// Function to calculate the height of a node with a given ID in the tree
int height(Node* p, int id) {
    int h = 0;
    while (p != z) {
        if (p->ID == id) return h;
        p = (id < p->ID) ? p->left : p->right;
        h++;
    }
    return -1;
}

// Function to calculate the distance between two nodes with IDs id1 and id2 in the tree
int distance(int id1, int id2) {
    Node* p = rot;
    int v_height, h_height;

    // Ensure id1 is smaller than id2
    if (id1 > id2) {
        int temp = id1;
        id1 = id2;
        id2 = temp;
    }

    while (p != z) {
        if (id2 < p->ID) p = p->left;
        else if (id1 > p->ID) p = p->right;
        else {
            v_height = height(p, id1);
            if (v_height == -1) return -1;
            h_height = height(p, id2);
            if (h_height == -1) return -1;
            return (v_height + h_height);
        }
    }
    return -1;
}

// Function to display the tree in an in-order traversal
void display(Node* p) {
    if (p != z) {
        display(p->left);
        cout << "\tID: " << p->ID << " (" << p->left->ID << ", " << p->right->ID << ")\n";
        display(p->right);
    }
}

int main() {
    // Create nodes to construct the binary tree
    Node* a = new Node(3, z, z);
    Node* b = new Node(12, z, z);
    Node* c = new Node(4, a, b);
    a = new Node(28, z, z);
    b = new Node(46, z, z);
    Node* d = new Node(33, a, b);
    rot = new Node(22, c, d);
    a->left = new Node(23, z, z);
    a->right = new Node(31, z, z);
    b->left = new Node(40, z, z);
    b->right = new Node(49, z, z);

    // Uncomment the following line to display the tree
    // display(rot);

    // Calculate and display distances between various node pairs
    cout << "\nDistance between 4 and 33: " << distance(4, 33);
    cout << "\nDistance between 3 and 12: " << distance(3, 12);
    cout << "\nDistance between 3 and 28: " << distance(3, 28);
    cout << "\nDistance between 23 and 49: " << distance(23, 49);
    cout << "\nDistance between 3 and 40: " << distance(3, 40);
    cout << "\nDistance between 23 and 28: " << distance(23, 28);
    cout << "\nDistance between 22 and 33: " << distance(22, 33);
    cout << "\nDistance between 28 and 28: " << distance(28, 28);
    cout << "\nDistance between 3 and 50: " << distance(3, 50);
    cout << "\nDistance between 3 and 32: " << distance(3, 32);
    cout << "\nDistance between 7 and 31: " << distance(7, 31);
    cout << "\n\n";
    return 0;
}
