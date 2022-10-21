#include "lib.h"

using namespace std;

Villain::Villain()
{
	cout << "Constructor Villain without attributes was called." << endl;
}

Villain::~Villain()
{
	cout << "Destructor Villain was called." << endl;
}

Villain::Villain(const Villain& Villain_copy)
{
	name = Villain_copy.name;
	wheaponType = Villain_copy.wheaponType;
	evilType = Villain_copy.evilType;
	location = Villain_copy.location;
	baseSkills = Villain_copy.baseSkills;
}

Villain::Villain(string name)
{
	this->name = name;
}

string Villain::get_name() const { return name; }

void Villain::set_name(string name_ch) { name = name_ch; }

string Villain::get_wheaponTypes() const { return wheaponType; }

void Villain::set_wheaponTypes(string wheaponType_ch) { wheaponType = wheaponType_ch; }

string Villain::get_evilT() const { return evilType; }

void Villain::set_evilT(string evilT_ch) { evilType = evilT_ch; }

string Villain::get_location() const { return location; }

void Villain::set_location(string loc_ch) { location = loc_ch; }

string Villain::get_baseSkills() const { return baseSkills; }

void Villain::set_baseSkills(string bskills_ch) { baseSkills = bskills_ch; }

void Villain::show()
{
	cout << "------------------------------------" << endl;
	cout << "Person: Villain" << endl;
	cout << "Name: " << name << endl;
	cout << "WheaponType: " << wheaponType << endl;
	cout << "EvilType: " << evilType << endl;
	cout << "Location:" << location << endl;
	cout << "BaseSkills: " << baseSkills << endl;

	cout << "------------------------------------" << endl;
}

void Villain::rewrite()
{
	cout << "------------------------------------" << endl;
	cin.ignore(32767, '\n');
	cout << "Villain: " << endl;
	cout << "Input new name: ";
	getline(cin, name);
	cout << "Input new wheaponType: ";
	getline(cin, wheaponType);
	cout << "Input new evilType: ";
	getline(cin, evilType);
	cout << "Input new location: ";
	getline(cin, location);
	cout << "Input new baseSkills: ";
	getline(cin, baseSkills);
	cout << "------------------------------------" << endl;
}

void Villain::saving()
{
	ofstream outfile;
	string initfile = "data.txt";
	outfile.open(initfile, ios_base::app);
	if (!outfile)
	{
		throw "Error opening!";
		system("pause");
		exit(1);
	}
	else
	{
		outfile << 2 << endl << name << endl << wheaponType << endl << evilType << location << baseSkills << endl;
		outfile.close();
	}
}

void Villain::redact_str(int num_str, string red_str)
{
	switch (num_str)
	{
	case 1:
		this->name = red_str;
		break;
	case 2:
		this->wheaponType = red_str;
		break;
	case 3:
		this->evilType = red_str;
		break;
	case 4:
		this->location = red_str;
		break;
	case 5:
		this->baseSkills = red_str;
		break;
	default:
		throw "Incorrect number of string!";
		break;
	}
}

