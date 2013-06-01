//Algorithm:  simulation
//Complexity: O(N)
//IndexBased: 0
//Trick:      table-driven


#include<cstdio>
#include<cstring>


/*
 *  0
 * 1 2
 *  3
 * 4 5
 *  6
 */
bool is_light[10][7] = 
{
// 0, 1, 2, 3, 4, 5, 6
  {1, 1, 1, 0, 1, 1, 1}, //0
  {0, 0, 1, 0, 0, 1, 0}, //1
  {1, 0, 1, 1, 1, 0, 1}, //2
  {1, 0, 1, 1, 0, 1, 1}, //3
  {0, 1, 1, 1, 0, 1, 0}, //4
  {1, 1, 0, 1, 0, 1, 1}, //5
  {1, 1, 0, 1, 1, 1, 1}, //6
  {1, 0, 1, 0, 0, 1, 0}, //7
  {1, 1, 1, 1, 1, 1, 1}, //8
  {1, 1, 1, 1, 0, 1, 1}, //9
};

void print_nchar(char c, size_t n){
  for (size_t i = 0; i < n; i++){
    printf("%c", c);
  }
}
void LCD_Display_horizontal(char *buf_n, size_t size, int pos){
  for (int i = 0; buf_n[i]; i++){
    int n = buf_n[i] - '0';
    if (i != 0){
      print_nchar(' ', 1);
    }
    print_nchar(' ', 1);
    char ch = is_light[n][pos]?'-':' ';
    print_nchar(ch, size);
    print_nchar(' ', 1);
  }
  printf("\n");
}
  
void LCD_Display_vertical(char *buf_n, size_t size, int pos1, int pos2){
  for (size_t si = 0; si < size; si++){
    for (int i = 0; buf_n[i]; i++){
      int n = buf_n[i] - '0';
      char ch1 = is_light[n][pos1] ? '|' : ' ';
      char ch2 = is_light[n][pos2] ? '|' : ' ';
      if (i != 0){
        print_nchar(' ', 1);
      }
      print_nchar(ch1, 1);
      print_nchar(' ', size);
      print_nchar(ch2, 1);
    } 
    printf("\n");
  }
}

void LCD_Display(char *buf_n, size_t size){
  LCD_Display_horizontal(buf_n, size, 0);
  LCD_Display_vertical(buf_n, size, 1, 2);
  LCD_Display_horizontal(buf_n, size, 3);
  LCD_Display_vertical(buf_n, size, 4, 5);
  LCD_Display_horizontal(buf_n, size, 6);
}

int main(){
  int s;
  char buf_n[16];
  while (scanf("%d%s", &s, buf_n) && s){
    LCD_Display(buf_n, s);
    printf("\n");
  }
}
