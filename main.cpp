#include <iostream>
#include <cstdlib>
#include <time.h>
#include <vector>
#include<windows.h>

using namespace std;

char** tworzenie_tablicy_dwu_wymiarowej(int rozmiar_tablicy)
{
    char** tablica = new char*[rozmiar_tablicy];
    for(int i=0; i<rozmiar_tablicy; i++)
    {
        tablica[i]=new char[rozmiar_tablicy];
        for (int j=0; j<rozmiar_tablicy; j++)
        {
            tablica[i][j]=' ';
        }
    }

    return tablica;
}

char** losuj(int rozmiar_tablicy, char** tablica, int ile)
{
    vector<pair<int, int>>wszystkie_mozliwe_pary;
    for(int i=0;i<rozmiar_tablicy; i++)
    {
        for(int j=0; j< rozmiar_tablicy; j++)
        {
            pair<int,int>para;
            para.first=i;
            para.second=j;
            wszystkie_mozliwe_pary.push_back(para);
        }

    }
    // wylosowany indeks- losowanie par

    srand(time(NULL));
    for(int i = 0; i<ile; i++)
    {
        int losownie_par=rand()% wszystkie_mozliwe_pary.size();
        pair<int,int> c = wszystkie_mozliwe_pary[losownie_par];
        tablica[c.first][c.second] = 'o';
        wszystkie_mozliwe_pary.erase(wszystkie_mozliwe_pary.begin()+losownie_par);
    }

    return tablica;
}

void print5x5(int rozmiar_tablicy, char** tablica_zgadywanek, string gora, string dol, string prawa, string lewa, int focusedX, int focusedY)
{
    cout<< "    +---+---+---+---+---+    "<< endl;
    cout<< "    | "<<gora[0]<<" | "<<gora[1]<<" | "<<gora[2]<<" | "<<gora[3]<<" | "<<gora[4]<<" |"<<endl;
    cout<< "+---+---+---+---+---+---+---+"<<endl;
    cout<< "| "<<prawa[0]<<" | "<< tablica_zgadywanek[0][0]<<" | "<< tablica_zgadywanek[0][1]<<" | "<< tablica_zgadywanek[0][2]<<" | "<< tablica_zgadywanek[0][3]<<" | "<< tablica_zgadywanek[0][4]<<" | "<<lewa[0]<<" |"<< endl;
    cout<< "+---+---+---+---+---+---+---+"<<endl;
    cout<< "| "<<prawa[0]<<" | "<< tablica_zgadywanek[1][0]<<" | "<< tablica_zgadywanek[1][1]<<" | "<< tablica_zgadywanek[1][2]<<" | "<< tablica_zgadywanek[1][3]<<" | "<< tablica_zgadywanek[1][4]<<" | "<<lewa[0]<<" |"<< endl;
    cout<< "+---+---+---+---+---+---+---+"<<endl;
    cout<< "| "<<prawa[0]<<" | "<< tablica_zgadywanek[2][0]<<" | "<< tablica_zgadywanek[2][1]<<" | "<< tablica_zgadywanek[2][2]<<" | "<< tablica_zgadywanek[2][3]<<" | "<< tablica_zgadywanek[2][4]<<" | "<<lewa[0]<<" |"<< endl;
    cout<< "+---+---+---+---+---+---+---+"<<endl;
    cout<< "| "<<prawa[0]<<" | "<< tablica_zgadywanek[3][0]<<" | "<< tablica_zgadywanek[3][1]<<" | "<< tablica_zgadywanek[3][2]<<" | "<< tablica_zgadywanek[3][3]<<" | "<< tablica_zgadywanek[3][4]<<" | "<<lewa[0]<<" |"<< endl;
    cout<< "+---+---+---+---+---+---+---+"<<endl;
    cout<< "| "<<prawa[0]<<" | "<< tablica_zgadywanek[4][0]<<" | "<< tablica_zgadywanek[4][1]<<" | "<< tablica_zgadywanek[4][2]<<" | "<< tablica_zgadywanek[4][3]<<" | "<< tablica_zgadywanek[4][4]<<" | "<<lewa[0]<<" |"<< endl;
    cout<< "+---+---+---+---+---+---+---+"<<endl;
    cout<< "    | "<<dol[0]<<" | "<<dol[1]<<" | "<<dol[2]<<" | "<<dol[3]<<" | "<<dol[4]<<" |"<<endl;
    cout<< "    +---+---+---+---+---+    "<< endl;

}

