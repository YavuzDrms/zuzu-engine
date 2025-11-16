#ifndef EVENT_H
#define EVENT_H

#include <iostream>
#include <vector>
#include <functional>

namespace zuzu {
    class Event
    {
    public:
        Event(int num, std::function<void()> func)
            :m_Number(num), m_Function(func){};

        int GetNumber(){return m_Number;}
        std::function<void()> GetFunction(){return m_Function;}

    private:
        int m_Number;
        std::function<void()> m_Function;
    };

    class EventListener
    {
    public:
        std::vector<Event> m_Events;

        void AddEvent(const Event& event);
        void RemoveEvent(int num);
        Event GetEvent(int num);
        void EmitEvent(int num);
        void LogEvents();
    };  
}

#endif