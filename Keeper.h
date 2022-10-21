#pragma once
#include "lib.h"

class Keeper
{
private:
	int m_size = 0;
	Elem* head = NULL;
public:
	Keeper();
	Keeper(int size);
	~Keeper();

	Human* operator[] (int index);

	int get_size();
	void insert(Human* n_data); //добавление в массив перед индексом
	void remove(int index);
	void save(); //сохранить в файл
	void load(); //чтение из файла
};

