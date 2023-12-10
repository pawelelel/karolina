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
    for(int i=1;i<rozmiar_tablicy - 1; i++)
    {
        for(int j=1; j< rozmiar_tablicy - 1; j++)
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
        int losownie_par=rand() % wszystkie_mozliwe_pary.size();
        pair<int,int> c = wszystkie_mozliwe_pary[losownie_par];
        tablica[c.first][c.second] = 'o';
        wszystkie_mozliwe_pary.erase(wszystkie_mozliwe_pary.begin()+losownie_par);
    }

    return tablica;
}

char** stala_tablica(int rozmiar_tablicy, char** tablica, int ile)
{
    tablica[1][2] = 'o';
    tablica[2][2] = 'o';
    return tablica;
}

char** wypelnij_tablice(int rozmiar_tablicy, char** tablica, int ile)
{
    // return losuj(rozmiar_tablicy, tablica, ile);
    return stala_tablica(rozmiar_tablicy, tablica, ile);
}

void print5x5(int rozmiar_tablicy, char** tablica_zgadywanek, int focusedX, int focusedY)
{
    cout << "    +---+---+---+---+---+    " << endl;
    cout << "    | " << tablica_zgadywanek[0][1] << " | " << tablica_zgadywanek[0][2] << " | " << tablica_zgadywanek[0][3] << " | " << tablica_zgadywanek[0][4] << " | " << tablica_zgadywanek[0][5] << " |" << endl;
    cout << "+---+---+---+---+---+---+---+" << endl;
    cout << "| " << tablica_zgadywanek[1][0] << " | " << tablica_zgadywanek[1][1] << " | " << tablica_zgadywanek[1][2] << " | " << tablica_zgadywanek[1][3] << " | " << tablica_zgadywanek[1][4] << " | " << tablica_zgadywanek[1][5] << " | " << tablica_zgadywanek[1][6] << " |" << endl;
    cout << "+---+---+---+---+---+---+---+" << endl;
    cout << "| " << tablica_zgadywanek[2][0] << " | " << tablica_zgadywanek[2][1] << " | " << tablica_zgadywanek[2][2] << " | " << tablica_zgadywanek[1][3] << " | " << tablica_zgadywanek[1][4] << " | " << tablica_zgadywanek[1][5] << " | " << tablica_zgadywanek[1][6] << " |" << endl;
    cout << "+---+---+---+---+---+---+---+" << endl;
    cout << "| " << tablica_zgadywanek[3][0] << " | " << tablica_zgadywanek[3][1] << " | " << tablica_zgadywanek[3][2] << " | " << tablica_zgadywanek[3][3] << " | " << tablica_zgadywanek[3][4] << " | " << tablica_zgadywanek[3][5] << " | " << tablica_zgadywanek[3][6] << " |" << endl;
    cout << "+---+---+---+---+---+---+---+" << endl;
    cout << "| " << tablica_zgadywanek[4][0] << " | " << tablica_zgadywanek[4][1] << " | " << tablica_zgadywanek[4][2] << " | " << tablica_zgadywanek[4][3] << " | " << tablica_zgadywanek[4][4] << " | " << tablica_zgadywanek[4][5] << " | " << tablica_zgadywanek[4][6] << " |" << endl;
    cout << "+---+---+---+---+---+---+---+" << endl;
    cout << "| " << tablica_zgadywanek[5][0] << " | " << tablica_zgadywanek[5][1] << " | " << tablica_zgadywanek[5][2] << " | " << tablica_zgadywanek[5][3] << " | " << tablica_zgadywanek[5][4] << " | " << tablica_zgadywanek[5][5] << " | " << tablica_zgadywanek[5][6] << " |" << endl;
    cout << "+---+---+---+---+---+---+---+" << endl;
    cout << "    | " << tablica_zgadywanek[6][1] << " | " << tablica_zgadywanek[6][2] << " | " << tablica_zgadywanek[6][3] << " | " << tablica_zgadywanek[6][4] << " | " << tablica_zgadywanek[6][5] << " |" << endl;
    cout << "    +---+---+---+---+---+    " << endl;
    cout << "x: " << focusedX << " y: " << focusedY << endl;
}

