#include <iostream>

#include <RenderSystem/Window.h>
#include <Log/Log.h>
#include <EventSystem/event.h>
#include <InputSystem/InputSystem.h>

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

    zuzu::Window window(800,800,"Zuzu");
    window.Init();

    zuzu::InputSystem::Init(window.GetWindow());

    while(!window.IsClosed())
    {
        window.SetBackgroundColor(0.7,0.3,0.4,1.0); // begin

        zuzu::InputSystem::Update();

        if (zuzu::InputSystem::isKeyPressed(GLFW_KEY_A)) ZUZU_LOG_TRACE("A");
        
        window.Update(); // end
    }

    window.Close();

    return 0;
}
