#include <systemc.h>
SC_MODULE(FullAdder){
 sc_in<sc_bv<1>> a;
 sc_in<sc_bv<1>> b;
 sc_in<sc_bv<1>> cin;
 sc_out<sc_bv<1>> sum, carry_out;
 
  /*void full_adder()
  {
           sum.write ( a.read() xor b.read() xor cin.read() );  
           carry.write ( (a.read() and b.read()) or (b.read() and cin.read()) or (cin.read() and a.read()) );	   
  }*/
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