void print8x8(int rozmiar_tablicy, char** tablica_zgadywanek, string gora, string dol, string prawa, string lewa, int focusedX, int focusedY)
{
    cout<< "    +---+---+---+---+---+---+---+---+    "<< endl;
    cout<< "    | "<<gora[0]<<" | "<<gora[1]<<" | "<<gora[2]<<" | "<<gora[3]<<" | "<<gora[4]<<" | "<<gora[5]<<" | "<<gora[6]<<" | "<<gora[7]<<" | "<<gora[8]<<endl;
    cout<< "+---+---+---+---+---+---+---+---+---+---+"<<endl;
    cout<< "| "<<prawa[0]<<" | "<< tablica_zgadywanek[0][0]<<" | "<< tablica_zgadywanek[0][1]<<" | "<< tablica_zgadywanek[0][2]<<" | "<< tablica_zgadywanek[0][3]<<" | "<< tablica_zgadywanek[0][4]<<" | "<<tablica_zgadywanek[0][3]<<" | "<< tablica_zgadywanek[0][3]<<" | "<< tablica_zgadywanek[0][4]<<" | "<<lewa[0]<<" |"<< endl;
    cout<< "+---+---+---+---+---+---+---+---+---+---+"<<endl;
    cout<< "| "<<prawa[0]<<" | "<< tablica_zgadywanek[1][0]<<" | "<< tablica_zgadywanek[1][1]<<" | "<< tablica_zgadywanek[1][2]<<" | "<< tablica_zgadywanek[1][3]<<" | "<< tablica_zgadywanek[1][4]<<" | "<<tablica_zgadywanek[1][3]<<" | "<< tablica_zgadywanek[1][3]<<" | "<< tablica_zgadywanek[1][4]<<" | "<<lewa[0]<<" |"<< endl;
    cout<< "+---+---+---+---+---+---+---+---+---+---+"<<endl;
    cout<< "| "<<prawa[0]<<" | "<< tablica_zgadywanek[2][0]<<" | "<< tablica_zgadywanek[2][1]<<" | "<< tablica_zgadywanek[2][2]<<" | "<< tablica_zgadywanek[2][3]<<" | "<< tablica_zgadywanek[2][4]<<" | "<<tablica_zgadywanek[2][3]<<" | "<< tablica_zgadywanek[2][3]<<" | "<< tablica_zgadywanek[2][4]<<" | "<<lewa[0]<<" |"<< endl;
    cout<< "+---+---+---+---+---+---+---+---+---+---+"<<endl;
    cout<< "| "<<prawa[0]<<" | "<< tablica_zgadywanek[3][0]<<" | "<< tablica_zgadywanek[3][1]<<" | "<< tablica_zgadywanek[3][2]<<" | "<< tablica_zgadywanek[3][3]<<" | "<< tablica_zgadywanek[3][4]<<" | "<<tablica_zgadywanek[3][3]<<" | "<< tablica_zgadywanek[3][3]<<" | "<< tablica_zgadywanek[3][4]<<" | "<<lewa[0]<<" |"<< endl;
    cout<< "+---+---+---+---+---+---+---+---+---+---+"<<endl;
    cout<< "| "<<prawa[0]<<" | "<< tablica_zgadywanek[4][0]<<" | "<< tablica_zgadywanek[4][1]<<" | "<< tablica_zgadywanek[4][2]<<" | "<< tablica_zgadywanek[4][3]<<" | "<< tablica_zgadywanek[4][4]<<" | "<<tablica_zgadywanek[4][3]<<" | "<< tablica_zgadywanek[4][3]<<" | "<< tablica_zgadywanek[4][4]<<" | "<<lewa[0]<<" |"<< endl;
    cout<< "+---+---+---+---+---+---+---+---+---+---+"<<endl;
    cout<< "| "<<prawa[0]<<" | "<< tablica_zgadywanek[5][0]<<" | "<< tablica_zgadywanek[5][1]<<" | "<< tablica_zgadywanek[5][2]<<" | "<< tablica_zgadywanek[5][3]<<" | "<< tablica_zgadywanek[5][4]<<" | "<<tablica_zgadywanek[5][3]<<" | "<< tablica_zgadywanek[5][3]<<" | "<< tablica_zgadywanek[5][4]<<" | "<<lewa[0]<<" |"<< endl;
    cout<< "+---+---+---+---+---+---+---+---+---+---+"<<endl;
    cout<< "| "<<prawa[0]<<" | "<< tablica_zgadywanek[6][0]<<" | "<< tablica_zgadywanek[6][1]<<" | "<< tablica_zgadywanek[6][2]<<" | "<< tablica_zgadywanek[6][3]<<" | "<< tablica_zgadywanek[6][4]<<" | "<<tablica_zgadywanek[6][3]<<" | "<< tablica_zgadywanek[6][3]<<" | "<< tablica_zgadywanek[6][4]<<" | "<<lewa[0]<<" |"<< endl;
    cout<< "+---+---+---+---+---+---+---+---+---+---+"<<endl;
    cout<< "| "<<prawa[0]<<" | "<< tablica_zgadywanek[7][0]<<" | "<< tablica_zgadywanek[7][1]<<" | "<< tablica_zgadywanek[7][2]<<" | "<< tablica_zgadywanek[7][3]<<" | "<< tablica_zgadywanek[7][4]<<" | "<<tablica_zgadywanek[7][3]<<" | "<< tablica_zgadywanek[7][3]<<" | "<< tablica_zgadywanek[7][4]<<" | "<<lewa[0]<<" |"<< endl;
    cout<< "+---+---+---+---+---+---+---+---+---+---+"<<endl;
    cout<< "    | "<<dol[0]<<" | "<<dol[1]<<" | "<<dol[2]<<" | "<<dol[3]<<" | "<<dol[4]<<" | "<<dol[5]<<" | "<<dol[6]<<" | "<<dol[7]<<" | "<<dol[8]<<endl;
    cout<< "    +---+---+---+---+---+---+---+---+    "<< endl;
}

