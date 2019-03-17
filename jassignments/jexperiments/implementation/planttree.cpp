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
    std::cout << "subdisplay end" << endl;
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
//treenode* planttree::seek(plant& target, treenode* current)
//{
//    std::cout << "AAAAAAAAAAAAAAAAAAAAAAAAAAAatarget: " << target.getPlantID() << endl;
//    std::cout << "BBBBBBBBBBBBBBBBBBBBBBBBBBBcurrent: " << current->individual.getPlantID() << endl;
//    if(current != nullptr)
//    {
//        if(strcmp(target.getPlantID(), current->individual.getPlantID()) == 0)
//        {
//            cout << "YES!" << endl;
//            std::cout << current->individual.getPlantID();
//            nextNode = current;
//            return current;
//        }
//    }
//    if(current->left)
//        seek(target, current->left);
//    if(current->right)
//        seek(target, current->right);
//    std::cout << "CCCCCCCCCCCCCCCCCCCCCCCCCCCCC: Last target: " << target.getPlantID() << endl;
//    return nullptr;
//}




treenode* planttree::sikh(plant& target, treenode* current)
{
    treenode* temporary = nullptr;
    if(current == nullptr)
    {
        return nullptr;
    }
    else if(target == current->individual)
    {
        std::cout << "THIS IS CURRENT: " << current->individual << endl;
        std::cout << "THIS IS TARGET " << target << endl;
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
    //broken!
    //current = seek(parentPlant, root);
    //current = nextNode;
    current = sikh(parentPlant, root);
    std::cout << current->individual << endl;
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
    cout << "jjjjjjjjjjjjjjjjjjjjjjjjj" << endl;
    tempPlant = subFBG(root, 0);
    plant* address = tempPlant->individual.getPlantPointer();
    //int thisVal = theGreatest('G', )
    cout << tempPlant->individual << endl; 
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
        cout << "nullptr end" << endl;
        return nullptr;
    }
    else if(current->individual.getGrowth() > top)
    {
        cout << "read current: " << endl;
        top = current->individual.getGrowth();
        cout << "read Left" << endl;
        temporaryLeft = subFBG(current->left, newTop);
        cout << "check These out: " << endl;
        if((temporaryLeft) && temporaryLeft->individual.getGrowth() > current->individual.getGrowth())
        {
            cout << "left is bigger " << endl;
            leftOrRightBigger = true;
        }
        cout << "read Right" << endl;
        temporaryRight = subFBG(current->right, newTop);
        if((temporaryRight) && temporaryRight->individual.getGrowth() > current->individual.getGrowth())
        {
            cout << "right is bigger " << endl;
            leftOrRightBigger = true;
        }
        if(leftOrRightBigger)
        {
            if(temporaryLeft->individual.getGrowth() >= temporaryRight ->individual.getGrowth())
            {
                std::cout << "returning left " << endl;
                return temporaryLeft;
            }
            else
                return temporaryRight;
        }
        else
            cout << "local is bigger " << endl;
            cout << "returning local" << endl;
            return current;
    }
}


//void planttree::display() const
//{
//    std::cout << "display()" << endl;
//    planttree::subDisplay(root);
//    //std::cout << root->individual.getPlantID();
//}
//
//void planttree::subDisplay(treenode* inNode) const
//{
//    std::cout << "subDisplay start" << endl;
//    std::cout << inNode->individual;
//    std::cout << "subdisplay end" << endl;
//    if(inNode->left != nullptr)
//    {
//        subDisplay(inNode->left);
//    }
//    if(inNode->right != nullptr)
//    {
//        subDisplay(inNode->right);
//    }
//}



plant* planttree::findBestNutrition() const
{
}

plant* planttree::findBestWater() const
{
}

//REDO THIS SO THAT EACH IS INDIVIDUAL IF PROGRAM IS SLOW
//int planttree::theGreatest(const char& type, int& top, treenode* inNode)
//{
//    int temporary = 0;
//    switch (type)
//    {
//    case 'G': 
//        temporary = inNode->individual.getGrowth();
//        break;
//    case 'N':
//        temporary = inNode->individual.getNutrition();
//        break;
//    case 'W':
//        temporary = inNode->individual.getWater();
//        break;
//    }
//    return temporary;
//    //just like the print statement except compare each instead of printing it
//}














