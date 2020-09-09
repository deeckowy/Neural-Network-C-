#ifndef _NEURON_HPP_
#define _NEURON_HPP_
#include <vector>
#include "connection.hpp"

class neuron;

class neuron
{
    public:
        neuron(int plc=0,int nlc=0);
        void setinput(double in=1){input=in;};
        void set_in_weights(std::vector<connection*>* iw){in_weights=iw;};
        void set_delta(double dest);
        void forward();
        void backward();
        void update();
        double getoutput(){return output;};
        connection* get_out_weight(int idx){return (*out_weights)[idx];};
    private:
        std::vector<connection*>* in_weights;
        std::vector<connection*>* out_weights;
        double input;
        double output;
        double delta;
};

#endif