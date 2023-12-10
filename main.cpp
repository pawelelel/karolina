#include <iostream>
#include <cstdlib>
#include <time.h>
#include <windows.h>

using namespace std;

struct Wspolrzedne {
    int x, y;
};

struct ListaWspolrzednych {
    Wspolrzedne* lista;
    int rozmiar;
    int ilosc_elementow;
};

ListaWspolrzednych utworzListeWspolrzednych(int rozmiar) {
    ListaWspolrzednych lista;

    lista.lista = new Wspolrzedne[rozmiar];
    lista.rozmiar = rozmiar;
    lista.ilosc_elementow = 0;
    return lista;
}

void dodajElementListaWspolrzednych(ListaWspolrzednych& wspolrzedne, Wspolrzedne element) {

    if (wspolrzedne.ilosc_elementow == wspolrzedne.rozmiar) {
        for (int i = 1; i < wspolrzedne.rozmiar - 1; i++){
            wspolrzedne.lista[i-1] = wspolrzedne.lista[i];
        }

        wspolrzedne.lista[wspolrzedne.rozmiar - 1] = element;
    }
    else {
        wspolrzedne.lista[wspolrzedne.ilosc_elementow] = element;
        wspolrzedne.ilosc_elementow++;
    }
}

void usunElementListaWspolrzednych(ListaWspolrzednych& wspolrzedne, int ktory) {

    if (ktory < wspolrzedne.ilosc_elementow) {
        for (int i = ktory; i < wspolrzedne.rozmiar - 1; i++){
            wspolrzedne.lista[i] = wspolrzedne.lista[i+1];
        }

        wspolrzedne.ilosc_elementow--;
    }
}

void usunOstatniElementListaWspolrzednych(ListaWspolrzednych& wspolrzedne) {

    if (wspolrzedne.ilosc_elementow > 0) {
        wspolrzedne.ilosc_elementow--;
    }
}

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
    ListaWspolrzednych wszystkie_mozliwe_pary = utworzListeWspolrzednych((rozmiar_tablicy-2) * (rozmiar_tablicy - 2));
    for(int i=1;i<rozmiar_tablicy - 1; i++)
    {
        for(int j=1; j< rozmiar_tablicy - 1; j++)
        {
            Wspolrzedne para;
            para.x=i;
            para.y=j;
            dodajElementListaWspolrzednych(wszystkie_mozliwe_pary, para);
        }

    }

    srand(time(NULL));
    for(int i = 0; i<ile; i++)
    {
        int losowanie_par=rand() % wszystkie_mozliwe_pary.ilosc_elementow;
        Wspolrzedne c = wszystkie_mozliwe_pary.lista[losowanie_par];
        tablica[c.y][c.x] = 'o';
        usunElementListaWspolrzednych(wszystkie_mozliwe_pary, losowanie_par);
    }

    return tablica;
}

void menuGry()
{
    cout << endl;
    cout << "w => ruch do góry" << endl;
    cout << "s => ruch w dol" << endl;
    cout << "a => ruch w lewo" << endl;
    cout << "d => ruch w prawo" << endl;
    cout << "o => zaznacz atom" << endl;
    cout << "u => undo" << endl;
    cout << "r => redo" << endl;
    cout << "m => strzal" << endl;
    cout << "k => pokaz punkty i koniec gry" << endl;
    cout << "p => pokaz plansze i koniec gry" << endl;
    cout << "h => pokaz na chwile plansze" << endl;
    cout << "q => koniec gry, menu glowne" << endl;
}

