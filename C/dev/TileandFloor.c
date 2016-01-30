#include <stdio.h>

int TileN(int RoomW, int RoomH, int TileW, int TileH){
	int W,H;
	W=RoomW/TileW;
	H=RoomH/TileH;
	return W*H; 
}

int main(void){
	int RoomW, RoomH, TileW, TileH;
	scanf("%d,%d,%d,%d",&RoomW, &RoomH, &TileW, &TileH);
	printf("%d",TileN(RoomW, RoomH,TileW, TileH));
	printf("\n");
	system("pause");
	return 0;
}
