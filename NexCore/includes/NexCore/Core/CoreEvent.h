#ifndef __NexCore_Core_CoreEvent_H__
#define __NexCore_Core_CoreEvent_H__

namespace nex {
    enum class CoreEventType {
        None = 0,
        WindowClose,
        WindowSize,
        KeyPressed,
        KeyReleased,
        MouseButtonPressed,
        MouseButtonReleased,
        MouseMoved,
        MouseScrolled,
    };

    enum EventCategory {
        None = 0,
        EventCategoryWindow      = 1 << 0,
        EventCategoryKeyboard         = 1 << 1,
        EventCategoryMouse       = 1 << 2,
        EventCategoryMouseButton = 1 << 3,
    };

    class CoreEvent {
    public:
        virtual const char* eventName() const = 0;
        virtual CoreEventType eventType() const = 0;
        virtual int categoryFlags() const = 0;

        bool hasCategory(int category) {
            return categoryFlags() & category;
        }
    };

    class CoreEventListener {
    public:
        virtual bool onEvent(CoreEvent& event) { return false; }
    };

    #define CORE_EVENT_TYPE(type) \
        const char* eventName() const override { return #type; }; \
        CoreEventType eventType() const override { return CoreEventType::type; };

    #define CORE_EVENT_CATEGORY(category) \
        int categoryFlags() const override  { return category; }
}

#endif // __NexCore_Core_CoreEvent_H__
