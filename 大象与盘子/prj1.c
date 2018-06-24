#include <stdio.h>
#include <math.h>

#define _USE_MATH_DEFINES

//计算平方，x^y
double my_pow(double x,int y){
	if(y == 0){
		return 1;
	}else if(y == 1){
		return x;
	}else{
		return x*my_pow(x,y-1);
	}
}
//计算两点距离
double caculate_two_points_distance(int start_x,int start_y,int end_x,int end_y){
	return sqrt(pow(start_x-end_x,2)+pow(start_y-end_y,2));
}
//计算点对应的极坐标的角度
double caculate_ceta(int point_x,int point_y){
	double ceta = 0;
	double zero_distance = caculate_two_points_distance(0,0,point_x,point_y);
	if(zero_distance!=0){
		ceta = asin(point_y/zero_distance);
		if(point_y >=0){
			if(point_x < 0) ceta = M_PI - ceta;
		}else{
			if(point_x < 0) ceta = -M_PI - ceta;
		}
	}
	return ceta;
}
//计算点到圆边的最短距离
double caculate_round_distance(int r,int point_x,int point_y){
	double zero_distance = caculate_two_points_distance(0,0,point_x,point_y);
	if(zero_distance >= r){
		return zero_distance - r;
	}else{
		return r - zero_distance;
	}
}
//计算点到其对面的圆上的点的坐标
void caculate_opposite_point(int r,int point_x,int point_y,double *opposite_point_x,double *opposite_point_y){
	double point_ceta = caculate_ceta(point_x,point_y);
	double opposite_point_ceta = point_ceta + M_PI; 
	*opposite_point_x = r*cos(opposite_point_ceta);
	*opposite_point_y = r*sin(opposite_point_ceta);
}

double caculate_shortest_distance(int r,int start_x,int start_y,int end_x,int end_y){
	//只有4条比较路线，取其中最短即可。
	//1号
	//4号+2号
	//3号+5号+2号
	//3号+6号
	int i = 0;
	double shortest_distance = 0;
	double route[4] = {0};
	double opposite_start[2];
	double opposite_end[2];
	double start_point_to_round_distance = 0; //3号
	double end_point_to_round_distance = 0; //2号
	double start_point_to_opposite_end_distance = 0; //4号
	double opposite_start_to_opposite_end_distance = 0; //5号
	double opposite_start_to_end_point_distance = 0; //6号
	route[0] = caculate_two_points_distance(start_x,start_y,end_x,end_y); //1号
	if((start_x==0&&start_y==0)||(end_x==0&&end_y==0)){
		return route[0];
	}
	//printf("route0:%.12lf\n",route[0]);
	shortest_distance = route[0];
	start_point_to_round_distance = caculate_round_distance(r,start_x,start_y);
	end_point_to_round_distance = caculate_round_distance(r,end_x,end_y);
	caculate_opposite_point(r,start_x,start_y,&opposite_start[0],&opposite_start[1]);
	caculate_opposite_point(r,end_x,end_y,&opposite_end[0],&opposite_end[1]);
	start_point_to_opposite_end_distance = caculate_two_points_distance(start_x,start_y,opposite_end[0],opposite_end[1]);
	opposite_start_to_opposite_end_distance = caculate_two_points_distance(opposite_start[0],opposite_start[1],opposite_end[0],opposite_end[1]);
	opposite_start_to_end_point_distance = caculate_two_points_distance(opposite_start[0],opposite_start[1],end_x,end_y);
	route[1] = start_point_to_opposite_end_distance + end_point_to_round_distance;
	route[2] = start_point_to_round_distance + opposite_start_to_opposite_end_distance + end_point_to_round_distance;
	route[3] = start_point_to_round_distance + opposite_start_to_end_point_distance;
	for(i=1;i<4;i++){
		//printf("route%d:%.12lf\n",i,route[i]);
		if(route[i] < shortest_distance){
			shortest_distance = route[i];
		}
	}
	return shortest_distance;
}

int main(void)
{
	int r = 0;
	int start_x = 0;
	int start_y = 0;
	int end_x = 0;
	int end_y = 0;
	double shortest_distance = 0;
	scanf("%d",&r);
	scanf("%d",&start_x);
	scanf("%d",&start_y);
	scanf("%d",&end_x);
	scanf("%d",&end_y);
	shortest_distance = caculate_shortest_distance(r,start_x,start_y,end_x,end_y);
	printf("%.12lf\n",shortest_distance);
	return 0;
}