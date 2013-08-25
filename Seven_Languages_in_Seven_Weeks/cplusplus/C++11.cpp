

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<stack>
#include<vector>
#include<cassert>
#include<queue>
using namespace std;

int foo(int x)
{
  for (size_t i = 0; i < asdf; i++) {
    sdifj
  }
  for (int i = 0; i < ; i++) {
    
  }
  
  for (auto sdlkfj = sdlkfj.begin(); sdlkfj != sdlkfj.end(); ++sdlkfj) {
    asdl;kfj
  } 
  for (auto isdf = isdf.begin(); isdf != isdf.end(); ++isdf) {
    std::cout << *isdf << std::endl;
  }

  for (i = 0; i < count; i++) {
    
  }
	return x;
}

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


void lambda_test()
{
	[] { cout << "Hello, World" << endl; } ();
	
	
	int i = 1024;
    auto func = [=] { printf("%d\n", i); };
    func();
    
    int&& s = 0;
    int arr[4];
	for (const int& x : {0,1,2})
    	s=max(s,foo(x));
	printf("%d", s);
	for (const int& x : arr)
    	s=max(s,foo(x));
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
  scope_test();
  stack_test();
  vector_test();
  cin_test();
}
