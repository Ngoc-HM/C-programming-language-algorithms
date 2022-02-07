#include <stdio.h>
void SapXepChen(int a[], int Size)
{
    int i, j, last;
    for (i = 1; i < Size; i++)
    {
        last = a[i];
        j = i;
        while ((j > 0) && (a[j - 1] > last))
        {
            a[j] = a[j - 1];
            j = j - 1;
        }
        a[j] = last;
    }
}

void SapXepChon(int a[], int Size)
{
    int i, j, min, temp;
    for (int i = 0; i < Size - 1; i++){
        min = i;

        for (int j = i+1; j < Size; j++){
            if (a[j] < a[min]) min = j;
        }
        int tg = a[i] ; 
        a[i] = a[min] ; 
        a[min] = tg;
    }
}
void inra(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d, ", a[i]);
}
void SapXepNoiBot(int a[], int Size){
    int i,j;
    for (int i = Size-1; i >= 0; i--)
    {
     for (int j = 1; j <= i ; j++)
     {
         if(a[j-1] > a[j]){
             int tg = a[j-1];
             a[j-1] = a[j];
             a[j] = tg;
         }
     }
     
    }
    

}
int main()
{
    int n, a[100], chucnang;
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("phan tu %d: ", i + 1);
        scanf("%d", &a[i]);
    }
    printf("\n1) Sap Xep Chen ");
    printf("\n2) Sap Xep Chon");
    printf("\n3) Sap Xep Noi Bot ");
    printf("\nLua chon chuc nang: ");
    scanf("%d", &chucnang);
    if (chucnang == 1)
    {
        printf("Sap Xep Chen: ");
        SapXepChen(a, n);
        inra(a, n);
    }
    if(chucnang == 2){
        printf("Sap Xep Chon: ");
        SapXepChon(a, n);
        inra(a,n);
    }
    if(chucnang == 3){
        printf("Sap Xep Noi Bot: ");
        SapXepNoiBot(a, n);
        inra(a,n);
    }
    return 0;
}