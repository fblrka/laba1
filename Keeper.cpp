#pragma warning( disable : 6386 )
#pragma warning( disable : 26451 )
#include "lib.h"

using namespace std;

Keeper::Keeper() : m_size(0), head(nullptr) {}

Keeper::Keeper(int size) : head(nullptr) { this->m_size = size; }

Keeper::~Keeper()
{
	if (head != NULL)
	{
		Elem* buffer;
		while (head->next != NULL)
		{
			buffer = head;
			head = head->next;
			buffer->m_data->~Human();
			delete(buffer);
		}
		head->m_data->~Human();
		delete(head);
	}
}

Human* Keeper::operator[](const int index)
{
	if ((index >= m_size) || index < 0)
	{
		throw "Incorrect index!";
	}
	else
	{
		Elem* buffer = head;
		for (int i = 0; i < m_size - index - 1; i++)
		{
			buffer = buffer->next;
		}
		return (buffer->m_data);
	}
}

int Keeper::get_size() { return m_size; }

void Keeper::insert(Human* new_data)
{
	Elem* tmp;
	tmp = new Elem;
	if (m_size == 0)
	{
		tmp->m_data = new_data;
		tmp->next = 0;
		++m_size;
	}
	else
	{
		tmp->m_data = new_data;
		tmp->next = head;
		++m_size;
	}
	head = tmp;
}

void Keeper::remove(int index)
{
	//if (m_size == 0 || head == NULL)
	//{
	//	throw "Nothing to delete!";
	//	system("pause");
	//}
	//int counter = 0;
	//while (counter < index - 1)
	//{
	//	head = head->next;
	//	counter++;
	//}

	///*Elem* prev = head;
	//prev->next->m_data->~Human();
	//prev->next->next;
	//delete(prev->next);
	//--m_size;*/
	if ((head != NULL) && (index < m_size) && (index >= 0)) // если по этому номеру что-то лежит и этот элемент внутри списка
	{
		// Mass - объекты, которые хранятся в списке
		Elem* tmonst = head, * helping = head;

		for (int i = 0; i < index; i++)
		{
			helping = tmonst; // предыдущее значение tmonst
			tmonst = tmonst->next;
		}

		if (tmonst == head) // если элемент который надо удалить первый
		{
			head = tmonst->next;
		}
		else
		{
			helping->next = tmonst->next;
		}
		tmonst->m_data->~Human();
		delete(tmonst);
		m_size--; // уменьшаем размер списка
	}

}



void Keeper::save()
{
	ofstream outfile;
	string initfile = "data.txt";
	outfile.open(initfile);
	if (!outfile)
	{
		throw "Error opening file!";
		system("pause");
		exit(1);
	}
	else
	{
		outfile << m_size << endl;
		outfile.close();
	}

	Elem* buffer = head;
	for (int i = 0; i < m_size; i++)
	{
		buffer->m_data->saving();
		buffer = buffer->next;
	}

}

// Дописать

void Keeper::load()
{
	if (m_size != 0)
	{
		Elem* buffer;
		while (head->next != NULL)
		{
			buffer = head;
			head = head->next;
			buffer->m_data->~Human();
			delete(buffer);
		}
		head->m_data->~Human();
		delete(head);
	}


	ifstream infile;
	int read_size, num_human; //переменная читки размера и персонажа
	string a, b, c, d, e; //считываемые строки
	string initfile = "data.txt";
	Human* humans;

	infile.open(initfile);
	if (!infile)
	{
		throw "Error opening!";
		system("pause");
		exit(1);
	}

	infile >> read_size; //читаем кол-во людей

	for (int i = 0; i < read_size; i++)
	{
		infile >> num_human; //читаем номер персоны
		infile.ignore(32767, '\n');

		if (num_human == 1) //перед нами студени
		{
			//infile >> a >> b >> c >> d >> e;

			getline(infile, a);
			getline(infile, b);
			getline(infile, c);
			getline(infile, d);
			getline(infile, e);
			Heroes* hero;
			hero = new Heroes;
			hero->set_name(a);
			hero->set_wheaponType(b);
			hero->set_spec(c);
			hero->set_specTwo(d);
			hero->set_specThree(e);
			humans = hero;
			insert(humans);
		}

		if (num_human == 2) //перед нами злодей
		{
			//infile >> a >> b >> c >> d >> e >> f >> g;

			getline(infile, a);
			getline(infile, b);
			getline(infile, c);
			getline(infile, d);
			getline(infile, e);
			Villain* villain;
			villain = new Villain;
			villain->set_name(a);
			villain->set_wheaponTypes(b);
			villain->set_evilT(c);
			villain->set_location(d);
			villain->set_baseSkills(e);
			humans = villain;
			insert(humans);
		}

		if (num_human == 3) //перед нами монстр
		{
			//infile >> a >> b >> c;

			getline(infile, a);
			getline(infile, b);
			getline(infile, c);
			getline(infile, d);

			Monster* monst;
			monst = new Monster;
			monst->set_name(a);
			monst->set_description(b);
			humans = monst;
			insert(humans);
		}
	}
}