void print5x5(int rozmiar_tablicy, char** tablica_zgadywanek)
{
    cout << "    +---+---+---+---+---+    " << endl;
    cout << "    | " << tablica_zgadywanek[0][1] << " | " << tablica_zgadywanek[0][2] << " | " << tablica_zgadywanek[0][3] << " | " << tablica_zgadywanek[0][4] << " | " << tablica_zgadywanek[0][5] << " |" << endl;
    cout << "+---+---+---+---+---+---+---+" << endl;
    cout << "| " << tablica_zgadywanek[1][0] << " | " << tablica_zgadywanek[1][1] << " | " << tablica_zgadywanek[1][2] << " | " << tablica_zgadywanek[1][3] << " | " << tablica_zgadywanek[1][4] << " | " << tablica_zgadywanek[1][5] << " | " << tablica_zgadywanek[1][6] << " |" << endl;
    cout << "+---+---+---+---+---+---+---+" << endl;
    cout << "| " << tablica_zgadywanek[2][0] << " | " << tablica_zgadywanek[2][1] << " | " << tablica_zgadywanek[2][2] << " | " << tablica_zgadywanek[2][3] << " | " << tablica_zgadywanek[2][4] << " | " << tablica_zgadywanek[2][5] << " | " << tablica_zgadywanek[2][6] << " |" << endl;
    cout << "+---+---+---+---+---+---+---+" << endl;
    cout << "| " << tablica_zgadywanek[3][0] << " | " << tablica_zgadywanek[3][1] << " | " << tablica_zgadywanek[3][2] << " | " << tablica_zgadywanek[3][3] << " | " << tablica_zgadywanek[3][4] << " | " << tablica_zgadywanek[3][5] << " | " << tablica_zgadywanek[3][6] << " |" << endl;
    cout << "+---+---+---+---+---+---+---+" << endl;
    cout << "| " << tablica_zgadywanek[4][0] << " | " << tablica_zgadywanek[4][1] << " | " << tablica_zgadywanek[4][2] << " | " << tablica_zgadywanek[4][3] << " | " << tablica_zgadywanek[4][4] << " | " << tablica_zgadywanek[4][5] << " | " << tablica_zgadywanek[4][6] << " |" << endl;
    cout << "+---+---+---+---+---+---+---+" << endl;
    cout << "| " << tablica_zgadywanek[5][0] << " | " << tablica_zgadywanek[5][1] << " | " << tablica_zgadywanek[5][2] << " | " << tablica_zgadywanek[5][3] << " | " << tablica_zgadywanek[5][4] << " | " << tablica_zgadywanek[5][5] << " | " << tablica_zgadywanek[5][6] << " |" << endl;
    cout << "+---+---+---+---+---+---+---+" << endl;
    cout << "    | " << tablica_zgadywanek[6][1] << " | " << tablica_zgadywanek[6][2] << " | " << tablica_zgadywanek[6][3] << " | " << tablica_zgadywanek[6][4] << " | " << tablica_zgadywanek[6][5] << " |" << endl;
    cout << "    +---+---+---+---+---+    " << endl;
}

void print8x8(int rozmiar_tablicy, char** tablica_zgadywanek)
{
    cout << "    +---+---+---+---+---+---+---+---+    " << endl;
    cout << "    | " << tablica_zgadywanek[0][1] << " | " << tablica_zgadywanek[0][2] << " | " << tablica_zgadywanek[0][3] << " | " << tablica_zgadywanek[0][4] << " | " << tablica_zgadywanek[0][5] << " | " << tablica_zgadywanek[0][6] << " | " << tablica_zgadywanek[0][7] << " | " << tablica_zgadywanek[0][8] << " |" << endl;
    cout << "+---+---+---+---+---+---+---+---+---+---+" << endl;
    cout << "| " << tablica_zgadywanek[1][0] << " | " << tablica_zgadywanek[1][1] << " | " << tablica_zgadywanek[1][2] << " | " << tablica_zgadywanek[1][3] << " | " << tablica_zgadywanek[1][4] << " | " << tablica_zgadywanek[1][5] << " | " << tablica_zgadywanek[1][6] << " | " << tablica_zgadywanek[1][7] << " | " << tablica_zgadywanek[1][8] << " | " << tablica_zgadywanek[1][9] << " |" << endl;
    cout << "+---+---+---+---+---+---+---+---+---+---+" << endl;
    cout << "| " << tablica_zgadywanek[2][0] << " | " << tablica_zgadywanek[2][1] << " | " << tablica_zgadywanek[2][2] << " | " << tablica_zgadywanek[2][3] << " | " << tablica_zgadywanek[2][4] << " | " << tablica_zgadywanek[2][5] << " | " << tablica_zgadywanek[2][6] << " | " << tablica_zgadywanek[2][7] << " | " << tablica_zgadywanek[2][8] << " | " << tablica_zgadywanek[2][9] << " |" << endl;
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
}

void print10x10(int rozmiar_tablicy, char** tablica_zgadywanek)
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
}


bool w_polu(int x, int y, int rozmiar_tablicy)
{
    return (x > 0 && x < rozmiar_tablicy-1 && y > 0 && y < rozmiar_tablicy-1);
}

