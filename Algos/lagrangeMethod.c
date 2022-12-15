#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>

const int MAX_ITER = 4;
double x[1001], y[1001], t;
int n;

int main(){
    scanf("%d", &n);
    for(int i = 0; i<n; i++) scanf("%lf%lf", &x[i], &y[i]);

    scanf("%lf", &t);
    double ans = 0.0;
    for(int i = 0; i<n; i++){
        double temp = y[i];
        double num = 1.0;
        double deno = 1.0;
        for(int j = 0; j<n; j++){
            if(i == j) continue;
            num = num*(t-x[j]);
            deno = deno*(x[i] - x[j]);
        }
        ans = ans + temp*num/deno;
        printf("%lf\n", ans);
    }
    printf("\nf(%lf) = %lf", t, ans);
    return 0;
}
/*
4
5 12
6 13
9 14
11 16
10
 */
