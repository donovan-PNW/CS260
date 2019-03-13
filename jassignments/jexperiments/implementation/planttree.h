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

    public:
        planttree();
        planttree(planttree& otherTree);
        const planttree& operator=(const planttree& otherTree);
        ~planttree();

        void display();
        const treenode* seek(plant& target, treenode* current);
        void addChildren(plant& parentPlant, plant& leftPlant, plant& rightPlant);
        void setRoot(plant& startingPlant);
        const plant* findBestGrowth();
        const plant* findBestNutrition();
        const plant* findBestWater();

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
