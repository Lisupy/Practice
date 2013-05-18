#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;


struct TestCase{
  char left[5];
  char right[5];
  char result[20];
};

TestCase tests[3];

struct Try{
  char false_coin;
  bool heavy;
};

bool judge(const Try &t, const TestCase &test){
  if (strcmp(test.result, "even") == 0){
    if (find(test.left, test.left+4, t.false_coin) != test.left+4){
      return false;
    }
    if (find(test.right, test.right+4, t.false_coin) != test.right+4){
      return false;
    }
    return true;
  }
  if (strcmp(test.result, "up") == 0){
    if (find(test.left, test.left+4, t.false_coin) != test.left+4 && 
      t.heavy == true){
      return true;
    }
    if (find(test.right, test.right+4, t.false_coin) != test.right+4 &&
      t.heavy == false){
      return true;
    }
  }

  if (strcmp(test.result, "down") == 0){
    if (find(test.left, test.left+4, t.false_coin) != test.left+4 && 
      t.heavy == false){
      return true;
    }
    if (find(test.right, test.right+4, t.false_coin) != test.right+4 &&
      t.heavy == true){
      return true;
    }
  }
  return false;
}


bool judge3(const Try& t){
  for (int i = 0; i < 3; i++){
    if (!judge(t, tests[i])){
      return false;
    }
  }
  return true;
}

int main(){
  int n;
  scanf("%d", &n);

  while (n--){
    for (int i = 0; i < 3; i++){
      scanf("%s %s %s", tests[i].left, tests[i].right, tests[i].result);
    }

    Try t;
    for (char c = 'A'; c <= 'L'; c++){
  //    printf("===%c :\n", c);
      t.false_coin = c;
      t.heavy = true;
      if (judge3(t)){
        break;
      }
   //   printf("===%c :\n", c);
      t.heavy = false;
      if (judge3(t)){
        break;
      }
    }

    printf("%c is the counterfeit coin and it is %s.\n",
      t.false_coin, t.heavy? "heavy" : "light");
  }
}
