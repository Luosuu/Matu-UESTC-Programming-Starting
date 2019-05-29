#include <stdio.h>
int main(){
    int s;
    scanf("%d",&s);
    int arr[100];
    for(int i=0; i<s;i++)
    {
        scanf("%d",&arr[i+1]);
        if(getchar()=='\n')
            break;
    }
    int t;
    //getchar();
    scanf("%d",&t);
    int low = 1, high = s, mid;
    mid = (low + high)/2;
    while(low<=high)
    {
        if(arr[mid]>t) high = mid - 1;
        else if(arr[mid]<t) low = mid + 1;
        else if(arr[mid]==t){
            printf("%d",mid);
           low=65535;
        }
        mid = (low + high)/2;
    }
    return 0;
}
