#pragma once
#include "lib.h"
class Heroes : public Human
{
private:
	string name;
	string wheaponType;
	string spec;
	string specTwo;
	string specThree;

public:
	Heroes();
	Heroes(string name);
	~Heroes();
	Heroes(const Heroes& Heroes_copy);

	string get_name() const;
	void set_name(string name_ch);
	string get_wheaponType() const;
	void set_wheaponType(string wheaponType_ch);
	string get_spec() const;
	void set_spec(string spec_ch);
	string get_specTwo() const;
	void set_specTwo(string specTwo_ch);
	string get_specThree() const;
	void set_specThree(string specThree_ch);

	virtual void show();
	virtual void rewrite();
	virtual void saving();
	virtual void redact_str(int num_str, string red_str);
	
};
