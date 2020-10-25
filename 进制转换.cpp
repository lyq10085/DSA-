#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <stack>
#include <time.h>

using namespace std;


void swap (int &a, int &b)
    {
        int temp;
        temp = a;
        a = b;
        b = temp;
}
void bubblesort(int a[], int n){
    for (int i = 1; i <= n - 1;i++){
        for (int j = 0; j < n - i;j++)
            if(a[j]<a[j+1])
                swap(a[j], a[j + 1]);
    }
}


char findmax(int a,int b,int c){
    if(a>=b&&a>=c)
        return 'B';
    else if(b>=a&&b>=c)
        return 'C';
    else
        return 'J';
}

bool isleap(int year){
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int dextom(unsigned int  m, unsigned int x,char a[]){ //10进制数x 转化为m进制
    int i=0;
    while(x>0){
        if(x%m<10){
            a[i++] = (char)(x % m + 48 );
        }
        else
            a[i++] = (char)(x % m - 10 + (int)('A'));
        x = x / m;
        }
    return i-1;
}


int mtodex(unsigned int m,char x[]){  //m进制数 x 转化为10进制
    int ans=0, i=0;
    while(x[i]!= '\0'){
        if(x[i]>='0' && x[i]<='9')
            ans = ans*m + (int)(x[i]-'0');
        else if(x[i]>='A' && x[i]<='F')
            ans = ans*m + (int)(x[i] - 'A')+10;
        else
            ans = ans*m + (int)(x[i] - 'a')+10;
        i++;
    }
    return ans;
}


int main()
{
    unsigned int a, b;
    char n[10000];
    char num[10000] = {'0'};
    while(scanf("%d%s%d",&a,n,&b)!= EOF){
        memset(num, '0', sizeof(num));

        unsigned int len =dextom(b, mtodex(a, n), num);
        for ( int i = len; i >= 0;i--){
            printf("%c", num[i]);
        }

            printf("\n");
    }
    return 0;
}
        