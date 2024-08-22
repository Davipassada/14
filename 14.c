//Autores: Davi Passos e Luís Gabryel
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{

  int num_avi;

  char nome[30];

} Reservas;

void cadastraAviao(int *v){
  for(int i = 0; i < 4; i++){
   printf("Digite o numero do %d aviao: ", i+1);
   scanf("%d", &v[i]);
  }
}

void cadastraLugar(int *v){
  for(int i = 0; i < 4; i++){
   printf("Digite o numero de lugares disponiveis no %d aviao: ", i+1);
   scanf("%d", &v[i]);
  }
}

void reservaPassagem(char *nome, int *pos_livre, int numero, int posi, int achou, int *lug, int *avi, Reservas *reservas){
    int i = 0;
    printf("Digite o numero do aviao no qual deseja efetuar a reserva: ");
    scanf("%d", &numero);
if(*pos_livre > 60){
  printf("Reservas em todos os avioes esgotadas\n");
    }

    else{
 achou = 0;
        
for( i = 0; i < 4; i++){
if(avi[i] == numero){
achou = 1;
 posi = i;
  }
 }
}

if (achou == 0){
 printf("Este aviao nao existe\n");
 }

    else if(lug[posi] == 0){
        printf("Aviao lotado\n");
    
    }else{
printf("Digite o nome do passageiro: ");
scanf("%s", nome);
reservas[*pos_livre].num_avi = numero;
strcpy(reservas[*pos_livre].nome, nome);
printf("Reserva efetuada com sucesso\n");

 *pos_livre++;
  lug[posi]--;

    }

}

void consultaNumeroAviao(int numero, int *avi, int pos_livre, Reservas *reservas){
  int achou = 0;
    printf("Digite o numero do aviao para consultar as reservas: ");
    scanf("%d", &numero);
 achou = 0;
for(int i = 0; i < 4; i++){
 if(avi[i] == numero){
 achou = 1;
     }

} if(achou == 0){
 printf("Este aviao nao existe\n");

        }else{
            achou = 0;
for(int i = 1; i <= pos_livre; i++){

 if(reservas[i].num_avi == numero){
  printf("%s\n", reservas[i].nome);

 achou = 1;

    }

 }

    if(achou == 0){
printf("Nenhuma reserva esta cadastrada para este aviao\n");
     }
  }

}

void consultaNome( int pos_livre, Reservas *reservas){
int achou;
char nome[99];

printf("Digite o nome do passageiro para consultar as reservas: ");
scanf("%s", nome);
achou = 0;

for(int i = 1; i <= pos_livre; i++){

if(strcmp(reservas[i].nome, nome) == 0){

printf("%d\n", reservas[i].num_avi);
  achou = 1;
  }
}

 if(achou == 0){
  printf("Nenhuma reserva esta cadastrada para este nome\n");

  }
}

int main(){

int avi[4], lug[4];

int i, pos_livre, op, numero, achou,posi;

char nome[50];

Reservas reservas[60];
    
for(i = 0; i < 4; i++){
  avi[i] = 0;
  lug[i] = 0;

  }

for(i = 0; i < 60; i++){
reservas[i].num_avi = 0;
reservas[i].nome[0] = '\0';

  }

  pos_livre = 1;

  do{

printf("\nmenu de opcoes\n");
printf("1 - cadastrar os numeros dos avioes\n");
printf("2 - cadastrar os lugares disponiveis em cada aviao\n");
printf("3 - reservar passagem\n");
printf("4 - consultar pelo numero do aviao\n");
printf("5 - consultar pelo nome do passageiro\n");
printf("6 - finalizar\n");
printf("\nDigite a opcao desejada : ");
scanf("%d", &op);
switch(op){

 case 1:
cadastraAviao(&avi[0]);
break;

    case 2:
cadastraLugar(&lug[0]);
break;
case 3:

reservaPassagem(&nome, &pos_livre, numero, posi, achou, &lug[0], &avi[0], &reservas[0]);
 break;

 case 4:
consultaNumeroAviao(numero, &avi[0], pos_livre, &reservas[0]);

break;
 case 5:

consultaNome( pos_livre, &reservas);

break;

  case 6:
printf("finalizado");
break;

default:
printf("opcoa invalida");
 break;

  }

  }while(op != 6);
  return 0;
}

