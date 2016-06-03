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

    // runnable code
    static void* run(void* pdata) ;

private:
    Application* p_application;

    // threading for reading a cosnole input if not daemonized
    pthread_t m_thread;
    pthread_mutex_t m_mutex;


};

#endif // EVENTLISTENER_H
