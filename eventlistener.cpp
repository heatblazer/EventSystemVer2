#include "eventlistener.h"

#include "application.h"
#include "event.h"

// ANSI C
#include <stdio.h>
#include <string.h>

void* EventListener::run(void *pdata)
{
    EventListener *e = (EventListener*) pdata;
    static char msg[256] = {0};

    while (1) {
        // listen for input
        fgets(msg, sizeof(msg)/sizeof(char), stdin);
        if (strlen(msg) > 0) {
            msg[strlen(msg)-1] = 0; // cut the newline
            e->p_application->push(new Event(msg));
        }
        usleep(100); // needs a time to breathe
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
    // it`s good to setup some defauts for the thread
    pthread_create(&m_thread, NULL, run, this);
    pthread_mutex_init(&m_mutex, NULL);
}
