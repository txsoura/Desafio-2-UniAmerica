#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <ctype.h>
#include <windows.h>
#include <process.h>

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

//declaração variáveis
int tamanho,curvan, tam, vida;
char tecla;
//decalaração métodos
void cobrinha(), erro(), gravartxt(), intervalo(long double), mover(), comer(), xyz(int x, int y), curvar(), borda(), descer(), esquerda(), subir(), direita(), sair(), menu(), jogar(), pontuacao(), descricao(), desenvolvedor();
int placar(), placarx();

struct coordenada
{
  int x, y, direcao;
};

typedef struct coordenada coordenada;

coordenada cabeca, curva[500], comida, corpo[30];

//método principal
void main()
{
  system("cls");
  menu();
}

//método que imprime e valida as opções do menu
void menu()
{
  int opc = 0;

  do
  {
    cobrinha();
    printf("\n1. Jogar \n2. Ver pontuacao \n3. Intrucoes \n4. Sobre o desenvolvedor \n5. Sair\n****************************\n");
    scanf("%d", &opc);

    switch (opc)
    {
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
      erro();
      printf("\nXXXXXXXXXXXXXXXXXXXXXXX Selecione de 1 a 5 XXXXXXXXXXXXXXXXXXXXXXX\n");
      break;
    }

  } while (opc != 5);
}

//método que inicia o jogo
void jogar()
{
  char tecla;

  system("cls");
  tamanho = 5;
  cabeca.x = 25;
  cabeca.y = 20;
  cabeca.direcao = RIGHT;
  borda();
  comer();  //cria a primeira comida
  vida = 3; //numero de vidas
  curva[0] = cabeca;
  mover(); //inicia o jogo
}

//método que imprime a cobrinha em ASCII art do ficheiro de texto
void cobrinha()
{
  FILE *info = fopen("cobrinha.txt", "r");
  char c;

  do
  {
    putchar(c = getc(info));
  } while (c != EOF);

  fclose(info);
}

//método que imprime mensagem de erro em ASCII art do ficheiro de texto
void erro()
{
  FILE *info = fopen("erro.txt", "r");
  char c;

  do
  {
    putchar(c = getc(info));
  } while (c != EOF);

  fclose(info);
}

//método que imprime pontuação salva no ficheiro de texto
void pontuacao()
{
  printf("_______  Pontuacao _______\n");
  FILE *info = fopen("pontuacao.txt", "r");
  char c;

  do
  {
    putchar(c = getc(info));
  } while (c != EOF);

  fclose(info);
}

//método para imprimir instruções do jogo
void descricao()
{
  printf("_______  Instrucoes _______\n-> O objetivo deste jogo, e alimentar a cobrinha o maximo possivel;\n-> Cada vez que alimentares a cobrinha, o seu tamanho aumentara;\n-> Se bater as paredes ou enrolar a cobrinha, perde uma vida;\n-> Tem direito a 3 vidas por jogo;\n-> Cada comida, vale 1 ponto;\n-> No final a sua pontuacao, ficara salva no jogo com o seu nome;\n-> Use as setas direcionais, para jogar;\n-> Pressione qualquer tecla durante o jogo, para pausar;\n-> Pressione qualquer tecla, para retomar ao jogo pausado;\n-> Use a tecla ESC para fechar o jogo;\n____________________________\n");
}

//método para imprimir dados do desenvolvedor
void desenvolvedor()
{
  printf("______  Desenvolvedor  ______\nNome: Victor Tesoura Junior\nVersao: 1.0\nUniAmerica: Desafio 2 (semestre 1)\n____________________________\n");
}

//método que movimenta a cobrinha em função de coordenadas
void mover()
{
  int a, i;

  do
  {
    comer();
    fflush(stdin);
    tam = 0;

    for (i = 0; i < 30; i++)
    {
      corpo[i].x = 0;
      corpo[i].y = 0;

      if (i == tamanho)
      {
        break;
      }
    }

    intervalo(tamanho);
    borda();

    if (cabeca.direcao == RIGHT)
    {
      direita();
    }
    else if (cabeca.direcao == LEFT)
    {
      esquerda();
    }
    else if (cabeca.direcao == DOWN)
    {
      descer();
    }
    else if (cabeca.direcao == UP)
    {
      subir();
    }

    sair();
  } while (!kbhit());

  a = getch();

  if (a == 27)
  {
    system("cls");
    exit(0);
  }

  tecla = getch();

  if ((tecla == RIGHT && cabeca.direcao != LEFT && cabeca.direcao != RIGHT) || (tecla == LEFT && cabeca.direcao != RIGHT && cabeca.direcao != LEFT) || (tecla == UP && cabeca.direcao != DOWN && cabeca.direcao != UP) || (tecla == DOWN && cabeca.direcao != UP && cabeca.direcao != DOWN))
  {
    curvan++;
    curva[curvan] = cabeca;
    cabeca.direcao = tecla;

    if (tecla == UP)
    {
      cabeca.y--;
    }

    if (tecla == DOWN)
    {
      cabeca.y++;
    }

    if (tecla == RIGHT)
    {
      cabeca.x++;
    }

    if (tecla == LEFT)
    {
      cabeca.x--;
    }

    mover();
  }
  else if (tecla == 27)
  {
    system("cls");
    exit(0);
  }
  else
  {
    printf("\a");
    mover();
  }
}

