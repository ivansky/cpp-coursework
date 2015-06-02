#ifndef COURSEWORK_ITEMS_H
#define COURSEWORK_ITEMS_H

#include <vector>
#include "Item.h"

class Items {
private:
    std::vector<Item*> list;
public:
    void clear();
    void addItem(Item* el);
    void printAll();
    void toFile(char filename[255]);
    void toFile(char filename[255], bool bin);
    void fromFile(char filename[255]);
    void fromFile(char filename[255], bool bin);
    void sortBy(const char* field);
};


#endif //COURSEWORK_ITEMS_H
