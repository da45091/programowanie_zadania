#include "pch.h"
#include "Item.h"

//constructors

Item::Item()
{
	name = "";
	value = 0;
}

Item::Item(std::string _name, int _value) :name(_name), value(_value) {};


//getters

std::string Item::get_name()
{
	return name;
}

int Item::get_value()
{
	return value;
}

//setters

void Item::set_name(std::string _name)
{
	name = _name;
}

void Item::set_value(int _value)
{
	value = _value;
}