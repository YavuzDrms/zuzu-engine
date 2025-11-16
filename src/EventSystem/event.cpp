#include <EventSystem/event.h>
#include <Log/Log.h>
namespace zuzu
{
    void EventListener::AddEvent(const Event& event)
    {
        m_Events.push_back(event);
        ZUZU_LOG_INFO("Event added");
    }
    void EventListener::RemoveEvent(int num)
    {
        for (long long unsigned int i = 0; i < m_Events.size(); i++)
        {
            if (m_Events[i].GetNumber() == num)
                m_Events.erase(m_Events.begin() + i);
            else
                ZUZU_LOG_ERROR("Can not find event");
        }
    }
    Event EventListener::GetEvent(int num)
    {
        for (auto& a : m_Events)
        {
            if (a.GetNumber() == num){
                return a;
            }
        }
        ZUZU_LOG_ERROR("Can not find event");
    }
    void EventListener::EmitEvent(int num)
    {
        for (auto& a : m_Events)
        {
            if(num == a.GetNumber())
            {
                a.GetFunction()();
                ZUZU_LOG_INFO("Event emitted: {}", a.GetNumber());
                return;
            }
        }
        ZUZU_LOG_ERROR("Can not find event");
    }
    void EventListener::LogEvents()
    {
        if (!m_Events.empty())
        {
            for(auto &e : m_Events)
            {
                ZUZU_LOG_INFO("{}", e.GetNumber());
            }
        }
        else 
        {
            ZUZU_LOG_ERROR("Event listener is empty");
        }        
    }
}