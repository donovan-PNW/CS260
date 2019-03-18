#ifndef PLANT_H
#define PLANT_H

#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

class plant
{
    private:
        char* plantID;
        int growth;
        int nutrition;
        int water;

    public:
        plant();
        plant(const plant& otherPlant);
        plant(const char* newPlantID, int growth, int nutrition, int water);
        ~plant();


        void setGrowth(int& value);
        void setNutrition(int& value);
        void setWater(int& value);
        int getGrowth() const;
        int getNutrition() const;
        int getWater() const;
        char* getPlantID() const;
        plant* getPlantPointer();
        
        const plant& operator=(const plant& otherPlant);
        friend std::ostream& operator<<(std::ostream& out, const plant& thisPlant);
        friend bool operator==(plant& plantA, plant& plantB);
};



































#endif












