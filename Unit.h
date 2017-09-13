//
// Created by DanMagor on 03.09.2017.
//

#ifndef ASSIGNMENT1_UNIT_H
#define ASSIGNMENT1_UNIT_H

#include <vector>
#include <string>


using namespace std;

class Unit {
protected:
    string ID_;
    pair<int,int> position_; //the position of unit in environment
    char symbol_=' ';  //symbol for visualization
    int life_;
public:
    //Initialization
    Unit(string); //constructor with ID initialization
    Unit(pair<int,int>); //constructor with position initialization

    void SetID(string);

    //Unit information
    string GetID();
    char GetSymbol();

    pair<int,int> GetPosition();

    //Unit Behavior
    void SetPosition(pair<int,int>);
    void SetPosition(int,int);
    virtual void MakeAction();

    virtual bool CheckArea();
    virtual void Die();
    virtual void SetLife(int);
    virtual int GetLife();
    //Destructor
    ~Unit();
};


#endif //ASSIGNMENT1_UNIT_H
