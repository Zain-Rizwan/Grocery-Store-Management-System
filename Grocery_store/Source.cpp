#include <iostream>

#include <string.h>
#include <stdio.h>
#include <windows.h>
#include <chrono>
#include "Checkout_Simulation.h"


#include "../i21-2500_Project/Grocery_Store.h"

using namespace std;


int main()
{
    double t;
    auto starter = chrono::steady_clock::now();//   Starting Timer

    Grocery_Store g;
    g.menu();
    auto ender = chrono::steady_clock::now();//     Ending Timer
    t = double(chrono::duration_cast <chrono::seconds>(ender - starter).count());// Calculating Total Time in Seconds

    simulation s(t);
    s.saveTime();// Saving Time in File
    
    return 0;
}