void print10x10(int rozmiar_tablicy, char** tablica_zgadywanek, string gora, string dol, string prawa, string lewa, int focusedX, int focusedY)
{
    cout<< "    +---+---+---+---+---+---+---+---+---+---+   "<< endl;
    cout<< "    | "<<gora[0]<<" | "<<gora[1]<<" | "<<gora[2]<<" | "<<gora[3]<<" | "<<gora[4]<<" | "<<gora[5]<<" | "<<gora[6]<<" | "<<gora[7]<<" | "<<gora[8]<<" | " << gora[9] << " |"<<endl;
    cout<< "+---+---+---+---+---+---+---+---+---+---+---+---+"<<endl;
    cout<< "| "<<prawa[0]<<" | "<< tablica_zgadywanek[0][0]<<" | "<< tablica_zgadywanek[0][1]<<" | "<< tablica_zgadywanek[0][2]<<" | "<< tablica_zgadywanek[0][3]<<" | "<< tablica_zgadywanek[0][4]<<" | "<<tablica_zgadywanek[0][5]<<" | "<< tablica_zgadywanek[0][6]<<" | "<< tablica_zgadywanek[0][7]<<" | "<< tablica_zgadywanek[0][8]<<" | "<< tablica_zgadywanek[0][9]<<" | "<<lewa[0]<<" |"<< endl;
    cout<< "+---+---+---+---+---+---+---+---+---+---+---+---+"<<endl;
    cout<< "| "<<prawa[0]<<" | "<< tablica_zgadywanek[1][0]<<" | "<< tablica_zgadywanek[1][1]<<" | "<< tablica_zgadywanek[1][2]<<" | "<< tablica_zgadywanek[1][3]<<" | "<< tablica_zgadywanek[1][4]<<" | "<<tablica_zgadywanek[1][5]<<" | "<< tablica_zgadywanek[1][6]<<" | "<< tablica_zgadywanek[1][7]<<" | "<< tablica_zgadywanek[0][8]<<" | "<< tablica_zgadywanek[0][9]<<" | "<<lewa[0]<<" |"<< endl;
    cout<< "+---+---+---+---+---+---+---+---+---+---+---+---+"<<endl;
    cout<< "| "<<prawa[0]<<" | "<< tablica_zgadywanek[2][0]<<" | "<< tablica_zgadywanek[2][1]<<" | "<< tablica_zgadywanek[2][2]<<" | "<< tablica_zgadywanek[2][3]<<" | "<< tablica_zgadywanek[2][4]<<" | "<<tablica_zgadywanek[2][5]<<" | "<< tablica_zgadywanek[2][6]<<" | "<< tablica_zgadywanek[2][7]<<" | "<< tablica_zgadywanek[0][8]<<" | "<< tablica_zgadywanek[0][9]<<" | "<<lewa[0]<<" |"<< endl;
    cout<< "+---+---+---+---+---+---+---+---+---+---+---+---+"<<endl;
    cout<< "| "<<prawa[0]<<" | "<< tablica_zgadywanek[3][0]<<" | "<< tablica_zgadywanek[3][1]<<" | "<< tablica_zgadywanek[3][2]<<" | "<< tablica_zgadywanek[3][3]<<" | "<< tablica_zgadywanek[3][4]<<" | "<<tablica_zgadywanek[3][5]<<" | "<< tablica_zgadywanek[3][6]<<" | "<< tablica_zgadywanek[3][7]<<" | "<< tablica_zgadywanek[0][8]<<" | "<< tablica_zgadywanek[0][9]<<" | "<<lewa[0]<<" |"<< endl;
    cout<< "+---+---+---+---+---+---+---+---+---+---+---+---+"<<endl;
    cout<< "| "<<prawa[0]<<" | "<< tablica_zgadywanek[4][0]<<" | "<< tablica_zgadywanek[4][1]<<" | "<< tablica_zgadywanek[4][2]<<" | "<< tablica_zgadywanek[4][3]<<" | "<< tablica_zgadywanek[4][4]<<" | "<<tablica_zgadywanek[4][5]<<" | "<< tablica_zgadywanek[4][6]<<" | "<< tablica_zgadywanek[4][7]<<" | "<< tablica_zgadywanek[0][8]<<" | "<< tablica_zgadywanek[0][9]<<" | "<<lewa[0]<<" |"<< endl;
    cout<< "+---+---+---+---+---+---+---+---+---+---+---+---+"<<endl;
    cout<< "| "<<prawa[0]<<" | "<< tablica_zgadywanek[5][0]<<" | "<< tablica_zgadywanek[5][1]<<" | "<< tablica_zgadywanek[5][2]<<" | "<< tablica_zgadywanek[5][3]<<" | "<< tablica_zgadywanek[5][4]<<" | "<<tablica_zgadywanek[5][5]<<" | "<< tablica_zgadywanek[5][6]<<" | "<< tablica_zgadywanek[5][7]<<" | "<< tablica_zgadywanek[0][8]<<" | "<< tablica_zgadywanek[0][9]<<" | "<<lewa[0]<<" |"<< endl;
    cout<< "+---+---+---+---+---+---+---+---+---+---+---+---+"<<endl;
    cout<< "| "<<prawa[0]<<" | "<< tablica_zgadywanek[6][0]<<" | "<< tablica_zgadywanek[6][1]<<" | "<< tablica_zgadywanek[6][2]<<" | "<< tablica_zgadywanek[6][3]<<" | "<< tablica_zgadywanek[6][4]<<" | "<<tablica_zgadywanek[6][5]<<" | "<< tablica_zgadywanek[6][6]<<" | "<< tablica_zgadywanek[6][7]<<" | "<< tablica_zgadywanek[0][8]<<" | "<< tablica_zgadywanek[0][9]<<" | "<<lewa[0]<<" |"<< endl;
    cout<< "+---+---+---+---+---+---+---+---+---+---+---+---+"<<endl;
    cout<< "| "<<prawa[0]<<" | "<< tablica_zgadywanek[7][0]<<" | "<< tablica_zgadywanek[7][1]<<" | "<< tablica_zgadywanek[7][2]<<" | "<< tablica_zgadywanek[7][3]<<" | "<< tablica_zgadywanek[7][4]<<" | "<<tablica_zgadywanek[7][5]<<" | "<< tablica_zgadywanek[7][6]<<" | "<< tablica_zgadywanek[7][7]<<" | "<< tablica_zgadywanek[0][8]<<" | "<< tablica_zgadywanek[0][9]<<" | "<<lewa[0]<<" |"<< endl;
    cout<< "+---+---+---+---+---+---+---+---+---+---+---+---+"<<endl;
    cout<< "| "<<prawa[0]<<" | "<< tablica_zgadywanek[8][0]<<" | "<< tablica_zgadywanek[8][1]<<" | "<< tablica_zgadywanek[8][2]<<" | "<< tablica_zgadywanek[8][3]<<" | "<< tablica_zgadywanek[8][4]<<" | "<<tablica_zgadywanek[8][5]<<" | "<< tablica_zgadywanek[8][6]<<" | "<< tablica_zgadywanek[8][7]<<" | "<< tablica_zgadywanek[0][8]<<" | "<< tablica_zgadywanek[0][9]<<" | "<<lewa[0]<<" |"<< endl;
    cout<< "+---+---+---+---+---+---+---+---+---+---+---+---+"<<endl;
    cout<< "| "<<prawa[0]<<" | "<< tablica_zgadywanek[9][0]<<" | "<< tablica_zgadywanek[9][1]<<" | "<< tablica_zgadywanek[9][2]<<" | "<< tablica_zgadywanek[9][3]<<" | "<< tablica_zgadywanek[9][4]<<" | "<<tablica_zgadywanek[9][5]<<" | "<< tablica_zgadywanek[9][6]<<" | "<< tablica_zgadywanek[9][7]<<" | "<< tablica_zgadywanek[0][8]<<" | "<< tablica_zgadywanek[0][9]<<" | "<<lewa[0]<<" |"<< endl;
    cout<< "+---+---+---+---+---+---+---+---+---+---+---+---+"<<endl;
    cout<< "    | "<<dol[0]<<" | "<<dol[1]<<" | "<<dol[2]<<" | "<<dol[3]<<" | "<<dol[4]<<" | "<<dol[5]<<" | "<<dol[6]<<" | "<<dol[7]<<" | "<<dol[8]<<" | " << dol[9] << " |"<<endl;
    cout<< "    +---+---+---+---+---+---+---+---+---+---+    "<< endl;
}

