#include <systemc.h>
SC_MODULE(HalfAdder){
 sc_in<sc_uint<1>> a;
 sc_in<sc_uint<1>> b;
 sc_out<sc_uint<1>> sum, carry;
 
 void half_adder()
  {
           sum.write ( a.read() ^ b.read() );  
           carry.write ((a.read() & b.read()) );	   
  }
  
  SC_CTOR(HalfAdder){
    SC_METHOD(half_adder);
    sensitive << a << b ;
  }
 

  
};
