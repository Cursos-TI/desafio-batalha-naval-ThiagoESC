#include <stdio.h>

#define HABLINHA 3
#define HABCOLUNA 5

void aplicarHabilidade(int tabuleiro[10][10], int habilidade[HABLINHA][HABCOLUNA], int origem_x, int origem_y) {
    int offset_linha = origem_x - HABLINHA / 2;
    int offset_coluna = origem_y - HABCOLUNA / 2;

    for (int i = 0; i < HABLINHA; i++) {
        for (int j = 0; j < HABCOLUNA; j++) {
            if (habilidade[i][j] != 0) {
                int linha = offset_linha + i;
                int coluna = offset_coluna + j;
                if (linha >= 0 && linha < 10 && coluna >= 0 && coluna < 10) {
                    tabuleiro[linha][coluna] = habilidade[i][j];
                }
            }
        }
    }
}

int main (){
    //Declaração de variáveis
    char coluna[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int tabuleiro[10][10] = {0};
    int habilidade[HABLINHA][HABCOLUNA] = {0};

    //Imprimindo o tabuleiro vazio na tela
    printf("*** JOGO DE BATALHA NAVAL ***\n\n");
    printf("   ");

    for (int i = 0; i < 10; i++){ 
        printf("%c ", coluna[i]);
    }
    printf("\n");

    for (int i = 0; i < 10; i++){
        printf("%2d ", i + 1);
        for (int j = 0; j < 10; j++){
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    //Setando o primeiro navio - linha 2 da coluna 2 a 4
    for (int i = 2; i <=4; i++){
        tabuleiro[2][i] == 0 ? tabuleiro[2][i] = 3 : 0;
    }

    //Setando o segundo navio - linha 7 a 9 da coluna 6
    for (int i = 7; i <= 9; i++){
        tabuleiro[i][6] == 0 ? tabuleiro[i][6] = 3 : 0;
    }

    // Setando o terceiro navio - [8,0][7,1][6,2]
    int x = 8;
    int y = 0;
    for (int k = 0; k < 3; k++) {
        if (tabuleiro[x][y] == 0){
            tabuleiro[x][y] = 3;
        } else {
            printf("Erro: sobreposição de navios em (%d, %d)", x, y);
            break;
        }
        x--;
        y++;
    }

    //Setando o quarto navio - [4,6][5,7][6,8]
     x = 4;
     y = 6;
    for (int k = 0; k < 3; k++){
        if (tabuleiro[x][y] == 0){
            tabuleiro[x][y] = 3;
        } else {
            printf("Erro: sobreposição de navios em (%d, %d)", x, y);
            break;
        }
        x++;
        y++;
    }
    
    //Criando a primeira habilidade CONE
    printf("\n");
    for (int i = 0; i < HABLINHA; i++){
        for (int j = 0; j < HABCOLUNA; j++){
            if (i == 2 || (i == 1 && j != 0 && j != 4) || (i == 0 && j == 2)){
                habilidade[i][j] = 5;
            } else {habilidade[i][j] = 0;}
            printf("%d ", habilidade[i][j]);
        }
        printf("\n");
    }
    aplicarHabilidade(tabuleiro, habilidade, 1, 7);

    //Criando a segunda habilidade CRUZ
    printf("\n");
    for (int i = 0; i < HABLINHA; i++){
        for (int j = 0; j < HABCOLUNA; j++){
            if (i == 1 || j == 2){
                habilidade[i][j] = 5;
            } else {habilidade[i][j] = 0;}
            printf("%d ", habilidade[i][j]);
        }
        printf("\n");
    }
    aplicarHabilidade(tabuleiro, habilidade, 8, 3);

    //Criando a terceira habilidade Octaedro
    printf("\n");
    for (int i = 0; i < HABLINHA; i++){
        for (int j = 0; j < HABCOLUNA; j++){
            if ((i == 1 && j != 0 && j != 4)  || j == 2){
                habilidade[i][j] = 5;
            } else {habilidade[i][j] = 0;}
            printf("%d ", habilidade[i][j]);
        }
        printf("\n");
    }
    aplicarHabilidade(tabuleiro, habilidade, 4, 2);

    //Imprimindo tabuleiro atualizado
    printf("\n   ");
    for (int i = 0; i < 10; i++){ 
        printf("%c ", coluna[i]);
    }
    printf("\n");

    for (int i = 0; i < 10; i++){
        printf("%2d ", i + 1);
        for (int j = 0; j < 10; j++){
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
