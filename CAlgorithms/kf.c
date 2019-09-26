//
// Created by messi-lp on 18-9-24.
/*
 * 第一章
 * k阶斐波那契函数
 */
#include <stdlib.h>
#include <stdint.h>

int Fibonacci(int k,int n){
    if(k<1)exit(-1);
    int sum=0;
    int f[10001]={0};
    f[k-1]=1;
    for (int i = k; i <=n; ++i) {
        sum+=f[i-1];
        f[i]=sum;
    }

    return f[n];
}

void Calculation(int *a,int arrsize, int n){
    if (n>arrsize||n<=0||arrsize<=0)exit(-1);
    int c=1;
    int b=1;
    a[0]=1;
    for (int i = 1; i < n; ++i) {
        c=c*i;
        b=b*2;
        if ((unsigned)c*(unsigned)b>INT32_MAX)
            exit(-1);
        a[i]=c*b;
    }


}
