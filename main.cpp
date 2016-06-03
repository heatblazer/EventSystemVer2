#include "application.h"

#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{

    // test the new event class and sub system
    Application app(argc, argv);
    return app.exec();
}
