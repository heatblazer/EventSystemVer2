#ifndef EVENT_H
#define EVENT_H

// pure abstract or some default implementation???

class Event
{
public:

    explicit Event(const char* msg);
    virtual ~Event();
    virtual void printMessage(void);

private:

    char m_message[256];
};

#endif // EVENT_H
