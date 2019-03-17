



//- plant -- This class represents a plant. Each plant has an ID as well as a
//  growth rate factor, nutritional value factor, and water requirement
//  factor. The plant class should have these data members. The plant ID follows
//  the format "Plant ??-??-??" where the first two digits are the growth value,
//  the second two are the nutritional value, and the third two are the water
//  requirements value.

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












