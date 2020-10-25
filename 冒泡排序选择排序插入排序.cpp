#include <stdio.h>
#include <math.h>
#include <string.h>
#include <algorithm>


using namespace std;


int dextobinary(int x,int a[]){
    int i = 0;
    do{
        a[i++] = x % 2;
        x = x / 2;

    } while (x > 0);
    return i - 1;

}
void bubblesort(int a[],int n){
    for (int i = 1; i <= n - 1;i++){
        for (int j = 0; j < n - i;j++)
            if(a[j]>a[j+1]){
                int temp;
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
    }
}

void selectsort(int a[],int n){
    for (int i = 0; i < n-1;i++){
        int k = i;
        for (int j = i + 1; j < n;j++){
            if(a[j]<a[k]){
                int temp;
                temp = a[k];
                a[k] = a[j];
                a[j] = temp;
            }
        }
    }
}

void insertsort(int a[],int n){
    for (int i = 1; i < n;i++){
        int temp = a[i];
        int j = i;
        while(temp<a[j-1]&&j>0){
            a[j] = a[j - 1];
            j--;
        }
        a[j] = temp;
}

}
int main()
{
    int n;
    int a[120];
    scanf("%d", &n);
    for (int i = 0; i < n;i++){
        scanf("%d", &a[i]);
    }
    insertsort(a, n);
    for (int i = 0; i < n; i++)
    {
        
        printf("%d ", a[i]);
        }
        getchar();
        getchar();
        return 0;
}
        