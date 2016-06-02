#include "eventlistener.h"

#include "application.h"

#include <stdio.h>

void* EventListener::run(void *pdata)
{
    EventListener *e = (EventListener*) pdata;

    while (1) {
        // listen for input
        char c = getchar();
        getchar();
        e->p_application->push((int)c);
    }
}


EventListener::EventListener(Application *papp)
    : p_application(papp)
{

}


EventListener::EventListener()
{

}


EventListener::~EventListener()
{

}


void EventListener::init()
{
    pthread_create(&m_thread, NULL, run, this);
}
