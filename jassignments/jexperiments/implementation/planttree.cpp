#include "planttree.h"
#include "plant.h"
#include <iostream>

using namespace std;


planttree::planttree()
{
    root = nullptr;
}

planttree::planttree(planttree& otherTree)
{
    root = otherTree.root; 
}

planttree::~planttree()
{
}

const planttree& planttree::operator=(const planttree& otherTree)
{
}

void planttree::display() const
{
}

//current is set at root for first iteration!
treenode* planttree::seek(plant& target, treenode* current) const
{
    if((current == nullptr) || (target == current->individual))
    {
        return current;
    }
    seek(target, current->left);
    seek(target, current->right);
}

void planttree::addChildren(plant& parentPlant, plant& leftPlant, plant& rightPlant)
{
    treenode* current;
    current = seek(parentPlant, root);
    current->left = new treenode;
    current->left->individual = leftPlant;
    current->right = new treenode;
    current->right->individual = rightPlant;
}

void planttree::setRoot(plant& startingPlant)
{
    root = new treenode;
    root->individual = startingPlant;
    root->left = nullptr;
    root->right = nullptr;
}

plant* planttree::findBestGrowth() const
{
    
}

plant* planttree::findBestNutrition() const
{
}

plant* planttree::findBestWater() const
{
}














