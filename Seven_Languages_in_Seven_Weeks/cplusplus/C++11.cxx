

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<stack>
#include<vector>
#include<cassert>
#include<queue>
#include<array>
using namespace std;


void cin_test(){
  if (cin){
    cout << "test" << endl;
  }
}
void vector_test(){
  vector<int> va1 = {1, 2}; // Best!
  vector<int> va2({1, 2}); // Best!
  vector<int> va3{1, 2};
  vector<int> va4{{1, 2}};
 // vector<int> va5{{{1, 2}}}; // CompileError!
  assert(va1 == va2);
  assert(va1 == va3);
  assert(va1 == va4);
 // assert(va1 == va5);
  va2 = {1, 2};
  cout << "vector_test Done!" << endl;
}
  
void stack_test(){
  // stack<int> s1 = {1, 2}; // CompileError!
  //stack<int> s33 = va1; // CompileError!
//  stack<int> s34 = 1;
//  stack<int> s35{1, 2}; // CompileError!
  stack<int> s36({1, 2}); // Best!

  

  deque<int> dq1 = {1, 2};
  // stack<int> s2 = dq1; // CompileError!
  stack<int> s3 = decltype(s3)(dq1);
  stack<int> s4(dq1);
}

#include<algorithm>
void lambda_test()
{
	[] { cout << "Hello, World" << endl; } ();
	
	
    
  array<int, 3> arr = { {1, 2, 3} };
  int inc = 55;
  for_each(arr.begin(), arr.end(), [inc](int &i) { i = i + inc; });
  for (auto k : arr  ) cout << k << endl;

  //int s = 0;
	//for (const int& x : arr) s=max(s,foo(x));
    //generate_n (myarray, 9, UniqueNumber);
	system("Pause");
}

void scope_test(){
//  int a = 1;
  struct A{
    static void foo() {
      cout << "foo()" << endl;
   //   cout << a << endl; 
    }
  };
  A::foo();
}
int main(){
  lambda_test();
  //scope_test();
  //stack_test();
  //vector_test();
  //cin_test();
}
