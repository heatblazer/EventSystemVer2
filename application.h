#ifndef APPLICATION_H
#define APPLICATION_H

typedef struct n node;
class EventListener;

class Application
{

private:
    node* p_head;

public:
    Application(int a, char** pa);
    virtual ~Application();
    virtual int exec(void);
    virtual int execd(void);

private:
    Application();
    void push(int taskId);

    int argc;
    char** argv;
    EventListener *p_evListener;

    friend class EventListener;
};

#endif // APPLICATION_H
