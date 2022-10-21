#pragma once
#include "lib.h"
class Monster : public Human
{
private:
    string name;
	string description;
   
public:
    Monster();
    ~Monster();
    Monster(const Monster& Monster_copy);
    Monster(string name);

	string get_name() const;
	void set_name(string name_ch);
	string get_description() const;
	void set_description(string description_ch);
	//void TypeMonsters(string typeM_ch);
	


	virtual void show(); 
	virtual void rewrite(); 
	virtual void saving();
	virtual void redact_str(int num_str, string red_str);
	virtual bool averball(double a){ return false; };
};

