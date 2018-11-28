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
            //1.1. Zadeklarowaæ zmienne typu int, float, char. Przypisaæ do nich wartoœæ, wyœwietliæ je na ekran.
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
            //1.2. Wyœwietliæ zmienn¹ typu int na ekran. Nale¿y u¿yæ metody printf i konstrukcji %d
            case 2:
            {
                int x = 1;
                cout << x << endl;
                break;
            }
            //1.3. Pobraæ od u¿ytkownika liczbê x. Wyœwietliæ kwadrat liczby x.
            case 3:
            {
                float x;
                cout << "Podaj liczbe: ";
                cin >> x;
                int wynik = x*x;
                cout << "Podana liczba podniesiona do kwadratu wynosi: " << wynik << endl << endl;
                break;
            }
            //1.4. Zapoznaæ siê z instrukcjami warunkowymi (if, else if, else oraz switch). Pobraæ od u¿ywkownika liczbê i wyœwietliæ informacjê, czy jest ona: mniejsza, wiêksza, czy równa 0.
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
            //1.5. Pobraæ ud u¿ytkownika 3 liczby (x1, x2, x3). Wyœwietliæ informacjê, która z tych liczb jest najwiêksza.
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
            /*1.6. Napisaæ prosty kalkulator. Nale¿y pobraæ od u¿ytkownika 2 liczby oraz operator (jeden z czterech: mno¿enie, dzielenie, dodawanie,
            odejmowanie). Wymagane jest utworzenie prostego menu u¿ytkownika. Uwaga - nale¿y pamiêtaæ o u³amkach (1/3 powinno daæ 0.33, a nie 0)*/
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
            /*2.1. Zapoznaæ siê z pêtl¹ while. Pêtla ta s³u¿y do wielokrotnego wykonania fragmentu kodu przez NIEZNAN¥ Z GÓRY iloœæ razy. Pêtla
            wykonuje siê zawsze, jeœli warunek jest prawdziwy (ewaluowany do true). Napisaæ pêtlê, w któej u¿ytkownik podaje liczbê x. Nale¿y
            wyœwietliæ tê liczbê. Je¿eli u¿ytkownik poda 0, nale¿y zakoñczyæ program.*/
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
            /*2.2. Przerobiæ kalkulator z zadania 1.6. Teraz po ka¿dym dzia³aniu program powinien spytaæ u¿ytkownika, czy ten chce powtórzyæ
            wszystko od pocz¹tku. Jeœli tak - restartujemy kalkulator i zaczynamy od nowa. Jeœli nie - koñczymy program.*/
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
            //2.3. Pobraæ od u¿ytkownika liczbê x. Nale¿y wyœwietliæ wszystkie kolejne potêgi liczby x. Zakoñczyæ program, kiedy liczba przekroczy 100 000.
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
            /*2.4. Pobraæ od u¿ytkownika liczbê x. Jeœli liczba jest niedodatnia - nale¿y zakoñczyæ program. Nastêpnie nale¿y wyœwietlaæ kolejno (w
            nowej linii) wszystkie liczby mniejsze od x, a¿ osi¹gniête zostanie 0.*/
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
            /*2.5. Zapoznaæ siê z instrukcjami continue; i break;. Pierwsza s³u¿y do zakoñczenia iteracji i przejœcia do nastêpnej, a druga natychmiast
            koñczy pêtlê. Przerobiæ program z zadania 1.4, aby wyœwietla³ tylko parzyste liczby (u¿yæ if oraz continue). Jeœli liczba wynosi 40, nale¿y
            wyjœæ z pêtli i zakoñczyæ program.*/
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
            /*2.6. Zapoznaæ siê z pêtl¹ for. Pêtla s³u¿y do wykonania danego fragmentu kodu ZNAN¥ Z GÓRY okreœlon¹ iloœæ razy. Uwaga - ka¿d¹ pêtlê
            for mo¿na zast¹piæ pêtl¹ while i wzajemnie. Zwyczajowo obowiazuje zasada, ¿e jeœli iloœæ iteracji jest znana - u¿ywamy for, a jeœli nie jest
            znana (zale¿y od u¿ytkownika lub jakiegoœ stanu zewnêtrznego) - u¿ywamy pêtli while. Pêtla for sk³ada siê z: ZMIENNEJ ITERACYJNEJ,
            czyli stanu pocz¹tkowego pêtli, np. int i = 0. Nastêpnie WARUNKU ZAKOÑCZENIA PÊTLI, np. i<10. Nastêpnie OPERACJI WYKONYWANEJ
            PO KA¯DEJ ITERACJI - zazwyczaj jest to zwiêkszenie iteratora o 1, czyli i = i + 1, b¹dŸ w skrócie i++. Napisaæ pêtlê for, która wyœwietli cyfry
            od 0 do 9.*/
            case 12:
            {
                for(int i=0;i<=9;i++)
                {
                    cout << i << endl;
                }
                 break;
            }
            /*2.7. Pobraæ od u¿ytkownika liczby x i y. Zak³adamy, ¿e y > x (zawsze, nie musimy tego sprawdzaæ). Za pomoc¹ pêtli for wypisaæ liczby
            miêdzy x a y (do przemyœlenia - co jest stanem pocz¹tkowym, a co warunkiem zakoñczenia pêtli?)*/
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
            //2.8. Pobraæ od u¿ytkownika liczbê x. Za pomoc¹ pêtli for wypisaæ wszystkie liczby mniejsze od x, ale wiêksze ni¿ 0.
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
            /*2.9. Pobraæ od u¿ytkownika liczbê x. Za pomoc¹ pêtli for wypisywaæ CO TRZECI¥ liczbê wiêksz¹ od x. Pêtla powinna siê zakoñczyæ, jeœli
            liczba przekroczy 100. Uwaga - proszê nie u¿ywaæ operacji continue i break, a sterowaæ tylko parametrami pêtli.*/
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
            //3.1. Napisaæ metodê void NewLine(). Powinna ona wypisaæ na ekran pojedyncz¹ pust¹ liniê. U¿yæ tej metodê w main().
            case 16:
            {
                NewLine();
                break;
            }
            /*3.2. Napisaæ metodê void NewLines(int count). Powinna ona wypisaæ tyle nowych linii, ile zosta³o podanych W PARAMETRZE count (nale¿y
            u¿yæ pêtli for). U¿yæ metodê w main()*/
            case 17:
            {
                int parametr;
                cout << "Podaj parametr: ";
                cin >> parametr;
                NewLines(parametr);
                break;
            }
            /*3.3. Napisaæ metodê void WriteBiggerNumber(int x, int y). Metoda powinna pobraæ 2 parametry i zwróciæ wiêkszy z nich. Wykorzystaæ
            funckjê w metodzie main(). UWAGA - pobieranie liczb od u¿ytkownika powinno odbyæ siê w funkcji main(), a NIE w WriteBiggerNumber! Do
            funkcji nale¿y jedynie przes³aæ pobrane wczeœniej parametry*/
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
            /*3.4. Napisaæ metodê Multiply(int x, int y) . Metoda powinna ZWRÓCIÆ (s³owo kluczowe return) iloczyn dwóch parametrów. Uwaga! Metoda
            NIE POWINNA wypisywaæ wyniku - powinien on byæ wyœwietlony w funkcji main!*/
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




