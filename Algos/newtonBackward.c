#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

double x[1001], delF[1001][1001], t;
int n;
double h, a, u;


double f();

int main(){
    scanf("%d", &n);
    for(int i = 0; i<n; i++){
        scanf("%lf%lf", &x[i], &delF[i][0]);
    }
    
    for(int j = 1; j<n; j++){
        for(int i = 0; i<n-j; i++){
            delF[i][j] = delF[i+1][j-1] - delF[i][j-1];
        }
    }
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n-i; j++){
            printf("%lf ", delF[i][j]);
        }
        printf("\n");
    }

    scanf("%lf", &t);

    h = x[n-1] - x[n-2];
    a = x[n-1];
    u = (t - a)/h;
    printf("h: %lf\n", h);
    printf("a: %lf\n", a);
    printf("u: %lf\n", u);


    printf("f(%lf) = %lf", t, f());
}

double f(){
    double res = delF[n-1][0]; // f(a)
    double num2 = u;
    double num = u;
    double deno2 = 1;
    double deno = 1;
    for(int j = 1; j<n; j++){
        res += delF[n-1-j][j]*num/deno;
        deno2++;
        num2++;
        num *= num2;
        deno *= deno2;
    }
    return res;
}

/*
5
1891 46
1901 66
1911 81
1921 93 
1931 101
1925
*/