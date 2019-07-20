#include "stdio.h"

// Extended Euclidean Algorithm
// d = gcd(a, b) = ax + by
// input a,b
// output x,y
// return d
int gcd_ex(int a, int b, int *x, int *y){
    int a_temp;
    int b_temp;

    int a_negative_flag = 0;
    int b_negative_flag = 0;
    int a_b_swap_flag = 0;

    int x1 = 1; //init value
    int y1 = 0; //x(-1) = 1, y(-1) = 0;
    int x2 = 0;
    int y2 = 1; //x(0) = 0, y(0) = 1;

    int q; // q = a_temp / b_temp;
    int r; // r = a_temp % b_temp;
   
    if(a < 0){
        a_temp = -a;
	a_negative_flag = 1;
    }else{
        a_temp = a;
    }

    if(b < 0){
        b_temp = -b;
	b_negative_flag = 1;
    }else{
        b_temp = b;
    }

    if(b_temp > a_temp){
        r = a_temp;
	a_temp = b_temp;
	b_temp = r;
	a_b_swap_flag = 1;
    }

    if(b_temp == 0){
	*x = 1;
	*y = 0;
	if(a_b_swap_flag){
	    *x = 0;
	    *y = 1;
	}
	if(a_negative_flag){
	    *x = -*x;
	}
	if(b_negative_flag){
            *y = -*y;
	}
	return a_temp;
    }

    r = a_temp % b_temp;
    q = a_temp / b_temp;

    if(r == 0){
	*x = 0;
	*y = 1;
        if(a_b_swap_flag){
	    *x = 1;
	    *y = 0;
	}
        if(a_negative_flag){
	    *x = -*x;
	}	
	if(b_negative_flag){
	    *y = -*y;
	}
        return b_temp;
    }

    while(r != 0){
	*x = x1 - (q * x2);
        *y = y1 - (q * y2);
	x1 = x2;
	y1 = y2;
	x2 = *x;
	y2 = *y;
	a_temp = b_temp;
        b_temp = r;
        r = a_temp % b_temp;
        q = a_temp / b_temp;	
    }
   
    if(a_b_swap_flag){
	r = *x;
	*x = *y;
	*y = r;
    }
    if(a_negative_flag){
        *x = -*x;
    }
    if(b_negative_flag){
        *y = -*y;
    }
    
    return b_temp;
}

int main(int argc, char *argv[]){
    int a;
    int b;
    int d;
    int x;
    int y;
    while(1){
        printf("enter a:");
        scanf("%d", &a);
        printf("enter b:");
        scanf("%d", &b);
        d = gcd_ex(a, b, &x, &y);
        printf("gcd(a, b) = %d \n", d);
        printf("ax + by = gcd(a, b)\n");
        printf("x = %d, y = %d \n", x, y);	
    }
    return 0;
}
