#include "application.h"

// ANSI C
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // sleep

// custom headers
#include "event.h"
#include "eventlistener.h"

typedef struct n
{
    Event* ev;  // evvent reference
    struct n* next;
} node;


void Application::push(Event* pEv)
{

    node* pn = (node*)malloc(sizeof(node));
    if(!pn) {
        return;
    }
    pn->ev = pEv;
    pn->next = p_head;
    p_head = pn;
}


Application::Application()
{

}


Application::~Application()
{
    while (p_head) {
        node* pdel = p_head;
        p_head = p_head->next;
        if (pdel) {
            free(pdel);
        }
    }
}


Application::Application(int a, char **pa)
    :argc(a), argv(pa), p_head(0)
{
    p_evListener = new EventListener(this);
    p_evListener->init();
}


int Application::exec()
{
    // by default this will loop forever
    while (1) {
        // listen for events
        // process latest event

        while (p_head) {

            node* pdel = p_head;
            p_head = p_head->next;
            if(pdel) {
                pdel->ev->printMessage();
                free(pdel);
            }
        }
        // remove processed event
    }

    return 0;
}


//! exec as daemon, also need to handle the kill signals
//! \brief Application::execd
//! \return
//!
int Application::execd()
{
    switch(fork()) {
    case 0:
        break;
    case 1:
        exit(0);
    default:
        exit(0);
    }

    // when we get here we start to listen for registered events
    static int i =0;
    while (1) {
        // listen for events
        // process latest event
        FILE* fp = fopen("log", "a");
        if(!fp) {
            continue;
        }
        fprintf(fp, "logging...[%d] times\n", i++);
        usleep(10000);
        fclose(fp);
        // remove processed event
    }
}
