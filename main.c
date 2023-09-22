#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include<string.h>
#include<conio.h>
#include<winuser.h>


void posicaoxy( int x, int y )
{
    COORD coord;
    coord.X = (short)x;
    coord.Y = (short)y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

struct tempo{
   int dia;
   int mes;
   int ano;
};


typedef struct tempo Data;


struct Nota_Fiscal{
       char numero[9];
       int serie;
       float valor;
       Data data_em;
       Data datarecebe;
};

typedef struct Nota_Fiscal NF;

NF* criarNotasFrias(int n){
   NF notas[n];
   int i;
   for(i=0;i < n; i++){
       notas[i].data_em.dia= 14;
       notas[i].data_em.mes= 11;
       notas[i].data_em.ano= 2020;
       notas[i].valor = 1500+i;
   }
   return &notas;
}



//====================================Funcoes===========================================

void textPosicao (char * texto,int x,int y)
{    
     fflush(stdin);
     posicaoxy(x,y);//12,10
     printf("%s",texto);        
}
void floatPosicao (float texto,int x,int y)
{    
     fflush(stdin);
     posicaoxy(x,y);//12,10
     printf("%.2f",texto);        
}
void intPosicao (int texto,int x,int y)
{    
     fflush(stdin);
     posicaoxy(x,y);//12,10
     printf("%d",texto);        
}

void dataPosicao (Data d,int x,int y)
{    
     fflush(stdin);
     posicaoxy(x,y);//12,10
     printf("%d/%d/%d",d.dia,d.mes,d.ano);        
}

void posicaoC(char texto,int x,int y)
{    
     posicaoxy(x,y);//12,10
     printf("%c",texto);        
}


void caracter(){
     int i;
     for(i=106;i<350;i++)
        printf("%c %d\n",i,i);
}


void quadrado(){      
 int i;    
 int x = 10;
 int y = 5; 
 posicaoC(201,x,y);
 for(x=x+1;x<70;x++)
   printf("%c",205,187);
   
 posicaoC(187,x,y);
 x=10;
 for(y=6;y<20;y++){
     posicaoC(186,x,y);
 }
x=70;
for(y=6;y<20;y++){
 posicaoC(186,x,y);
}
 posicaoC(188,70,20);  
 posicaoC(200,10,20);   
 for(x=11;x<70;x++){
   posicaoC(205,x,20);                 
}
 
}


void screen_bg_buscar(){      
 int i;    
 int x = 10;
 int y = 0; 
  
 posicaoC(201,x,y);
 for(x=x+1;x<70;x++)
   printf("%c",205,187);
   
 posicaoC(187,x,y);
 x=10;
 //tamanho da Linha Direita do Quadro
 int tmx = 10;
 int tmy = 33;
 
 for(y=1;y<34;y++){
     posicaoC(186,tmx,y);
     posicaoC(186,tmx+60,y);
 }
 
 posicaoC(188,70,tmy);  
 posicaoC(200,10,tmy);   
 for(x=11;x<70;x++){
       posicaoC(205,x,tmy);                 
 }
}



void q_m(){    
     HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
     WORD saved_attributes;
    /* Salvar estado atual */
     GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
     saved_attributes = consoleInfo.wAttributes;
     SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY);
 int i;    
 int x = 14;
 int y = 6;
//Borda sup-diagponal Esquerda
posicaoC(218,28,6);
//Borda inf-diagponal Esquerda
posicaoC(192,28,8);
//Borda sup-diagponal Direita
posicaoC(191,51,6);
//Borda inf-diagponal Direita    
posicaoC(217,51,8);
//Linha superior e Inferior Reta
 for(x=29;x<51;x++){
   posicaoC(196,x,y);
   posicaoC(196,x,y+2);
 }
for(y=7;y<8;y++){
   posicaoC(179,28,y);
   posicaoC(179,51,y);
 }
 
 //caracter();
SetConsoleTextAttribute(hConsole, saved_attributes);
 
}

void q_m_ex(){    
     HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
     WORD saved_attributes;
    /* Salvar estado atual */
     GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
     saved_attributes = consoleInfo.wAttributes;
     SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY);
 int i;    
 int x = 14;
 int y = 1;
