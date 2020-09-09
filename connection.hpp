#ifndef _CONNECTION_HPP_
#define _CONNECTION_HPP_

class connection
{
    public:
        connection(double weight):weight(weight){};
        void set_input(double val){input=val;};
        void set_delta(double del){delta=del;};
        void update();
        double get_output(){return input*weight;};
        double get_delta(){return delta*weight;};
    private:
        double delta;
        double weight;
        double input;
        static double lr;//lr - learning rate
};

#endif