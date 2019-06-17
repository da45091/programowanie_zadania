#include "pch.h"

void check_for_items(int steps, int x, int y, Room *room_array[3][6])
{
	for (int i1 = 0; i1 < 3; i1++)
	{

		for (int i2 = 0; i2 < 6; i2++)
		{
			if (room_array[i1][i2]->x == x && room_array[i1][i2]->y == y)
			{
				if (room_array[i1][i2]->has_item())
				{
					std::cout << "Krok: " << steps << " Nazwa: " << room_array[i1][i2]->get_item().get_name() << '\n';
				}
			}
		}
	}
}

int main()
{
	//utworzy¢ 18 pomieszcze« (18 obiektów) i ustawi¢ im wska¹niki na s¡siadów wg takiego wzoru :


	Room *room_array[3][6];
	
	room_array[0][0] = new Room(0, 0, "11", nullptr			, room_array[0][1], nullptr			, nullptr		  );
	room_array[0][1] = new Room(0, 1, "12", nullptr			, nullptr		  , room_array[1][0], room_array[0][0]);
	room_array[0][2] = new Room(0, 3, "14", nullptr			, nullptr		  , room_array[1][2], nullptr		  );
	room_array[0][3] = new Room(0, 5, "16", nullptr			, room_array[0][4], room_array[1][4], room_array[0][2]);
	room_array[0][4] = new Room(0, 6, "17", nullptr			, room_array[0][5], nullptr			, room_array[0][3]);
	room_array[0][5] = new Room(0, 7, "18", nullptr			, nullptr		  , room_array[1][5], room_array[0][4]);

	room_array[1][0] = new Room(1, 1, "22", room_array[0][1], room_array[1][1], room_array[2][1], nullptr		  );
	room_array[1][1] = new Room(1, 2, "23", nullptr			, room_array[1][2], nullptr			, room_array[1][0]);
	room_array[1][2] = new Room(1, 3, "24", room_array[0][2], room_array[1][3], room_array[2][2], room_array[1][1]);
	room_array[1][3] = new Room(1, 4, "25", nullptr			, room_array[1][5], nullptr			, room_array[1][2]);
	room_array[1][4] = new Room(1, 5, "26", room_array[0][3], nullptr		  , room_array[2][3], room_array[1][3]);
	room_array[1][5] = new Room(1, 7, "28", room_array[0][5], nullptr		  , room_array[2][5], nullptr		  );

	room_array[2][0] = new Room(2, 0, "31", nullptr			, room_array[2][1], nullptr			, nullptr		  );
	room_array[2][1] = new Room(2, 1, "32", room_array[1][0], nullptr		  , nullptr			, room_array[2][0]);
	room_array[2][2] = new Room(2, 3, "34", room_array[1][2], nullptr		  , nullptr			, nullptr		  );
	room_array[2][3] = new Room(2, 5, "36", room_array[1][4], room_array[2][4], nullptr			, nullptr		  );
	room_array[2][4] = new Room(2, 6, "37", nullptr			, room_array[2][5], nullptr			, room_array[2][3]);
	room_array[2][5] = new Room(2, 7, "38", room_array[1][5], nullptr		  , nullptr			, room_array[2][4]);

	// wy±wietli¢ pomieszczenia w nast¦puj¡cy sposób:

	char map[3][8] = 
	{
		{NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
		{NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
		{NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL}
	};

	#define EMPTY 'X';
	#define FULL '#';

	for (int i1 = 0; i1 < 3; i1++)
	{
		for (int i2 = 0; i2 < 6; i2++)
		{	
			if (room_array[i1][i2]->x != 0)
			{
				if (map[room_array[i1][i2]->x-1][room_array[i1][i2]->y] == NULL)
				{
					if (room_array[i1][i2]->get_room_n() != nullptr)
					{
						map[room_array[i1][i2]->x-1][room_array[i1][i2]->y] = FULL;
					}
					else if (room_array[i1][i2]->get_room_n() == nullptr)
					{
						map[room_array[i1][i2]->x-1][room_array[i1][i2]->y] = EMPTY;
					}
				}
			}
			
			if (room_array[i1][i2]->x != 2)
			{
				if (map[room_array[i1][i2]->x+1][room_array[i1][i2]->y] == NULL)
				{
					if (room_array[i1][i2]->get_room_s() != nullptr)
					{
						map[room_array[i1][i2]->x+1][room_array[i1][i2]->y] = FULL;
					}
					else if (room_array[i1][i2]->get_room_s() == nullptr)
					{
						map[room_array[i1][i2]->x+1][room_array[i1][i2]->y] = EMPTY;
					}
				}
			}
			
			if (room_array[i1][i2]->y != 0)
			{
				if (map[room_array[i1][i2]->x][room_array[i1][i2]->y-1] == NULL)
				{
					if (room_array[i1][i2]->get_room_w() != nullptr)
					{
						map[room_array[i1][i2]->x][room_array[i1][i2]->y-1] = FULL;
					}
					else if (room_array[i1][i2]->get_room_w() == nullptr)
					{
						map[room_array[i1][i2]->x][room_array[i1][i2]->y-1] = EMPTY;
					}
				}
			}
			
			if (room_array[i1][i2]->y != 7)
			{
				if (map[room_array[i1][i2]->x][room_array[i1][i2]->y+1] == NULL)
				{
					if (room_array[i1][i2]->get_room_e() != nullptr)
					{
						map[room_array[i1][i2]->x][room_array[i1][i2]->y+1] = FULL;
					}
					else if (room_array[i1][i2]->get_room_e() == nullptr)
					{
						map[room_array[i1][i2]->x][room_array[i1][i2]->y+1] = EMPTY;
					}
				}
			}
		}
	}

	for (int i1 = 0; i1 < 3; i1++)
	{
		for (int i2 = 0; i2 < 8; i2++)
		{
			std::cout << map[i1][i2];
		}
		std::cout << "\n";
	}

	//utworzy¢ obiekty dla trzech przedmiotów

	srand(time(NULL));

	Item items[3];
	items[0] = Item("wazon", 10);
	items[1] = Item("miska", 5);
	items[2] = Item("ziemniak", 150);

	int int1 = 0;
	int int2 = 0;

	for (int i = 0; i < 3; i++)
	{
		do
		{
			int1 = rand() % 3;
			int2 = rand() % 6;
		} while (room_array[int1][int2]->has_item());

		room_array[int1][int2]->set_item(items[i]);

	}

	//przej±¢ przez pomieszczenia, zaczynaj¡c od lewego górnego rogu[...]

	int current_x = 0;
	int current_y = 0;
	int steps = 0;

	#define n current_x -= 1;
	#define e current_y += 1;
	#define s current_x += 1;
	#define w current_y -= 1;

	check_for_items(steps, current_x, current_y, room_array);

	e;
	steps++;
	check_for_items(steps, current_x, current_y, room_array);

	s;
	steps++;
	check_for_items(steps, current_x, current_y, room_array);

	s;
	steps++;
	check_for_items(steps, current_x, current_y, room_array);

	w;
	steps++;
	check_for_items(steps, current_x, current_y, room_array);

	e;
	steps++;
	check_for_items(steps, current_x, current_y, room_array);

	n;
	steps++;
	check_for_items(steps, current_x, current_y, room_array);

	e;
	steps++;
	check_for_items(steps, current_x, current_y, room_array);

	e;
	steps++;
	check_for_items(steps, current_x, current_y, room_array);

	s;
	steps++;
	check_for_items(steps, current_x, current_y, room_array);

	n;
	steps++;
	check_for_items(steps, current_x, current_y, room_array);

	n;
	steps++;
	check_for_items(steps, current_x, current_y, room_array);

	s;
	steps++;
	check_for_items(steps, current_x, current_y, room_array);

	e;
	steps++;
	check_for_items(steps, current_x, current_y, room_array);

	e;
	steps++;
	check_for_items(steps, current_x, current_y, room_array);

	n;
	steps++;
	check_for_items(steps, current_x, current_y, room_array);

	e;
	steps++;
	check_for_items(steps, current_x, current_y, room_array);

	e;
	steps++;
	check_for_items(steps, current_x, current_y, room_array);

	w;
	steps++;
	check_for_items(steps, current_x, current_y, room_array);

	w;
	steps++;
	check_for_items(steps, current_x, current_y, room_array);

	s;
	steps++;
	check_for_items(steps, current_x, current_y, room_array);

	s;
	steps++;
	check_for_items(steps, current_x, current_y, room_array);

	e;
	steps++;
	check_for_items(steps, current_x, current_y, room_array);

	e;
	steps++;
	check_for_items(steps, current_x, current_y, room_array);
	//autor zadania nie uwzględnił tutaj jeszcze jednego "n" na koniec, więc jeśli przedmiot będzie w 2 rzędzie, 8 kolumnie to nie zostanie odczytany.


	//wy±wietli¢ pomieszczenia raz jeszcze

	char map2[3][8] =
	{
		{NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
		{NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
		{NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL}
	};

	for (int i1 = 0; i1 < 3; i1++)
	{
		for (int i2 = 0; i2 < 6; i2++)
		{
			if (room_array[i1][i2]->has_item())
			{
				map2[room_array[i1][i2]->x][room_array[i1][i2]->y] = room_array[i1][i2]->get_item().get_name()[0];
			}
		}
	}

	for (int i1 = 0; i1 < 3; i1++)
	{
		for (int i2 = 0; i2 < 6; i2++)
		{
			if (room_array[i1][i2]->x != 0)
			{
				if (map2[room_array[i1][i2]->x - 1][room_array[i1][i2]->y] == NULL)
				{
					if (room_array[i1][i2]->get_room_n() != nullptr)
					{
						map2[room_array[i1][i2]->x - 1][room_array[i1][i2]->y] = FULL;
					}
					else if (room_array[i1][i2]->get_room_n() == nullptr)
					{
						map2[room_array[i1][i2]->x - 1][room_array[i1][i2]->y] = EMPTY;
					}
				}
			}

			if (room_array[i1][i2]->x != 2)
			{
				if (map2[room_array[i1][i2]->x + 1][room_array[i1][i2]->y] == NULL)
				{
					if (room_array[i1][i2]->get_room_s() != nullptr)
					{
						map2[room_array[i1][i2]->x + 1][room_array[i1][i2]->y] = FULL;
					}
					else if (room_array[i1][i2]->get_room_s() == nullptr)
					{
						map2[room_array[i1][i2]->x + 1][room_array[i1][i2]->y] = EMPTY;
					}
				}
			}

			if (room_array[i1][i2]->y != 0)
			{
				if (map2[room_array[i1][i2]->x][room_array[i1][i2]->y - 1] == NULL)
				{
					if (room_array[i1][i2]->get_room_w() != nullptr)
					{
						map2[room_array[i1][i2]->x][room_array[i1][i2]->y - 1] = FULL;
					}
					else if (room_array[i1][i2]->get_room_w() == nullptr)
					{
						map2[room_array[i1][i2]->x][room_array[i1][i2]->y - 1] = EMPTY;
					}
				}
			}

			if (room_array[i1][i2]->y != 7)
			{
				if (map2[room_array[i1][i2]->x][room_array[i1][i2]->y + 1] == NULL)
				{
					if (room_array[i1][i2]->get_room_e() != nullptr)
					{
						map2[room_array[i1][i2]->x][room_array[i1][i2]->y + 1] = FULL;
					}
					else if (room_array[i1][i2]->get_room_e() == nullptr)
					{
						map2[room_array[i1][i2]->x][room_array[i1][i2]->y + 1] = EMPTY;
					}
				}
			}
		}
	}

	for (int i1 = 0; i1 < 3; i1++)
	{
		for (int i2 = 0; i2 < 8; i2++)
		{
			std::cout << map2[i1][i2];
		}
		std::cout << "\n";
	}
}
