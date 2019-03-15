#include "planttree.h"
#include "plant.h"
#include <iostream>

using namespace std;


planttree::planttree()
{
    root = nullptr;
}

planttree::planttree(const planttree& otherTree)
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
    std::cout << "display()" << endl;
    std::cout << root->individual.getPlantID();
}

//current is set at root for first iteration!
treenode* planttree::seek(plant& target, treenode* current) const
{
    std::cout << "target: " << target.getPlantID() << endl;
    std::cout << "current: " << current->individual.getPlantID() << endl;
    //if((current == nullptr) || (target.getPlantID() == current->individual.getPlantID()))
    if((target.getPlantID() == current->individual.getPlantID()))
    {
        std::cout << "IN: " << current << endl;
        return current;
    }
    seek(target, current->left);
    seek(target, current->right);
}

void planttree::addChildren(plant& parentPlant, plant& leftPlant, plant& rightPlant)
{
    treenode* current;
    //broken!
    current = seek(parentPlant, root);
    current->left = new treenode;
    current->left->individual = leftPlant;
    current->right = new treenode;
    current->right->individual = rightPlant;
}

void planttree::setRoot(plant& startingPlant)
{
    std::cout << "setroot " << endl;
    root = new treenode;
    //root->individual(startingPlant);
    root->individual = startingPlant;
    std::cout << "inStart: " << startingPlant << endl;
    std::cout << "ROOTINDIE" << root->individual << endl;
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














