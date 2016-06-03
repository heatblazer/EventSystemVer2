#ifndef EVENTLISTENER_H
#define EVENTLISTENER_H

#include <pthread.h>
#include <unistd.h>



class Application;

class EventListener
{
public:
    EventListener();
    EventListener(Application* papp);
    virtual ~EventListener();

    void init(void);
    static void* run(void* pdata) ;

private:
    Application* p_application;

    pthread_t m_thread;
    pthread_mutex_t m_mutex;


};

#endif // EVENTLISTENER_H
