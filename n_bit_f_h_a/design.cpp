#include "systemc.h"
#include "full_adder.cpp" 
#include "const.h" 

SC_MODULE(NBitAdder) {
    // input ports
    sc_in<sc_bv<1>> a[N];
    sc_in<sc_bv<1>> b[N];
    sc_in<sc_bv<1>> cin;


    // output ports
    sc_out<sc_bv<1>> sum[N];
    sc_out<sc_bv<1>> carry_out;

    // internal signals
    sc_signal<sc_bv<1>> carry[N];

    // full adder modules
    FullAdder* adder[N];

    SC_CTOR(NBitAdder) {
        // instantiate N full adder modules
        for (int i = 0; i < N; i++) {
            adder[i] = new FullAdder(sc_gen_unique_name("adder"));
            adder[i]->a(a[i]);
            adder[i]->b(b[i]);

            // set the carry-in signal of the first adder to 0
            if (i == 0) {
                adder[i]->cin(cin);
            }
            // set the carry-in signal of the remaining adders to the carry-out of the previous adder
            else {
                adder[i]->cin(carry[i-1]);
            }

            adder[i]->sum(sum[i]);

            // set the carry-out signal of the last adder to the carry-out port of the ripple carry adder module
            if (i == N-1) {
                adder[i]->carry_out(carry_out);
            }
            // set the carry-out signal of the remaining adders to the carry signal array
            else {
                adder[i]->carry_out(carry[i]);
            }
        }
    }
};

