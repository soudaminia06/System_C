#include <systemc.h>
SC_MODULE(HalfAdder){
 sc_in<bool> a, b;
 sc_out<bool> sum, carry;
 
  void function(){
    sum = a ^ b;
    carry = a & b;
  }
  
  SC_CTOR(HalfAdder){
    SC_METHOD(function);
    sensitive << a << b;
  }
  
  
};
