#include<stdio.h>
int i=0;
void TowerofHanoi(int n, char from, char to, char help){
    // printf("\n");
    if (n==1){
        i++;
        printf("Move Disk 1 from rod %c to rod %c\n", from, to);
        return;
    }

    TowerofHanoi(n-1, from, help, to);
    printf("Move Disk %d from rod %c to rod %c\n", n, from, to);
    i++;
    TowerofHanoi(n-1, help, to, from);
}


int main(){
    int n;
    printf("Enter no of rings : ");
    scanf("%d", &n);
    TowerofHanoi(n, 'A', 'C', 'B');
    printf("Moves = %d\n", i);
}