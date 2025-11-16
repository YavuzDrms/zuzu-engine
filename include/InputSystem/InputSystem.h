#ifndef INPUTSYSTEM_H
#define INPUTSYSTEM_H

#include <GLFW/glfw3.h>
#include <unordered_map>

namespace zuzu
{
    class InputSystem
    {
    public:
        static void Init(GLFWwindow* win);
        static void Update();

        static bool isKeyDown(int key); // basıldığında = true
        static bool isKeyPressed(int key); // basılı tutulduğu sürece = true
        static bool isKeyReleased(int key); // basmayı bıraktığında = true

        static bool IsMouseDown(int button); // basıldığında = true
        static bool IsMousePressed(int button); // basılı tutulduğu sürece = true
        static bool IsMouseReleased(int button); // basmayı bıraktığında = true
        static void GetMousePosition(double& x, double& y);
    private:
        static GLFWwindow* window;
        static std::unordered_map<int, bool> currentKeys;
        static std::unordered_map<int, bool> previousKeys;

        static std::unordered_map<int, bool> currentMouse;
        static std::unordered_map<int, bool> previousMouse;
        static double mouseX, mouseY;
    };
    }

#endif