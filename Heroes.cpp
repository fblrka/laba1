#include "lib.h"

using namespace std;

Heroes::Heroes()
{
    cout << "Constructor Heroes without attributes was called." << endl;
}

Heroes::~Heroes()
{
    cout << "Destructor Heroes was called." << endl;
}


Heroes::Heroes(const Heroes& Heroes_copy)
{
    name = Heroes_copy.name;
    wheaponType = Heroes_copy.wheaponType;
    spec = Heroes_copy.spec;
    specTwo = Heroes_copy.specTwo;
    specThree = Heroes_copy.specThree;
}

Heroes::Heroes(string name)
{
    this->name = name;
}

string Heroes::get_name() const { return name; }

void Heroes::set_name(string name_ch) { name = name_ch; }

string Heroes::get_wheaponType() const { return wheaponType; }

void Heroes::set_wheaponType(string groups_ch) { wheaponType = groups_ch; }

string Heroes::get_spec() const { return spec; }

void Heroes::set_spec(string spec_ch) { spec = spec_ch; }

string Heroes::get_specTwo() const { return specTwo; }

void Heroes::set_specTwo(string specTwo_ch) { specTwo = specTwo_ch; }

string Heroes::get_specThree() const { return specThree; }

void Heroes::set_specThree(string spec3_ch) { specThree = spec3_ch; }

void Heroes::show()
{
    cout << "------------------------------------" << endl;
    cout << "Person: Heroes" << endl;
    cout << "Name: " << name << endl;
    cout << "Group: " << wheaponType << endl;
    cout << "Specialization: " << spec << endl;
    cout << "specTwo: " << specTwo << endl;
    cout << "specThree: " << specThree << endl;
    cout << "------------------------------------" << endl;
}

void Heroes::rewrite()
{
    cout << "------------------------------------" << endl;
    cin.ignore(32767, '\n');
    cout << "Person: Heroes" << endl;
    cout << "Input new name: ";
    getline(cin, name);
    cout << "Input new wheaponType: ";
    getline(cin, wheaponType);
    cout << "Input new spec: ";
    getline(cin, spec);
    cout << "Input new specTwo: ";
    getline(cin, specTwo);
    
    bool fl = false;
    string a;
    cout << "Input new specThree: ";
    while (fl == false)
    {
        try {
            
            getline(cin, a);
            float f = stof(a);
            fl = true;
        }
        catch (...)
        {
            cout << "Enter the number" << endl;
           
        }
    }
    specThree = a;
    
    cout << "------------------------------------" << endl;
}

void Heroes::saving()
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
    outfile << 1 << endl << name << endl << wheaponType << endl << spec << endl << specTwo << endl << specThree << endl;
    outfile.close();
}

void Heroes::redact_str(int num_str, string red_str)
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
        this->spec = red_str;
        break;
    case 4:
        this->specTwo = red_str;
        break;
    case 5:
        this->specThree = red_str;
        break;
    default:
        throw "Incorrect number of string!";
        break;
    }
}

