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
    planttree::subDisplay(root);
    //std::cout << root->individual.getPlantID();
}

void planttree::subDisplay(treenode* inNode) const
{
    std::cout << "subDisplay start" << endl;
    std::cout << inNode->individual;
    std::cout << "subdisplay fart" << endl;
    if(inNode->left != nullptr)
    {
        subDisplay(inNode->left);
    }
    if(inNode->right != nullptr)
    {
        subDisplay(inNode->right);
    }
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














