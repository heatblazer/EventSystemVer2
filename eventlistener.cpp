#include "eventlistener.h"

#include "application.h"

#include <stdio.h>

void* EventListener::run(void *pdata)
{
    EventListener *e = (EventListener*) pdata;
    static int i =0;
    while (1) {
        // listen for input
 //       char c = getchar();
 //       getchar();
        if ( (i % 0xffff == 0) ) {
            i = 0;
        }
        i++;
        pthread_mutex_lock(&e->m_mutex);
        e->p_application->push(i);
        pthread_mutex_unlock(&e->m_mutex);

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
