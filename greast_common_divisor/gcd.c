#include <stdio.h>

int gcd(int a, int b){
    int a_temp;
    int b_temp;
    int r;
    if(a < 0){
        a_temp = -a;
    }else{
	a_temp = a;
    }
    if(b < 0){
        b_temp = -b;
    }else{
        b_temp = b;
    }
    if(b_temp > a_temp){
	r = a_temp;
        a_temp = b_temp;
        b_temp = r;	
    }
    r = a_temp % b_temp;
    while(r != 0){
	a_temp = b_temp;
	b_temp = r;
	r = a_temp % b_temp;
    }
    return b_temp;
}

int main(int argc, char* argv[]){
    int a;
    int b;
    int n;
    while(1){
	printf("enter a:");
	scanf("%d", &a);
	printf("enter b:");
	scanf("%d", &b);
        n = gcd(a, b);
	printf("gcd(a, b)= %d \n", n);
    }
    return 0;
}
