#include "planttree.h"
#include "plant.h"
#include <iostream>

using namespace std;


planttree::planttree()
{
    root = nullptr;
    nextNode = nullptr;
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
treenode* planttree::seek(plant& target, treenode* current)
{
    std::cout << "AAAAAAAAAAAAAAAAAAAAAAAAAAAatarget: " << target.getPlantID() << endl;
    std::cout << "BBBBBBBBBBBBBBBBBBBBBBBBBBBcurrent: " << current->individual.getPlantID() << endl;
    if((current == nullptr) || (strcmp(target.getPlantID(), current->individual.getPlantID()) == 0))
    {
        if(strcmp(target.getPlantID(), current->individual.getPlantID()) == 0)
        {
            cout << "FUCK YES!" << endl;
            std::cout << current->individual.getPlantID();
            nextNode = current;
            return current;
        }
    }
    if(current->left)
        seek(target, current->left);
    if(current->right)
        seek(target, current->right);
    std::cout << "CCCCCCCCCCCCCCCCCCCCCCCCCCCCC: Last target: " << target.getPlantID() << endl;
    return current;
}

void planttree::addChildren(plant& parentPlant, plant& leftPlant, plant& rightPlant)
{
    treenode* current;
    //broken!
    current = seek(parentPlant, root);
    current = nextNode;
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














