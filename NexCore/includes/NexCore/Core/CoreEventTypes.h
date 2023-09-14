#ifndef __NexCore_Core_CoreEventTypes_H__
#define __NexCore_Core_CoreEventTypes_H__

#include <NexCore/Core/CoreEvent.h>

namespace nex {
    class WindowCloseEvent : public CoreEvent {
    public:
        CORE_EVENT_TYPE(WindowClose)
        CORE_EVENT_CATEGORY(EventCategoryWindow)
    };

    class WindowSizeEvent : public CoreEvent {
    public:
        CORE_EVENT_TYPE(WindowSize)
        CORE_EVENT_CATEGORY(EventCategoryWindow)

        WindowSizeEvent(int width, int height)
            : width_(width), height_(height) {}

        int width() const { return width_; }
        int height() const { return height_; }

    private:
        int width_;
        int height_;
    };
}

#endif // __NexCore_Core_CoreEventTypes_H__