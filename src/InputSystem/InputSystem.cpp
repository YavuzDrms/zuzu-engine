#include <InputSystem/InputSystem.h>

namespace zuzu
{
    GLFWwindow* InputSystem::window = nullptr;
    std::unordered_map<int, bool> InputSystem::currentKeys;
    std::unordered_map<int, bool> InputSystem::previousKeys;

    std::unordered_map<int, bool> InputSystem::currentMouse;
    std::unordered_map<int, bool> InputSystem::previousMouse;
    double InputSystem::mouseX = 0.0;
    double InputSystem::mouseY = 0.0;

    void InputSystem::Init(GLFWwindow* win)
    {
        window = win;
    }
    void InputSystem::Update()
    {
        previousKeys = currentKeys;

        for (int key = GLFW_KEY_SPACE; key <= GLFW_KEY_LAST; key++)
        {
            int state = glfwGetKey(window, key);
            currentKeys[key] = (state == GLFW_PRESS || state == GLFW_REPEAT);
        }

        glfwGetCursorPos(window, &mouseX, &mouseY);
    }
    bool InputSystem::isKeyDown(int key)
    {
        return currentKeys[key];
    }
    bool InputSystem::isKeyPressed(int key)
    {
        return currentKeys[key] && !previousKeys[key];
    }
    bool InputSystem::isKeyReleased(int key)
    {
        return !currentKeys[key] && previousKeys[key];
    }

    bool InputSystem::IsMouseDown(int button)
    {
        return currentMouse[button];
    }

    bool InputSystem::IsMousePressed(int button)
    {
        return currentMouse[button] && !previousMouse[button];
    }

    bool InputSystem::IsMouseReleased(int button)
    {
        return !currentMouse[button] && previousMouse[button];
    }

    void InputSystem::GetMousePosition(double& x, double& y)
    {
        x = mouseX;
        y = mouseY;
    }
}