void print8x8(int rozmiar_tablicy, char** tablica_zgadywanek, int focusedX, int focusedY)
{
    cout << "    +---+---+---+---+---+---+---+---+    " << endl;
    cout << "    | " << tablica_zgadywanek[0][1] << " | " << tablica_zgadywanek[0][2] << " | " << tablica_zgadywanek[0][3] << " | " << tablica_zgadywanek[0][4] << " | " << tablica_zgadywanek[0][5] << " | " << tablica_zgadywanek[0][6] << " | " << tablica_zgadywanek[0][7] << " | " << tablica_zgadywanek[0][8] << " |" << endl;
    cout << "+---+---+---+---+---+---+---+---+---+---+" << endl;
    cout << "| " << tablica_zgadywanek[1][0] << " | " << tablica_zgadywanek[1][1] << " | " << tablica_zgadywanek[1][2] << " | " << tablica_zgadywanek[1][3] << " | " << tablica_zgadywanek[1][4] << " | " << tablica_zgadywanek[1][5] << " | " << tablica_zgadywanek[1][6] << " | " << tablica_zgadywanek[1][7] << " | " << tablica_zgadywanek[1][8] << " | " << tablica_zgadywanek[1][9] << " |" << endl;
    cout << "+---+---+---+---+---+---+---+---+---+---+" << endl;
    cout << "| " << tablica_zgadywanek[2][0] << " | " << tablica_zgadywanek[2][1] << " | " << tablica_zgadywanek[2][2] << " | " << tablica_zgadywanek[1][3] << " | " << tablica_zgadywanek[1][4] << " | " << tablica_zgadywanek[1][5] << " | " << tablica_zgadywanek[1][6] << " | " << tablica_zgadywanek[1][7] << " | " << tablica_zgadywanek[1][8] << " | " << tablica_zgadywanek[1][9] << " |" << endl;
    cout << "+---+---+---+---+---+---+---+---+---+---+" << endl;
    cout << "| " << tablica_zgadywanek[3][0] << " | " << tablica_zgadywanek[3][1] << " | " << tablica_zgadywanek[3][2] << " | " << tablica_zgadywanek[3][3] << " | " << tablica_zgadywanek[3][4] << " | " << tablica_zgadywanek[3][5] << " | " << tablica_zgadywanek[3][6] << " | " << tablica_zgadywanek[3][7] << " | " << tablica_zgadywanek[3][8] << " | " << tablica_zgadywanek[3][9] << " |" << endl;
    cout << "+---+---+---+---+---+---+---+---+---+---+" << endl;
    cout << "| " << tablica_zgadywanek[4][0] << " | " << tablica_zgadywanek[4][1] << " | " << tablica_zgadywanek[4][2] << " | " << tablica_zgadywanek[4][3] << " | " << tablica_zgadywanek[4][4] << " | " << tablica_zgadywanek[4][5] << " | " << tablica_zgadywanek[4][6] << " | " << tablica_zgadywanek[4][7] << " | " << tablica_zgadywanek[4][8] << " | " << tablica_zgadywanek[4][9] << " |" << endl;
    cout << "+---+---+---+---+---+---+---+---+---+---+" << endl;
    cout << "| " << tablica_zgadywanek[5][0] << " | " << tablica_zgadywanek[5][1] << " | " << tablica_zgadywanek[5][2] << " | " << tablica_zgadywanek[5][3] << " | " << tablica_zgadywanek[5][4] << " | " << tablica_zgadywanek[5][5] << " | " << tablica_zgadywanek[5][6] << " | " << tablica_zgadywanek[5][7] << " | " << tablica_zgadywanek[5][8] << " | " << tablica_zgadywanek[5][9] << " |" << endl;
    cout << "+---+---+---+---+---+---+---+---+---+---+" << endl;
    cout << "| " << tablica_zgadywanek[6][0] << " | " << tablica_zgadywanek[6][1] << " | " << tablica_zgadywanek[6][2] << " | " << tablica_zgadywanek[6][3] << " | " << tablica_zgadywanek[6][4] << " | " << tablica_zgadywanek[6][5] << " | " << tablica_zgadywanek[6][6] << " | " << tablica_zgadywanek[6][7] << " | " << tablica_zgadywanek[6][8] << " | " << tablica_zgadywanek[6][9] << " |" << endl;
    cout << "+---+---+---+---+---+---+---+---+---+---+" << endl;
    cout << "| " << tablica_zgadywanek[7][0] << " | " << tablica_zgadywanek[7][1] << " | " << tablica_zgadywanek[7][2] << " | " << tablica_zgadywanek[7][3] << " | " << tablica_zgadywanek[7][4] << " | " << tablica_zgadywanek[7][5] << " | " << tablica_zgadywanek[7][6] << " | " << tablica_zgadywanek[7][7] << " | " << tablica_zgadywanek[7][8] << " | " << tablica_zgadywanek[7][9] << " |" << endl;
    cout << "+---+---+---+---+---+---+---+---+---+---+" << endl;
    cout << "| " << tablica_zgadywanek[8][0] << " | " << tablica_zgadywanek[8][1] << " | " << tablica_zgadywanek[8][2] << " | " << tablica_zgadywanek[8][3] << " | " << tablica_zgadywanek[8][4] << " | " << tablica_zgadywanek[8][5] << " | " << tablica_zgadywanek[8][6] << " | " << tablica_zgadywanek[8][7] << " | " << tablica_zgadywanek[8][8] << " | " << tablica_zgadywanek[8][9] << " |" << endl;
    cout << "+---+---+---+---+---+---+---+---+---+---+" << endl;
    cout << "    | " << tablica_zgadywanek[9][1] << " | " << tablica_zgadywanek[9][2] << " | " << tablica_zgadywanek[9][3] << " | " << tablica_zgadywanek[9][4] << " | " << tablica_zgadywanek[9][5] << " | " << tablica_zgadywanek[9][6] << " | " << tablica_zgadywanek[9][7] << " | " << tablica_zgadywanek[9][8] << " |" << endl;
    cout << "    +---+---+---+---+---+---+---+---+    " << endl;
    cout << "x: " << focusedX << " y: " << focusedY << endl;
}

