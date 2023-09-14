#include <NexCore/Platform/Windows/WindowsWindow.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <NexCore/Core/Core.h>
#include <NexCore/Core/CoreEventTypes.h>
#include <NexCore/Input/InputEventTypes.h>

namespace nex {
    static bool glfwInitialized = false;

    void glfwWindowSizeCallback(GLFWwindow* window, int width, int height);
    void glfwWindowCloseCallback(GLFWwindow* window);
    void glfwKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
    void glfwMouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
    void glfwCursorPosCallback(GLFWwindow* window, double xPos, double yPos);
    void glfwScrollCallback(GLFWwindow* window, double xOffset, double yOffset);

    Window* Window::Create(const WindowProps& props) {
        return new WindowsWindow(props.title, props.width, props.height);
    }

    WindowsWindow::WindowsWindow(const char* title, int width, int height)
        : data_{ title, width, height }
    {
        init();
    }

    WindowsWindow::~WindowsWindow() {
        shutdown();
    }

    void glfwErrorCallback(int error, const char* description) {
        log_crit("GLFW Error ({0}): {1}", error, description);
    }

    void WindowsWindow::init() {
        if (!glfwInitialized) {
            int initialized = glfwInit();
            NEX_ASSERT(initialized, "GLFW initialization failed!");
            glfwSetErrorCallback(glfwErrorCallback);
            glfwInitialized = true;
        }

        window_ = glfwCreateWindow(data_.width, data_.height, data_.title, nullptr, nullptr);
        NEX_ASSERT(window_ == nullptr, "GLFW window creation failed!");

        glfwMakeContextCurrent(window_);
        int gladLoaded = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
        NEX_ASSERT(gladLoaded, "glad load failed!");

        log_info("OpenGL Info:");
        log_info("  Vendor:   {0}", (const char*)glGetString(GL_VENDOR));
        log_info("  Renderer: {0}", (const char*)glGetString(GL_RENDERER));
        log_info("  Version:  {0}", (const char*)glGetString(GL_VERSION));

        glfwSetWindowUserPointer(window_, &data_);
        setVSync(true);

        glfwSetWindowSizeCallback(window_, glfwWindowSizeCallback);
        glfwSetWindowCloseCallback(window_, glfwWindowCloseCallback);
        glfwSetKeyCallback(window_, glfwKeyCallback);
        glfwSetMouseButtonCallback(window_, glfwMouseButtonCallback);
        glfwSetCursorPosCallback(window_, glfwCursorPosCallback);
        glfwSetScrollCallback(window_, glfwScrollCallback);

        glfwGetKey(window_, GLFW_KEY_LEFT_CONTROL);
    }

    void WindowsWindow::shutdown() {
        glfwDestroyWindow(window_);
    }

    void WindowsWindow::onUpdate() {
        glfwPollEvents();
        glfwSwapBuffers(window_);
    }
    
    void WindowsWindow::setVSync(bool enabled) {
        if (enabled) {
            glfwSwapInterval(1);
        } else {
            glfwSwapInterval(0);
        }
        data_.vsync = enabled;
    }

    void glfwWindowSizeCallback(GLFWwindow* window, int width, int height) {
        WindowsWindow::WindowData* data = reinterpret_cast<WindowsWindow::WindowData*>(glfwGetWindowUserPointer(window));
        data->width = width;
        data->height = height;

        WindowSizeEvent event(width, height);
        data->eventListener->onEvent(event);
    }

    void glfwWindowCloseCallback(GLFWwindow* window) {
        WindowsWindow::WindowData* data = reinterpret_cast<WindowsWindow::WindowData*>(glfwGetWindowUserPointer(window));

        WindowCloseEvent event;
        data->eventListener->onEvent(event);
    }

    void glfwKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
        WindowsWindow::WindowData* data = reinterpret_cast<WindowsWindow::WindowData*>(glfwGetWindowUserPointer(window));

        switch (action) {
            case GLFW_PRESS: {
                KeyPressedEvent event(key, false);
                data->eventListener->onEvent(event);
                break;
            }
            
            case GLFW_REPEAT: {
                KeyPressedEvent event(key, true);
                data->eventListener->onEvent(event);
                break;
            }

            case GLFW_RELEASE: {
                KeyReleasedEvent event(key);
                data->eventListener->onEvent(event);
                break;
            }
        }
    }

    void glfwMouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
        WindowsWindow::WindowData* data = reinterpret_cast<WindowsWindow::WindowData*>(glfwGetWindowUserPointer(window));

        switch (action) {
            case GLFW_PRESS: {
                MouseButtonPressedEvent event(button);
                data->eventListener->onEvent(event);
                break;
            }

            case GLFW_RELEASE: {
                MouseButtonReleasedEvent event(button);
                data->eventListener->onEvent(event);
                break;
            }
        }
    }

    void glfwCursorPosCallback(GLFWwindow* window, double xPos, double yPos) {
        WindowsWindow::WindowData* data = reinterpret_cast<WindowsWindow::WindowData*>(glfwGetWindowUserPointer(window));

        MouseMovedEvent event(static_cast<float>(xPos), static_cast<float>(yPos));
        data->eventListener->onEvent(event);
    }

    void glfwScrollCallback(GLFWwindow* window, double xOffset, double yOffset) {
        WindowsWindow::WindowData* data = reinterpret_cast<WindowsWindow::WindowData*>(glfwGetWindowUserPointer(window));

        MouseScrolledEvent event(static_cast<float>(xOffset), static_cast<float>(yOffset));
        data->eventListener->onEvent(event);
    }
}