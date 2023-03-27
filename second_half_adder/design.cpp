#include <systemc.h>
//#include "half_adder.cpp"
SC_MODULE(HalfAdder){
 sc_in<bool> a, b;
 sc_out<bool> sum, carry_out;
 
  void function();
  
  SC_CTOR(HalfAdder){
    SC_METHOD(function);
    sensitive << a << b;
  }
 

  
};
void HalfAdder :: function(){
    sum = a ^ b;
    carry_out = a & b;
  }
