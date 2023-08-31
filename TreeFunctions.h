#ifndef TREEFUNCTIONS_H
#define TREEFUNCTIONS_H

#include "Node.h"

class TreeFunctions {
public:
    static void writeEveryOtherLeafNode(Node* node);
    static int countBigger(Node* node, int value);
    static bool greaterThanChildren(Node* node);
    static void isCompleteTree(Node* node);
};

#endif // TREEFUNCTIONS_H
