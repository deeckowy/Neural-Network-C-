#include <iostream>
#include <vector>
#include <cmath>
#include "nn.hpp"

int main()
{
    std::vector<int> t={2,2,1};
    nn mynet=nn(t);
    for(int i=0;i<1000000;i++)
    {
        int x=rand()%2;
        int y=rand()%2;
        mynet.forward({double(x),double(y)});
        mynet.backward({double(x^y)});
    }
    mynet.forward({1.0,1.0});
    std::cout<<"1^1 = "<<round(mynet.get_output()[0])<<"\nReal neural network prediction :"<<mynet.get_output()[0]<<std::endl;
    mynet.forward({1.0,0.0});
    std::cout<<"1^0 = "<<round(mynet.get_output()[0])<<"\nReal neural network prediction :"<<mynet.get_output()[0]<<std::endl;
    mynet.forward({0.0,1.0});
    std::cout<<"0^1 = "<<round(mynet.get_output()[0])<<"\nReal neural network prediction :"<<mynet.get_output()[0]<<std::endl;
    mynet.forward({0.0,0.0});
    std::cout<<"0^0 = "<<round(mynet.get_output()[0])<<"\nReal neural network prediction :"<<mynet.get_output()[0]<<std::endl;
    
    return 0;
}