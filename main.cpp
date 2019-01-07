#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

bool IsSorted(int *tab, int s)
{
    for(int i=1;i<=s;i++)
    {
        if(tab[i]>tab[i+1])
        {
            return 0;
        }
    }
    return 1;
}

void printBackwards(int *tab, int s)
{
    for(int i=s-1;i>=0;i--)
    {
        cout << tab[i] << endl;
    }
}

void printDots(int *tab, int s)
{
    for(int i=0;i<s;i++)
    {
        for(int x=0;x<tab[i];x++)
        {
            cout << ".";
        }
        cout << endl;
    }
}

int Sum(int *tab, int s)
{
    int suma = 0;
    for(int i=0;i<s;i++)
    {
        suma=suma+tab[i];
    }
    cout << "Suma elementow tablicy wynosi: " << suma << endl;
}

int getLength(char *str)
{
    int i=0;
    while(str[i] != '\0')
    {
        i++;
    }
    return i;
}

void Reverse (char *str)
{
    for(int i=getLength(str);i>=0;i--)
    {
        cout << str[i];
    }
}

bool containsDigits(char * str)
{
    for(int i=0;i<getLength(str);i++)
    {
        if(isdigit(str[i]))
        {
            return true;
        }
    }
    return false;
}

bool AreArraysldentical(int * a1, int s1, int * a2, int s2)
{
    if(s1==s2)
    {
        for(int i=0;i<s1;i++)
        {
            cout << i << " element tablicy a1 jest rowny " << i << " elementowi tablicy a2" << endl;
        }
    }
    else
    {
        cout << "Podane tablice nie sa identyczne" << endl;
    }
}

