#include<iostream>
#include<cmath>
using namespace std;


int n;
int f;
int sizeFarm[32];
int numAnimal[32];
int envFriendly[32];


int main(){
  cin >> n;
  while (n--){
    cin >> f;
    for (int i = 0; i < f; i++){
      cin >> sizeFarm[i] >> numAnimal[i] >> envFriendly[i];
    }


    int s1 = 0;
    for (int i = 0; i < f; i++){
      s1 += envFriendly[i] * sizeFarm[i];
    }

    cout << s1 << endl;
  }
}
