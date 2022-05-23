#include<stdio.h>
#include<stdbool.h>

int main(){
    int n, m;
    printf("Enter array dimensions : ");
    scanf("%d%d", &n, &m);
    n = n * m;
    bool b=true;
    printf("Enter Elements : \n");
    for(int i=0; i<n; i++){
        scanf("%d", &m);
        if (m!=0 && m!=1){
            b=0;
            break;
        }
    }

    if (b) printf("Yes\n");
    else printf("No\n");

}