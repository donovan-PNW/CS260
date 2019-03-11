#include "plant.h"

using namespace std;

plant::plant(): plantID(nullptr), growth(0), nutrition(0), water(0)
{
}

plant::plant(plant& otherPlant): plantID(nullptr), growth(otherPlant.growth), nutrition(otherPlant.nutrition),
    water(otherPlant.water)
{
    plantID = new char[strlen(otherPlant.plantID)+1];
    strcpy(plantID, otherPlant.plantID);
}

plant::plant(const char* newPlantID, int newGrowth, int newNutrition, int newWater):
    plantID(nullptr)
{
    //
    //char* plantID = nullptr;
    //std:: cout << "innnnnnnnnnnnnnnnn: " << newPlantID << endl;
    //std::cout << "Length of in: " << strlen(newPlantID)+1;
    plantID = new char[strlen(newPlantID)+1];
    //std::cout << " " << plantID << "wwwwwwwwwww" << endl; 

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

const int plant::getGrowth()
{
    return growth;
}

const int plant::getNutrition()
{
    return nutrition;
}

const int plant::getWater()
{
    return water;
}


const plant& plant::operator=(const plant& otherPlant)
{
    growth = otherPlant.growth;
    nutrition = otherPlant.nutrition;
    water = otherPlant.water;
    return *this;
}

ostream& operator<<(ostream& out, const plant& thisPlant)
{
    out << "Plant ID: Plant " << thisPlant.plantID;
    out << " " << thisPlant.growth << "-";
    out << thisPlant.nutrition<< "-";
    out << thisPlant.water << " ";
    out << "(G: " << thisPlant.growth << " N: " << thisPlant.nutrition;
    out << " W: " << thisPlant.water << ")" << endl;
    out << "change whole plantIDPlant field to come from a string held completely in plant class" << endl;
    
    return out;
}






































