#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <fstream>
using namespace std;


class item
{
private:
    string name;
    int vida=0;
    int defensa=0;
    int velocidad=0;
public:
    item(string);
    void cualidad();
};

#endif // ITEM_H
