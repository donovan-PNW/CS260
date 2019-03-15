#include "planttree.h"
#include "plant.h"
#include <iostream>

using namespace std;


planttree::planttree()
{
    root = nullptr;
    displayTicker = nullptr;
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
    //std::cout << root->individual.getPlantID();
}

void planttree::subDisplay(treenode* inNode) const
{
    
}


//current is set at root for first iteration!
treenode* planttree::seek(plant& target, treenode* current) const
{
    std::cout << "rootalicious! " << endl;
    std::cout << "AAAAAAAAA" << root->individual.getPlantID() << "BBBBBB" << target.getPlantID();
    std::cout << "target: " << target.getPlantID() << endl;
    std::cout << "current: " << current->individual.getPlantID() << endl;
    //if((current == nullptr) || (target.getPlantID() == current->individual.getPlantID()))
    if((current == nullptr) || (strcmp(target.getPlantID(), current->individual.getPlantID()) == 0))
    {
        if(strcmp(target.getPlantID(), current->individual.getPlantID()) == 0)
        {
            cout << "FUCK YES!" << endl;
            return current;
        }
        seek(target, current->left);
        seek(target, current->right);
    }
    std::cout << "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz" << endl;
    return current;
    //std::cout << "screwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww" << endl;
    //if((target.getPlantID() == current->individual.getPlantID()))
    //{
    //    std::cout << "jjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjj: " << current << endl;
    //    return current;
    //}
    //seek(target, current->left);
    //seek(target, current->right);
}

void planttree::addChildren(plant& parentPlant, plant& leftPlant, plant& rightPlant)
{
    std::cout << "rrrrrrrrrrrrrrrrrrrrrrrrrrrrrr" << endl;
    treenode* current;
    //broken!
    std::cout << "aaaaaaaaaaaaaaaaaaaaaaa" << endl;
    current = seek(parentPlant, root);
    std::cout << "bbbbbbbbbbbbbbbbbbB" << endl;
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














