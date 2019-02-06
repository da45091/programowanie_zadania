#include <iostream>
#include <stdlib.h>
#include <stdio.h>


using namespace std;

struct Student
{
	int Age;
	int Height;
	int Semester;
};

Student * StudentCreate(int age, int height, int semester)
{
	Student * student;
	student = (Student*)malloc(sizeof(Student));
	student -> Age = age;
	student -> Height = height;
	student -> Semester = semester;
	return student;
}

void PrintStudent(Student * s)
{
	cout << "Age: " << s -> Age << " Height: " << s -> Height << " Semester: " << s -> Semester << endl;
}

bool AreEqual(Student * s1, Student * s2)
{
	if (s1 -> Age == s2 -> Age && s1 -> Height == s2 -> Height && s1 -> Semester == s2 -> Semester)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

struct Node
{
    int Value;
    Node * Next;
};

Node * Create (int value)
{
    Node * n;
    n = (Node*)malloc(sizeof(Node));
    n -> Value = value;
    n -> Next = n;
}

Node * GetTail(Node * root)
{
    Node * n;
    n = root;
    while(n -> Next != root)
    {
        n = n -> Next;
    }
    return n;
}

void Add(Node * root, int value)
{
    Node * tail;
    tail = GetTail(root);
    tail -> Next = (Node*)malloc(sizeof(Node));
  	Node * node_1;
  	node_1 = tail -> Next;
    node_1 -> Value = value;
	node_1 -> Next = root;

}

void PrintList(Node * root)
{
	Node * n;
	n = root;
	if(root != NULL)
    {
        Node * tail;
        tail = GetTail(root);
        while (n!=tail)
        {
            cout << n -> Value << "->";
            n = n -> Next;
        }
    }
    cout << n -> Value << endl;
}


void RemoveNode(Node * root, int value)
{
    Node * n;
    n = root;
    while (n -> Next != root)
	{
		if (n -> Next -> Value == value)
		{
			Node * temp;
			temp = n -> Next;
			n -> Next = temp -> Next;
			free(temp);
		}
		n = n -> Next;
    }
}

void FreeList(Node * root)
{
	while(root != NULL)
	{
        Node * n;
	    n =  root -> Next;
		free(n);
	}
}

int Count(Node * root)
{
	Node * n;
	n = root;
	int count = 1;
	while(n -> Next != root)
	{
		n = n -> Next;
		count++;
	}
	return count;
}

int main()
{
    int warunek = 1;
    while(warunek != 0)
    {
        int zadanie = 1;
        cout << "Podaj numer zadania ";
        cin >> zadanie;
        switch(zadanie)
        {
            /*Zad 1.1
            Utworzyć strukturę Student taką jak powyżej.Napisaæ metody :
            Student * Create(int age, int height, int semester)  alokuje pamięć i tworzy studenta o podanych parametrach.
            WAŻNE - pamięć należy potem zwolnić w main() !
            void PrintStudent(Student *s)  wypisuje wszystkich składowych struktury
            bool AreEqueal(Student* sl, Student* s2)  zwraca informację, czy składowe są takie same (Uwaga - w C int zamiast
            bool)*/
            case 1: /*Student * Create(int age, int height, int semester), alokuje pamięć i tworzy studenta o podanych parametrach.
            WAŻNE - pamięć należy potem zwolnić w main() ! void PrintStudent(Student *s) wypisuje wszystkich składowych struktury */
            {
                Student * s;
                s = StudentCreate(20, 179, 1);
                PrintStudent(s);
                free(s);
                break;
            }

            case 2: /* bool AreEqueal(Student* sl, Student* s2) zwraca informację, czy składowe są takie same (Uwaga - w C int zamiast
            bool) */
            {
                int age, height, semester;

                cout << "Podaj dane pierwszego studenta: " << endl;
                cout << "wiek " << endl;
                cin >> age;
                cout << "wzrost " << endl;
                cin >> height;
                cout << "semestr " << endl;
                cin >> semester;
                Student * s1;
                s1 = StudentCreate(age, height, semester);

                cout << "Podaj dane drugiego studenta: " << endl;
                cout << "wiek " << endl;
                cin >> age;
                cout << "wzrost " << endl;
                cin >> height;
                cout << "semestr " << endl;
                cin >> semester;
                Student * s2;
                s2 = StudentCreate(age, height, semester);


                if(AreEqual(s1, s2))
                {
                    cout << "Dane studentow sa takie same" << endl;
                }
                else
                {
                    cout << "Dane studentow sa rozne" << endl;
                }

                free(s1);
                free(s2);
                break;
            }
            /*Zad 1 2
            Utworzyć tablicę 3 studentów.Zapełnić je wartościami, wyświetlić, zwolnić pamięć.Tablica powinna być utworzona za
            pomocą metody malloc(proszę pilnować odpowiedniej ilości gwiazdek!)*/
            case 3:
            {
                int tablica = 3;
                Student * s_tablica;
                s_tablica = (Student*)malloc(tablica * sizeof(Student));
                for (int i = 0; i < tablica; i++)
                {
                    cout << "Prosze wprowadzic dane studenta nr: " << i+1 << endl;
                    cout << "wiek " << endl;
                    cin >> s_tablica[i].Age;
                    cout << "wzrost " << endl;
                    cin >> s_tablica[i].Height;
                    cout << "semestr " << endl;
                    cin >> s_tablica[i].Semester;
                }
                for (int i = 0; i < tablica; i++)
                {
                    cout << "Dane studenta nr " << i+1 << " wiek: " << s_tablica[i].Age << " wzrost: " << s_tablica[i].Height << " semestr: " << s_tablica[i].Semester << endl;
                }
                free(s_tablica);
                break;
            }
            /*Zad 1
            Zaimplementować cykliczną listę jednokierunkową. */
            case 4:
            {
                Node * root;
                root = Create(2);
                PrintList(root); // 2
                Add(root, 4);
                Add(root, 8);
                Add(root, 16);
                PrintList(root); // 2 -> 4 -> 8 -> 16
                Add(root, 20);
                PrintList(root); // 2 4 8 16 20
                printf("Ostatni wezel ma wartosc %d\n", GetTail(root)->Value); // 20
                Add(root, 16);
                PrintList(root); // 2 -> 4 -> 8 -> 16 -> 20 -> 16
                printf("%d\n", Count(root)); // 6
                RemoveNode(root, 8);
                PrintList(root); // 2 -> 4 -> 16 -> 20 -> 16
                RemoveNode(root, 10); // element nieistniej¹cy
                PrintList(root); // 2 -> 4 -> 16 -> 20 -> 16
                RemoveNode(root, 16); // usuñ wszystkie wêz³y o wartoœci 16
                PrintList(root); // 2 -> 4 -> 20
                printf("%d\n", Count(root)); // 3
                FreeList(root); // zwolnienie pamiêci na wszystkie wêz³y.
                PrintList(root); // (nic, lista niezaalokowana) Tutaj po zwolnieniu pamięci program mi się zatrzymuje i nie wykonuje sie dalej. Sądzę, że błąd leży w funkcji FreeList(), ale nie mogę go poprawić
                return 0;
                break;
            }
            /*Zad 3.1
            Wczytywać od użytkownika liczby, aż nie poda on 0. Wszystkie wczytane liczby zapisać w pliku numbers.txt */
            case 5:
            {
                FILE *file;
                file = fopen("numbers.txt","w");
                int dane = 1;
                do
                {
                    cout << "Podaj liczbe: ";
                    cin >> dane;
                    fprintf(file, "%d\t", dane);
                }
                while(dane!=0);

                fclose(file);
                break;
            }
            /*Zad 3.2
            Wczytać z numbers.txt liczby. Utworzyć listę jednokierunkową (z zadania 2) zawierającą te liczby. Wypisać je na ekran. */
            case 6:
            {
                FILE * file;
                file = fopen("numbers.txt", "r");
                int dane = 0;
                fscanf(file, "%d ", &dane);
                Node * root = Create(dane);
                for(int i=0;(fscanf(file, "%d ", &dane))!=EOF;i++)
                {
                    Add(root, dane);
                }
                PrintList(root);
                fclose(file);
                break;
            }
            /*Zad 3.3
            Posortować (w dowolnu sposób) listę z zadania 3.2 (już po wczytaniu pliku). Zapisać posortowaną liczbę do pliku sorted.txt. Algorytm sortowania proszę zaimplementować samodzielnie. */
            case 7:
            {
                FILE *file;
                file = fopen("numbers.txt", "r");
                FILE *sorted;
                sorted = fopen("sorted.txt", "w");

                int table[sizeof(file)];
                int dane;
                int s;

                for(s=0;(fscanf(file, "%d ", &dane))!=EOF;s++)
                {
                    table[s]=dane;
                }

                dane=table[0];

                for(int i=0; i<s; i++)
                {
                    for(int j=0; j<s-1-i; j++)
                    {
                        if(table[j] > table[j+1])
                        {
                            int temp;
                            temp = table[j+1];
                            table[j+1] = table[j];
                            table[j] = temp;
                        }
                    }
                }

                for(int i=0; i<s; i++)
                {
                    fprintf(sorted, "%d\t", table[i]);
                }
                fclose(file);
                fclose(sorted);

                break;
            }
        }
    }
}