//Borda sup-diagponal Esquerda
posicaoC(218,28,1);
//Borda inf-diagponal Esquerda
posicaoC(192,28,3);
//Borda sup-diagponal Direita
posicaoC(191,51,1);
//Borda inf-diagponal Direita    
posicaoC(217,51,3);
//Linha superior e Inferior Reta
 for(x=29;x<51;x++){
   posicaoC(196,x,y);
   posicaoC(196,x,y+2);
 }
for(y=2;y<3;y++){
   posicaoC(179,28,y);
   posicaoC(179,51,y);
 }
SetConsoleTextAttribute(hConsole, saved_attributes);
 
}

void grade(){
     int i;    
     int x = 7;
     int y = 9;
      for(x=11;x<70;x++){
           posicaoC(196,x,y);              
           posicaoC(196,x,y+2);
      } 
     for(x=30;x<60;x+=15){
           posicaoC(179,x,10);               
     }
     for(x=11;x<70;x++){
         posicaoC(196,x,13);
         }
}

void tela_cadastro_nf(){
     quadrado();
     q_m();
     grade();
        textPosicao("numero:",11,10);
        textPosicao("Serie:",31,10);  
        textPosicao("Valor R$:",47,10);
        textPosicao("Data Emissao:",11,12);    
        textPosicao("Data Recebimento:",37,12); 
        textPosicao("Cadastro Nota Fiscal",30,7);
}
void tela_busca_nf(){
     int x,y;
     screen_bg_buscar();
     q_m_ex();
     textPosicao("DIGITE A DATA:",12,5);
     for(x=27;x<37;x++){
       posicaoC(196,x,6);
     }
     for(x=11;x<70;x++){
       posicaoC(196,x,7);
     }
     textPosicao("Nota F. /valor R$",12,8);
     textPosicao("Nota F. /valor R$",31,8);
     textPosicao("Nota F. /valor R$",51,8);
     
     for(x=11;x<70;x++){
       posicaoC(196,x,9);
       posicaoC(196,x,9);
     }
     for(y=8;y<33;y++){
        posicaoC(179,29,y);
        posicaoC(179,50,y);
      }
     
}

void tela_cadastro_menu(){
     quadrado();
     q_m();
     posicaoxy(30,7);
     printf("  Nota Fiscal - MENU");
}

int inputInt(int x,int y){
      int d;
      posicaoxy(x,y);
      scanf("%d",&d);
      return d;
}

void inputChar(char *texto,int x,int y){
      fflush(stdin);
      posicaoxy(x,y);
      gets(texto);
}
float inputFloat(int x,int y){
      float v;
      posicaoxy(x,y);
      scanf("%f",&v);
      return v;
}


int menu(){
    system("CLS");
    int opcao = 0;        
        int i;
        i=9;
        int x = 29;
        tela_cadastro_menu();
        textPosicao("1 - Lancar venda",x+1,10);
        textPosicao("2 - Pesquisar Nota Fiscal",x+1,11);
        textPosicao("3 - Lista venda por data",x+1,12);
        textPosicao("4 - Media vendas mes",x+1,13);
        textPosicao("5 - FIM",x+1,14);
        int k;
        for(k=x;k<x+27;k++){
          posicaoC(196,k,9);
          posicaoC(196,k,15);
        }
        for(x=11;x<70;x++){
           posicaoC(196,x,9);              
        }      
              
      posicaoC(':',30,16);         
    return inputInt(31,16);    
}


void cad_data(Data *dt,char *data){
    char dias[3],mes[3],ano[5];
    dias[0] =data[0];
    dias[1] =data[1];
    dias[2] ='\0';
    mes[0] =*(data+3) ;
    mes[1] =*(data+4) ;
    mes[2] ='\0';
    
    ano[0] =*(data+6);
    ano[1] =*(data+7);
    ano[2] =*(data+8);
    ano[3] =*(data+9);
    ano[4] ='\0';
    dt->dia = atoi(dias);
    dt->mes = atoi(mes);
    dt->ano = atoi(ano);  
}

