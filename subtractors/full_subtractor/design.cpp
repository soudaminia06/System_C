#include <systemc.h>
SC_MODULE(FullSubtractor){
 sc_in <bool> a;
 sc_in <bool> b;
 sc_in <bool> cin;
 sc_out <bool> diff, borrow;
 
  void full_subtractor()
  {
           diff = (((not a) and (not b) and cin) or ((not a) and b and (not cin)) or (a and (not b) and (not cin)i) or ( a and b and cin )) ;  
           borrow = ((( not a) and cin) or ((not a) and b) or (b and cin));	   
  }
  
  SC_CTOR(FullSubtractor){
    SC_METHOD(full_subtractor);
    sensitive << a << b << cin;
  }
 

  
};
