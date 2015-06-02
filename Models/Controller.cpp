#include "Controller.h"
#include "../Helpers.h"

Controller::Controller(string __copyright){
	status = 0;

	copyright = __copyright;

	itemCollection = new Items();

	Register("Меню", &Controller::Menu);

	Register("Список продуктов", &Controller::List);
	Register("Добавить продукт", &Controller::Add);
	Register("Удалить продукт", &Controller::Remove);
	Register("Сохранить/Загрузить в/из файл(а)", &Controller::File);
	Register("Сохранить/Загрузить в/из BIN файл(а)", &Controller::Binary);
	Register("Сортировать", &Controller::Sort);

	Register("Выход", &Controller::Exit);
};

void Controller::Register(string __name, DynamicFunction __function){
	menuNames.push_back(__name);
	menuFunctions.push_back(__function);
}


void Controller::Invoke(int index){
	(this->*menuFunctions[index])();

	if(index != 0){
		printf("\n\nНажмите Enter, чтобы продолжить...\n");
		SleepEnter();
		Menu();
	}
};

void Controller::Listen(){
	int input = 0;

	do {

		Invoke(input);

		if(!status) cin >> input;

	}while(!status);
};

void Controller::SleepEnter() {
	char prev = 0;
	while(1){
		char c = (char) getchar();
		if(c == '\n' && c == prev)
			break;
		prev = c;
	}
}

void Controller::Menu(){
	const int menuSize = (const int)menuNames.size();

	Clear();

	printf("%s\n", copyright.c_str());

	for(int i = 0; i < menuSize; i++){
		printf("%d. %s\n", i, menuNames[i].c_str());
	}
};

void Controller::List(){
	printf("Список товаров:\n\n");
	itemCollection->printAll();
};

void Controller::Add(){
	Clear();

	Item *item = new Item;

	string tmp;

	printf("Добавление нового продукта в список:\n");

	printf("Введите название: ");

	cin >> tmp;

	if(tmp.length() > 149){
		tmp = tmp.substr(0, 149);
	}

	strcpy(item->name, tmp.c_str());

	printf("Введите цену (например 10.99): ");

	cin >> tmp;

	while(!Helpers::isFloatNumber(tmp)){

		printf("Ошибка! Введите целочисленное или дробное число: ");

		cin >> tmp;
	}

	item->price = stof(tmp);

	printf("Введите кол-во: ");

	cin >> tmp;

	while(!Helpers::isNumber(tmp)){

		printf("Ошибка! Введите целочисленное число: ");

		cin >> tmp;
	}

	item->count = (unsigned int)stoi(tmp);

	item->isCommercial = false;

	char isCommercial[10];

	printf("Это коммерческий продукт? (Да, Нет): ");

	cin >> tmp;

	if(isAccept((char *)tmp.c_str())){
		item->isCommercial = true;
	}

	itemCollection->addItem(item);

	printf("Добавлен новый продукт");
};

void Controller::Remove(){

};

void Controller::File(){

};

void Controller::Binary(){

};

void Controller::Sort(){
	Clear();

	printf("Выберите по какому полю сортировать:\n");
	printf("1. Наименованию товара\n");
	printf("2. Цене\n");
	printf("3. Количеству\n");
	printf("4. Коммерческий сектор\n");
	printf("\n");

	int fieldNumber;

	cin >> fieldNumber;

	switch(fieldNumber){
		case 4:
			itemCollection->sortBy("commercial");
			break;
		case 3:
			itemCollection->sortBy("count");
			break;
		case 2:
			itemCollection->sortBy("price");
			break;
		default:
			itemCollection->sortBy("name");
			break;
	}

	printf("В порядке убывания? (Да, Нет)\n");

};

bool Controller::isAccept(char* cond){
	unsigned int first = (unsigned int)cond[0];

	return (
		first == 89 || first == 121 ||
		first == -48 || first == -108 ||
		first == -60 || first == -28
	);
};

void Controller::Exit(){
	status = true;
};

void Controller::Clear(){
	#ifdef _WIN32
		std::system("cls");
	#else
		// Assume POSIX
		std::system("clear");
	#endif
}

Controller::Controller(const char *s) {
	Controller((string) s);
}