void strzal(char** tablica_odpowiedzi, char** tablica_zgadywanek, char kierunek, int x, int y, int rozmiar_tablicy, int& szufladka) {

    int start_x = x;
    int start_y = y;

    do {
        switch (kierunek) {
            case 'P': {
                if (tablica_odpowiedzi[y - 1][x+1] == 'o') {
                    kierunek = 'D';
                }
                else if (tablica_odpowiedzi[y][x+1] == 'o') {
                    tablica_zgadywanek[start_y][start_x] = 'H';
                    return;
                }
                else if (tablica_odpowiedzi[y + 1][x+1] == 'o') {
                    kierunek = 'G';
                }
                else {
                    x++;
                }
                break;
            }
            case 'L': {
                if (tablica_odpowiedzi[y - 1][x-1] == 'o') {
                    kierunek = 'G';
                }
                else if (tablica_odpowiedzi[y][x-1] == 'o') {
                    tablica_zgadywanek[start_y][start_x] = 'H';
                    return;
                }
                else if (tablica_odpowiedzi[y + 1][x-1] == 'o') {
                    kierunek = 'D';
                }
                else {
                    x--;
                }
                break;
            }
            case 'G': {
                if (tablica_odpowiedzi[y-1][x - 1] == 'o') {
                    kierunek = 'L';
                }
                else if (tablica_odpowiedzi[y-1][x] == 'o') {
                    tablica_zgadywanek[start_y][start_x] = 'H';
                    return;
                }
                else if (tablica_odpowiedzi[y-1][x + 1] == 'o') {
                    kierunek = 'P';
                }
                else {
                    y--;
                }
                break;
            }
            case 'D': {
                if (tablica_odpowiedzi[y+1][x - 1] == 'o') {
                    kierunek = 'P';
                }
                else if (tablica_odpowiedzi[y+1][x] == 'o') {
                    tablica_zgadywanek[start_y][start_x] = 'H';
                    return;
                }
                else if (tablica_odpowiedzi[y+1][x + 1] == 'o') {
                    kierunek = 'L';
                }
                else {
                    y++;
                }
                break;
            }
        }
    }
    while (w_polu(x, y, rozmiar_tablicy));

    if (start_x == x && start_y == y) {
        tablica_zgadywanek[start_y][start_x] = 'R';
        return;
    }
    tablica_zgadywanek[y][x] = szufladka;
    tablica_zgadywanek[start_y][start_x] = szufladka;
    szufladka++;

}

