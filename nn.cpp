#include "nn.hpp"
#include <iostream>

nn::nn(std::vector<int> top):topology(top)
{
    for(int i=0;i<topology.size();i++)
    {
        layer play=layers.empty()?layer():layers[i-1];
        layer nlay;
        for(int k=0;k<topology[i];k++)
        {
            nlay.push_back(new neuron(i==0?0:topology[i-1],i==topology.size()-1?0:topology[i+1]));
            if(!play.empty())
            {
                std::vector<connection*>* tconn=new std::vector<connection*>();
                for(auto x:play)
                    tconn->push_back(x->get_out_weight(k));
                nlay.back()->set_in_weights(tconn);
            }
        }
        if(i!=topology.size()-1)
        {
            nlay.push_back(new neuron(i==0?0:topology[i-1],i==topology.size()-1?0:topology[i+1]));
            nlay.back()->setinput();
        }
        layers.push_back(nlay);
    }
}

void nn::forward(std::vector<double> in)
{
    for(int i=0;i<in.size();i++)
        layers[0][i]->setinput(in[i]);
    for(auto l:layers)
        for(auto n:l)
            n->forward();
}

void nn::backward(std::vector<double> pout)
{
    for(int i=0;i<pout.size();i++)
        layers.back()[i]->set_delta(pout[i]);
    for(int i=layers.size()-1;i>0;i--)
        for(auto n:layers[i])
            n->backward();
    for(auto l:layers)
        for(auto n:l)
            n->update();
}

std::vector<double> nn::get_output()
{
    std::vector<double> output;
    for(auto n:layers.back())
        output.push_back(n->getoutput());
    return output;        
}