#pragma once

#include "lib.h"

using namespace std;

class Human
{

public:
	Human() {};
	virtual ~Human() {};

	virtual void show() = 0;
	virtual void rewrite() = 0;
	virtual void saving() = 0;
	virtual void redact_str(int num_str, string red_str) = 0;
	
};

typedef struct Elem
{
	Human* m_data;
	Elem* next;
} Elem;
