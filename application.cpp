#include "application.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // sleep

#include "eventlistener.h"

typedef struct n
{
    int ID;
    struct n* next;
} node;


void Application::push(int taskId)
{

    node* pn = (node*)malloc(sizeof(node));
    if(!pn) {
        return;
    }
    pn->ID = taskId;
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
            printf("[%d]\n", p_head->ID);
            node* pdel = p_head;
            p_head = p_head->next;
            if(pdel) {
                free(pdel);
            }
        }
        // remove processed event
    }

    return 0;
}

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
