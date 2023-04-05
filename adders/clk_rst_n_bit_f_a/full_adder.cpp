#include <systemc.h>
SC_MODULE(FullAdder){
 sc_in<sc_bv<1>> a;
 sc_in<sc_bv<1>> b;
 sc_in<sc_bv<1>> cin;
 sc_out<sc_bv<1>> sum, carry_out;
 
 void full_adder()
  {
           sum.write ( a.read() ^ b.read() ^ cin.read() );  
           carry_out.write ((a.read() & b.read()) | (b.read() & cin.read()) | (cin.read() & a.read()) );	   
  }
  
  SC_CTOR(FullAdder){
    SC_METHOD(full_adder);
    sensitive << a << b << cin;
  }
 

  
};
