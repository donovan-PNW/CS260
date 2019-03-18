#ifndef TREENODE_H
#define TREENODE_H

#include <iostream>
#include "plant.h"

using namespace std;


struct treenode
{
    plant individual;
    treenode *left = nullptr;
    treenode *right = nullptr;
};










































#endif
