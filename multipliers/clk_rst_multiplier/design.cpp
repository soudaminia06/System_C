#include "systemc.h"
#include "const.h"


SC_MODULE(multiplier) {
    sc_in<bool> clk;
    sc_in<bool> rst;

    sc_in<sc_biguint<N>> a;
    sc_in<sc_biguint<N>> b;

    sc_out<sc_biguint<2*N>> out;

    void multiply() {
        sc_biguint<2*N> product = 0; //initializing product which is of 64 bit to zero

        for (int i = 0; i < N-1; i++) {
            if (b.read()[i]) {
                product = product + (a.read() << i);
            }
        }
        out.write(product);
    }

    SC_CTOR(multiplier) {
        SC_METHOD(multiply);
        sensitive << clk.pos();
        sensitive << rst.pos();
        sensitive << a;
        sensitive << b;
    }
};