int menu()
{
    system("cls");

    cout << "Wybierz stopien trudnosci: " << endl;
    cout << "uzyj w i s" << endl;
    cout << "1=> 5x5 " << endl;
    cout << "2=> 8x8 " << endl;
    cout << "3=> 10x10 " << endl;
    cout << "4=> ustawienia klawiszy" << endl;
    cout << "5=> wyjscie" << endl;

    int rezultat_wybrania_z_menu;
    cin >> rezultat_wybrania_z_menu;
    return rezultat_wybrania_z_menu;
}

bool validation(char c)
{
    string keys = "wWaAsSdDqQuUrRokpH ";

    if (keys.find(c) != -1)
    {
        return true;
    }

    return false;
}

void gameLoop(char **tablica_odpowiedzi, char** tablica_zgadywanek, int rozmiar_tablicy)
{
    string gora, dol, prawa, lewa;
    int focusedX = 0, focusedY = 0;

    for (int i = 0; i < rozmiar_tablicy; ++i)
    {
        gora += ' ';
        dol += ' ';
        prawa += ' ';
        lewa += ' ';
    }

    while (true)
    {
        system("cls");
        switch (rozmiar_tablicy)
        {
            case 5:
            {
                print5x5(rozmiar_tablicy, tablica_zgadywanek, gora, dol, prawa, lewa, focusedX, focusedY);
                break;
            }
            case 8:
            {
                print8x8(rozmiar_tablicy, tablica_zgadywanek, gora, dol, prawa, lewa, focusedX, focusedY);
                break;
            }
            case 10:
            {
                print10x10(rozmiar_tablicy, tablica_zgadywanek, gora, dol, prawa, lewa, focusedX, focusedY);
                break;
            }
        }
        char key;
        cin >> key;
        if (validation(key))
        {
            switch (toupper(key))
            {
                case 'W':
                {
                    focusedY--;
                    break;
                }
                case 'S':
                {
                    focusedY++;
                    break;
                }
                case 'A':
                {
                    focusedX--;
                    break;
                }
                case 'D':
                {
                    focusedX++;
                    break;
                }
                case 'Q':
                {
                    return;
                }
                case 'U':
                {
                    // do zrobienia
                    // undo
                    break;
                }
                case 'R':
                {
                    // do zrobienia
                    // redo
                    break;
                }
                case 'O':
                {
                    tablica_zgadywanek[focusedY][focusedX] = 'o';
                    break;
                }
                case 'K':
                {
                    int sumaWygranych = 0;
                    for (int i = 0; i < rozmiar_tablicy; ++i)
                    {
                        for (int j = 0; j < rozmiar_tablicy; ++j)
                        {
                            if (tablica_zgadywanek[i][j] == 'o' && tablica_odpowiedzi[i][j] == 'o')
                            {
                                sumaWygranych++;
                            }
                        }
                    }

                    cout << "Koniec. Liczba uzyskanych punktow: " << sumaWygranych << endl;
                    cout << "Nacisnij enter by kontynuowac." << endl;
                    char a;
                    cin >> a;
                    return;
                }
                case 'P':
                {
                    system("cls");
                    switch (rozmiar_tablicy)
                    {
                        case 5:
                        {
                            print5x5(rozmiar_tablicy, tablica_odpowiedzi, gora, dol, prawa, lewa, -1, -1);
                            break;
                        }
                        case 8:
                        {
                            print8x8(rozmiar_tablicy, tablica_odpowiedzi, gora, dol, prawa, lewa, -1, -1);
                            break;
                        }
                        case 10:
                        {
                            print10x10(rozmiar_tablicy, tablica_odpowiedzi, gora, dol, prawa, lewa, -1, -1);
                            break;
                        }
                    }
                    cout << "Nacisnij dowolny przycisk i enter aby kontynuowac" << endl;
                    char a;
                    cin >> a;
                    return;
                }
                case 'H':
                {
                    system("cls");
                    switch(rozmiar_tablicy)
                    {
                        case 5:
                        {
                            print5x5(rozmiar_tablicy, tablica_odpowiedzi, gora, dol, prawa, lewa, focusedX, focusedY);
                            break;
                        }
                        case 8:
                        {
                            print8x8(rozmiar_tablicy, tablica_odpowiedzi, gora, dol, prawa, lewa, focusedX, focusedY);
                            break;
                        }
                        case 10:
                        {
                            print10x10(rozmiar_tablicy, tablica_odpowiedzi, gora, dol, prawa, lewa, focusedX, focusedY);
                            break;
                        }
                    }

                    Sleep(1000);

                    break;
                }
                case ' ':
                {
                    // do zrobienia
                    // strzal jak jest zfocusowana linia
                    break;
                }
            }
        }
    }
}

