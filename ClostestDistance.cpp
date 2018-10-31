#include<iostream>
#include<cmath>
#include<ctime>
#include<algorithm>

using namespace std;

#define NO_DISTANCE 1000000

typedef struct point{
	float x; 
	float y;
}Point;//点的结构 

void randPoint(Point *points,int length){//生成的点数组，需要生成的点数 
	srand((unsigned)time(NULL));
	for( int i = 0; i < length; i++){
		points[i].x = (rand()%20000)/100.0-100;
		points[i].y = (rand()%20000)/100.0-100;
	}
}

float getDistance(Point a,Point b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));//计算两点之间的距离 
}

bool cmpX(Point a,Point b){
	return a.x<b.x;//制定按x升序排序的规则 
} 

float mergeDistance(Point points[],int length,Point &a,Point &b){
	float distance;//记录最近距离
	float d1,d2;//记录子集最小距离
	Point a1,a2,b1,b2;//记录子集的最小点对
	int i,j,k;
	
	if(length < 1){
		return NO_DISTANCE;
	}
	
	if(length == 2){
		a = points[0];
		b = points[1];
		
		distance = getDistance(a,b);
	}
	else{
		Point *pts1 = new Point[length];
		Point *pts2 = new Point[length];//开辟两个新空间 
		
		sort(points,points+length,cmpX);
		float mid = points[(length-1)/2].x;
		
		for(i = 0;i<length/2;i++){
			pts1[i] = points[i];
		}
		for(j = 0,i=length/2;i<length;i++){
			pts2[j++] = points[i];
		}
		d1 = mergeDistance(pts1,length/2,a1,b1);
		d2 = mergeDistance(pts2,length/2,a2,b2);
		
		if(d1<d2){
			distance = d1;
			a = a1;
			b = b1;
		}else{
			distance = d2;
			a = a2;
			b = b2;
		}
		
		Point *pts3 = new Point[length];
		for(i=0,k=0;i<length;i++){
			if(abs(points[i].x-mid)<=distance){
				pts3[k++] = points[i];//判断是否在distance内部 
			}
		}
		for(i=0;i<k;i++){
			for(j=i+1;j<=i+7&&j<k;j++){
				if(getDistance(pts3[i],pts3[j])<distance){
					distance = getDistance(pts3[i],pts3[j]);
					a = pts3[i];
					b = pts3[j];
				}
			}
		}
		 
	}
	return distance;
} 

int main(){
	int N;
	Point a,b;
	float distance;
	
	cout<<"输入生成的点对个数";
	cin>>N;
	
	cout<<endl<<"生成的点对如下"<<endl;
	Point *points = new Point[N];
	randPoint(points,N);
	
	for(int i = 0;i<N;i++){
		cout<<points[i].x<<","<<points[i].y<<endl;
	}
	
	distance = mergeDistance(points,N,a,b);
	
	cout<<"排序后的点对为"<<endl; 
	for(int i = 0;i<N;i++){
		cout<<points[i].x<<","<<points[i].y<<endl;
	}
	
	cout<<"最近点对为"<<"("<<a.x<<","<<a.y<<")"<<"和"<<"("<<b.x<<","<<b.y<<")"<<endl<<"最近距离是："<<distance<<endl; 
}
