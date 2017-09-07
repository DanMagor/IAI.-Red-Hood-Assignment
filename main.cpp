#include <iostream>
#include "Environment.h"
#include "RedHood.h"
#include "Granny.h"

int main() {

    Environment environment;
    environment.UpdateUnitsPositions();
    environment.PrintCell();

    Granny granny("Granny");
    RedHood redHood("RedHood");
    environment.AddUnit(redHood);
    environment.AddUnit(granny);
    unsigned int a,b;
    cin>>a;
    cin>>b;
    granny.SetPosition(a-1,b-1);
    cin>>a;
    cin>>b;
    redHood.SetPosition(a-1,b-1);
    cout<<endl<<endl<<endl;
    environment.UpdateUnitsPositions();
    environment.PrintCell();
    return 0;
}