void print10x10(int rozmiar_tablicy, char** tablica_zgadywanek, int focusedX, int focusedY)
{
    cout << "    +---+---+---+---+---+---+---+---+---+---+    " << endl;
    cout << "    | " << tablica_zgadywanek[0][1] << " | " << tablica_zgadywanek[0][2] << " | " << tablica_zgadywanek[0][3] << " | " << tablica_zgadywanek[0][4] << " | " << tablica_zgadywanek[0][5] << " | " << tablica_zgadywanek[0][6] << " | " << tablica_zgadywanek[0][7] << " | " << tablica_zgadywanek[0][8] << " | " << tablica_zgadywanek[0][9] << " | " << tablica_zgadywanek[0][10] << " |" << endl;
    cout << "+---+---+---+---+---+---+---+---+---+---+---+---+" << endl;
    cout << "| " << tablica_zgadywanek[1][0] << " | " << tablica_zgadywanek[1][1] << " | " << tablica_zgadywanek[1][2] << " | " << tablica_zgadywanek[1][3] << " | " << tablica_zgadywanek[1][4] << " | " << tablica_zgadywanek[1][5] << " | " << tablica_zgadywanek[1][6] << " | " << tablica_zgadywanek[1][7] << " | " << tablica_zgadywanek[1][8] << " | " << tablica_zgadywanek[1][9] << " | " << tablica_zgadywanek[1][10] << " | " << tablica_zgadywanek[1][11] << " |" << endl;
    cout << "+---+---+---+---+---+---+---+---+---+---+---+---+" << endl;
    cout << "| " << tablica_zgadywanek[2][0] << " | " << tablica_zgadywanek[2][1] << " | " << tablica_zgadywanek[2][2] << " | " << tablica_zgadywanek[2][3] << " | " << tablica_zgadywanek[2][4] << " | " << tablica_zgadywanek[2][5] << " | " << tablica_zgadywanek[2][6] << " | " << tablica_zgadywanek[2][7] << " | " << tablica_zgadywanek[2][8] << " | " << tablica_zgadywanek[2][9] << " | " << tablica_zgadywanek[2][10] << " | " << tablica_zgadywanek[2][11] << " |" << endl;
    cout << "+---+---+---+---+---+---+---+---+---+---+---+---+" << endl;
    cout << "| " << tablica_zgadywanek[3][0] << " | " << tablica_zgadywanek[3][1] << " | " << tablica_zgadywanek[3][2] << " | " << tablica_zgadywanek[3][3] << " | " << tablica_zgadywanek[3][4] << " | " << tablica_zgadywanek[3][5] << " | " << tablica_zgadywanek[3][6] << " | " << tablica_zgadywanek[3][7] << " | " << tablica_zgadywanek[3][8] << " | " << tablica_zgadywanek[3][9] << " | " << tablica_zgadywanek[3][10] << " | " << tablica_zgadywanek[3][11] << " |" << endl;
    cout << "+---+---+---+---+---+---+---+---+---+---+---+---+" << endl;
    cout << "| " << tablica_zgadywanek[4][0] << " | " << tablica_zgadywanek[4][1] << " | " << tablica_zgadywanek[4][2] << " | " << tablica_zgadywanek[4][3] << " | " << tablica_zgadywanek[4][4] << " | " << tablica_zgadywanek[4][5] << " | " << tablica_zgadywanek[4][6] << " | " << tablica_zgadywanek[4][7] << " | " << tablica_zgadywanek[4][8] << " | " << tablica_zgadywanek[4][9] << " | " << tablica_zgadywanek[4][10] << " | " << tablica_zgadywanek[1][11] << " |" << endl;
    cout << "+---+---+---+---+---+---+---+---+---+---+---+---+" << endl;
    cout << "| " << tablica_zgadywanek[5][0] << " | " << tablica_zgadywanek[5][1] << " | " << tablica_zgadywanek[5][2] << " | " << tablica_zgadywanek[5][3] << " | " << tablica_zgadywanek[5][4] << " | " << tablica_zgadywanek[5][5] << " | " << tablica_zgadywanek[5][6] << " | " << tablica_zgadywanek[5][7] << " | " << tablica_zgadywanek[5][8] << " | " << tablica_zgadywanek[5][9] << " | " << tablica_zgadywanek[5][10] << " | " << tablica_zgadywanek[5][11] << " |" << endl;
    cout << "+---+---+---+---+---+---+---+---+---+---+---+---+" << endl;
    cout << "| " << tablica_zgadywanek[6][0] << " | " << tablica_zgadywanek[6][1] << " | " << tablica_zgadywanek[6][2] << " | " << tablica_zgadywanek[6][3] << " | " << tablica_zgadywanek[6][4] << " | " << tablica_zgadywanek[6][5] << " | " << tablica_zgadywanek[6][6] << " | " << tablica_zgadywanek[6][7] << " | " << tablica_zgadywanek[6][8] << " | " << tablica_zgadywanek[6][9] << " | " << tablica_zgadywanek[6][10] << " | " << tablica_zgadywanek[6][11] << " |" << endl;
    cout << "+---+---+---+---+---+---+---+---+---+---+---+---+" << endl;
    cout << "| " << tablica_zgadywanek[7][0] << " | " << tablica_zgadywanek[7][1] << " | " << tablica_zgadywanek[7][2] << " | " << tablica_zgadywanek[7][3] << " | " << tablica_zgadywanek[7][4] << " | " << tablica_zgadywanek[7][5] << " | " << tablica_zgadywanek[7][6] << " | " << tablica_zgadywanek[7][7] << " | " << tablica_zgadywanek[7][8] << " | " << tablica_zgadywanek[7][9] << " | " << tablica_zgadywanek[7][10] << " | " << tablica_zgadywanek[7][11] << " |" << endl;
    cout << "+---+---+---+---+---+---+---+---+---+---+---+---+" << endl;
    cout << "| " << tablica_zgadywanek[8][0] << " | " << tablica_zgadywanek[8][1] << " | " << tablica_zgadywanek[8][2] << " | " << tablica_zgadywanek[8][3] << " | " << tablica_zgadywanek[8][4] << " | " << tablica_zgadywanek[8][5] << " | " << tablica_zgadywanek[8][6] << " | " << tablica_zgadywanek[8][7] << " | " << tablica_zgadywanek[8][8] << " | " << tablica_zgadywanek[8][9] << " | " << tablica_zgadywanek[8][10] << " | " << tablica_zgadywanek[8][11] << " |" << endl;
    cout << "+---+---+---+---+---+---+---+---+---+---+---+---+" << endl;
    cout << "| " << tablica_zgadywanek[9][0] << " | " << tablica_zgadywanek[9][9] << " | " << tablica_zgadywanek[9][2] << " | " << tablica_zgadywanek[9][3] << " | " << tablica_zgadywanek[9][4] << " | " << tablica_zgadywanek[9][5] << " | " << tablica_zgadywanek[9][6] << " | " << tablica_zgadywanek[9][7] << " | " << tablica_zgadywanek[9][8] << " | " << tablica_zgadywanek[9][9] << " | " << tablica_zgadywanek[9][10] << " | " << tablica_zgadywanek[9][11] << " |" << endl;
    cout << "+---+---+---+---+---+---+---+---+---+---+---+---+" << endl;
    cout << "| " << tablica_zgadywanek[10][0] << " | " << tablica_zgadywanek[10][1] << " | " << tablica_zgadywanek[10][2] << " | " << tablica_zgadywanek[10][3] << " | " << tablica_zgadywanek[10][4] << " | " << tablica_zgadywanek[10][5] << " | " << tablica_zgadywanek[10][6] << " | " << tablica_zgadywanek[10][7] << " | " << tablica_zgadywanek[10][8] << " | " << tablica_zgadywanek[10][9] << " | " << tablica_zgadywanek[10][10] << " | " << tablica_zgadywanek[10][11] << " |" << endl;
    cout << "+---+---+---+---+---+---+---+---+---+---+---+---+" << endl;
    cout << "    | " << tablica_zgadywanek[11][1] << " | " << tablica_zgadywanek[11][2] << " | " << tablica_zgadywanek[11][3] << " | " << tablica_zgadywanek[11][4] << " | " << tablica_zgadywanek[11][5] << " | " << tablica_zgadywanek[11][6] << " | " << tablica_zgadywanek[11][7] << " | " << tablica_zgadywanek[11][8] << " | " << tablica_zgadywanek[11][9] << " | " << tablica_zgadywanek[11][10] << " |" << endl;
    cout << "    +---+---+---+---+---+---+---+---+---+---+    " << endl;
    cout << "x: " << focusedX << " y: " << focusedY << endl;
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
    string keys = "wWaAsSdDqQuUrRokpH mM";

    if (keys.find(c) != -1)
    {
        return true;
    }

    return false;
}

