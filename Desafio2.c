#include <stdio.h>

void menu(),jogar(),pontuacao(),descricao(),desenvolvedor();
const int maior;
const char * jogador;

void main(){
 menu();
}

void menu(){
    int opc=0;

    do{
       printf("***** Jogo da cobrinha *****\n1. Jogar \n2. Ver pontuacao \n3. Intrucoes \n4. Sobre o desenvolvedor \n5. Sair\n****************************\n"); 
       scanf("%d",&opc);

       switch (opc) {
                //opcao 1
                case 1:
                    // clrscr();
                    jogar();
                    break;
                //opcao 2
                case 2:
                    // clrscr();
                    pontuacao();
                    break;
                //opcao 3
                case 3:
                    // clrscr();
                    descricao();
                    break;
                //opcao 4
                case 4:
                    // clrscr();
                    desenvolvedor();
                    break;

                default:
                    printf("XXXXXXXXXXXXXXXXXXXXXXXXXXX\nOpcao invalida. Selecione de 1 a 5\nXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
                    break;
            }

    }while(opc!=5);
}

void jogar(){

}

void pontuacao(){
    printf("***** Jogo da cobrinha *****\n_______  Pontuacao _______\nNome: %s\nPontos: %d",&jogador,&maior,"\n****************************\n");
}

void descricao(){
    printf("***** Jogo da cobrinha *****\n_______  Instrucoes _______\n- O objetivo deste jogo, e alimentar a cobrinha o maximo possivel;\n- Se demorar alimentar, a comida mudara de lugar;\n- Cada comida, vale 1 ponto;\n- Se a sua pontuacao for a maior, ficara salva no jogo com o seu nome;\n- Use as setas direcionais, para jogar;\n- Use a tecla ESC para fechar o jogo;\n- Use a tecla S para voltar ao Menu\n****************************\n");
}

void desenvolvedor(){
    printf("***** Jogo da cobrinha *****\nDesenvolvedor: Victor Tesoura Junior\nVersao: 1.0\nUniAmerica: Desafio 1 (semestre 1)\n****************************\n");
}