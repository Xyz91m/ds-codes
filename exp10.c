#include <stdio.h>
#include <math.h>

int main(){
    int no, bi=0, r, m=1;
    printf("Enter a number: ");
    scanf("%d", &no);
    int temp = no;
    while(no!=0){
        r=no%2;
        no=no/2;
        bi += r * m;
        m *= 10;
    }
    printf("Binary equivalent of %d is %d", temp, bi);
    return 0;
}