#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>

const int MAX_ITER = 100;
const double e = 0.0001;
double f(double x);

int main(){
    double a, b;
    int curIter = 0;
    double c, fc;
    scanf("%lf%lf", &a, &b);
    do{
        double fa = f(a),fb = f(b);
        c = (a*fb - b*fa)/(fb - fa);
        fc = f(c);
        if(fa<0 && fb>0){
            if(fc<0){
                a = c;
            }else{
                b = c;
            }
        }else if(fa>0 && fb<0){
            if(fc<0){
                b = c;
            }else{
                a = c;
            }
        }else{
            printf("Not a valid range!!!....\n");
            break;
        }
        printf("a: %lf, fa = %lf\n", a, fa);
        printf("b: %lf, fb = %lf\n", b, fb);
        printf("c: %lf, fc = %lf\n", c, fc);
        if(fabs(fc) < e){
            printf("Root is: %.4lf with an error of under %.4lf and value of %.4lf\nAlso it took %d iterations", c, e, fc, curIter);
            break;
        }
        curIter++;
    }while(true && curIter < MAX_ITER);
    return 0;
}

double f(double x){
    double v = x*log10(x) - 1.2;
    return v;
}