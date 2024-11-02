#include <stdio.h>
#include <stdlib.h>
int zero = 0;
int one = 1;
int two = 2;
int three =3;
int count = 0;

int safe(int ** arr,int ** combination,int n,int i, int j){
    for(int k = i-one; k>= zero  ; k--){
        if(arr[k][j] == two)
            break;
        if(arr[k][j] == one  &&   ( combination[i][j] == zero ))
            return zero;
        if(arr[k][j] == one  &&   ( combination[i][j] == two ) )
            return zero;
        if(arr[k][j] == one  &&   ( combination[k][j] == zero ) )
            return zero;
        if(arr[k][j] == one  &&   (  combination[k][j] == two) )
            return zero;
        
    }
    for(int k = one; i-k >=zero  && j-k >=zero  ; k++){
        if(arr[i-k][j-k] == two)
            break;
        if(arr[i-k][j-k] == one && (   combination[i-k][j-k] == one ) )
            return zero;
        if(arr[i-k][j-k] == one && (   combination[i-k][j-k] == two ) )
            return zero;
        if(arr[i-k][j-k] == one && (   combination[i][j] == one ) )
            return zero;
        if(arr[i-k][j-k] == one && (    combination[i][j] == two) )
            return zero;
    }
    for(int k = one; i-k >=zero  && j+k <n  ; k++){
        if(arr[i-k][j+k] == two)
            break;
        if(arr[i-k][j+k] == one   && (combination[i-k][j+k] == one ))
            return zero;
        if(arr[i-k][j+k] == one   && (combination[i-k][j+k] == two ))
            return zero;
        if(arr[i-k][j+k] == one   && (combination[i][j] == one ))
            return zero;
        if(arr[i-k][j+k] == one   && (combination[i][j] == two))
            return zero;
    }
    return one;
}

void place(int ** arr, int** combination,int n, int r,int piece ){
    if(piece == n  ){
            count++;
            return;
        }
    
    if(r == n ){
        if(piece == n  )
            count++;
        return;
    }

    for(int c = zero;c<n ; c++){
        if( arr[r][c] != two  &&  safe(arr,combination,n,r,c)){
            arr[r][c] = one;
            place(arr,combination,n,r+one,piece+one);
            arr[r][c] = zero;
        }
    }
}
int main(){
    int n;
    int k;
    scanf("%d",&n);
    scanf("%d",&k);
    int watchmen[k][two];

    int z = zero;
    while(z < k){
        scanf("%d",&watchmen[z][zero]);
        scanf("%d",&watchmen[z][one]);
        z++;
    }
    int ref[two];
    scanf("%d %d",&ref[zero],&ref[one]);

    int ** combination = (int**) malloc(n* sizeof(int*));
    int **arr = (int**) malloc(n* sizeof(int*));

    int op = zero;
    while(op<n){
        combination[op] = (int*) calloc(n,sizeof(int));
        arr[op] = (int*) calloc(n,sizeof(int));op++;
    }

    for(int i=zero;i<n;i++){
        for(int j=zero; j<n; j++){
            int a = abs(i - ref[zero]);
            int b = abs(j - ref[one]);
            combination[i][j] =  (a+b)% three;
            arr[i][j] = zero;
        }
    }
    for(int i=zero; i<k;i++){
        arr[watchmen[i][zero]][watchmen[i][one]] = two;
    }
    place(arr,combination,n,zero,zero);
    printf("%d",count);
}
