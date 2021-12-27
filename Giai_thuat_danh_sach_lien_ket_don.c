#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>
typedef int ElementType;

typedef struct NodeType{
    ElementType Inf;
    struct NodeType *Next; 
} List;

// tạo nút mới, cấp phát bộ nhớ động cho nút mới 
// gán giá trị X cho nút đó
List *Cap_phat_nut_moi(ElementType X){
    List *newnode=(List*)malloc(sizeof(List));
    if(newnode==NULL){
        printf("Cap phat that bai\n");
        exit(0);
    }
    newnode->Inf=X;
    newnode->Next=NULL;
    return newnode;
}

// duyệt danh sách liên kết 
void duyetds(List *head){
    List *tg=head; // lưu địa chỉ đầu danh sách  
    printf("\n"); 
    while(tg!=NULL){               
        printf("%d ",tg->Inf);    // in ra giá trị của nút đó 
        tg=tg->Next;              // nhận địa chỉ nut kế tiếp cho tới khi đến nút cuối 
    }                             // khi tới nút cuối tức là tg = NULL vậy vòng sẽ dừng 
}

 
// giải phóng danh sách liên kết đơn 
void freelist(List *head){
    List *tg=head,*temp;
    while(tg!=NULL){
        temp=tg->Next;
        free(tg);
        tg=temp;
    }    
}

// chèn vào đầu danh sách 1 nút có giá trị là X
List *Chen_dau_danh_sach(List *head, ElementType X)
{
    List *newnode = Cap_phat_nut_moi(X);
    newnode->Next = head;
    return newnode;
}

// chèn 1 nút vào cuối danh sách 
List *Chen_cuoi_danh_sach(List *head, ElementType X)
{
    List *newnode,*temp;
    newnode=Cap_phat_nut_moi(X);
    
    if(head==NULL) {
        head=newnode;
    }
    else{
        temp=head;
        while(temp->Next!=NULL){
            temp=temp->Next;
        }
        temp->Next=newnode;
    }
    
    return head;
}

void Chen_vao_vi_tri_sau_Prev(List *Prev, ElementType X){
    if(Prev==NULL) return;
    List *newnode=Cap_phat_nut_moi(X);
    newnode->Next=Prev->Next;
    Prev->Next=newnode;
}
 
List *daothutuds1(List *head){
    List *tg=head;
    List *out=NULL;
    
    while(tg!=NULL){
        out=Chen_dau_danh_sach(out,tg->Inf);
        tg=tg->Next;
    }    
    
    return out;    
}

 

List *daothutuds2(List *head){
    List *t1,*t2,*t3;
    if((head==NULL)||(head->Next==NULL)) return head;
    t1=NULL;
    t2=head;
    t3=head->Next;
    while(t3!=NULL){
        t2->Next=t1;
        t1=t2;
        t2=t3;
        t3=t3->Next;
    }
    t2->Next=t1;
    return t2;
}
List *daothutuds3(List *head){
    if(head==NULL) return NULL;
    if(head->Next==NULL) return head;
    List *l=daothutuds3(head->Next);
    //thuc hien dao chieu mui ten
    head->Next->Next=head;
    head->Next=NULL;
    return l;
}

List *Xoa_nut_dau(List *head){
    if(head==NULL) return NULL;
    List *tg=head->Next;
    free(head);
    return tg;
}
// xóa nút cuối trong danh sách liên kết 
List *Xoa_nut_cuoi(List *head){
    if(head==NULL) return NULL;
    if(head->Next==NULL){ free(head); return NULL;}
    List *tg=head;
    while(tg->Next->Next!=NULL){
        tg=tg->Next;
    }
    free(tg->Next);
    tg->Next=NULL;
    return head;
}

List *Xoanutam_cach1(List *head) {
    while(head->Inf < 0){
        head = Xoa_nut_dau(head);
    }
    List *tmp = head;
    
    while(tmp != NULL) {
        if (tmp->Next==NULL) break;
        if (tmp->Next->Inf < 0 ) {
            List *tmp1 = tmp->Next;
            tmp->Next = tmp->Next->Next ;
            free(tmp1);
        }
        else tmp = tmp->Next;
    }
    return head;
}

List *Xoanutam_cach2(List *head) {
    List *tg1=NULL,*tg2=head;
    
    while(tg2!=NULL){
        if(tg2->Inf < 0){
            if(tg1==NULL){
                head=head->Next;
                free(tg2);
                tg2=head;
            }
            else{
                tg1->Next=tg2->Next;
                free(tg2);
                tg2=tg1->Next;
            }
        }
        else{
            tg1=tg2;
            tg2=tg2->Next;
        }
    }
    return head;
}

int main(){
     
    return 1;
}
 