#include "lib.h"

using namespace std;

Monster::Monster()
{
    cout << "Constructor Monster without attributes was called." << endl;
}

Monster::~Monster()
{
    cout << "Destructor Monster was called." << endl;
}


Monster::Monster(const Monster& Monster_copy)
{
    name = Monster_copy.name;
    description = Monster_copy.description;
   

}

Monster::Monster(string name)
{
    this->name = name;
}

string Monster::get_name() const { return name; }

void Monster::set_name(string name_ch) { name = name_ch; }

string Monster::get_description() const { return description; }

void Monster::set_description(string description_ch) { description = description_ch; }



void Monster::show()
{
    cout << "------------------------------------" << endl;
    cout << "Person: Monster" << endl;
    cout << "Name: " << name << endl;
    cout << "Appearance description : " << description << endl;
 
    cout << "------------------------------------" << endl;
}

void Monster::rewrite()
{
    cout << "------------------------------------" << endl;
    cin.ignore(32767, '\n');
    cout << "Person: Monster" << endl;
    cout << "Input new name: ";
    getline(cin, name);
    cout << "Input new appearance description: ";
    getline(cin, description);
  
    cout << "------------------------------------" << endl;
}

void Monster::saving()
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
    outfile << 3 << endl << name << endl << description << endl;
    outfile.close();
}

void Monster::redact_str(int num_str, string red_str)
{
    switch (num_str)
    {
    case 1:
        this->name = red_str;
        break;
    case 2:
        this->description = red_str;
        break;
    default:
        throw "Incorrect number of string!";
        break;
    }
}

