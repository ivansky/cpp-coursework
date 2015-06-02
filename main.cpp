#include "main.h"

int main(){

    setlocale(LC_ALL, "ru_RU.UTF-8");
    setlocale(LC_ALL, "Russian");
    setlocale(LC_CTYPE, "Russian");

    auto c = new Controller("Курсовая работа (c) Мартьянов Иван, Б03-191-1з");

    c->Listen();

    return 0;
};