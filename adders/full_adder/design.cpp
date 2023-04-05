#include <systemc.h>
SC_MODULE(FullAdder){
 sc_in <bool> a;
 sc_in <bool> b;
 sc_in <bool> cin;
 sc_out <bool> sum, carry;
 
  void full_adder()
  {
           sum= a xor b xor cin;  
           carry = (a and b) or (b and cin) or (cin and a);	   
  }
  
  SC_CTOR(FullAdder){
    SC_METHOD(full_adder);
    sensitive << a << b << cin;
  }
 

  
};
