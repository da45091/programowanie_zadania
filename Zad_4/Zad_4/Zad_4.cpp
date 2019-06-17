// Zada_3.cpp : Ten plik zawiera funkcjê „main”. W nim rozpoczyna siê i koñczy wykonywanie programu.
//

#include "pch.h"


using namespace std;


class Player
{
public:
	Player(string name, string surname, string height, string advantage, string disadvantage)
	{
		player_data[0] = name;
		player_data[1] = surname;
		player_data[2] = height;
		player_data[3] = advantage;
		player_data[4] = disadvantage;

	}

	Player(string data_string);

	Player() {};

	Player(const Player &);

	string ReturnProperties();
	string ReturnPropertiesSemicolonSeparated();	//zbiera dane z player_data 
	void CreatePlayer();
	void ChangeProperties();

	string player_data[5];

};

Player::Player(string data_string)
{
	stringstream sstream(data_string);
	string segment;
	vector<string> segment_list;

	while (getline(sstream, segment, ';'))
	{
		segment_list.push_back(segment);
	}

	if (segment_list.size() == 5)
	{
		for (int i = 0; i < 5; i++)
		{
			this->player_data[i] = segment_list.at(i);
		}
	}
}

string Player::ReturnProperties()
{

	string Properties = player_data[0] + " " + player_data[1] + " " + player_data[2] + " " + player_data[3] + " " + player_data[4];
	return Properties;
}

string Player::ReturnPropertiesSemicolonSeparated()
{

	string Properties = player_data[0] + ";" + player_data[1] + ";" + player_data[2] + ";" + player_data[3] + ";" + player_data[4];
	return Properties;
}

void Player::CreatePlayer()
{
	cout << "Podaj dane zawodnikow: " << endl;
	cout << "Imie: ";
	cin >> player_data[0];
	cout << "Nazwisko: ";
	cin >> player_data[1];
	cout << "Wzrost: ";
	cin >> player_data[2];
	cout << "Zaleta: ";
	cin >> player_data[3];
	cout << "Wada: ";
	cin >> player_data[4];

}

Player::Player(const Player &source)
{
	player_data[0] = source.player_data[0];
	player_data[1] = source.player_data[1];
	player_data[2] = source.player_data[2];
	player_data[3] = source.player_data[3];
	player_data[4] = source.player_data[4];
}

void Player::ChangeProperties()
{
	cout << "Podaj nowe imie: " << endl;
	cin >> player_data[0];
	cout << "Podaj nowe nazwisko: " << endl;
	cin >> player_data[1];
	cout << "Podaj nowy wzrost: " << endl;
	cin >> player_data[2];
	cout << "Podaj nowa zalete: " << endl;
	cin >> player_data[3];
	cout << "Podaj nowa wade: " << endl;
	cin >> player_data[4];

}

class Team
{
public:
	Team(string name, Player* player, Player* player_1, Player* player_2, Player* player_3, Player* player_4)
	{
		this->name = name;
		this->player = player;
		this->player_1 = player_1;
		this->player_2 = player_2;
		this->player_3 = player_3;
		this->player_4 = player_4;
	}

	Team(string name, string file_name);

	void ReturnProperties();
	string ReturnPropertiesSemicolonSeparated();

	void SaveToFile();

	Team(const Team &);

	string name;
	Player* player;
	Player* player_1;
	Player* player_2;
	Player* player_3;
	Player* player_4;

};

Team::Team(string name, string file_name)
{
	this->name = name;

	ifstream file;
	string input_string = "";

	file.open(file_name, ios::in);
	if (file.is_open())
	{
		int i = 0;
		while (i < 5 && getline(file, input_string))
		{
			switch (i)
			{
			case 0:
				this->player = new Player(input_string);
				break;
			case 1:
				this->player_1 = new Player(input_string);
				break;
			case 2:
				this->player_2 = new Player(input_string);
				break;
			case 3:
				this->player_3 = new Player(input_string);
				break;
			case 4:
				this->player_4 = new Player(input_string);
				break;
			}
			i++;
		}
		file.close();
	}
}

