#include <iostream>
#include "restaurante.h"
using namespace std;

int main()
{
    restaurante *rr = new restaurante ();
    rr->control();
    delete rr;
    return 0;
}

