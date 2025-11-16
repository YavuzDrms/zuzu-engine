#ifndef WINDOW_H
#define WINDOW_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <Log/Log.h>

namespace zuzu
{
    class Window
    {
    private:
        int m_Width, m_Height;
        const char* m_Title;
        GLFWwindow* m_Window;

        void m_CreateWindow();
        void m_LoadOpenGL();
        void m_Terminate();
        void m_Update();

    public:
        Window(int w, int h, const char* t)
            :   m_Width(w), m_Height(h), m_Title(t){};
        ~Window();

        void Init();
        void Close();
        void Update();
        void SetBackgroundColor(GLfloat red,GLfloat green, GLfloat blue,GLfloat alpha);

        bool IsClosed() {return glfwWindowShouldClose(this->m_Window);}

        int GetWidth() {return this->m_Width;}
        int GetHeight() {return this->m_Height;}
        const char* GetTitle() {return this->m_Title;}
        GLFWwindow* GetWindow() {return this->m_Window;}

        static void frame_buffer_size_callback(GLFWwindow* window, int width, int height);
    };
}

#endif