void Team::ReturnProperties()
{
	cout << player->ReturnProperties();
	cout << " ";
	cout << this->player_1->ReturnProperties();
	cout << " ";
	cout << this->player_2->ReturnProperties();
	cout << " ";
	cout << this->player_3->ReturnProperties();
	cout << " ";
	cout << this->player_4->ReturnProperties();
	cout << " ";
	cout << endl;
}

string Team::ReturnPropertiesSemicolonSeparated()
{
	stringstream to_return;

	to_return << player->ReturnPropertiesSemicolonSeparated();
	to_return << endl;
	to_return << this->player_1->ReturnPropertiesSemicolonSeparated();
	to_return << endl;
	to_return << this->player_2->ReturnPropertiesSemicolonSeparated();
	to_return << endl;
	to_return << this->player_3->ReturnPropertiesSemicolonSeparated();
	to_return << endl;
	to_return << this->player_4->ReturnPropertiesSemicolonSeparated();
	to_return << endl;

	return to_return.str();
}

Team::Team(const Team &source)
{
	name = source.name;
	player = source.player;
	player_1 = source.player_1;
	player_2 = source.player_2;
	player_3 = source.player_3;
	player_4 = source.player_4;
}

void Team::SaveToFile()
{
	string filename_const = "druzyna";
	string filename_teamName = this->name;

	time_t t = time(0);
	struct tm now;
	localtime_s(&now, &t);

	stringstream filename_time;
	filename_time << now.tm_hour << now.tm_min << now.tm_sec;

	string filename_format = ".txt";

	stringstream filename;
	filename << filename_const << filename_teamName << filename_time.str() << filename_format;

	ofstream file;
	file.open(filename.str(), ios::out);

	if (file.is_open())
	{
		file << this->ReturnPropertiesSemicolonSeparated();
		file.close();
	}
}


int main()
{
	Player p1;
	p1.CreatePlayer();
	Player p2;
	p2.CreatePlayer();
	Player p3;
	p3.CreatePlayer();
	Player p4;
	p4.CreatePlayer();
	Player p5;
	p5.CreatePlayer();

	Team A("team1", &p1, &p2, &p3, &p4, &p5);

	Player p6;
	p6.CreatePlayer();
	Player p7;
	p7.CreatePlayer();
	Player p8;
	p8.CreatePlayer();
	Player p9;
	p9.CreatePlayer();
	Player p10;
	p10.CreatePlayer();

	Team B("team2", &p6, &p7, &p8, &p9, &p10);

	Team C = B;
	
	Team D("team4", "team_4.txt");

	D.player_1->ChangeProperties();

	A.ReturnProperties();
	B.ReturnProperties();
	C.ReturnProperties();
	D.ReturnProperties();

	A.SaveToFile();
	B.SaveToFile();
	C.SaveToFile();
	D.SaveToFile();

}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotycz¹ce rozpoczynania pracy:
//   1. U¿yj okna Eksploratora rozwi¹zañ, aby dodaæ pliki i zarz¹dzaæ nimi
//   2. U¿yj okna programu Team Explorer, aby nawi¹zaæ po³¹czenie z kontrol¹ Ÿród³a
//   3. U¿yj okna Dane wyjœciowe, aby sprawdziæ dane wyjœciowe kompilacji i inne komunikaty
//   4. U¿yj okna Lista b³êdów, aby zobaczyæ b³êdy
//   5. Wybierz pozycjê Projekt > Dodaj nowy element, aby utworzyæ nowe pliki kodu, lub wybierz pozycjê Projekt > Dodaj istniej¹cy element, aby dodaæ istniej¹ce pliku kodu do projektu
//   6. Aby w przysz³oœci ponownie otworzyæ ten projekt, przejdŸ do pozycji Plik > Otwórz > Projekt i wybierz plik sln