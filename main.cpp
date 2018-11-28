#include <iostream>
#include <math.h>

using namespace std;

void NewLine()
{
    cout << " " << endl;
}

void NewLines(int x)
{
    for(int i=0;i<x;i++)
    {
        cout << " " << endl;
    }
}

int WriteBiggerNumber(int x, int y)
{
    if(x>y)
    {
        cout << x << endl;
    }
    else
    {
        cout << y << endl;
    }
}

int Multiply(int x, int y)
{
    return x * y;
}

int main()
{
    int warunek = 1;
    while(warunek != 0)
    {
        int zadanie;
        cout << "Podaj numer zadania ";
        cin >> zadanie;
        switch(zadanie)
        {
            //1.1. Zadeklarowa� zmienne typu int, float, char. Przypisa� do nich warto��, wy�wietli� je na ekran.
            case 1:
            {
                int a = 7;
                float b = 7.13;
                char c = 'c';

                cout << "Zmienna a typu int wynosi " << a << endl;
                cout << "Zmienna b typu float wynosi " << b << endl;
                cout << "Zmienna c typu char wynosi " << c << endl << endl;
                break;
            }
            //1.2. Wy�wietli� zmienn� typu int na ekran. Nale�y u�y� metody printf i konstrukcji %d
            case 2:
            {
                int x = 1;
                cout << x << endl;
                break;
            }
            //1.3. Pobra� od u�ytkownika liczb� x. Wy�wietli� kwadrat liczby x.
            case 3:
            {
                float x;
                cout << "Podaj liczbe: ";
                cin >> x;
                int wynik = x*x;
                cout << "Podana liczba podniesiona do kwadratu wynosi: " << wynik << endl << endl;
                break;
            }
            //1.4. Zapozna� si� z instrukcjami warunkowymi (if, else if, else oraz switch). Pobra� od u�ywkownika liczb� i wy�wietli� informacj�, czy jest ona: mniejsza, wi�ksza, czy r�wna 0.
            case 4:
            {
                float x;
                cout << "Podaj liczbe: ";
                cin >> x;
                if(x>0)
                {
                    cout << "Podana liczba jest wieksza od 0" << endl << endl;
                }
                else if(x<0)
                {
                    cout << "Podana liczba jest mniejsza od 0" << endl << endl;
                }
                else
                {
                    cout << "Podana liczba jest rowna 0" << endl << endl;
                }
                break;
            }
            //1.5. Pobra� ud u�ytkownika 3 liczby (x1, x2, x3). Wy�wietli� informacj�, kt�ra z tych liczb jest najwi�ksza.
            case 5:
            {
                int a, b, c;
                cout << "Podaj pierwsza liczbe: " << endl;
                cin >> a;
                cout << "Podaj druga liczbe: " << endl;
                cin >> b;
                cout << "Podaj trzecia liczbe: " << endl;
                cin >> c;

                if(a>b && a>c)
                {
                    cout << "Liczba " << a << " jest najwieksza" << endl << endl;
                }
                else if(b>a && b>c)
                {
                    cout << "Liczba " << b << " jest najwieksza" << endl << endl;
                }
                else
                {
                    cout << "Liczba " << c << " jest najwieksza" << endl << endl;
                }
                break;
            }
            /*1.6. Napisa� prosty kalkulator. Nale�y pobra� od u�ytkownika 2 liczby oraz operator (jeden z czterech: mno�enie, dzielenie, dodawanie,
            odejmowanie). Wymagane jest utworzenie prostego menu u�ytkownika. Uwaga - nale�y pami�ta� o u�amkach (1/3 powinno da� 0.33, a nie 0)*/
            case 6:
            {

                cout << "------------Kalkulator------------" << endl;
                int a,b;
                cout << "Podaj pierwsza liczbe ";
                cin >> a;
                cout << "Podaj druga liczbe ";
                cin >> b;
                int dzialanie;
                cout << "Wybierz dzialanie " << endl;
                cout << "1 - dodawanie " << endl;
                cout << "2 - odejmowanie " << endl;
                cout << "3 - mnozenie " << endl;
                cout << "4 - dzielenie " << endl;
                cin >> dzialanie;
                switch(dzialanie)
                {
                    case 1:
                    {
                        int wynik = a+b;
                        cout << "Wynik: " << wynik << endl;
                        break;
                    }
                    case 2:
                    {
                        int wynik = a-b;
                        cout << "Wynik: " << wynik << endl;
                        break;
                    }
                    case 3:
                    {
                        int wynik = a*b;
                        cout << "Wynik: " << wynik << endl;
                        break;
                    }
                    case 4:
                    {
                        int wynik = a/b;
                        cout << "Wynik: " << wynik << endl;
                        break;
                    }
                }
                break;
            }
            /*2.1. Zapozna� si� z p�tl� while. P�tla ta s�u�y do wielokrotnego wykonania fragmentu kodu przez NIEZNAN� Z G�RY ilo�� razy. P�tla
            wykonuje si� zawsze, je�li warunek jest prawdziwy (ewaluowany do true). Napisa� p�tl�, w kt�ej u�ytkownik podaje liczb� x. Nale�y
            wy�wietli� t� liczb�. Je�eli u�ytkownik poda 0, nale�y zako�czy� program.*/
            case 7:
            {
                int x;
                do
                {
                    cout << "Podaj liczbe: ";
                    cin >> x;
                    cout << "Podales liczbe: " << x << endl;
                }
                while(x!=0);
                break;
            }
            /*2.2. Przerobi� kalkulator z zadania 1.6. Teraz po ka�dym dzia�aniu program powinien spyta� u�ytkownika, czy ten chce powt�rzy�
            wszystko od pocz�tku. Je�li tak - restartujemy kalkulator i zaczynamy od nowa. Je�li nie - ko�czymy program.*/
            case 8:
            {
                int warunek = 1;
                do
                {
                cout << "------------Kalkulator------------" << endl;
                int a,b;
                cout << "Podaj pierwsza liczbe ";
                cin >> a;
                cout << "Podaj druga liczbe ";
                cin >> b;
                int dzialanie;
                cout << "Wybierz dzialanie " << endl;
                cout << "1 - dodawanie " << endl;
                cout << "2 - odejmowanie " << endl;
                cout << "3 - mnozenie " << endl;
                cout << "4 - dzielenie " << endl;
                cin >> dzialanie;
                switch(dzialanie)
                {
                    case 1:
                    {
                        int wynik = a+b;
                        cout << "Wynik: " << wynik << endl << endl;
                        break;
                    }
                    case 2:
                    {
                        int wynik = a-b;
                        cout << "Wynik: " << wynik << endl << endl;
                        break;
                    }
                    case 3:
                    {
                        int wynik = a*b;
                        cout << "Wynik: " << wynik << endl << endl;
                        break;
                    }
                    case 4:
                    {
                        int wynik = a/b;
                        cout << "Wynik: " << wynik << endl << endl;
                        break;
                    }
                }
                char reset;
                cout << "R-RESET" << "S-STOP";
                cin >> reset;
                if(reset=='R')
                {
                    warunek = 1;
                }
                else if(reset=='S')
                {
                    warunek = 0;
                }
                }
                while(warunek==1);
                break;
            }
            //2.3. Pobra� od u�ytkownika liczb� x. Nale�y wy�wietli� wszystkie kolejne pot�gi liczby x. Zako�czy� program, kiedy liczba przekroczy 100 000.
            case 9:
            {
                int x;
                cout << "Podaj liczbe: ";
                cin >> x;
                int n = 100000;
                int potega=1;
                while(potega<=n)
                {
                    cout << potega << endl;
                    potega=potega*x;
                }
                break;
            }
            /*2.4. Pobra� od u�ytkownika liczb� x. Je�li liczba jest niedodatnia - nale�y zako�czy� program. Nast�pnie nale�y wy�wietla� kolejno (w
            nowej linii) wszystkie liczby mniejsze od x, a� osi�gni�te zostanie 0.*/
            case 10:
            {
                int x;
                cout << "Podaj liczbe: ";
                cin >> x;
                if(x>0)
                {
                    int y=0;
                    while(x!=y)
                    {
                        x--;
                        cout << x << endl;

                    }
                }
                break;
            }
            /*2.5. Zapozna� si� z instrukcjami continue; i break;. Pierwsza s�u�y do zako�czenia iteracji i przej�cia do nast�pnej, a druga natychmiast
            ko�czy p�tl�. Przerobi� program z zadania 1.4, aby wy�wietla� tylko parzyste liczby (u�y� if oraz continue). Je�li liczba wynosi 40, nale�y
            wyj�� z p�tli i zako�czy� program.*/
            case 11:
            {
                int x;
                cout << "Podaj liczbe: ";
                cin >> x;
                if(x>0)
                {
                    int y=0;
                    while(x!=y)
                    {
                        x--;
                        if(x%2==0)
                        {
                            cout << x << endl;

                        }
                        else if(x%2!=0)
                        {
                            continue;
                           cout << x << endl;
                        }

                    }
                }
                else if(x==40)
                {
                    break;
                }
                break;
            }
            /*2.6. Zapozna� si� z p�tl� for. P�tla s�u�y do wykonania danego fragmentu kodu ZNAN� Z G�RY okre�lon� ilo�� razy. Uwaga - ka�d� p�tl�
            for mo�na zast�pi� p�tl� while i wzajemnie. Zwyczajowo obowiazuje zasada, �e je�li ilo�� iteracji jest znana - u�ywamy for, a je�li nie jest
            znana (zale�y od u�ytkownika lub jakiego� stanu zewn�trznego) - u�ywamy p�tli while. P�tla for sk�ada si� z: ZMIENNEJ ITERACYJNEJ,
            czyli stanu pocz�tkowego p�tli, np. int i = 0. Nast�pnie WARUNKU ZAKO�CZENIA P�TLI, np. i<10. Nast�pnie OPERACJI WYKONYWANEJ
            PO KA�DEJ ITERACJI - zazwyczaj jest to zwi�kszenie iteratora o 1, czyli i = i + 1, b�d� w skr�cie i++. Napisa� p�tl� for, kt�ra wy�wietli cyfry
            od 0 do 9.*/
            case 12:
            {
                for(int i=0;i<=9;i++)
                {
                    cout << i << endl;
                }
                 break;
            }
            /*2.7. Pobra� od u�ytkownika liczby x i y. Zak�adamy, �e y > x (zawsze, nie musimy tego sprawdza�). Za pomoc� p�tli for wypisa� liczby
            mi�dzy x a y (do przemy�lenia - co jest stanem pocz�tkowym, a co warunkiem zako�czenia p�tli?)*/
            case 13:
            {
                int x;
                int y;
                cout << "Podaj x: ";
                cin >> x;
                cout << "Podaj y: ";
                cin >> y;
                for(int i=x+1;i<y;i++)
                {
                    cout << i << endl;
                }
                break;
            }
            //2.8. Pobra� od u�ytkownika liczb� x. Za pomoc� p�tli for wypisa� wszystkie liczby mniejsze od x, ale wi�ksze ni� 0.
            case 14:
            {
                int x;
                cout << "Podaj x: ";
                cin >> x;
                for(int i=1;i<x;i++)
                {
                    cout << i << endl;
                }
                break;
            }
            /*2.9. Pobra� od u�ytkownika liczb� x. Za pomoc� p�tli for wypisywa� CO TRZECI� liczb� wi�ksz� od x. P�tla powinna si� zako�czy�, je�li
            liczba przekroczy 100. Uwaga - prosz� nie u�ywa� operacji continue i break, a sterowa� tylko parametrami p�tli.*/
            case 15:
            {
                int x;
                cout << "Podaj x: ";
                cin >> x;
                for(int i=x;i<=100;i=i+3)
                {
                    cout << i << endl;
                }
                break;
            }
            //3.1. Napisa� metod� void NewLine(). Powinna ona wypisa� na ekran pojedyncz� pust� lini�. U�y� tej metod� w main().
            case 16:
            {
                NewLine();
                break;
            }
            /*3.2. Napisa� metod� void NewLines(int count). Powinna ona wypisa� tyle nowych linii, ile zosta�o podanych W PARAMETRZE count (nale�y
            u�y� p�tli for). U�y� metod� w main()*/
            case 17:
            {
                int parametr;
                cout << "Podaj parametr: ";
                cin >> parametr;
                NewLines(parametr);
                break;
            }
            /*3.3. Napisa� metod� void WriteBiggerNumber(int x, int y). Metoda powinna pobra� 2 parametry i zwr�ci� wi�kszy z nich. Wykorzysta�
            funckj� w metodzie main(). UWAGA - pobieranie liczb od u�ytkownika powinno odby� si� w funkcji main(), a NIE w WriteBiggerNumber! Do
            funkcji nale�y jedynie przes�a� pobrane wcze�niej parametry*/
            case 18:
            {
                int parametr1;
                int parametr2;
                cout << "Podaj pierwszy parametr: ";
                cin >> parametr1;
                cout << "Podaj pierwszy parametr: ";
                cin >> parametr2;

                WriteBiggerNumber(parametr1, parametr2);
                break;
            }
            /*3.4. Napisa� metod� Multiply(int x, int y) . Metoda powinna ZWR�CI� (s�owo kluczowe return) iloczyn dw�ch parametr�w. Uwaga! Metoda
            NIE POWINNA wypisywa� wyniku - powinien on by� wy�wietlony w funkcji main!*/
            case 19:
            {
                int x;
                int y;
                cout << "Podaj x: ";
                cin >> x;
                cout << "Podaj y: ";
                cin >> y;

                cout << "Iloczyn x * y wynosi: " << Multiply(x, y) << endl;
                break;
            }
        }
    }
}




