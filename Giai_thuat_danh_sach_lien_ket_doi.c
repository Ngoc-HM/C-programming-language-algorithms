#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>

 

typedef int ElementType;

 

typedef struct _dllist {
    int inf;
    struct _dllist *next;
    struct _dllist *prev;
} dllist;

 

// tạo nút mới 
dllist *createNewNode(ElementType X){
    dllist *newnode=(dllist*)malloc(sizeof(dllist));
    if(newnode==NULL){
        printf("Error in memory allocation\n");
        exit(0);
    }
    
    newnode->inf=X;
    newnode->next=NULL;
    newnode->prev=NULL;
    
    return newnode;
}

 

// duyệt danh sách 
void duyetds(dllist *head){
    dllist *tg=head;
    printf("\n");
    while(tg!=NULL){
        printf("%d ",tg->inf);
        tg=tg->next;
    }    
}

 

 // giải phóng
void freelist(dllist *head){
    dllist *tg=head,*temp;
    while(tg!=NULL){
        temp=tg->next;
        free(tg);
        tg=temp;
    }    
}

 
// thêm 1 nút vào đầu danh sách 
dllist *Insert_ToHead(dllist *head, ElementType X)
{
    dllist *newnode = createNewNode(X);
    newnode->next=head;
    if(head!=NULL) head->prev=newnode;
    //head=newnode;
    
    return newnode;
}

 

//xoa 1 nut bat ki duoc tro boi p
dllist *Delete(dllist *p){
    if(p==NULL) return NULL;
    if(p->prev==NULL){
        if(p->next==NULL){
            free(p);
            return NULL;
        }
        else{
            p->next->prev=NULL;
            dllist *tmp=p->next;
            free(p);
            return tmp;
        }
    }
    else{
        if(p->next!=NULL) 
            p->next->prev=p->prev;
        p->prev->next=p->next;
        dllist *tg=p;
    
        while(tg->prev!=NULL){
            tg=tg->prev;
        }    
        
        free(p);
        return tg;
    }
}

 


//ham tinh tong cac nut trong ds voi con tro tro toi nut bat ki
int sum(dllist *p){
    int s=0;
    dllist *tg=p;
    
    while(tg!=NULL){
        s+=tg->inf;
        tg=tg->next;
    }    
    
    tg=p;
    
    while(tg!=NULL){
        s+=tg->inf;
        tg=tg->prev;
    }    
    
    return s-p->inf;
}

 


int main(){
    dllist *head=NULL;
    head=Insert_ToHead(head,10);
    head=Insert_ToHead(head,5);
    head=Insert_ToHead(head,50);
    head=Insert_ToHead(head,7);
    duyetds(head);
    printf("sum=%d\n",sum(head->next->next));
    head=Delete(head->next->next);
    duyetds(head);
    printf("sum=%d\n",sum(head));
    
    freelist(head);
    return 1;
}