void gameLoop(char **tablica_odpowiedzi, char** tablica_zgadywanek, int rozmiar_tablicy, int ilosc_atomow)
{
    int focusedX = 0, focusedY = 0;
    int szufladka = '0';

    ListaWspolrzednych undo = utworzListeWspolrzednych(ilosc_atomow);
    ListaWspolrzednych redo = utworzListeWspolrzednych(ilosc_atomow);

    while (true) {
        system("cls");
        switch (rozmiar_tablicy) {
            case 7: {
                print5x5(rozmiar_tablicy, tablica_zgadywanek);
                cout << "x: " << focusedX << " y: " << focusedY << endl;
                menuGry();
                break;
            }
            case 10: {
                print8x8(rozmiar_tablicy, tablica_zgadywanek);
                cout << "x: " << focusedX << " y: " << focusedY << endl;
                menuGry();
                break;
            }
            case 12: {
                print10x10(rozmiar_tablicy, tablica_zgadywanek);
                cout << "x: " << focusedX << " y: " << focusedY << endl;
                menuGry();
                break;
            }
        }

        char key;
        cin >> key;

        switch (toupper(key)) {
            case 'W': {
                if (focusedY > 0) {
                    focusedY--;
                }
                break;
            }
            case 'S': {
                if (focusedY < rozmiar_tablicy) {
                    focusedY++;
                }
                break;
            }
            case 'A': {
                if (focusedX > 0) {
                    focusedX--;
                }
                break;
            }
            case 'D': {
                if (focusedX < rozmiar_tablicy) {
                    focusedX++;
                }
                break;
            }
            case 'Q': {
                return;
            }
            case 'U': {
                if (undo.ilosc_elementow > 0) {
                    Wspolrzedne wspolrzedne = undo.lista[undo.ilosc_elementow - 1];
                    tablica_zgadywanek[wspolrzedne.y][wspolrzedne.x] = ' ';
                    dodajElementListaWspolrzednych(redo, wspolrzedne);
                    usunOstatniElementListaWspolrzednych(undo);
                }
                break;
            }
            case 'R': {
                if (redo.ilosc_elementow > 0) {
                    Wspolrzedne wspolrzedne = redo.lista[redo.ilosc_elementow - 1];
                    tablica_zgadywanek[wspolrzedne.y][wspolrzedne.x] = 'o';
                    dodajElementListaWspolrzednych(undo, wspolrzedne);
                    usunOstatniElementListaWspolrzednych(redo);
                }
                break;
            }
            case 'O': {
                if (focusedX >= 1 && focusedX <= rozmiar_tablicy && focusedY >= 1 && focusedY <= rozmiar_tablicy) {
                    if (tablica_zgadywanek[focusedY][focusedX] == ' ') {
                        tablica_zgadywanek[focusedY][focusedX] = 'o';
                        Wspolrzedne wspolrzedne;
                        wspolrzedne.x = focusedX;
                        wspolrzedne.y = focusedY;
                        dodajElementListaWspolrzednych(undo, wspolrzedne);
                    }
                }
                break;
            }
            case 'K': {
                int sumaWygranych = 0;
                for (int i = 1; i < rozmiar_tablicy - 1; ++i) {
                    for (int j = 1; j < rozmiar_tablicy - 1; ++j) {
                        if (tablica_zgadywanek[i][j] == 'o' && tablica_odpowiedzi[i][j] == 'o') {
                            sumaWygranych++;
                            tablica_odpowiedzi[i][j] = 'O';
                        }
                        else if (tablica_zgadywanek[i][j] == 'o') {
                            tablica_odpowiedzi[i][j] = 'X';
                        }
                    }
                }

                system("cls");
                switch (rozmiar_tablicy) {
                    case 7: {
                        print5x5(rozmiar_tablicy, tablica_odpowiedzi);
                        break;
                    }
                    case 10: {
                        print8x8(rozmiar_tablicy, tablica_odpowiedzi);
                        break;
                    }
                    case 12: {
                        print10x10(rozmiar_tablicy, tablica_odpowiedzi);
                        break;
                    }
                }

                cout << "Koniec. Liczba uzyskanych punktow: " << sumaWygranych << " z " << ilosc_atomow << "." << endl;
                cout << "O => poprawnie oznaczony atom" << endl;
                cout << "o => nieodgadniety atom" << endl;
                cout << "X => błednie oznaczony atom" << endl;

                cout << endl;
                cout << "Nacisnij dowolny klawisz i enter aby kontynuowac" << endl;
                char a;
                cin >> a;

                return;
            }
            case 'P': {
                system("cls");
                switch (rozmiar_tablicy) {
                    case 7: {
                        print5x5(rozmiar_tablicy, tablica_odpowiedzi);
                        break;
                    }
                    case 10: {
                        print8x8(rozmiar_tablicy, tablica_odpowiedzi);
                        break;
                    }
                    case 12: {
                        print10x10(rozmiar_tablicy, tablica_odpowiedzi);
                        break;
                    }
                }

                cout << "Nacisnij dowolny klawisz i enter aby kontynuowac" << endl;
                char a;
                cin >> a;
                return;
            }
            case 'H': {
                system("cls");
                switch (rozmiar_tablicy) {
                    case 7: {
                        print5x5(rozmiar_tablicy, tablica_odpowiedzi);
                        break;
                    }
                    case 10: {
                        print8x8(rozmiar_tablicy, tablica_odpowiedzi);
                        break;
                    }
                    case 12: {
                        print10x10(rozmiar_tablicy, tablica_odpowiedzi);
                        break;
                    }
                }

                Sleep(5000);

                break;
            }
            case 'M': {
                if (tablica_odpowiedzi[focusedY][focusedX] != ' ') {
                }
                else if (focusedX == 0 && focusedY == 0) {
                }
                else if (focusedX == rozmiar_tablicy && focusedY == rozmiar_tablicy) {
                }
                else if (focusedY == 0) {
                    strzal(tablica_odpowiedzi, tablica_zgadywanek, 'D', focusedX, focusedY, rozmiar_tablicy, szufladka);
                }
                else if (focusedY == rozmiar_tablicy) {
                    strzal(tablica_odpowiedzi, tablica_zgadywanek, 'G', focusedX, focusedY, rozmiar_tablicy, szufladka);
                }
                else if (focusedX == 0) {
                    strzal(tablica_odpowiedzi, tablica_zgadywanek, 'P', focusedX, focusedY, rozmiar_tablicy, szufladka);
                }
                else if (focusedX == rozmiar_tablicy) {
                    strzal(tablica_odpowiedzi, tablica_zgadywanek, 'L', focusedX, focusedY, rozmiar_tablicy, szufladka);
                }
                break;
            }
        }
    }
}

