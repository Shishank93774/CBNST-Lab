#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
// #define double long double

const int MAX_ITER = 100;
const double ERR = 0.0001;
const double e = 2.718281828459;
double mat[100][100+1], ans[100];

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            scanf("%lf", &mat[i][j]);  // LHS
        }
        scanf("%lf", &mat[i][n]);  // RHS 
    }
    for(int j = 0; j<n; j++){
        for(int i = j+1; i<n; i++){
            double f = mat[i][j]/(double)mat[j][j];
            for(int k = j; k<=n; k++){
                mat[i][k] = mat[i][k] - (f*mat[j][k]);
            }
        }
    }
    for(int j = n-1; j>0; j--){
        for(int i = 0; i<j; i++){
            double f = mat[i][j]/(double) mat[j][j];
            for(int k = n; k>=0; k--){
                mat[i][k] = mat[i][k] - (f*mat[j][k]);
            }
        }
    }
    for(int i = n-1; i>=0; i--){
        ans[i] = mat[i][n] / mat[i][i];
    }
    for(int i = 0; i<n; i++)printf("%lf ",ans[i]);
    return 0;
}
