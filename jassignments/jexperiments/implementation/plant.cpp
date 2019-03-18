#include "plant.h"

using namespace std;

plant::plant(): plantID(nullptr), growth(0), nutrition(0), water(0)
{
}

plant::plant(const plant& otherPlant): plantID(nullptr), growth(otherPlant.growth), nutrition(otherPlant.nutrition),
    water(otherPlant.water)
{
    plantID = new char[strlen(otherPlant.plantID)+1];
    strcpy(plantID, otherPlant.plantID);
}

plant::plant(const char* newPlantID, int newGrowth, int newNutrition, int newWater):
    plantID(nullptr)
{
    plantID = new char[strlen(newPlantID)+1];
    strcpy(plantID, newPlantID);
    growth = newGrowth;
    nutrition = newNutrition;
    water = newWater;
}


plant::~plant()
{
    if(plantID)
        delete [] plantID;
}

void plant::setGrowth(int& value)
{
    growth = value;
}

void plant::setNutrition(int& value)
{
    nutrition = value;
}

void plant::setWater(int& value)
{
    water = value;
}

int plant::getGrowth() const
{
    return growth;
}

int plant::getNutrition() const
{
    return nutrition;
}

int plant::getWater() const
{
    return water;
}

plant* plant::getPlantPointer()
{
    return this;
}


const plant& plant::operator=(const plant& otherPlant)
{
    plantID = new char[strlen(otherPlant.plantID)+1];
    strcpy(plantID, otherPlant.plantID);
    growth = otherPlant.growth;
    nutrition = otherPlant.nutrition;
    water = otherPlant.water;
    return *this;
}
char* plant::getPlantID() const
{ 
    return plantID;
}



bool operator==(plant& plantA, plant& plantB)
{
    bool isEqual = false;
    if(strcmp(plantA.plantID, plantB.plantID) == 0)
    {
        isEqual = true;
    }
    return isEqual;
}

ostream& operator<<(ostream& out, const plant& thisPlant)
{
    out << "Plant ID: " << thisPlant.plantID;
    out << " (G: " << thisPlant.growth << " N: " << thisPlant.nutrition;
    out << " W: " << thisPlant.water << ")";// << endl;
    return out;
}






































