#include<cstdio>


int a;

bool is_leapyear(int y){
  if (y % 4 != 0)
    return false;
  if (y % 100 == 0 && y % 400 != 0)
    return false;
  if (y % 3200 == 0)
    return false;
  return true;
}


int main(){
  scanf("%d", &a);
  if (is_leapyear(a)){
    printf("Y\n");
  }else{
    printf("N\n");
  }
  return 0;
}
