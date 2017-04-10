#include <stdio.h>
#include <stdbool.h>

int main(void) {
  int goal_x, goal_y;
  int x_size = 10;
  int y_size = 19;
  bool foundWave;
  int currentWave = 2; //Looking for goal first
  int map[10][19] = {{0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0,0,1,1,1,1,0,2,0,0,0,0},
                     {0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
  
  int y = 0;
  int x = 0;
  
  foundWave = true;
  
  while(foundWave == true)
  {
    foundWave = false;
    for(y=0; y < y_size; y++)
    {
      for(x=0; x < x_size; x++)
      {
        if(map[x][y] == currentWave)
        {
          foundWave = true;
          goal_x = x;
          goal_y = y;
 
          if(goal_x > 0) //This code checks the array bounds heading WEST
            if(map[goal_x-1][goal_y] == 0)  //This code checks the WEST direction
              map[goal_x-1][goal_y] = currentWave + 1;
 
          if(goal_x < (x_size - 1)) //This code checks the array bounds heading EAST
            if(map[goal_x+1][goal_y] == 0)//This code checks the EAST direction
              map[goal_x+1][goal_y] = currentWave + 1;
 
          if(goal_y > 0)//This code checks the array bounds heading SOUTH
            if(map[goal_x][goal_y-1] == 0) //This code checks the SOUTH direction
              map[goal_x][goal_y-1] = currentWave + 1;
 
          if(goal_y < (y_size - 1))//This code checks the array bounds heading NORTH
            if(map[goal_x][goal_y+1] == 0) //This code checks the NORTH direction
              map[goal_x][goal_y+1] = currentWave + 1;
        }
      }
    }
    currentWave++;
  }
  
  
  int i = 0;
  int j = 0;
  
  for(i = 0; i < x_size; i++) {
      printf("{");
      for( j = 0; j < y_size; j++) {
        printf("%d", map[i][j]);
        if(j != y_size - 1) {
            printf(",");
        }
      }
      printf("}\n");
  }
  
  return 0;
}
