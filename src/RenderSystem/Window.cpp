#include <RenderSystem/Window.h>

namespace zuzu 
{
    void Window::Init()
    {
        this->m_CreateWindow();
        this->m_LoadOpenGL();
    }
    void Window::Update()
    {
        this->m_Update();
    }
    void Window::Close()
    {
        this->m_Terminate();
    }
    void Window::m_CreateWindow()
    {
        if(!glfwInit()){
            ZUZU_LOG_ERROR("Can not init glfw");
            return;
        }
        this->m_Window = glfwCreateWindow(this->m_Width,this->m_Height,this->m_Title, NULL,NULL);
        if(this->m_Window == NULL){
            ZUZU_LOG_ERROR("Can not create window");
            glfwTerminate();
            return;
        }
    }
    void Window::m_Terminate()
    {
        glfwTerminate();
    }
    void Window::m_LoadOpenGL()
    {
        glfwMakeContextCurrent(this->m_Window);
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            ZUZU_LOG_ERROR("Can not init OpenGL");
            return;
        } 
        glViewport(0,0,this->m_Width,this->m_Height);

        glfwSetFramebufferSizeCallback(this->m_Window, Window::frame_buffer_size_callback);
        glfwSetWindowCloseCallback(this->m_Window, [](GLFWwindow*){
            ZUZU_LOG_INFO("Window close requested");
        });
        glfwSetWindowFocusCallback(this->m_Window, [](GLFWwindow* window, int focused){
            if(focused) ZUZU_LOG_INFO("Window focused");
            else ZUZU_LOG_INFO("Window lost focus");
        });
        glfwSetWindowIconifyCallback(this->m_Window, [](GLFWwindow* window,int iconified){
            if(iconified) ZUZU_LOG_INFO("Window minimized");
            else ZUZU_LOG_INFO("Window restored");
        });
        glfwSetWindowMaximizeCallback(this->m_Window, [](GLFWwindow* window,int maximized){
            if(maximized) ZUZU_LOG_INFO("Window maximized");
            else ZUZU_LOG_INFO("Window unmaximized");
        });
        glfwSetWindowPosCallback(this->m_Window, [](GLFWwindow* window,int x, int y){
            ZUZU_LOG_INFO("Window moved to {}, {}",x,y);
        });
        glfwSetWindowRefreshCallback(this->m_Window,[](GLFWwindow*){
            ZUZU_LOG_WARN("Window needs redraw");
        });

        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    }
    void Window::m_Update()
    {
        glfwSwapBuffers(this->m_Window);
        glfwPollEvents();
    }
    Window::~Window(){}
    void Window::frame_buffer_size_callback(GLFWwindow* window, int width, int height)
    {
        glViewport(0,0,width,height);
        ZUZU_LOG_INFO("Window and viewport resized: 0, 0, {}, {}",width,height);
    }
    void Window::SetBackgroundColor(GLfloat red,GLfloat green, GLfloat blue,GLfloat alpha)
    {
        glClearColor(red, green, blue, alpha);
        glClear(GL_COLOR_BUFFER_BIT);
    }
}