int cadastroNotaFiscal(NF *nf){
        char data[10];
        system("CLS");
        tela_cadastro_nf();
        int i;
        i=7;        
        inputChar(&nf->numero,18,10);
        nf->serie = inputInt(38,10); 
        nf->valor = inputFloat(56,10);
        inputChar(&data,25,12);     
        cad_data(&nf->data_em,&data);
        inputChar(&data,55,12);     
        cad_data(&nf->datarecebe,&data);
        return 1;        
}
void exibeNOTA(NF *notas_f,int t){
    int i;
    system("CLS");
    tela_cadastro_nf();
    textPosicao("numero:",11,10);
    char numero[9];
    inputChar(&numero,19,10);
    //textPosicao(numero,19,15);
       
    for(i=0;i < t;i++){
      if((strcmp(notas_f[i].numero,numero)==0)){
            textPosicao(notas_f[i].numero,19,10);
            intPosicao(notas_f[i].serie,37,10);  
            floatPosicao(notas_f[i].valor,56,10);
            dataPosicao(notas_f[i].data_em,25,12);    
            dataPosicao(notas_f[i].datarecebe,54,12); 
            break;                                   
      }        
    }
    inputChar(&numero,19,10);
}
void buscarNOTAS_DATA(NF *notas_f,int t){
    int i;
    system("CLS");
    
    tela_busca_nf();
    textPosicao("Busca Nota Fiscal",30,2);
    char data[10];
    Data dt;
    inputChar(&data,27,5);
    cad_data(&dt,data);
    int x,y;
    x=11;
    y=10;
    t = 99;
    //notas_f = criarNotasFrias(t);
    
    for(i=0;i < t;i++){
      if(dt.mes==notas_f[i].data_em.mes && dt.ano==notas_f[i].data_em.ano){
            textPosicao(notas_f[i].numero,x,y); 
            //textPosicao("123456789",x,y);
            floatPosicao(notas_f[i].valor,x+10,y);
            y++;                                  
      }  
      if(y>32){
        y=10;
        x+=20;
      }     
    }
    
    inputChar(&data,77,21);
}



void totalNOTAS_DATA(NF *notas_f,int t){
    int i,x,y;
    system("CLS");
    float soma=0;
    tela_busca_nf();
    textPosicao("Total Nota Fiscal",30,2);
    textPosicao("Total R$:",38,5);
    for(x=27;x<37;x++){
       posicaoC(196,x,6);
       posicaoC(196,x+20,6);
     }
    char data[10];
    Data dt;
    inputChar(&data,27,5);
    cad_data(&dt,data);
   
    x=11;
    y=10;
    t = 99;
    //notas_f = criarNotasFrias(t);
    
    for(i=0;i < t;i++){
      if(dt.mes==notas_f[i].data_em.mes && dt.ano==notas_f[i].data_em.ano){
            textPosicao(notas_f[i].numero,x,y); 
            //textPosicao("123456789",x,y);
            floatPosicao(notas_f[i].valor,x+10,y);
            soma+=notas_f[i].valor;
            y++;                                  
      }  
      if(y>32){
        y=10;
        x+=20;
      }     
    }
    
    floatPosicao(soma,47,5);
    inputChar(&data,77,21);
}



int main(int argc, char *argv[])
{
  	
  system("title Nota Fiscal" );	
  
  system("COLOR 9F"); 
  system("mode con:cols=75 lines=25");
  NF nota_fiscal[100]; 
  const int nf =100;
  int total_notas = 0;
  int opcao = 3;
  quadrado();
  
  
  while(opcao!=5){
    system("mode con:cols=75 lines=25");
    opcao = menu();
   switch(opcao){
       case 1:
         total_notas+=cadastroNotaFiscal(&nota_fiscal[total_notas]);         
         Data dt = nota_fiscal[total_notas-1].datarecebe;       
       break;  
       case 2:
            exibeNOTA(&nota_fiscal,total_notas);  
            getchar();   
       break; 
       case 3:
            system("mode con:cols=75 lines=35");
            buscarNOTAS_DATA(&nota_fiscal,total_notas);
	   case 4:
            system("mode con:cols=75 lines=35");
            totalNOTAS_DATA(&nota_fiscal,total_notas);   
              
       break; 
      }
}
  
  system("CLS");
  printf("\n\n");
  //system("PAUSE");	
  return 0;
}