//método responsável por imprimir a parte gráfica do jogo
void xyz(int x, int y)
{
  HANDLE a;
  COORD b;
  fflush(stdout);
  b.X = x;
  b.Y = y;
  a = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleCursorPosition(a, b);
}

//método para descer a direção da cobrinha
void descer()
{
  int i;

  for (i = 0; i <= (cabeca.y - curva[curvan].y) && tam < tamanho; i++)
  {
    xyz(cabeca.x, cabeca.y - i);
    {
      if (tam == 0)
      {
        printf("v");
      }
      else
      {
        printf("*");
      }
    }

    corpo[tam].x = cabeca.x;
    corpo[tam].y = cabeca.y - i;
    tam++;
  }

  curvar();

  if (!kbhit())
  {
    cabeca.y++;
  }
}

//método que define a taxa de atualização (movimento da cobrinha)
void intervalo(long double k)
{
  placar();
  long double i;

  for (i = 0; i <= (10000000); i++)
    ;
}

//método que verifica as vidas
void sair()
{
  int i, verificar = 0;

  for (i = 4; i < tamanho; i++) //inicia com 4, pois só assim é que a cobrinha poderá enrolar-se
  {
    if (corpo[0].x == corpo[i].x && corpo[0].y == corpo[i].y)
    {
      verificar++; //verifica se a coordenada da cabeça é a mesma que do corpo
    }

    if (i == tamanho || verificar != 0)
    {
      break;
    }
  }

  if (cabeca.x <= 10 || cabeca.x >= 70 || cabeca.y <= 10 || cabeca.y >= 30 || verificar != 0)
  {
    vida--;

    if (vida > 0)
    {
      cabeca.x = 25;
      cabeca.y = 20;
      curvan = 0;
      cabeca.direcao = RIGHT;
      mover();
    }
    else
    {
      system("cls");
      printf("Ohh perdeu!!!\nPressione qualquer tecla para voltar ao Menu\n");
      gravartxt();
      menu();
    }
  }
}

//método que cria a comida
void comer()
{
  if (cabeca.x == comida.x && cabeca.y == comida.y)
  {
    tamanho++;
    time_t a;
    a = time(0);
    srand(a);
    comida.x = rand() % 70;

    if (comida.x <= 10)
    {
      comida.x += 11;
    }

    comida.y = rand() % 30;

    if (comida.y <= 10)
    {
      comida.y += 11;
    }
  }
  else if (comida.x == 0) /*cria a primeira comida do jogo*/
  {
    comida.x = rand() % 70;

    if (comida.x <= 10)
    {
      comida.x += 11;
    }

    comida.y = rand() % 30;

    if (comida.y <= 10)
    {
      comida.y += 11;
    }
  }
}

//método para mudar a direção da cobrinha a esquerda
void esquerda()
{
  int i;

  for (i = 0; i <= (curva[curvan].x - cabeca.x) && tam < tamanho; i++)
  {
    xyz((cabeca.x + i), cabeca.y);
    {
      if (tam == 0)
      {
        printf("<");
      }
      else
      {
        printf("*");
      }
    }

    corpo[tam].x = cabeca.x + i;
    corpo[tam].y = cabeca.y;
    tam++;
  }

  curvar();

  if (!kbhit())
  {
    cabeca.x--;
  }
}

//método para mudar a direção da cobrinha a direita
void direita()
{
  int i;

  for (i = 0; i <= (cabeca.x - curva[curvan].x) && tam < tamanho; i++)
  {
    corpo[tam].x = cabeca.x - i;
    corpo[tam].y = cabeca.y;
    xyz(corpo[tam].x, corpo[tam].y);
    {
      if (tam == 0)
      {
        printf(">");
      }
      else
      {
        printf("*");
      }
    }

    tam++;
  }

  curvar();

  if (!kbhit())
  {
    cabeca.x++;
  }
}

