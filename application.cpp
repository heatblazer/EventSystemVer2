#include "application.h"

#include <iostream>
#include <stdio.h>

#include "eventlistener.h"

typedef struct n
{
    int ID;
    struct n* next;
} node;


void Application::push(int taskId)
{
    node* pn = new node;
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
            printf("[%d]\n", pdel->ID);
            delete pdel;
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
            std::cout << p_head->ID << std::endl;
            node* pdel = p_head;
            p_head = p_head->next;
            delete pdel;
        }
        // remove processed event
    }

    return 0;
}
