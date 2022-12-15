#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

double h, x[1000 + 1], y[1000 + 1], t;
double k1, k2, k3, k4, k;
int n;

double f(double , double );  // dy/dx = f(x, y)

int main(){
    scanf("%d", &n);   // n (STEPS) should be a large number
    scanf("%lf%lf", &x[0], &y[0]);
    scanf("%lf", &t);
    h = t/(double)n;
    for(int i = 1; i<=n; i++){
        k1 = h*f(x[i-1], y[i-1]);
        k2 = h*f(x[i-1] + h/2, y[i-1] + k1/2);
        k3 = h*f(x[i-1] + h/2, y[i-1] + k2/2);
        k4 = h*f(x[i-1] + h, y[i-1] + k3);
        k = (k1+2*k2+2*k3+k4)/6;
        y[i] = y[i-1] + k;
        x[i] = x[i-1] + h;
    }
    printf("f(%lf) = %lf", t, y[n]);
    return 0;
}

double f(double x, double y){
    return x + y*y;
}

