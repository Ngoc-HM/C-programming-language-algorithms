#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>

int dem=0;
int n=4; // chạy xếp hậu
int m=4;
int a[]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
 
void ghinhan(){
    int i;
    printf("\ndem=%d:  ",++dem);
    for(i=1;i<=n;i++){
        printf("%d ",a[i]);
    }
}

 


void Indaynhiphan(int k){
    int i;
    for(i=0;i<2;i++){
        a[k]=i;
        if(k==n) ghinhan();
        else Indaynhiphan(k+1);
    }
}

 
int UCV(int i, int k){
    int j;
    for(j=1;j<k;j++){
        if(a[j]==i) return 0;
    }
    return 1;
}

 


void Inhoanvi_n_so(int k){
    int i;
    for(i=1;i<n+1;i++){
        if(UCV(i,k) == 1){
            a[k]=i;
            if(k==n) ghinhan();
            else Inhoanvi_n_so(k+1);
        }
    }
}

 

void ghinhan_m_ptu(){
    int i;
    printf("\ndem=%d:  ",++dem);
    for(i=1;i<=m;i++){
        printf("%d ",a[i]);
    }
}

 

int UCV_tapcon_m_ptu(int i,int k){
    if(i>a[k-1]) return 1;
    else return 0;
}

 

void Intapcon_m_ptu(int k){
    int i;
    for(i=1;i<n+1;i++){
        if(UCV_tapcon_m_ptu(i,k)==1){
            a[k]=i;
            if(k==m) ghinhan_m_ptu();
            else Intapcon_m_ptu(k+1);
        }
    }
}

 

int Hau_abs(int x){
    if(x>0) return x;
    else return -x;
}
    
int UCV_Hau(int i, int k)
{
    int j;
    for(j=1;j<k ;j++)
    {
        if(a[j] == i ) return 0;
        if(Hau_abs(i-a[j])== Hau_abs(k-j)) return 0;
    }
    return 1;
}

 

void Hau(int k)
{
    int i;
    for(i = 1 ; i <=n ;i++)  
    {
            if(UCV_Hau(i,k)==1)
            {
                    a[k] = i;
                    if(k==n) ghinhan();
                    else Hau(k+1);
            }
     }
}

 

int main(){
    //Indaynhiphan(1);
    Inhoanvi_n_so(1);
    //Intapcon_m_ptu(1);
    //Hau(1);
    
    //getch();
    return 1;
}