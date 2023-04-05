#include <systemc.h>
//#include "design.cpp"

void HalfAdder :: function(){
    sum = a ^ b;
    carry_out = a & b;
  }
