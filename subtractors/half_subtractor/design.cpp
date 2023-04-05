
#include <systemc.h>
SC_MODULE(HalfSubtractor){
 sc_in <bool> a;
 sc_in <bool> b;
 sc_out <bool> diff, borrow;
 
 void xor_gate()
 {
	 diff = a xor b;
 }

 void and_gate()
 {
	 borrow = (not a) and b;
 }
  
  SC_CTOR(HalfSubtractor){
    SC_METHOD(xor_gate);
    sensitive << a <<b;


    SC_METHOD(and_gate);
    sensitive <<a  <<  b ;
  }

 

  
};

