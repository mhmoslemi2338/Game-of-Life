#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void delay(int milli_seconds) { 
    clock_t start_time = clock(); 
    while (clock() < start_time + milli_seconds) ; 
} 

	
void draw(int h,int w,char tmp[w][h],int turn){
	system("CLS");
	int i,j;
	printf(" ");
	for(j=0;j<h;j++)
		printf("==");
	printf("\n");
	for(i=0;i<w;i++){
		printf("|");
		for(j=0;j<h;j++){
			printf(tmp[i][j]?"#":" ");
			printf(" ");
		}
		printf("|\n");
		if(i==w-1){
			printf(" ");
			for(j=0;j<h;j++)
				printf("==");
			printf("\n\n  size = %d\t generation = %d \n",h,turn);
		}
	}
}


void Evolution(int h,int w,char tmp[w][h]){
	char new_world[w][h];
	int alives;
	
	int i,j,x,y;
	for(i=0;i<w;i++){
		for(j=0;j<h;j++){
			alives=0;
			if(tmp[i][j]) alives--;
			for(x=i-1;x<=i+1;x++)
				for(y=j-1;y<=j+1;y++)
					if(tmp[(x+w)%w][(y+h)%h]) alives++;					 
						
			if(alives==3) new_world[i][j]=1;
			else if(alives==2 && tmp[i][j]==1) new_world[i][j]=1;
			else new_world[i][j]=0;
		}
	}
	for(i=0;i<w;i++){
		for(j=0;j<h;j++){
			tmp[i][j]=new_world[i][j];
		}
	}
}


int main(){
	srand(time(0));
	system("mode con: cols=100 lines=50");
	
	printf("\n  Enter the universe size(recommend 30) : ");
	int h;
	scanf("%d",&h);
	
	
	int w=h;
	char world[w][h];
	
	int i,j;
	for(i=0;i<w;i++){
		for(j=0;j<h;j++){
			world[i][j]=rand()< RAND_MAX/8 ? 1 : 0;
		}
	}
	int turn=1;
	while(1){	
	draw(h,w,world,turn);
	Evolution(h,w,world);
	turn++;
	delay(700); // in milli sec
	}
	
	return 0;
}






