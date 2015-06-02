//
// Created by user on 02.06.15.
//

#include <iostream>
#include <string>
#include <vector>
#include "Items.h"

#ifndef COURSEWORK_CONTROLLER_H
#define COURSEWORK_CONTROLLER_H

using namespace std;

class Controller {
private:
	typedef void (Controller::*DynamicFunction)();

	vector<DynamicFunction> menuFunctions;

	vector<string> menuNames;

	Items *itemCollection;

	int status;
	string copyright;

	void SleepEnter();

public:
	Controller(string __copyright);
	Controller(const char *string);

	void Listen();
	void Register(string __name, DynamicFunction __function);

	void Invoke(int);
	void Clear();

	virtual void Menu();
	virtual void Exit();
	virtual void List();
	virtual void Add();
	virtual void Remove();
	virtual void File();
	virtual void Binary();
	virtual void Sort();

	bool isAccept(char* cond);
};


#endif //COURSEWORK_CONTROLLER_H
