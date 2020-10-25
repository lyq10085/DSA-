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


int main()
{
    int month[14][2] = {
        {0,0},
        {31,31},
        {29,28},
        {31,31},
        {30,30},
        {31,31},
        {30,30},
        {31,31},
        {31,31},
        {30,30},
        {31,31},
        {30,30},
        {31,31}
    };
    int t1, t2, y1, y2, m1, m2, d1, d2;
    while(scanf("%d%d", &t1, &t2)!=EOF) {
        if(t1>t2)
            swap(t1, t2);
        int ans = 0;
        y1 = t1 / 10000;
        y2 = t2 / 10000;
        m1 = (t1 / 100) % 100;
        m2 = (t2 / 100) % 100;
        d1 = t1 % 100;
        d2 = t2 % 100;
        for (int i = y1+1; i < y2; i++)
        {
            if (isleap(i))
                ans += 366;
            else
                ans += 365;
        }
        // printf("%d\n", ans);
        if(y1==y2){
            if(isleap(y1))
                for (int i = m1; i < m2; i++)
                    ans += month[i][0];
            else
                for (int i = m1; i < m2; i++)
                    ans += month[i][1];
            ans -= d1;
            ans += d2;
        } 
        else{
            if(isleap(y1))
                for (int i = m1; i < 13;i++)
                    ans += month[i][0];
            else
                for (int i = m1; i < 13;i++)
                    ans += month[i][1];
            // printf("%d\n", ans);
            if (isleap(y2))
                for (int i = 1; i < m2; i++)
                    ans += month[i][0];
            else
                for (int i = 1; i < m2; i++)
                    ans += month[i][1];
            // printf("%d\n", ans);
            ans -= d1;
            ans += d2; 
    }   
    printf("%d\n", ans+1);
    }

    // system("pause");
    return 0;
}
        