bool out(int x, int y, int rozmiar_tablicy)
{
    if (x > 0 && x < rozmiar_tablicy - 1 && y > 0 && y < rozmiar_tablicy - 1)
    {
        return true;
    }

    return false;
}

void ustawDxy(int rozmiar_tablicy, int x, int y, int& dX, int& dY) {

    if (x == 0)
    {
        dX = 1, dY = 0;
    } else if (x == rozmiar_tablicy - 1)
    {
        dX = -1, dY = 0;
    } else if(y == 0)
    {
        dY = 1, dX = 0;
    } else if(y == rozmiar_tablicy - 1)
    {
        dY = -1, dX = 0;
    }
}

void strzal(char **tablica_odpowiedzi, char** tablica_zgadywanek, int rozmiar_tablicy, int startX, int startY, int& szufladka)
{
    int x = startX, y = startY;
    int dX, dY;
    ustawDxy(rozmiar_tablicy, x, y, dX, dY);

    do
    {
        if (dX == 0)
        {
            if (x != 0 && tablica_odpowiedzi[y + dY][x - 1] == 'o')
            {
                dX = dY;
                dY = 0;
            }
            else if (tablica_odpowiedzi[y + dY][x] == 'o')
            {
                tablica_zgadywanek[startY][startX] = 'H';
                return;
            }
            else if (x != rozmiar_tablicy - 1 && tablica_odpowiedzi[y + dY][x + 1] == 'o')
            {
                dX = -dY;
                dY = 0;
            }
            else {
                x += dX;
                y += dY;
            }
        } else
        {
            if (y != 0 && tablica_odpowiedzi[y - 1][x + dX] == 'o')
            {
                dY = dX;
                dX = 0;
            }
            else if (tablica_odpowiedzi[y][x + dX] == 'o')
            {
                tablica_zgadywanek[startY][startX] = 'H';
                return;
            }
            else if (y != rozmiar_tablicy - 1 && tablica_odpowiedzi[y + 1][x + dX] == 'o')
            {
                dY = -dX;
                dX = 0;
            }
            else {
                x += dX;
                y += dY;
            }
        }
    } while (out(x, y, rozmiar_tablicy));

    if (x == startX && y == startY)
    {
        tablica_zgadywanek[startY][startX] = 'R';
        return;
    }

    tablica_zgadywanek[startY][startX] = szufladka;
    tablica_zgadywanek[y][x] = szufladka;
    szufladka++;
}

