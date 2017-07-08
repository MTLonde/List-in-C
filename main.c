/* 
 * File:   main.c
 * Author: Marco Túlio Londe Silva
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "List.h"

typedef struct aluno{
    char nome[10];
    int codigo;
    float notas[3];
}Aluno;

Aluno* cria_aluno(char* nome,int codigo,float n1, float n2, float n3);
void teste1();
List teste2();

int main(int argc, char** argv) {
    int* pi;
    float* pf;
    char* pch;
    char* type;
    Aluno* pA;
    
    teste1();
    
    
    List L = teste2();
    printf("\n");
    List_Node N;
    for(N = get_head(L);N!=NULL;N = get_next(N)){
        type=get_node_type(N);
        if(strcmp(type,"int*\0")==0){
            pi=get_node_content(N);
            printf("\n\t%d %d",get_position(N),*pi);
        }else if(strcmp(type,"float*\0")==0){
            pf=get_node_content(N);
            printf("\n\t%d %.2f",get_position(N),*pf);
        }else if(strcmp(type,"char*\0")==0){
            pch=get_node_content(N);
            printf("\n\t%d %s",get_position(N),pch);
        }else if(strcmp(type,"Aluno*\0")==0){
            pA =  get_node_content(N);
        printf("\n\t%d\t%s\t%f\t%f\t%f",get_position(N),pA->nome,pA->notas[0],pA->notas[1],pA->notas[2]);
        }
    }
    printf("\n");
    
    
    return (EXIT_SUCCESS);
}



Aluno* cria_aluno(char* nome,int codigo,float n1, float n2, float n3){
    Aluno* novo = (Aluno*)malloc(sizeof(Aluno)); 
    
    strcpy(novo->nome,nome);
    novo->codigo=codigo;
    novo->notas[0]=n1;
    novo->notas[1]=n2;
    novo->notas[2]=n3;
    
    return(novo);
}

void teste1(){
    Aluno* novo;
    char nome[10];
    int cod = 1;
    float n1=2,n2=3,n3=4;
    
    List L = New_List();
    
    strcpy(nome,"Luis\0");
    novo = cria_aluno(nome,cod,n1,n2,n3);
    Insert_List(L,novo,1,"Aluno*\0");
    strcpy(nome,"Leandro\0");
    novo = cria_aluno(nome,cod,n1,n2,n3);
    Insert_List(L,novo,1,"Aluno*\0");
    strcpy(nome,"Lara\0");
    novo = cria_aluno(nome,cod,n1,n2,n3);
    Insert_List(L,novo,3,"Aluno*\0");
    strcpy(nome,"Loren\0");
    novo = cria_aluno(nome,cod,n1,n2,n3);
    Insert_List(L,novo,2,"Aluno*\0");
    
    
    List_Node N;
    
    for(N = get_head(L);N!=NULL;N = get_next(N)){
        novo =  get_node_content(N);
        printf("\n\t%d\t%s\t%f\t%f\t%f",get_position(N),novo->nome,novo->notas[0],novo->notas[1],novo->notas[2]);
    }
    printf("\n");
    Delete_List(L,2);
    printf("\n");
    for(N = get_head(L);N!=NULL;N = get_next(N)){
        novo = get_node_content(N);
        printf("\n\t%d\t%s\t%f\t%f\t%f",get_position(N),novo->nome,novo->notas[0],novo->notas[1],novo->notas[2]);
    }
    Destroy_List(L);
}

List teste2(){
    int* i;
    float* f;
    char* ch;
    
    List L = New_List();
    
    i=(int*)malloc(sizeof(int));
    *i = 30;
    Insert_List(L,i,1,"int*\0");
    f=(float*)malloc(sizeof(float));
    *f=20.44;
    Insert_List(L,f,2,"float*\0");
    ch=(char*)malloc(sizeof(char));
    *ch='T';
    Insert_List(L,ch,3,"char*\0");
    f=(float*)malloc(sizeof(float));
    *f=55.44;
    Insert_List(L,f,1,"float*\0");
    ch=(char*)malloc(sizeof(char)*10);
    strcpy(ch,"teste 2\0");
    Insert_List(L,ch,3,"char*\0");
    Aluno* novo = cria_aluno("João",2,3.5,4.5,9);
    Insert_List(L,novo,4,"Aluno*\0");
            
    return(L);
    
}
