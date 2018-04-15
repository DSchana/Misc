#include <iostream>

struct base { virtual ~base() { } }; // define a base type
struct derived1 : public base { }; // define a derived type
struct derived2 : public base { }; // define a derived type

int process(base*, base*) { return 0; } // process two base args
int process(derived1*, derived1*) { return 1; } // process two derived1 args
int process(derived1*, derived2*) { return 2; } // process derived1, derived2
int process(derived2*, derived1*) { return 3; } // process derived2, derived1
int process(derived2*, derived2*) { return 4; } // process two derived2 args

int main()
{
   base* b1 = new derived1; base* b2 = new derived2;
   std::cout << process(b1,b2) << '\n';
   delete b2; delete b1;

   return 0;
}
