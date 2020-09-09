#ifndef _NN_HPP_
#define _NN_HPP_
#include <vector>
#include "neuron.hpp"

typedef std::vector<neuron*> layer; 

class nn
{
    public:
        nn(std::vector<int> top);
        void forward(std::vector<double> in);
        void backward(std::vector<double> pout);
        //void train(std::vector<double> in,std::vector<double> out);
        std::vector<double> get_output();
    private:
        std::vector<int> topology;
        std::vector<layer> layers;
};


#endif