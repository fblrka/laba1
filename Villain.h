#pragma once
#include "lib.h"
class Villain :
    public Human
{
private:
    string name;
    string wheaponType;
    string evilType;
    string location;
    string baseSkills;

public:
    Villain();
    ~Villain();

    Villain(const Villain& Villian_copy);
    Villain(string name);

    string get_name() const;
    void set_name(string name_ch);
    string get_wheaponTypes() const;
    void set_wheaponTypes(string groups_ch);
    string get_evilT() const;
    void set_evilT(string evil_ch);
    string get_location() const;
    void set_location(string loc_ch);
    string get_baseSkills() const;
    void set_baseSkills(string bskills_ch);

    virtual void show();
    virtual void rewrite();
    virtual void saving();
    virtual void redact_str(int num_str, string red_str);
    virtual bool averball(double a){ return false; };
};