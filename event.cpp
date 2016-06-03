#include "event.h"

#include <stdio.h>
#include <string.h>


Event::Event(const char *msg)
{
    memset(m_message, 0, sizeof(m_message)/sizeof(char));
    strcpy(m_message, msg);
}

Event::~Event()
{

}


void Event::printMessage()
{
    printf("[%s]\n", m_message);
}
