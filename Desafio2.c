#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <ctype.h>
#include <windows.h>
#include <process.h>

void menu(),jogar(),pontuacao(),descricao(),desenvolvedor();

void main(){
    system("cls");
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
                    system("cls");
                    jogar();
                    break;
                //opcao 2
                case 2:
                    system("cls");
                    pontuacao();
                    break;
                //opcao 3
                case 3:
                    system("cls");
                    descricao();
                    break;
                //opcao 4
                case 4:
                    system("cls");
                    desenvolvedor();
                    break;
                //opcao 5
                case 5:
                    exit(0);
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
    printf("_______  Pontuacao _______\n");
    FILE *info=fopen("pontuacao.txt","r");
    char c;
    do{
       putchar(c=getc(info));
    }while(c!=EOF);
    
    fclose(info);
}

void descricao(){
    printf("_______  Instrucoes _______\n-> O objetivo deste jogo, e alimentar a cobrinha o maximo possivel;\n-> Cada vez que alimentares a cobrinha, o seu tamanho aumentara;\n-> Se bater as paredes ou enrolar a cobrinha, perde uma vida;\n-> Tem direito a 3 vidas por jogo;\n-> Cada comida, vale 1 ponto;\n-> No final a sua pontuacao, ficara salva no jogo com o seu nome;\n-> Use as setas direcionais, para jogar;\n-> Pressione qualquer tecla durante o jogo, para pausar;\n-> Pressione qualquer tecla, para retomar ao jogo pausado;\n-> Use a tecla ESC para fechar o jogo;\n____________________________\n");
}

void desenvolvedor(){
    printf("______  Desenvolvedor  ______\nNome: Victor Tesoura Junior\nVersao: 1.0\nUniAmerica: Desafio 1 (semestre 1)\n____________________________\n");
}
