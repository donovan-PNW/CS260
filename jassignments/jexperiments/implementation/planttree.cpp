#include "planttree.h"
#include "plant.h"
#include <iostream>

using namespace std;


planttree::planttree()
{
    root = nullptr;
    nextNode = nullptr;
}

planttree::planttree(planttree& otherTree)
{
    //setRoot(otherTree.root->individual);
    copyHelper(root, otherTree.root);
}

void planttree::copyHelper(treenode*& inNode, treenode*& copyFrom)
{
    if(copyFrom == nullptr)
    {
        inNode = nullptr;
    }
    else
    {
        inNode = new treenode;
        inNode->individual = copyFrom->individual;
        copyHelper(inNode->left, copyFrom->left);
        copyHelper(inNode->right, copyFrom->right);
    }


}

planttree::~planttree()
{
    destroyDex(root);
}

void planttree::destroyDex(treenode* inNode)
{
    if(inNode != nullptr)
    {
        destroyDex(inNode->left);
        destroyDex(inNode->right);
        delete inNode;
        inNode = nullptr;
    }
}

void planttree::display() const
{
    planttree::subDisplay(root, 0);
}

void planttree::subDisplay(treenode* inNode, int depth) const
{
    for(int i = 1; i < depth; i++)
    {
        cout << "  ";
    }
    std::cout << inNode->individual;
    cout << endl;
    if(inNode->left != nullptr)
    {
        cout << "  ";
        subDisplay(inNode->left, ++depth);
    }
    if(inNode->right != nullptr)
    {
        cout << "  ";
        subDisplay(inNode->right, depth);
    }
}

treenode* planttree::sikh(plant& target, treenode* current)
{
    treenode* temporary = nullptr;
    if(current == nullptr)
    {
        return nullptr;
    }
    else if(target == current->individual)
    {
        return current;
    }
    else
    {
        temporary = sikh(target, current->left);
        if(temporary != nullptr)
            return temporary;
        else
        {
            return sikh(target, current->right);
        }
    }
}






void planttree::addChildren(plant& parentPlant, plant& leftPlant, plant& rightPlant)
{
    treenode* current;
    current = sikh(parentPlant, root);
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

plant* planttree::findBestGrowth()
{
    treenode* tempPlant = nullptr;
    tempPlant = subFBG(root, 0);
    //I really have no idea why I needed to do this to get it
    //to return a pointer. Compiler kept spitting out an error
    //about converting from plant to plant* on return/assignment/everything else
    //but also wouldn't accept a reference or a pointer.
    plant* address = tempPlant->individual.getPlantPointer();
    return address;
    
}

treenode* planttree::subFBG(treenode* current, int top)
{
    int newTop = 0;
    bool leftOrRightBigger = false;
    treenode* temporaryLeft = nullptr;
    treenode* temporaryRight = nullptr;
    if(current == nullptr)
    {
        return nullptr;
    }
    else if(current->individual.getGrowth() > top)
    {
        top = current->individual.getGrowth();
        temporaryLeft = subFBG(current->left, newTop);
        if((temporaryLeft) && temporaryLeft->individual.getGrowth() > current->individual.getGrowth())
        {
            leftOrRightBigger = true;
        }
        temporaryRight = subFBG(current->right, newTop);
        if((temporaryRight) && temporaryRight->individual.getGrowth() > current->individual.getGrowth())
        {
            leftOrRightBigger = true;
        }
        if(leftOrRightBigger)
        {
            if(temporaryLeft->individual.getGrowth() >= temporaryRight ->individual.getGrowth())
            {
                return temporaryLeft;
            }
            else
                return temporaryRight;
        }
    }
        return current;
}


plant* planttree::findBestNutrition()
{
    treenode* tempPlant = nullptr;
    tempPlant = subFBN(root, 0);
    plant* address = tempPlant->individual.getPlantPointer();
    return address;
    
}

treenode* planttree::subFBN(treenode* current, int top)
{
    int newTop = 0;
    bool leftOrRightBigger = false;
    treenode* temporaryLeft = nullptr;
    treenode* temporaryRight = nullptr;
    if(current == nullptr)
    {
        return nullptr;
    }
    else if(current->individual.getNutrition() > top)
    {
        top = current->individual.getNutrition();
        temporaryLeft = subFBN(current->left, newTop);
        if((temporaryLeft) && temporaryLeft->individual.getNutrition() > current->individual.getNutrition())
        {
            leftOrRightBigger = true;
        }
        temporaryRight = subFBN(current->right, newTop);
        if((temporaryRight) && temporaryRight->individual.getNutrition() > current->individual.getNutrition())
        {
            leftOrRightBigger = true;
        }
        if(leftOrRightBigger)
        {
            if(temporaryLeft->individual.getNutrition() >= temporaryRight ->individual.getNutrition())
            {
                return temporaryLeft;
            }
            else
                return temporaryRight;
        }
    }
    return current;
}

plant* planttree::findBestWater()
{
    treenode* tempPlant = nullptr;
    tempPlant = subFBW(root, 0);
    plant* address = tempPlant->individual.getPlantPointer();
    return address;
    
}

treenode* planttree::subFBW(treenode* current, int top)
{
    int newTop = 0;
    bool leftOrRightBigger = false;
    treenode* temporaryLeft = nullptr;
    treenode* temporaryRight = nullptr;
    if(current == nullptr)
    {
        return nullptr;
    }
    else if(current->individual.getWater() > top)
    {
        top = current->individual.getWater();
        temporaryLeft = subFBW(current->left, newTop);
        if((temporaryLeft) && temporaryLeft->individual.getWater() > current->individual.getWater())
        {
            leftOrRightBigger = true;
        }
        temporaryRight = subFBW(current->right, newTop);
        if((temporaryRight) && temporaryRight->individual.getWater() > current->individual.getWater())
        {
            leftOrRightBigger = true;
        }
        if(leftOrRightBigger)
        {
            if(temporaryLeft->individual.getWater() >= temporaryRight ->individual.getWater())
            {
                return temporaryLeft;
            }
            else
                return temporaryRight;
        }
    }
    return current;
}












