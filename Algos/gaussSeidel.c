#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
// #define double long double

const int MAX_ITER = 4;
double mat[100][100+1], ans[100], sum[100];
int n;

bool isApplicable(){
    for(int i = 0; i<n; i++)
       if(2*mat[i][i] < sum[i]) return false;
    return true;
}

int main(){
    int curIter = 0;
    scanf("%d", &n);
    for(int i = 0; i<n; i++){
        sum[i] = 0;
        ans[i] = 0;
        for(int j = 0; j<n; j++){
            scanf("%lf", &mat[i][j]);  // LHS
            sum[i] += mat[i][j];
        }
        scanf("%lf", &mat[i][n]);  // RHS 
    }
    if(!isApplicable()){
        printf("This method can't be applied here!\n");
        return 0;
    }
    do{
        curIter++;
        for(int i = 0; i<n; i++){
            ans[i] = mat[i][n];
            for(int j = 0; j<n; j++){
                if(i == j) continue;
                ans[i] = ans[i] - mat[i][j]*ans[j];
            }
            ans[i] /= mat[i][i];
        }
    }while(curIter < MAX_ITER);
    for(int i = 0; i<n; i++)printf("%lf ",ans[i]);
    return 0;
}
