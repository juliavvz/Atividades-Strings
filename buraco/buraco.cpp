#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    string baralho[2][52];
    string mao[4][11];
    int cartasRestantes[2][52];
    int naipe, numero, baralhoNum, i, j, pos;
    
    srand(time(NULL));
    
    for(baralhoNum = 0; baralhoNum < 2; baralhoNum++) {
        pos = 0;
        for(naipe = 1; naipe <= 4; naipe++) {
            for(numero = 1; numero <= 13; numero++) {
                baralho[baralhoNum][pos] = to_string(naipe) + "-" + to_string(numero) + "-" + to_string(baralhoNum + 1);
                cartasRestantes[baralhoNum][pos] = 1;
                pos++;
            }
        }
    }
    
    for(i = 0; i < 4; i++) {
        for(j = 0; j < 11; j++) {
            do {
                baralhoNum = rand() % 2;
                pos = rand() % 52;
            } while(cartasRestantes[baralhoNum][pos] == 0);
            
            mao[i][j] = baralho[baralhoNum][pos];
            cartasRestantes[baralhoNum][pos] = 0;
        }
    }
    
    cout << "========================================" << endl;
    cout << "           DISTRIBUICAO DAS CARTAS       " << endl;
    cout << "========================================" << endl << endl;
    
    for(i = 0; i < 4; i++) {
        cout << "JOGADOR " << i + 1 << ":" << endl;
        cout << "----------------------------------------" << endl;
        for(j = 0; j < 11; j++) {
            cout << mao[i][j] << "  ";
        }
        cout << endl << endl;
    }
    
    system("pause");
    return 0;
}
