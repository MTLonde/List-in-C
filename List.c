/* 
 * File:   List.c
 * Author: Marco Túlio Londe Silva
 */
#include "List.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


struct H{
    int size;
    List_Node head;
    List_Node tail;
};

struct N{
    char type[20];
    int position;
    void* content;
    List_Node next;
    List_Node before;
};

int get_size(List l) { 
    if(l!=NULL){
        return(l->size);
    }else{
        printf("\nInvalid List");
        return(-1);
    }
}

List_Node get_head(List l){
    if(l!=NULL){
        return(l->head);
    }else{
        printf("\nInvalid List");
        return(NULL);
    }
}

List_Node get_tail(List l){ 
    if(l!=NULL){
        return(l->tail);
    }else{
        printf("\nInvalid List");
        return(NULL);
    }
}

List_Node get_next(List_Node n){
    if(n!=NULL){
        return(n->next);
    }else{
        printf("\nInvalid List");
        return(NULL);
    }
}

List_Node get_before(List_Node n){ 
    if(n!=NULL){
        return(n->before);
    }else{
        printf("\nInvalid Node");
        return(NULL);
    }    
}

void* get_node_content(List_Node n){ 
    if(n!=NULL){
        return(n->content);
    }else{
        printf("\nInvalid Node");
        return(NULL);
    }
}

char* get_node_type(List_Node n){ 
    if(n!=NULL){
        return(n->type);
    }else{
        printf("\nInvalid Node");
        return(NULL);
    }
}

void* get_content(List l,int position){
    List_Node aux;
    if(l!=NULL){
        for(aux=get_head(l);(get_position(aux)==position)||(aux==NULL);aux=get_next(aux));
        if(aux!=NULL){
            return(get_node_content(aux));
        }else{
            printf("/n Invalid position");
            return (NULL); 
        }
    }else{
        printf("\nInvalid List");
        return(NULL);
    }
}

int get_position(List_Node n){ 
    if(n!=NULL){
        return(n->position);
    }else{
        printf("\nInvalid Node");
        return(-1);
    }
}

List New_List(){
    List new = (List)malloc(sizeof(struct H));
    if(new==NULL){
        printf("\n Out Of memory");
        return(NULL);
    }
    new->head=NULL;
    new->tail=NULL;
    new->size=0;
    return(new);
} 

int Insert_List(List l,void* content,int position, char* type){
    List_Node aux;
    List_Node new;
    
    if(l!=NULL){
        if(strlen(type)<19){
            if(l->size >= position - 1){
                if(position==1){
                    new=(List_Node)malloc(sizeof(struct N));
                    if(new==NULL){
                        printf("\n Out Of memory");
                        return(-1);
                    }
                    new->next=l->head;
                    strcpy(new->type,type);
                    new->before=NULL;
                    new->position = 1;
                    new->content = content;
                    if(l->head==NULL){
                        l->tail=new;
                        l->head=new;
                        l->size++;
                        return(1);
                    }else{
                        l->size++;
                        l->head->before=new;
                        l->head=new;
                        for(aux = new->next;aux!=NULL;aux=get_next(aux)){
                            aux->position ++;
                        }
                        return(1);
                    }
                }

                if(position==l->tail->position+1){
                    new=(List_Node)malloc(sizeof(struct N));
                    if(new==NULL){
                        printf("\n Out Of memory");
                        return(-1);
                    }
                    new->next=NULL;
                    strcpy(new->type,type);
                    new->before=l->tail;
                    new->position = position;
                    new->content = content;
                    l->tail->next=new;
                    l->tail=new;
                    l->size++;
                    return(1);
                }
                for(aux=get_head(l);get_position(aux)!=position;aux=get_next(aux));

                new=(List_Node)malloc(sizeof(struct N));
                if(new==NULL){
                    printf("\n Out Of memory");
                    return(-1);
                }
                new->next=aux;
                new->before=aux->before;
                strcpy(new->type,type);
                new->position = aux->position;
                new->content = content;
                aux->before->next=new;
                aux->before=new;
                for(aux = new->next;aux!=NULL;aux=get_next(aux)){
                    aux->position ++;
                }
                l->size++;
                return(1);

            }else{
                printf("\n Invalid position");
                return (0);
            }
        }else{
            printf("\n Type too Long");
            return (0);
        }
    }else{
        printf("\n List not created");
        return (0);
    }
}

int Delete_List(List l,int position){
    List_Node aux;
    List_Node aux1;
    
    if(l!=NULL){
        for(aux=get_head(l);(get_position(aux)!=position)||(aux==NULL);aux=get_next(aux));
        if(aux!=NULL){
            if(aux->next==NULL){
                aux->before->next=NULL;
                l->tail=aux->before;
                free(aux->content);
                free(aux);
                l->size--;
                return(1);
            }

            if(aux->before==NULL){
                aux->next->before=NULL;
                l->head=aux->next;
                free(aux->content);
                free(aux);
                l->size--;
                for(aux=get_head(l);aux!=NULL;aux=get_next(aux)){
                    aux->position --;
                }
                return(1);
            }

            aux->before->next=aux->next;
            aux->next->before=aux->before;
            aux1=aux->next;
            free(aux->content);
            free(aux);
            l->size--;
            for(aux=aux1;aux!=NULL;aux=get_next(aux)){
                aux->position --;
            }
            return(1);   
        }else{
            printf("\n Invalid position");
            return (0); 
        }
    }else{
        printf("\n List not created");
        return (0);
    }
}

int Destroy_List(List l){
    List_Node aux;
    
    if(l!=NULL){
        for(aux=get_head(l);aux->next!=NULL;aux=get_next(aux)){
            if(aux->before!=NULL){
                free(aux->before->content);
                free(aux->before);
            }
        }
        free(aux->before->content);
        free(aux->before);
        free(aux->content);
        free(aux);
        free(l);
        return(1);
    }else{
        printf("\nInvalid List");
        return(0);
    }
}
