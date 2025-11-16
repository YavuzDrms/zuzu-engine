#include <iostream>

#include <Log/Log.h>
#include <EventSystem/event.h>

void func()
{
    ZUZU_LOG_INFO("event gerceklesti la");
}

int main()
{

    zuzu::Log::Init();

    ZUZU_LOG_INFO("Hello ZUZU");

    zuzu::Event event = zuzu::Event(115, func);
    zuzu::EventListener listener;
    listener.AddEvent(event);
    listener.LogEvents();

    listener.EmitEvent(115);

    std::cin.get();

    return 0;
}