void gameLoop(char **tablica_odpowiedzi, char** tablica_zgadywanek, int rozmiar_tablicy)
{
    int focusedX = 0, focusedY = 0;
    int szufladka = '0';

    vector<pair<int, int>> undo;
    vector<pair<int, int>> redo;

    while (true)
    {
        system("cls");
        switch (rozmiar_tablicy)
        {
            case 7:
            {
                print5x5(rozmiar_tablicy, tablica_zgadywanek, focusedX, focusedY);
                break;
            }
            case 10:
            {
                print8x8(rozmiar_tablicy, tablica_zgadywanek, focusedX, focusedY);
                break;
            }
            case 12:
            {
                print10x10(rozmiar_tablicy, tablica_zgadywanek, focusedX, focusedY);
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
                    if (focusedY > 0)
                    {
                        focusedY--;
                    }
                    break;
                }
                case 'S':
                {
                    if (focusedY < rozmiar_tablicy)
                    {
                        focusedY++;
                    }
                    break;
                }
                case 'A':
                {
                    if (focusedX > 0)
                    {
                        focusedX--;
                    }
                    break;
                }
                case 'D':
                {
                    if (focusedX < rozmiar_tablicy)
                    {
                        focusedX++;
                    }
                    break;
                }
                case 'Q':
                {
                    return;
                }
                case 'U':
                {
                    if (!undo.empty())
                    {
                        tablica_zgadywanek[undo.back().second][undo.back().first] = ' ';
                        redo.push_back(undo.back());
                        undo.erase(undo.end() - 1);
                    }
                    break;
                }
                case 'R':
                {
                    if (!redo.empty())
                    {
                        tablica_zgadywanek[redo.back().second][redo.back().first] = 'o';
                        undo.push_back(redo.back());
                        redo.erase(redo.end() - 1);
                    }
                    break;
                }
                case 'O':
                {
                    tablica_zgadywanek[focusedY][focusedX] = 'o';
                    pair<int, int> p;
                    p.first = focusedX;
                    p.second = focusedY;
                    undo.push_back(p);
                    break;
                }
                case 'K':
                {
                    int sumaWygranych = 0;
                    for (int i = 1; i < rozmiar_tablicy - 1; ++i)
                    {
                        for (int j = 1; j < rozmiar_tablicy - 1; ++j)
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
                        case 7:
                        {
                            print5x5(rozmiar_tablicy, tablica_odpowiedzi, -1, -1);
                            break;
                        }
                        case 10:
                        {
                            print8x8(rozmiar_tablicy, tablica_odpowiedzi, -1, -1);
                            break;
                        }
                        case 12:
                        {
                            print10x10(rozmiar_tablicy, tablica_odpowiedzi, -1, -1);
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
                        case 7:
                        {
                            print5x5(rozmiar_tablicy, tablica_odpowiedzi, focusedX, focusedY);
                            break;
                        }
                        case 10:
                        {
                            print8x8(rozmiar_tablicy, tablica_odpowiedzi, focusedX, focusedY);
                            break;
                        }
                        case 12:
                        {
                            print10x10(rozmiar_tablicy, tablica_odpowiedzi, focusedX, focusedY);
                            break;
                        }
                    }

                    Sleep(5000);

                    break;
                }
                case 'M':
                {
                    // do zrobienia
                    if (focusedX == 0 || focusedY == 0 || focusedX == rozmiar_tablicy - 1 || focusedY == rozmiar_tablicy - 1)
                    {
                        strzal(tablica_odpowiedzi, tablica_zgadywanek, rozmiar_tablicy, focusedX, focusedY, szufladka);
                    }
                    break;
                }
            }
        }
    }
}

