#ifndef PLANTTREE_H
#define PLANTTREE_H
#include "plant.h"
#include <iostream>
#include "treenode.h" 

using namespace std;

class planttree
{
    private:
        treenode* root;
        treenode* nextNode = nullptr;

    public:
        planttree();
        planttree(const planttree& otherTree);
        const planttree& operator=(const planttree& otherTree);
        ~planttree();

        void display() const;
        void subDisplay(treenode* inNode, int depth) const;
        treenode* seek(plant& target, treenode* current);
        treenode* sikh(plant& target, treenode* current);
        void addChildren(plant& parentPlant, plant& leftPlant, plant& rightPlant);
        void setRoot(plant& startingPlant);
        plant* findBestGrowth();
        treenode* subFBG(treenode* current, int top);
        plant* findBestNutrition();
        treenode* subFBN(treenode* current, int top);
        plant* findBestWater();
        treenode* subFBW(treenode* current, int top);
        int theGreatest(const char& type, int& top, treenode* inNode);

};





//struct treenode
//{
//    plant individual;
//    treenode *left = nullptr;
//    treenode *right = nullptr;
//    //treenode(const plant& nextIndividual):
//    //    individual(nextIndividual), left(0), right(0)
//    //{
//    // 
//    //}
//};

























#endif