int main()
{
    while (true)
    {
        system("cls");
        int rezultat_wybrania_z_menu = menu();

        char **tablica_odpowiedzi;
        char **tablica_zgadywanek;
        int rozmiar_tablicy;

        switch (rezultat_wybrania_z_menu)
        {
            case 1:
            {
                tablica_odpowiedzi = tworzenie_tablicy_dwu_wymiarowej(5);
                tablica_zgadywanek = tworzenie_tablicy_dwu_wymiarowej(5);
                losuj(5, tablica_odpowiedzi, 3);
                rozmiar_tablicy = 5;
                gameLoop(tablica_odpowiedzi, tablica_zgadywanek, rozmiar_tablicy);
                break;
            }
            case 2:
            {
                tablica_odpowiedzi = tworzenie_tablicy_dwu_wymiarowej(8);
                tablica_zgadywanek = tworzenie_tablicy_dwu_wymiarowej(8);
                losuj(8, tablica_odpowiedzi, 6);
                rozmiar_tablicy = 8;
                gameLoop(tablica_odpowiedzi, tablica_zgadywanek, rozmiar_tablicy);
                break;
            }
            case 3:
            {
                tablica_odpowiedzi = tworzenie_tablicy_dwu_wymiarowej(10);
                tablica_zgadywanek = tworzenie_tablicy_dwu_wymiarowej(10);
                losuj(10, tablica_odpowiedzi, 8);
                rozmiar_tablicy = 10;
                gameLoop(tablica_odpowiedzi, tablica_zgadywanek, rozmiar_tablicy);
                break;
            }
            case 4:
            {
                // ustawienia
                continue;
                //break;
            }
            case 5:
            {
                exit(0);
                break;
            }
        }

        delete tablica_odpowiedzi, tablica_zgadywanek;
    }
}