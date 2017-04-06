#include <stdio.h>
#include <stdlib.h>
 
 
struct node{
    int key;
    struct node *leftSon;
    struct node *rightSon;
};
 
void BalanceLeft(struct node **root);
void BalanceRight(struct node **root);
 
void RSBalancing(struct node **root);
void LSBalancing(struct node **root);
 
void delete(struct node **root, int key);
void printinorder(struct node *root);
void antecessor(struct node *no, struct node **root);
void insert(struct node **root, int key);
struct node *search(struct node *root, int key);
void initTree(struct node **root);
struct node *newNode();
int factorB(struct node *root);
int hCheck(struct node *root);
 
int main(){
    struct node **root;
    initTree(root);
    int key;
    int option;
    struct node *temp;
     
    do{
        printf("1-Inserir\n2-Search\n3-Listar arvore\n5-Delete\n0-Exit\n");
        scanf("%d", &option);
         
        switch(option){
            case 1:
                printf("Key: ");
                scanf("%d", &key);
                insert(root, key);
                printf("\n");
                break;
                 
            case 2:
                printf("Search for key: ");
                scanf("%d", &key);
                 
                if((temp = search(*root, key)))
                    printf("Key %d Found\n", temp->key);
                else
                    printf("Key %d Not Found\n", key);
                     
                printf("\n");
                break;
             
            case 3:
                printinorder(*root);
                printf("\n");
                break;
            case 4:
                printf("Delete key: ");
                scanf("%d", &key);
                delete(root, key);
                printf("\n");
                break;
                 
            default:
                break;
        }
         
    } while(option != 0);
     
    free(*root);
    return 0;
}
 
 
void BalanceLeft(struct node **root)
{
    int fbL = factorB( (*root)->leftSon );
    if (fbL > 0)
    {
        RSBalancing(root);
    }
    else if(fbL < 0)
    {
        LSBalancing( &((*root)->leftSon) );
        RSBalancing( &(*root) );
    }
 
}
 
void BalanceRight(struct node **root)
{
    int fbR = factorB( (*root)->rightSon );
    if (fbR < 0)
    {
        LSBalancing(root);
    }
    else if( fbR > 0)
    {
        RSBalancing( &((*root)->rightSon) );
        LSBalancing( &(*root) );
    }
}
 
 
void RSBalancing(struct node **root)
{
    struct node *tmp = (*root)->leftSon;
    (*root)->leftSon = tmp->rightSon;
    tmp->rightSon = (*root);
    (*root) = tmp;
 
}
 
void LSBalancing(struct node **root)
{
    struct node *tmp = (*root)->rightSon;
    (*root)->rightSon = tmp->leftSon;
    tmp->leftSon = (*root);
    (*root) = tmp;
 
}
  
void insert(struct node **root, int key){
    if(*root == NULL){
        *root = newNode();
        (*root)->key = key;
    }
     
    else if(key < (*root)->key)
            insert(&(*root)->leftSon, key);
    else if(key > (*root)->key)
            insert(&(*root)->rightSon, key);
             
    else printf("Valor %d ja existe na arvore\n", key);
     
    if(1 < factorB(*root))
    {
        BalanceLeft(root);
    }
    else if( -1 > factorB(*root))
    {
        BalanceRight(root);
    }
     
}
 
void delete(struct node **root, int key){
    struct node *aux;
     
    if (*root == NULL) { 
        printf("Erro : Registro nao esta na arvore\n");
        return;
    }
    if (key < (*root)->key) { 
        delete(&(*root)->leftSon, key);        
        return; 
    }
    if (key > (*root)->key){ 
        delete(&(*root)->rightSon, key); 
        return; 
    }
    if ((*root)->rightSon == NULL)  {
        aux = *root;
        *root = (*root)->leftSon;
        free(aux);
        return;
    }
    if ((*root)->leftSon != NULL) { 
        antecessor(*root, &(*root)->leftSon);
        return;
    }
     
    aux = *root; 
    *root = (*root)->rightSon;
    free(aux);
}
 
 
/*Retorna um valor <= -1 SE arvore estiver desbalanceada à direita
  Retorna um valor >= 1 SE arvore estiver desbalanceada à esquerda
*/
 
int factorB(struct node *root)
{
    if(!root)
        return 0;
     
    return (hCheck(root->leftSon)-hCheck(root->rightSon));
}
 
//Alturas
int hCheck(struct node *root)
{
    int iEsq,iDir;
     
    if(!root)
        return 0;
     
    iEsq = hCheck( root->leftSon );
    iDir = hCheck( root->rightSon );
     
    if( iEsq > iDir)
        return iEsq+1;
    else
        return iDir+1;
     
}
 
 
 
void printinorder(struct node *root){
    if(root != NULL){
        printinorder(root->leftSon);
        printf("%d ", root->key);
        printinorder(root->rightSon);
         
    }
}
 
void antecessor(struct node *no, struct node **root){
    struct node *aux;
    if((*root)->rightSon != NULL){
        antecessor(no, &(*root)->rightSon);
        return;
    }
     
    no->key = (*root)->key;
    aux = *root;
    *root = (*root)->leftSon;
    free(aux);
}
 
 
 
 
struct node *search(struct node *root, int key){
    struct node *aux = root;
     
    while(aux != NULL){
        if(aux->key != key){
            if(key > aux->key)
                aux = aux->rightSon;
            else
                aux = aux->leftSon;
        }
        else
            break;
    }
     
    return aux;
}
 
 
void initTree(struct node **root){
    *root = NULL;
}
 
 
struct node *newNode(){
    struct node *new = malloc (sizeof(struct node));
    new->leftSon = NULL;
    new->rightSon = NULL;
    return new;
}
