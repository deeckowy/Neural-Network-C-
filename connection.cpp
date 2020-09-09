#include "connection.hpp"
#include <iostream>

void connection::update(){weight+=lr*delta*input;}

double connection::lr=0.5;