#include "neuron.hpp"
#include <cstdlib>
#include <cmath>
#include <iostream>

double activ(double x){return 1/(1+exp(-x));}

double activ_deriv(double x){return activ(x)*(1-activ(x));}


neuron::neuron(int plc,int nlc)
{
    in_weights=new std::vector<connection*>();
    out_weights=new std::vector<connection*>();
    for(int i=0;i<nlc;i++)
        out_weights->push_back(new connection(rand()/double(RAND_MAX)));
}

void neuron::forward()
{
    if(!in_weights->empty())
    {
        input=0.0;
        for(auto x:(*in_weights))
            input+=x->get_output();
    }
    output=activ(input);
    if(!out_weights->empty())
    {
        for(auto x:(*out_weights))
            x->set_input(output);
    }
}

void neuron::backward()
{
    if(!out_weights->empty())
    {
        delta=0.0;
        for(auto x:(*out_weights))
            delta+=x->get_delta();
        delta*=activ_deriv(input);
    }
    if(!in_weights->empty())
        for(auto x:(*in_weights))
            x->set_delta(delta);
}

void neuron::set_delta(double dest){delta=activ_deriv(input)*(dest-output);}

void neuron::update()
{
    if(!in_weights->empty())
        for(auto x:(*in_weights))
            x->update();
}