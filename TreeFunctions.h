#ifndef TREEFUNCTIONS_H
#define TREEFUNCTIONS_H

#include "Node.h"

class TreeFunctions {
public:
    static void writeEveryOtherLeafNode(Node* node);
    static int countBigger(Node* node, int value);
};

#endif // TREEFUNCTIONS_H
