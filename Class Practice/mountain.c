a[5] ={1,2,3,2,1};
int count =0;
int count1=0;
for(int i = 0;i<2;i++){
    if(a[i]<a[i+1]){
        printf("Its a mountain");
        count++;
    }else{
        break;
    }
}

for(int i = 2;i<4;i++){
    if(a[i]>a[i+1]){
        printf("Its a mountain");
        count1++;
    }else{
        break;
    }
}
if(count==2&&count1==2){
    printf("Its a mountain array")
}