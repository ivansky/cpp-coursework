//
// Created by user on 02.06.15.
//

#include <iostream>
#include <fstream>
#include <unistd.h>
#include "Items.h"

using namespace std;

void Items::addItem(Item* el){
    list.push_back(el);
};

void Items::fromFile(char filename[255]){
    fromFile(filename, false);
};

void Items::fromFile(char filename[255], bool bin){
#ifdef _WIN32
	int accessFile = _access(filename, 04);
	#else
    int accessFile = access(filename, 3);
#endif

    if(accessFile){

    }else{
        printf("Файл с именем %s не найден\n", filename);
    }
};

void Items::toFile(char filename[255]){
    toFile(filename, false);
};

void Items::toFile(char filename[255], bool bin){

    const unsigned int size = (const unsigned int)list.size();

    ofstream fs;

    if(bin){

        fs.open("data.bin", std::ios::out | std::ios::binary);

        fs.write(reinterpret_cast<const char*>(&size), sizeof(unsigned int));

        for(unsigned int i = 0; i < size; i++){
            //printf("%d. %s\n", i, list[i]->name);

            fs.write((const char*)&list[i]->name, 150);
            fs.write(reinterpret_cast<const char*>(&list[i]->price),sizeof(float));
            fs.write(reinterpret_cast<const char*>(&list[i]->count),sizeof(unsigned int));
            fs.write(list[i]->isCommercial? "1" : "0", 1);

        }

    }else{

        fs.open("data.txt", std::ios::out);

        for(unsigned int i = 0; i < size; i++){

            fs << &list[i]->name;
            fs << "\t";
            fs << &list[i]->price;
            fs << "\t";
            fs << &list[i]->count;
            fs << "\t";
            fs << list[i]->isCommercial? 1 : 0;
            fs << "\n";

        }

    }

    fs.close();

    for(unsigned int i = 0; i < size; i++){
        printf("%d. %s\n", i, list[i]->name);
    }

};

void Items::sortBy(const char* field){

    if(field == "name")
        sort(list.begin(), list.end(),
             [](Item* a, Item* b) -> bool
             {
                 unsigned int i = 0;

                 //a < b == true

                 unsigned int charA;
                 unsigned int charB;

                 unsigned int sizeA = sizeof(a->name) / sizeof(char);
                 unsigned int sizeB = sizeof(b->name) / sizeof(char);

                 while(true){

                     charA = (int)a->name[i];
                     charB = (int)b->name[i];

                     if(charB == 0){
                         return false;
                     }

                     if(charA == 0 && charB > 0){
                         return true;
                     }

                     if(charA < charB){
                         return true;
                     }

                     if(charA > charB){
                         return false;
                     }

                     i++;

                     if(i > sizeA || i > sizeB) break;

                 }

                 return false;
             });

    if(field == "price")
        sort(list.begin(), list.end(),
             [](Item* a, Item* b) -> bool
             {
                 return (a->price < b->price);
             });

    if(field == "count")
        sort(list.begin(), list.end(),
             [](Item* a, Item* b) -> bool
             {
                 return (a->count < b->count);
             });

    if(field == "commercial")
        sort(list.begin(), list.end(),
             [](Item* a, Item* b) -> bool
             {
                 return (a->isCommercial < b->isCommercial);
             });

};

void Items::printAll(){

    clear();

    const unsigned int size = (const unsigned int)list.size();

    if(size > 0){

        printf("id\tname\tprice\tcnt\tcommercial\n");
        printf("----------------------------------------\n");

        for(unsigned int i = 0; i < size; i++){

            printf("%d\t%s\t%.2f\t%d\t%d\n", i+1, list[i]->name, list[i]->price, list[i]->count, list[i]->isCommercial? 1 : 0);

            //cout << i+1 << "\t" << list[i]->name << "\t" << list[i]->price << "\t" << list[i]->count << "\t" << (list[i]->isCommercial? 1 : 0) << endl;

        }

    }else{

        printf("Список пуст\n");

    }

    printf("\n");

};

void Items::clear(){
#ifdef _WIN32
		std::system("cls");
	#else
    // Assume POSIX
    std::system("clear");
#endif
};