char *reverseString(char *s)
{

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
            //1.1. Utworzyæ 5-cio elementow¹ tablicê typu int. Pobraæ od u¿ytkownika 5 elementów i dodac je do tablicy. Nastêpnie wyœwietliæ najwiêksz¹ liczbê z tablicy.
            case 1:
            {
                int tab[5];
                cout << "Podaj 5 elementow tablicy: " << endl;
                cin >> tab[0];
                cin >> tab[1];
                cin >> tab[2];
                cin >> tab[3];
                cin >> tab[4];

                int x = tab[0];
                for(int i=1;i<=sizeof(tab[5]);i++)
                {
                    if(x < tab[i])
                    {
                        x = tab[i];
                    }
                }
                cout << "Najwieksza liczba z podanych to: " << x << endl;
                break;
            }
            //1.2. Wyœwietliæ w pêtli tablice z zadania 1.1 od pocz¹tku i od koñca
            case 2:
            {
                int tab[5];
                cout << "Podaj 5 elementow tablicy: " << endl;
                cin >> tab[0];
                cin >> tab[1];
                cin >> tab[2];
                cin >> tab[3];
                cin >> tab[4];

                cout << "Podana tablica od poczatku: " << endl;
                for(int i=0;i<=sizeof(tab[5]);i++)
                {
                    cout << tab[i] << endl;
                }

                cout << "Podana tablica od konca: " << endl;
                for(int i=4;i<=sizeof(tab[5]);i--)
                {
                    cout << tab[i] << endl;
                }
                break;
            }
            //Napisaæ algorytm sprawdzajacy, czy tablica jest posortowana w kolejnoœci niemalej¹cej
            case 3:
            {
                int tab[5];
                cout << "Podaj 5 elementow tablicy: " << endl;
                cin >> tab[0];
                cin >> tab[1];
                cin >> tab[2];
                cin >> tab[3];
                cin >> tab[4];

                int x;
                for(int i=1;i<=sizeof(tab[5]);i++)
                {
                    if(tab[i]>tab[i+1])
                    {
                        x=1;
                    }
                }
                if(x==1)
                {
                    cout << "Tablica nie jest niemalejaca" << endl;
                }
                else
                {
                     cout << "Tablica jest niemalejaca" << endl;
                }
                break;
            }
            //2.1. Utworzyæ osobn¹ metodê bool IsSorted(int *, int) realizuj¹c¹ zadanie 1.3 (UWAGA - w jêzyku C niedostêpny jest typ bool z wartoœciami true i false, zamiast niego nale¿y u¿yæ int i wartoœci 1 i 0)
            case 4:
            {
                int tab[5];
                cout << "Podaj 5 elementow tablicy: " << endl;
                cin >> tab[0];
                cin >> tab[1];
                cin >> tab[2];
                cin >> tab[3];
                cin >> tab[4];

                if(IsSorted(tab,sizeof(tab[5])))
                {
                    cout << "Tablica jest niemalejaca" << endl;
                }
                else
                {
                     cout << "Tablica nie jest niemalejaca" << endl;
                }
                break;
            }
            //2.2. Utworzyæ metodê void printBackwards(int *a, int s) s³u¿¹c¹ do wypisania tablicy OD KOÑCA
            case 5:
            {
                int tab[5];
                cout << "Podaj 5 elementow tablicy: " << endl;
                cin >> tab[0];
                cin >> tab[1];
                cin >> tab[2];
                cin >> tab[3];
                cin >> tab[4];

                cout << "Podana tablica od konca " << endl;
                printBackwards(tab, 5);
                break;
            }
            //2.3 Utworzyæ metodê printDots(int *a, int s) wyœwietlaj¹c¹ w nowych liniach tyle kropek, ile znajduje siê w danym
            //elemencie tablicy.
            case 6:
            {
                int tab[]={1,2,3,4};
                printDots(tab, 4);
                break;
            }
            //2.4. Utworzyæ metodê int Sum(int *a, int s) licz¹c¹ sumê elementów tablicy.
            case 7:
            {
                int tab[]={1,2,30,4};
                Sum(tab, 4);
                break;
            }
            //2.5. Zaimplementowaæ algorytm sortowania b¹belkowego (w funkcji main(), nie ma potrzeby tworzenia dodatkowej
            //funkcji).Algorytm powinien posortowaæ dowolnie du¿¹ tablicê w kolejnoœci niemalej¹cej.
            case 8:
            {
                int s = 20;
                int tab[s];

                for(int i=0;i<s;i++)
                {
                    tab[i]=rand();
                }


                    int temp;
                    bool x = false;

                    while(x==false)
                    {
                        x = true;
                        for(int i=1;i<s;i++)
                        {
                            if(tab[i]<tab[i-1])
                            {
                                x = false;
                                temp = tab[i];
                                tab[i] = tab[i-1];
                                tab[i-1] = temp;
                            }
                        }
                    }


                for(int i=0;i<s;i++)
                {
                    cout << tab[i] << endl;
                }
                break;
            }
            //Napisaæ metodê int getLength(char *str) , w której W£ASNORECZNIE (nie wolno korzystaæ z metody strlen() )
            //przeliczony zostanie rozmiar ³añcucha(bez null - terminatora).Dla przyk³adu dla „Hello!" wynik powinien wynosiæ 6.
            case 9:
            {
                char str[]="Hello!";
                cout << "Rozmiar stringa wynosi " << getLength(str) << endl;
                break;
            }
            //3.2. Napisaæ metodê void Reverse (char *str) , która wypisze ³añcuch znaków od koñca (zakaz u¿ywania strlen,
            //mo¿na uzyæ metodê z zadania 3.1.)
            case 10:
            {
                char str[]="Hello!";
                Reverse(str);
                cout << endl;
                break;
            }
            //3.3.Napisaæ metodê bool containsDigits(char * str), która zwróci informacjê, czy w danym stringu znajduje siê
            //jakakolwiek cyfra.Dla przyk³adu : „asdfgzxcv" -> false, „asdf5asdf" -> true
            case 11:
            {
                char str[]="asdfasdf";
                if(containsDigits(str))
                {
                    cout << "String zawiera liczby" << endl;
                }
                else
                {
                    cout << "String nie zawiera liczb" << endl;
                }
                break;
            }
            //3.4. Pobraæ od u¿ytkownika ³añcuch znaków (dowolna metoda). Przekazaæ go do ka¿dej z metod z 3. czêœci zadañ.
            case 12:
            {
                char str[]="";
                cout << "Podaj lancuch znakow: ";
                cin >> str;

                cout << "Rozmiar stringa wynosi " << getLength(str) << endl;

                cout << "String od tylu ";
                Reverse(str);
                cout << endl;

                if(containsDigits(str))
                {
                    cout << "String zawiera liczby" << endl;
                }
                else
                {
                    cout << "String nie zawiera liczb" << endl;
                }
                break;
            }
            //4.1. Pobraæ od u¿ytkownika liczbê n. Zaalokowaæ pamiêæ na n elementów int i pobraæ je od u¿ytkownika. Wykonaæ na
            //niej metodê printBackwards z 2.2.
            case 13:
            {
                int * tab;
                int n;
                cout << "Podaj liczbe n: " << endl;
                cin >> n;

                tab=(int*)malloc(sizeof(int)*n);

                for(int i=0;i<n;i++)
                {
                    cout << "Podaj " << i << " element tablicy" << endl;
                    cin >> tab[i];
                }

                printBackwards(tab, n);
                free(tab);
                break;
            }
            //4.2.Pobraæ od u¿ytkownika liczbê n.Zaalokowaæ pamiêæ na n elementów int i pobraæ je od u¿ytkownika.Nastêpnie
            //zaalokowaæ pamiêæ i utworzyæ tablicê, w której bêd¹ tylko UJEMNE wartoœci z pierwszej tablicy.Na koniec zwolniæ
            //pamiêæ na obie tablice.
            case 14:
            {
                int * tab;
                int n;
                cout << "Podaj liczbe n: " << endl;
                cin >> n;

                tab=(int*)malloc(sizeof(int)*n);

                for(int i=0;i<n;i++)
                {
                    cout << "Podaj " << i << " element tablicy" << endl;
                    cin >> tab[i];
                }

                int i=0;
                int m=0;
                while(i<n)
                {
                    if(tab[i]<0)
                    {
                        m++;
                    }
                    i++;
                }

                int * tabminus;
                tabminus=(int*)malloc(sizeof(int)*m);

                for(int i=0,j=0;i<n;i++)
                {
                    if(tab[i]<0)
                    {
                        tabminus[j]=tab[i];
                        j++;
                    }
                }

                cout << "Tablica liczb ujemnych: " << endl;
                for(int i=0;i<m;i++)
                {
                    cout << tabminus[i] << endl;
                }
                free(tab);
                free(tabminus);

                break;
            }
            //4.3. Napisaæ metodê bool AreArraysldentical(int * al, int sl, int * a2, int s2) zwracaj¹c¹ informacjê, czy dwie tablice
            //podane jako parametr s¹ identyczne, tj.czy maj¹ tak¹ sam¹ d³ugoœæ i czy na ka¿dym indeksie wystêpuje taki sam
            //element.
            case 15:
            {
                int * a1;
                int s1;
                cout << "Podaj rozmiar tablicy a1: " << endl;
                cin >> s1;

                a1=(int*)malloc(sizeof(int)*s1);

                for(int i=0;i<s1;i++)
                {
                    cout << "Podaj " << i << " element tablicy a1" << endl;
                    cin >> a1[i];
                }

                int * a2;
                int s2;
                cout << "Podaj rozmiar tablicy a2: " << endl;
                cin >> s2;

                a2=(int*)malloc(sizeof(int)*s2);

                for(int i=0;i<s2;i++)
                {
                    cout << "Podaj " << i << " element tablicy a2" << endl;
                    cin >> a2[i];
                }

                AreArraysldentical(a1, s1, a2, s2);
                free(a1);
                free(a2);
                break;
            }
            //4.4. Napisać metodę char * reverseString(char*s), która ZWRÓCI (a nie wypisze!) string, który jest odwróconym
            //stringiem przekazanym jako pierwszy parametr.Funkcja zaalokuje pamięć na nowy łańcuch i go zwróci. (cały
            //algorytm należy zaimplementować samodzielnie).Należy go następnie „przechwycić" w funkcji main, aby pamięć na
            //koniec wyczyścić

            //Po wielu próbach nie udało mi się wykonać tego zadania.
            case 16:
            {
                char s[100];

                char *result = reverseString(s);



                free(s);
                free(result);

                break;
            }
            default:
            {

                cout << "Nie ma takiego zadania" << endl;
                break;
            }

        }
    }
}
