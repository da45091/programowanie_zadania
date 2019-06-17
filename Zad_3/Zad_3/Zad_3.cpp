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

	Player() {};

	Player(const Player &);

	string ReturnProperties();
	void CreatePlayer();
	void ChangeProperties();

	string player_data[5];

};

string Player::ReturnProperties()
{

	string Properties = player_data[0] + " " + player_data[1] + " " + player_data[2] + " " + player_data[3] + " " + player_data[4];
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
	Team(Player* player, Player* player_1, Player* player_2, Player* player_3, Player* player_4)
	{
		this->player = player;
		this->player_1 = player_1;
		this->player_2 = player_2;
		this->player_3 = player_3;
		this->player_4 = player_4;
	}

	void ReturnProperties();

	Team(const Team &);

private:
	Player* player;
	Player* player_1;
	Player* player_2;
	Player* player_3;
	Player* player_4;

};



void Team::ReturnProperties()
{
	cout << player->ReturnProperties();
	cout << " ";
	cout << player_1->ReturnProperties();
	cout << " ";
	cout << player_2->ReturnProperties();
	cout << " ";
	cout << player_3->ReturnProperties();
	cout << " ";
	cout << player_4->ReturnProperties();
	cout << " ";
	cout << endl;

}

Team::Team(const Team &source)
{
	player = source.player;
	player_1 = source.player_1;
	player_2 = source.player_2;
	player_3 = source.player_3;
	player_4 = source.player_4;
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

	Team A(&p1, &p2, &p3, &p4, &p5);

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

	Team B(&p6, &p7, &p8, &p9, &p10);

	Team C(B);

	A.ReturnProperties();
	B.ReturnProperties();
	C.ReturnProperties();


	p5.ChangeProperties();

	A.ReturnProperties();
	B.ReturnProperties();
	C.ReturnProperties();

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