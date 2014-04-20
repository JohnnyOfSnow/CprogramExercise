#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 4 // define a constant
int walk(const char *direction[]);
void result(int walkRemember[ ], int times);

int main(void){
    
    srand(time(NULL)); // randomize without entering a seed each time
    
    // initialize suit array                       
   const char *direction[ SIZE ] =            
      { "往上", "往下", "往左", "往右" };
      
   int walkRemember[SIZE] = {0};
   int count;
   int i;
   for(i = 0; i <= 500; ++i){
         count = walk(direction);
         walkRemember[count] = walkRemember[count] + 1;
   }
   
   i = i - 1;
   result(walkRemember, i);
   system("pause");
   return 0;
    
}


int walk(const char *direction[]){
    
     int path;
     path = rand() % 2;
     if(path == 0){
            path = rand() % 10;
            if(path <= 3){
                  path = 0;  
                  printf("他 %s 走\n",direction[0]);
            }else{
                  path = 1;  
                  printf("他 %s 走\n",direction[1]);
            }
     }else if(path == 1){
                   path = rand() % 10;
            if(path <= 6){
                  path = 2;
                  printf("他 %s 走\n",direction[2]);  
            }else{
                  path = 3;
                  printf("他 %s 走\n",direction[3]);  
            }
     }else{
           printf("程式出現邏輯錯誤，需要修改程式\n");
     }
     
     return path;
}

void result(int walkRemember[ ], int times){
     
     printf("-------------------------------------------------\n");
     printf("醉漢走了 %d 步後", times);
     int vertical = walkRemember[0] - walkRemember[1];
     int horizontal = walkRemember[3] - walkRemember[2];
     puts(""); 
     printf("醉漢水平距離移動了 %d\n", horizontal);
     printf("醉漢垂直距離移動了 %d\n", vertical);
     printf("最終醉漢到達的座標為( %d ,%d )\n", horizontal, vertical);
     
}
