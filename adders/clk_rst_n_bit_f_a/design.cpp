#include "systemc.h"
#include "full_adder.cpp"
#include "const.h"

SC_MODULE(NBitAdder) {
    // Input ports
    sc_in_clk clk;
    sc_in<bool> reset;
    sc_in<sc_bv<1>> a[N];
    sc_in<sc_bv<1>> b[N];
    sc_in<sc_bv<1>> cin;

    // Output ports
    sc_out<sc_bv<1>> sum[N];
    sc_out<sc_bv<1>> carry_out;

    // Internal signals
    sc_signal<sc_bv<1>> carry[N];

    // Full adder modules
    FullAdder* adder[N];

    SC_CTOR(NBitAdder) {

        // Instantiating N full adder modules
        for (int i = 0; i < N; i++) {
            adder[i] = new FullAdder(sc_gen_unique_name("adder"));
            adder[i]->a(a[i]);
            adder[i]->b(b[i]);

            // Setting the carry input of the first adder to cin
            if (i == 0) {
                adder[i]->cin(cin);
            }
            // Setting the carry input of the remaining adders to the carry output of the previous adder
            else {
                adder[i]->cin(carry[i-1]);
            }

            adder[i]->sum(sum[i]);

            // Setting the carry output of the last adder to cout
            if (i == N-1) {
                adder[i]->carry_out(carry_out);
            }
            // Setting the carry output of the remaining adders to the carry signal array
            else {
                adder[i]->carry_out(carry[i]);
            }
        }

        // Process for updating the carry signal
        SC_METHOD(data);
        sensitive << clk.pos();
        async_reset_signal_is(reset, true);
    }

    void data() {
        if (reset.read()) {
            carry[0] = 0;
        } else {
            for (int i = 0; i < N; i++) {
                carry[i] = adder[i]->carry_out.read();
            }
        }
    }
};







