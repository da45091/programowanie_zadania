#include "pch.h"
#include "Room.h"


//getters

Room::~Room()
{
	delete(room_n, room_e, room_s, room_w);
}

std::string Room::get_description()
{
	return description;
}

Room * Room::get_room_n()
{
	return room_n;
}

Room * Room::get_room_e()
{
	return room_e;
}

Room * Room::get_room_s()
{
	return room_s;
}

Room * Room::get_room_w()
{
	return room_w;
}

Item Room::get_item()
{
	return item;
}

//setters

void Room::set_item(Item _item)
{
	item = _item;
}

//rest

bool Room::has_item()
{
	if (item.get_value() != 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}