//método para curvar a direção da cobrinha
void curvar()
{
  int i, j, diff;

  for (i = curvan; i >= 0 && tam < tamanho; i--)
  {
    if (curva[i].x == curva[i - 1].x)
    {
      diff = curva[i].y - curva[i - 1].y;

      if (diff < 0)
      {
        for (j = 1; j <= (-diff); j++)
        {
          corpo[tam].x = curva[i].x;
          corpo[tam].y = curva[i].y + j;
          xyz(corpo[tam].x, corpo[tam].y);
          printf("*");
          tam++;

          if (tam == tamanho)
          {
            break;
          }
        }
      }
      else if (diff > 0)
      {
        for (j = 1; j <= diff; j++)
        {
          corpo[tam].x = curva[i].x;
          corpo[tam].y = curva[i].y - j;
          xyz(corpo[tam].x, corpo[tam].y);
          printf("*");
          tam++;

          if (tam == tamanho)
          {
            break;
          }
        }
      }
    }
    else if (curva[i].y == curva[i - 1].y)
    {
      diff = curva[i].x - curva[i - 1].x;

      if (diff < 0)
      {
        for (j = 1; j <= (-diff) && tam < tamanho; j++)
        {
          corpo[tam].x = curva[i].x + j;
          corpo[tam].y = curva[i].y;
          xyz(corpo[tam].x, corpo[tam].y);
          printf("*");
          tam++;

          if (tam == tamanho)
          {
            break;
          }
        }
      }
      else if (diff > 0)
      {
        for (j = 1; j <= diff && tam < tamanho; j++)
        {
          corpo[tam].x = curva[i].x - j;
          corpo[tam].y = curva[i].y;
          xyz(corpo[tam].x, corpo[tam].y);
          printf("*");
          tam++;

          if (tam == tamanho)
          {
            break;
          }
        }
      }
    }
  }
}

//método que imprime o retângulo
void borda()
{
  system("cls");
  int i;
  xyz(comida.x, comida.y); /*imprime a comida*/
  printf("C");

  for (i = 10; i < 71; i++)
  {
    xyz(i, 10);
    printf("-");
    xyz(i, 30);
    printf("_");
  }

  for (i = 10; i < 31; i++)
  {
    xyz(10, i);
    printf("|");
    xyz(70, i);
    printf("|");
  }
}

//método que grava a pontuação no ficheiro de texto
void gravartxt()
{
  char nome[20], nmaiusculo[20], cha, c;
  int i, j, px;
  FILE *info;

  info = fopen("pontuacao.txt", "a+");
  getch();
  system("cls");
  printf("Digite o seu nome\n");
  scanf("%[^\n]", nome);
  
  for (j = 0; nome[j] != '\0'; j++)
  { 
    //converter a primeira letra depois do espaço a maiuscula
    nmaiusculo[0] = toupper(nome[0]);

    if (nome[j - 1] == ' ')
    {
      nmaiusculo[j] = toupper(nome[j]);
      nmaiusculo[j - 1] = nome[j - 1];
    }
    else
    {
      nmaiusculo[j] = nome[j];
    }
  }

  nmaiusculo[j] = '\0';
  //grava o nome do jogador
  fprintf(info, "Nome: %s\n", nmaiusculo);
  //grava a data e hora
  time_t mytime;
  mytime = time(NULL);
  fprintf(info, "Data: %s", ctime(&mytime));
  //grava os pontos do placar
  fprintf(info, "Pontos: %d\n", px = placarx()); 
  for(i=0;i<=50;i++)
   fprintf(info,"%c",'_');
   fprintf(info,"\n");
   fclose(info);
}

//método que imprime o placar do jogo
int placar()
{
  int placa;

  xyz(20, 8);
  placa = tamanho - 5;
  printf("Pontos : %d", (tamanho - 5));
  placa = tamanho - 5;
  xyz(50, 8);
  printf("Vidas : %d", vida);

  return placa;
}

//método que atualiza o placar do jogo
int placarx()
{
  int placax = placar();

  system("cls");

  return placax;
}

//método para subir a direção da cobrinha
void subir()
{
  int i;

  for (i = 0; i <= (curva[curvan].y - cabeca.y) && tam < tamanho; i++)
  {
    xyz(cabeca.x, cabeca.y + i);
    {
      if (tam == 0)
      {
        printf("^");
      }
      else
      {
        printf("*");
      }
    }

    corpo[tam].x = cabeca.x;
    corpo[tam].y = cabeca.y + i;
    tam++;
  }

  curvar();

  if (!kbhit())
  {
    cabeca.y--;
  }
}