char menuGlowne()
{
    system("cls");
    cout << endl;

    cout << "    ____    _                  _        ____                      _____                              " << endl;
    cout << "   |  _ \\  | |                | |      |  _ \\                    / ____|                             " << endl;
    cout << "   | |_) | | |   __ _    ___  | | __   | |_) |   ___   __  __   | |  __    __ _   _ __ ___     ___   " << endl;
    cout << "   |  _ <  | |  / _` |  / __| | |/ /   |  _ <   / _ \\  \\ \\/ /   | | |_ |  / _` | | '_ ` _ \\   / _ \\  " << endl;
    cout << "   | |_) | | | | (_| | | (__  |   <    | |_) | | (_) |  >  <    | |__| | | (_| | | | | | | | |  __/  " << endl;
    cout << "   |____/  |_|  \\__,_|  \\___| |_|\\_\\   |____/   \\___/  /_/\\_\\    \\_____|  \\__,_| |_| |_| |_|  \\___|  " << endl;
    cout << "                                                                                                     " << endl;
    cout << "                                                                                                     " << endl;

    cout << "Autor: Karolina Pioterek (nr indeksu 197843)" << endl;
    cout << endl;

    cout << "Wybierz stopien trudnosci gry:" << endl;
    cout << "1 => plansza 5x5 (3 atomy)" << endl;
    cout << "2 => plansza 8x8 (6 atomow)" << endl;
    cout << "3 => plansza 10x10 (8 atomow)" << endl;
    cout << "q => wyjscie" << endl;

    char rezultat_wybrania_z_menu;
    cin >> rezultat_wybrania_z_menu;
    return rezultat_wybrania_z_menu;
}

int main()
{

    int tablica[5];

    while (true)
    {
        system("cls");
        int rezultat_wybrania_z_menu = menuGlowne();

        char **tablica_odpowiedzi;
        char **tablica_zgadywanek;
        int rozmiar_tablicy;
        int ilosc_atomow;

        switch (toupper(rezultat_wybrania_z_menu))
        {
            case '1':
            {
                rozmiar_tablicy = 7;
                ilosc_atomow = 3;
                tablica_odpowiedzi = tworzenie_tablicy_dwu_wymiarowej(rozmiar_tablicy);
                tablica_zgadywanek = tworzenie_tablicy_dwu_wymiarowej(rozmiar_tablicy);
                losuj(rozmiar_tablicy, tablica_odpowiedzi, ilosc_atomow);
                gameLoop(tablica_odpowiedzi, tablica_zgadywanek, rozmiar_tablicy, ilosc_atomow);
                break;
            }
            case '2':
            {
                rozmiar_tablicy = 10;
                ilosc_atomow = 6;
                tablica_odpowiedzi = tworzenie_tablicy_dwu_wymiarowej(rozmiar_tablicy);
                tablica_zgadywanek = tworzenie_tablicy_dwu_wymiarowej(rozmiar_tablicy);
                losuj(rozmiar_tablicy, tablica_odpowiedzi, ilosc_atomow);
                gameLoop(tablica_odpowiedzi, tablica_zgadywanek, rozmiar_tablicy, ilosc_atomow);
                break;
            }
            case '3':
            {
                rozmiar_tablicy = 12;
                ilosc_atomow = 8;
                tablica_odpowiedzi = tworzenie_tablicy_dwu_wymiarowej(rozmiar_tablicy);
                tablica_zgadywanek = tworzenie_tablicy_dwu_wymiarowej(rozmiar_tablicy);
                losuj(rozmiar_tablicy, tablica_odpowiedzi, ilosc_atomow);
                gameLoop(tablica_odpowiedzi, tablica_zgadywanek, rozmiar_tablicy, ilosc_atomow);
                break;
            }
            case 'Q':
            {
                return 0;
            }
        }

        delete tablica_odpowiedzi;
        delete tablica_zgadywanek;
    }
}
