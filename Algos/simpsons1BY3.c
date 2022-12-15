#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

double a, b, h, y[1000 + 1], res;
int n;

double f(double );

int main(){
    scanf("%d", &n);   // n should be a large number
    scanf("%lf%lf", &a, &b);
    h = (b - a)/(double)n;
    for(int i = 0; i<=n; i++) y[i] = f(a + i*h);
    res += (y[0] + y[n]);
    for(int i = 1; i<n; i++) res = res + (i%2?4:2)*y[i];
    res *= h/3;
    printf("INT.[%lf, %lf] f(x) = %lf", a, b, res);
    return 0;
}

double f(double x){
    return 1.0 / (1.0 + x*x);
}
