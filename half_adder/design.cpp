/*#include <systemc.h>
//#include "half_adder.cpp"
SC_MODULE(HalfAdder){
 sc_in <bool> a;
 sc_in <bool> b;
 sc_out <bool> sum, carry;
 
  void half_adder()
  {
	   sum = a ^ b;
    carry = a & b;
  }
  
  SC_CTOR(HalfAdder){
    SC_METHOD(half_adder);
    sensitive << a << b;
  }
 

  
};*/
/*void HalfAdder :: half_adder(){
    sum = a ^ b;
    carry = a & b;
  }*/





#include <systemc.h>
//#include "half_adder.cpp"
SC_MODULE(HalfAdder){
 sc_in <bool> a;
 sc_in <bool> b;
 sc_out <bool> sum, carry;
 
  /*void half_adder()
  {
	   sum = a ^ b;
  //  carry = a & b;
  }*/


 void xor_gate()
 {
	 sum = a ^ b;
 }




 void and_gate()
 {
	 carry = a & b;
 }
  
  SC_CTOR(HalfAdder){
    SC_METHOD(xor_gate);
    sensitive << a <<b;


    SC_METHOD(and_gate);
    sensitive <<a  <<  b ;
  }

 

  
};
/*void HalfAdder :: half_adder(){
    sum = a ^ b;
    carry = a & b;
  }*/








