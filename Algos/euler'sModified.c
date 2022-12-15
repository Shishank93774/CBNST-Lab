#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

double h, x[1000 + 1], y[1000 + 1], t;
int n;

double f(double , double );  // dy/dx = f(x, y)

int main(){
    scanf("%d", &n);   // n (STEPS) should be a large number
    scanf("%lf%lf", &x[0], &y[0]);
    scanf("%lf", &t);
    h = t/(double)n;
    for(int i = 1; i<=n; i++) y[i] = y[i-1] + h*f(x[i-1], y[i-1]), x[i] = x[i-1] + h;
    printf("f(%lf) = %lf", t, y[n]);
    return 0;
}

double f(double x, double y){
    return x + y;
}

