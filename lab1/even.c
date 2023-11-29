#include <stdio.h>
int main(){
    int n,i,a[20];
    printf("Enter the limit of the  numbers:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter the number:");
        scanf("%d",&a[i]);
    }
    printf("The even numbers are:");
    for(i=0;i<n;i++){
        if(a[i]%2==0){
             printf(" %d ",a[i]);
        }
    }
}