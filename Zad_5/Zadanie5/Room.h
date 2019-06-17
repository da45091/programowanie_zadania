#pragma once
#include "pch.h"

class Room
{
public:

	//constructors

	Room(int _x, int _y, std::string _desc, Item _item, Room *_room_n, Room *_room_e, Room *_room_s, Room *_room_w) : x(_x), y(_y), description(_desc), item(_item), room_n(_room_n), room_e(_room_e), room_s(_room_s), room_w(_room_w) {};
	Room(int _x, int _y, std::string _desc, Room *_room_n, Room *_room_e, Room *_room_s, Room *_room_w) : x(_x), y(_y), description(_desc), room_n(_room_n), room_e(_room_e), room_s(_room_s), room_w(_room_w) { item = Item(); };

	//destructor

	~Room();

	//getters

	std::string get_description();
	Room *get_room_n();
	Room *get_room_e();
	Room *get_room_s();
	Room *get_room_w();
	Item get_item();

	//setters

	void set_item(Item item);

	//rest

	bool has_item();

	int x;
	int y;

private:
	std::string description;
	Item item;
	Room *room_n;
	Room *room_e;
	Room *room_s;
	Room *room_w;
};

