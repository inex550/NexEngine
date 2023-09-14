#ifndef __NexCore_Input_InputEventTypes_H__
#define __NexCore_Input_InputEventTypes_H__

#include <NexCore/Core/CoreEvent.h>

namespace nex {
    class KeyEvent : public CoreEvent {
    public:
        KeyEvent(int keyCode): keyCode_(keyCode) {}

        int keyCode() const { return keyCode_; }

    protected:
        int keyCode_;
    };

    class KeyPressedEvent : public KeyEvent {
    public:
        CORE_EVENT_TYPE(KeyPressed)
        CORE_EVENT_CATEGORY(EventCategoryKeyboard)

        KeyPressedEvent(int keyCode, bool repeated)
            : KeyEvent(keyCode), repeated_(repeated) {}

    private:
        bool repeated_;
    };

    class KeyReleasedEvent : public KeyEvent {
    public:
        CORE_EVENT_TYPE(KeyReleased)
        CORE_EVENT_CATEGORY(EventCategoryKeyboard)

        KeyReleasedEvent(int keyCode): KeyEvent(keyCode) {}
    };

    class MouseButtonEvent : public CoreEvent {
    public:
        MouseButtonEvent(int mouseButton): mouseButton_(mouseButton) {}

        int mouseButton() const { return mouseButton_; }

    protected:
        int mouseButton_;
    };

    class MouseButtonPressedEvent : public MouseButtonEvent {
    public:
        CORE_EVENT_TYPE(MouseButtonPressed)
        CORE_EVENT_CATEGORY(EventCategoryMouse | EventCategoryMouseButton)

        MouseButtonPressedEvent(int mouseButton): MouseButtonEvent(mouseButton) {}
    };

    class MouseButtonReleasedEvent : public MouseButtonEvent {
    public:
        CORE_EVENT_TYPE(MouseButtonReleased)
        CORE_EVENT_CATEGORY(EventCategoryMouse | EventCategoryMouseButton)

        MouseButtonReleasedEvent(int mouseButton): MouseButtonEvent(mouseButton) {}
    };

    class MouseMovedEvent : public CoreEvent {
    public:
        CORE_EVENT_TYPE(MouseMoved)
        CORE_EVENT_CATEGORY(EventCategoryMouse)

        MouseMovedEvent(float x, float y)
            : x_(x), y_(y) {}

        float x() const { return x_; }
        float y() const { return y_; }

    private:
        float x_;
        float y_;
    };

    class MouseScrolledEvent : public CoreEvent {
    public:
        CORE_EVENT_TYPE(MouseScrolled)
        CORE_EVENT_CATEGORY(EventCategoryMouse)

        MouseScrolledEvent(float xOffset, float yOffset)
            : xOffset_(xOffset), yOffset_(yOffset) {}

        float xOffset() const { return xOffset_; }
        float yOffset() const { return yOffset_; }

    private:
        float xOffset_;
        float yOffset_;
    };
}

#endif // __NexCore_Input_InputEventTypes_H__