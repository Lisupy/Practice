//Algorithm:  simulation
//Complexity: 
//IndexBased: 0
//Trick:      


#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstring>
#include<string>
#include<iostream>
using namespace std;
const int MOD = 1000;

struct Machine{
  int reg[10];
  int ram[1000];
  int cmd_n;

  void debug(){
    for (int i = 0; i < 10; i++){
      printf("%d: %d,  ", i, reg[i]);
    }
    printf("\n");
    for (int i = 0; i < 10; i++){
      printf("%d: %d,  ", i, ram[i]);
    }
    printf("\n");
  }  
  
  void reset(){
    memset(reg, 0, sizeof(reg));
    memset(ram, 0, sizeof(ram));
    cmd_n = 0;
  }

  void add_cmd(int cmd){
    ram[cmd_n++] = cmd;
  }

  int execute(){
    int IP = 0;
    int executed_n = 0;
    int n, s, d, a;
    while (true){
      char cmd[16];
      sprintf(cmd, "%03d", ram[IP]);

      IP = (IP + 1) % MOD;
      ++executed_n;

      if (cmd[0] == '1' && cmd[1] == '0' && cmd[2] == '0'){
        break;
      }
      switch(cmd[0]){

      case '2':
        d = cmd[1] - '0';
        n = cmd[2] - '0';
        reg[d] = n;
        break;
      case '3':
        d = cmd[1] - '0';
        n = cmd[2] - '0';
        reg[d] += n;
        reg[d] %= MOD;
        break;
      case '4':
        d = cmd[1] - '0';
        n = cmd[2] - '0';
        reg[d] *= n;
        reg[d] %= MOD;
        break;
      case '5':
        d = cmd[1] - '0';
        s = cmd[2] - '0';
        reg[d] = reg[s];
        break;
      case '6':
        d = cmd[1] - '0';
        s = cmd[2] - '0';
        reg[d] += reg[s];
        reg[d] %= MOD;
        break;
      case '7':
        d = cmd[1] - '0';
        s = cmd[2] - '0';
        reg[d] *= reg[s];
        reg[d] %= MOD;
        break;
      case '8':
        d = cmd[1] - '0';
        a = cmd[2] - '0';
        reg[d] = ram[reg[a]];
        break;
      case '9':
        s = cmd[1] - '0';
        a = cmd[2] - '0';
        ram[reg[a]] = reg[s];
        break;
      case '0':
        d = cmd[1] - '0';
        s = cmd[2] - '0';
        if (reg[s] != 0){
          IP = reg[d];
        }
      }
    }
    return executed_n;
  }
};

Machine machine;


int main(){
  int T;
  scanf("%d\n", &T);
  char cmd[100];

  while (T--){
    machine.reset();

    while (fgets(cmd, sizeof(cmd), stdin)!= NULL){
      if (cmd[0] == '\n'){
        break;
      }else{
        int t;
        sscanf(cmd, "%d", &t);
        machine.add_cmd(t);
      }
    }

    int num_exection = machine.execute();

    printf("%d\n", num_exection);
    if (T){
      printf("\n");
    }

  }
}
