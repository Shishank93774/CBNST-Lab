#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
// #define double long double

const int MAX_ITER = 100;
const double ERR = 0.0001;
const double e = 2.718281828459;
double f(double x);
double g(double x);

int main(){
    double x0;
    int curIter = 0;
    double x1, fx1, gx1;
    scanf("%lf", &x0);
    do{
        double fx0 = f(x0), gx0 = g(x0);
        if(gx0 == 0){ printf("Can't find a valid solution!"); break;}
        x1 = x0 - fx0/gx0;
        fx1 = f(x1);
        curIter++;
        printf("x0: %lf\n fx0: %lf\n", x0, fx0);
        printf("x1: %lf\n fx1: %lf\n", x1, fx1);
        if(fabs(fx1) < ERR){
            printf("Root is: %.4lf with an error of under %.4lf and value of %.4lf\nAlso it took %d iteration(s)", x1, ERR, fx1, curIter);
            break;
        }
        x0 = x1;
    }while(true && curIter < MAX_ITER);
    return 0;
}

double f(double x){
    double v;
    // v = x*x*x - 3*x - 5;
    // v = cos(x) - x*pow(e, x);
    v = 2*(x-3) - log10(x);
    return v;
}

double g(double x){
    double v;
    // v = 3*x*x - 3;
    // v = -sin(x) - (1+x)*pow(e, x);
    v = 2.0 - 1.0/x;
    return v;
}