struct s{

};

struct s1{
    s tab[5];
};


int main()
{
    s1 aaa = {
            {s{}, s{}, s{}}
    };
    int tablica[5];

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
                tablica_odpowiedzi = tworzenie_tablicy_dwu_wymiarowej(7);
                tablica_zgadywanek = tworzenie_tablicy_dwu_wymiarowej(7);
                wypelnij_tablice(7, tablica_odpowiedzi, 3);
                rozmiar_tablicy = 7;
                gameLoop(tablica_odpowiedzi, tablica_zgadywanek, rozmiar_tablicy);
                break;
            }
            case 2:
            {
                tablica_odpowiedzi = tworzenie_tablicy_dwu_wymiarowej(10);
                tablica_zgadywanek = tworzenie_tablicy_dwu_wymiarowej(10);
                wypelnij_tablice(10, tablica_odpowiedzi, 6);
                rozmiar_tablicy = 10;
                gameLoop(tablica_odpowiedzi, tablica_zgadywanek, rozmiar_tablicy);
                break;
            }
            case 3:
            {
                tablica_odpowiedzi = tworzenie_tablicy_dwu_wymiarowej(12);
                tablica_zgadywanek = tworzenie_tablicy_dwu_wymiarowej(12);
                wypelnij_tablice(12, tablica_odpowiedzi, 8);
                rozmiar_tablicy = 12;
                gameLoop(tablica_odpowiedzi, tablica_zgadywanek, rozmiar_tablicy);
                break;
            }
            case 4:
            {
                // ustawienia
                continue;
            }
            case 5:
            {
                exit(0);
            }
        }

        delete tablica_odpowiedzi, tablica_zgadywanek;
    }
}
