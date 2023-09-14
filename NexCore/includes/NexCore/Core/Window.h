#ifndef __NexCore_Core_Window_H__
#define __NexCore_Core_Window_H__

#include <functional>

#include <NexCore/Core/CoreEvent.h>

namespace nex {
    struct WindowProps {
        const char* title = "NexWindow";
        int width = 1280;
        int height = 720;
    };

    class Window {
    public:
        virtual ~Window() = default;

        virtual void onUpdate() = 0;

        virtual int width() const = 0;
        virtual int height() const = 0;
        virtual const char* title() const = 0;

        virtual void* getNativeWindow() = 0;

        virtual void setEventListener(CoreEventListener* listener) = 0;

        static Window* Create(const WindowProps& props);
    };
}

#endif // __NexCore_Core_Window_H__