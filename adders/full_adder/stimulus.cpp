#include "systemc.h"

SC_MODULE (Stimulation) {
  // Module IO
  
  sc_out <bool>  a;
  sc_out <bool>  b;
  sc_out <bool> cin;
  sc_in  <bool> sum;
  sc_in  <bool> carry;

  sc_trace_file* f ;
  
  // Procinesses
  void stim () {
/*	srand(time(NULL)) ;
  for(int i = 0; i < 10; i++){
  a = rand() % 2;
  b = rand() % 2;
  cin = rand() % 2;
  wait(20, SC_NS);
  cout << " a = " << a.read() <<" b = " << b.read() <<" cin = " << cin.read() << " sum = " << sum.read() << " "<<" carry = " << carry.read() << " "<<sc_time_stamp() << std::endl;*/
 //  for(int i = 0; i < 2; i++){
 /* a = 0;
  b = 0;
  cin=0;
  wait(10, SC_NS);
  cout << " a = " << a.read() <<" b = " << b.read() <<" cin = " << cin.read() << " sum = " << sum.read() << " "<<" carry = " << carry.read() << " "<<sc_time_stamp() << std::endl;
  a = 0;
  b = 0;
  cin=1;
  wait(10, SC_NS);
  cout << " a = " << a.read() <<" b = " << b.read() <<" cin = " << cin.read() << " sum = " << sum.read() << " "<<" carry = " << carry.read() << " "<<sc_time_stamp() << std::endl;
  a = 0;
  b = 1;
  cin=0;
  wait(10, SC_NS);
  cout << " a = " << a.read() <<" b = " << b.read() <<" cin = " << cin.read() << " sum = " << sum.read() << " "<<" carry = " << carry.read() << " "<<sc_time_stamp() << std::endl;
  a = 0;
  b = 1;
  cin=1;
  wait(10, SC_NS);
  cout << " a = " << a.read() <<" b = " << b.read() <<" cin = " << cin.read() << " sum = " << sum.read() << " "<<" carry = " << carry.read() << " "<<sc_time_stamp() << std::endl;
   a = 1;
   b = 0;
   cin=0;
  wait(10, SC_NS);*/
  cout << " a = " << a.read() <<" b = " << b.read() <<" cin = " << cin.read() << " sum = " << sum.read() << " "<<" carry = " << carry.read() << " "<<sc_time_stamp() << std::endl;
  a = 1;
  b = 0;
  cin=1;
  wait(10, SC_NS);
  cout << " a = " << a.read() <<" b = " << b.read() <<" cin = " << cin.read() << " sum = " << sum.read() << " "<<" carry = " << carry.read() << " "<<sc_time_stamp() << std::endl;
/*  a = 1;
  b = 1;
  cin=0;
  wait(10, SC_NS);
  cout << " a = " << a.read() <<" b = " << b.read() <<" cin = " << cin.read() << " sum = " << sum.read() << " "<<" carry = " << carry.read() << " "<<sc_time_stamp() << std::endl;
  a = 1;
  b = 1;
  cin=1;
  wait(10, SC_NS);
  cout << " a = " << a.read() <<" b = " << b.read() <<" cin = " << cin.read() << " sum = " << sum.read() << " "<<" carry = " << carry.read() << " "<<sc_time_stamp() << std::endl;*/
// }
  };

   
  // Construcintor
  SC_CTOR(Stimulation) {
	  // Set up the waveform dump
   f = sc_create_vcd_trace_file("waves");
  sc_trace(f, a, "a");
  sc_trace(f, b, "b");
  sc_trace(f, cin, "cin");
  sc_trace(f, sum, "sum");
  sc_trace(f, carry, "carry");


    // Register a thread in SystemC
    //scin_start(100, SC_NS);
    SC_THREAD(stim);
      }    
  ~Stimulation()
  {
	  sc_close_vcd_trace_file(f);
  }
    
};
