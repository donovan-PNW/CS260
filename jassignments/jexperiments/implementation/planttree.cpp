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

void planttree::display()
{
}

//current is set at root for first iteration!
const treenode* planttree::seek(plant& target, treenode* current)
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
    //seek(parentPlant, root);

}

void planttree::setRoot(plant& startingPlant)
{
    root = new treenode;
    root->individual = startingPlant;
    root->left = nullptr;
    root->right = nullptr;
}

const plant* planttree::findBestGrowth()
{
}

const plant* planttree::findBestNutrition()
{
}

const plant* planttree::findBestWater()
{
}














