#include <stdio.h>
#include <stdlib.h>
// cây nhị phân 
typedef char elementtype;
typedef struct _Tnode
{
    elementtype inf;
    // Dữ liệu cất giữ ở nút
    struct _Tnode *left;
    struct _Tnode *right;
} Treenode;

 

Treenode *Tao_mot_nut_moi(elementtype X){
    Treenode *newnode=(Treenode*)malloc(sizeof(Treenode));
    if(newnode==NULL){printf("Error in memoty allocation\n");exit(0);}
    newnode->inf=X;
    newnode->left=NULL;
    newnode->right=NULL;
    
    return newnode;
}


void duyet_truoc( Treenode *r )
{
    if(r==NULL) return;
    printf("%c ",r->inf);
    duyet_truoc(r->left);
    duyet_truoc(r->right);
}

 

void duyet_sau( Treenode *r )
{
    if(r==NULL) return;
    duyet_sau(r->left);
    duyet_sau(r->right);
    printf("%c ",r->inf);
}

void duyet_giua( Treenode *r )
{
    if(r==NULL) return;
    duyet_giua(r->left);
    printf("%c ",r->inf);
    duyet_giua(r->right);
}
 
 void giai_phong_cay(Treenode * r)
{
    if(r == NULL) return;
    giai_phong_cay(r->left);
    giai_phong_cay(r->right);
    free(r); 
}

// đếm số nút trên cây nhị phân
int so_nut_tren_cay(Treenode* r){
    if(r == NULL) return 0;
    return 1 + so_nut_tren_cay(r->left) + so_nut_tren_cay(r->right);
}


int So_nut_ko_phai_nut_la(Treenode *r){
    if(r == NULL) return 0;
    if (r->left == NULL && r->right == NULL)
        return 0;
    return 1 + So_nut_ko_phai_nut_la(r->left) + So_nut_ko_phai_nut_la(r->right);
}


int Dem_so_nut_co_k_con(Treenode *r,int k)
{
    if(k<0||k>2) return -1;
    int i=0,count=0;
    if(r==NULL) return 0;
    if(r->left!=NULL) i+=1;
    if(r->right!=NULL) i+=1;
    if(i==k) count+=1;
    count+=Dem_so_nut_co_k_con(r->left,k);
    count+=Dem_so_nut_co_k_con(r->right,k);
    
    return count;
}

int main(){
    Treenode *root=NULL;
    Treenode *nutB, *nutC, *nutD, *nutE, *nutF, *nutG, *nutH, *nutI, *nutJ, *nutK;
    
    root=Tao_mot_nut_moi('A');
    nutB=Tao_mot_nut_moi('B');
    nutC=Tao_mot_nut_moi('C');
    nutD=Tao_mot_nut_moi('D');
    nutE=Tao_mot_nut_moi('E');
    nutF=Tao_mot_nut_moi('F');
    nutG=Tao_mot_nut_moi('G');
    nutH=Tao_mot_nut_moi('H');
    nutI=Tao_mot_nut_moi('I');
    nutJ=Tao_mot_nut_moi('J');
    nutK=Tao_mot_nut_moi('K');
    
    root->left=nutB;
    
    nutB->left=nutE;
    nutB->right=nutC;
    
    nutC->left=nutG;
    nutC->right=nutD;
    
    nutE->right=nutF;
    
    nutG->left=nutH;
    
    nutH->right=nutI;
    nutI->right=nutJ;
    nutJ->right=nutK;
    
    
    printf("-----------Duyet truoc-------\n");
    duyet_truoc(root);
    
    
    printf("\n-----------Duyet sau-------\n");
    duyet_sau(root);

     printf("\n-----------Duyet giua-------\n");
    duyet_giua(root);
    
    
    /*
    printf("\n-----------Duyet giua-------\n");
    duyet_giua(root);
    printf("\n-----------Dem so nut: %d\n",CountNodes(root));
    printf("\n-----------Dem so nut la: %d\n",CountLeaf(root));
    printf("\n-----------Dem so nut 1 con la: %d\n",Dem_so_nut_co_k_con(root,1));
    
    freetree(root);
    * */
    return 1;
}