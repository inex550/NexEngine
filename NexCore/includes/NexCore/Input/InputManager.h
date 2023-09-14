#ifndef __NexCore_Input_InputManager_H__
#define __NexCore_Input_InputManager_H__

#include <NexMath/Vec2.h>

#include <NexCore/Core/CoreEvent.h>
#include <NexCore/Core/Singleton.h>
#include <NexCore/Input/InputCodes.h>
#include <NexCore/Input/InputEventTypes.h>

namespace nex {
    class InputManager: public Singleton<InputManager>, public CoreEventListener {
    public:
        InputManager(): Singleton<InputManager>() {}

        bool onEvent(CoreEvent& event) override;

        InputState getKeyInputState(KeyCodes key) const;
        InputState getMouseButtonInputState(MouseButtonCodes mouseButton) const;

        Vec2f cursorPos() const { return m_cursorPos; }
        Vec2f scrollOffset() const { return m_scrollOffset; }

        static InputManager& Get() { return Singleton<InputManager>::Get(); }
        static InputManager* GetPtr() { return Singleton<InputManager>::GetPtr(); }

    private:
        void processKeyPressedEvent(KeyPressedEvent& event);
        void processKeyReleasedEvent(KeyReleasedEvent& event);
        void processMouseButtonPressedEvent(MouseButtonPressedEvent& event);
        void processMouseButtonReleasedEvent(MouseButtonReleasedEvent& event);
        void processMouseMovedEvent(MouseMovedEvent& event);
        void processMouseScrolledEvent(MouseScrolledEvent& event);

    private:
        InputState m_keys[static_cast<size_t>(KeyCodes::Last) + 1];
        InputState m_mouseButtons[static_cast<size_t>(MouseButtonCodes::ButtonLast) + 1];

        Vec2f m_cursorPos;
        Vec2f m_scrollOffset;
    };
}

#endif // __NexCore_Input_InputManager_H__
