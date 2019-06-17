#pragma once
#include "pch.h"

class Item
{
public:

	//constructors

	Item();

	Item(std::string _name, int _value);

	//getters

	std::string get_name();

	int get_value();

	//setters

	void set_name(std::string _name);

	void set_value(int _value);

private:
	std::string name;
	int value;
};

