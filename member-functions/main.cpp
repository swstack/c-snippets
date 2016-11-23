#include <iostream>

using namespace std;

class A {
 private:
  int id;

 public:
  A(int _id) {
    id = _id;
  }

  void a() {
    cout << "a() called on instance id: " << id << "\n";
  }
};

typedef void (A::*MemberFunctionPtr)();

int main() {
  cout << "---START---\n";
  A i1(1);
  A i2(2);

  i1.a();  // Prints: a() called on instance id: 1
  i2.a();  // Prints: a() called on instance id: 2


  MemberFunctionPtr ptr = &A::a;
  (i1.*ptr)();  // Prints: a() called on instance id: 1
  (i2.*ptr)();  // Prints: a() called on instance id: 2
}
