#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct{
    char nome[40];
    int idade;
}Pessoa;
 
typedef struct{
    Pessoa *pessoas;
    Pessoa *topo;
    int quantidade;
}Pilha;
 
 
void reset(Pilha *p){
     
    p->pessoas = NULL;
    p->quantidade = 0;
    p->topo = NULL;
}
 
void push(Pilha *pilha, Pessoa *pessoa){
    Pilha *p;
    p = pilha;
    Pessoa *temp;
        if(p->quantidade == 0){
            p->pessoas = malloc(sizeof(Pessoa));
            *p->pessoas = *pessoa;
            p->topo = p->pessoas;
            p->quantidade = 1;
    }else{
            p->quantidade++;
            temp = malloc(p->quantidade * sizeof(Pessoa));
            copiaPilha(temp, p->pessoas, pilha->quantidade);
         
            free(p->pessoas);
             
             
            p->pessoas = temp;
            p->topo = p->pessoas + (p->quantidade-1);
        *p->topo = *pessoa;
             
    }
     
}
 
void copiaPilha(Pessoa *j, Pessoa *pessoa, int quantidade){
    int i = 0;
    while(i < quantidade){
                j[i] = pessoa[i];
        i++;
    }
}
 
void listarPilha(Pilha *pilha){
    Pessoa *temp;
        Pilha *p;
        p = pilha;
    int i;
         
    if(p->quantidade == 0){
            printf("\nNAO HA PESSOAS NA PILHA!\n");
    }else{
            temp = p->topo;
            printf("\nListando...\n");
            for(i = 0; i < p->quantidade; i++){
                printf("Sr(a): %s, idade: %d\n", temp->nome, temp->idade);
                temp--;
            }
        }
}
 
void pop(Pilha *p){
    Pessoa *temp;
    if(p->quantidade == 0){
        printf("\n ERRO, A PILHA ESTA VAZIA\n");
    }else if(p->quantidade == 1){
        reset(p);
    }else{
        p->quantidade--;
        temp = malloc(p->quantidade *sizeof(Pessoa));
        copiaPilha(temp, p->pessoas, p->quantidade);
         
        free(p->pessoas);
        p->pessoas = temp;
        p->topo = p->pessoas + (p->quantidade-1);
    }
}
 
void popNome(Pilha *p, Pessoa *temp){
    int i, j = 0, encontrou = 0;
    Pilha *aux, *auxP;
    Pessoa *tempPessoa;
     
    auxP = p;
    aux = malloc(sizeof(Pilha));
    reset(aux);
    tempPessoa = malloc(sizeof(Pessoa));
     
    if(p->quantidade == 0){
        printf("\n, PILHA VAZIA !\n");
    }else{
        for(i = 0; i < p->quantidade; i++){
            *tempPessoa = *p->topo;
            pop(p);
            if((strcmp(tempPessoa->nome, temp->nome)) != 0){
                push(aux, tempPessoa);
                j++;
            }else{
                encontrou = 1;
                break;
            }
        }
        if(j > 0){
            while(j > 0){
                tempPessoa = aux->topo;
                push(p, tempPessoa);
                pop(aux);
                j--;
            }
        }else{
            if(encontrou != 1)
                printf("\nCADASTRO NAO LOCALIZADO\n");
        }
    }
}
 
void clear(Pilha *p){
    int i;
    for(i = p->quantidade; i > 0; i--){
        pop(p);
    }
}
 
 
int main(int argc, char** argv){
    int escolha;
    Pessoa *temp;
    Pilha *p;
    
    p = malloc(sizeof(Pilha));
     
    if(p == NULL){
        printf("ERRO AO ALOCAR MEMORIA !");
        return 0;
    }
     
    reset(p);
     
    temp = malloc(sizeof(Pessoa));
     
    if(temp == NULL){
        printf("ERRO AO ALOCAR MEMORIA !");
        return 0;
    }
     
    do{
         
    printf(" _________________MENU__________________\n");
    printf("|1-Inserir                              |\n");
    printf("|2-Retirar do Topo                      |\n");
    printf("|3-Retirar por Nome                     |\n");
    printf("|4-Limpar a Pilha                       |\n");  
    printf("|5-Listar a Pilha                       |\n");
    printf("|0-EXIT                                 |\n");
    printf("|_______________________________________|\n");
    scanf("%d", &escolha);
        
         
        if(escolha == 1){
            printf("\nDigite o Nome: ");
            scanf("%s", temp->nome);
            printf("Digite a Idade: ");
            scanf("%d", &temp->idade);
            push(p, temp);
        }
        if(escolha == 2){
            pop(p);
        }
        if(escolha == 3){
            printf("\nDigite o Nome a ser Retirado: ");
            scanf("%s", temp->nome);
            popNome(p, temp);
        }
         
        if(escolha == 4){
            clear(p);
        }
         
        if(escolha == 5){
            listarPilha(p);
        }
 
    }while(escolha != 0);
     
    free(p);
    free(temp);
     
     
    return (EXIT_SUCCESS);
}
