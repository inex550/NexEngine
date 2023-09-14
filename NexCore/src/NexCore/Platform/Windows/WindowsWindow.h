#ifndef __NexCore_Core_Platform_Windows_WindowsWindow_H__
#define __NexCore_Core_Platform_Windows_WindowsWindow_H__

#include <NexCore/Core/Window.h>

struct GLFWwindow;

namespace nex {

    class WindowsWindow : public Window {
    public:
        WindowsWindow(const char* title, int width, int height);
        ~WindowsWindow();

        void init();
        void shutdown();

        void onUpdate() override;

        const char* title() const override { return data_.title; }
        int width() const override { return data_.width; }
        int height() const override { return data_.height; }

        void setVSync(bool enabled);
        bool isVSyncEnabled() const { return data_.vsync; }

        void* getNativeWindow() override { return window_; }

        void setEventListener(CoreEventListener* eventListener) override { data_.eventListener = eventListener; }

        struct WindowData {
            const char* title = nullptr;
            int width = 0;
            int height = 0;

            bool vsync = false;

            CoreEventListener* eventListener;
        };

    private:
        GLFWwindow* window_;
        WindowData data_;
    };
}

#endif // __NexCore_Core_Platform_Windows_WindowsWindow_H__