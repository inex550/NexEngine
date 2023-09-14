#include <NexCore/Input/InputManager.h>

namespace nex {
    template<>
    InputManager* Singleton<InputManager>::s_instance = nullptr;

    InputState InputManager::getKeyInputState(KeyCodes key) const {
        if (key <= KeyCodes::Unknown || key > KeyCodes::Last) {
            NEX_ASSERT(false, "failed getKeyInputState: unknown key!");
            return InputState::Released;
        }
        return m_keys[static_cast<size_t>(key)];
    }

    InputState InputManager::getMouseButtonInputState(MouseButtonCodes mouseButton) const {
        if (mouseButton <= MouseButtonCodes::Unknown || mouseButton > MouseButtonCodes::ButtonLast) {
            NEX_ASSERT(false, "failed getMouseButtonInputState: unknown mouse button!");
            return InputState::Released;
        }
        return m_mouseButtons[static_cast<size_t>(mouseButton)];
    }

    bool InputManager::onEvent(CoreEvent& event) {
        switch (event.eventType()) {
        case CoreEventType::KeyPressed:
            processKeyPressedEvent(static_cast<KeyPressedEvent&>(event));
            return true;
        
        case CoreEventType::KeyReleased:
            processKeyReleasedEvent(static_cast<KeyReleasedEvent&>(event));
            return true;
        
        case CoreEventType::MouseButtonPressed:
            processMouseButtonPressedEvent(static_cast<MouseButtonPressedEvent&>(event));
            return true;
        
        case CoreEventType::MouseButtonReleased:
            processMouseButtonPressedEvent(static_cast<MouseButtonPressedEvent&>(event));
            return true;
        
        case CoreEventType::MouseMoved:
            processMouseMovedEvent(static_cast<MouseMovedEvent&>(event));
            return true;
        
        case CoreEventType::MouseScrolled:
            processMouseScrolledEvent(static_cast<MouseScrolledEvent&>(event));
            return true;
        }

        return false;
    }
    
    void InputManager::processKeyPressedEvent(KeyPressedEvent& event) {
        m_keys[event.keyCode()] = InputState::Pressed;
    }

    void InputManager::processKeyReleasedEvent(KeyReleasedEvent& event) {
        m_keys[event.keyCode()] = InputState::Released;
    }

    void InputManager::processMouseButtonPressedEvent(MouseButtonPressedEvent& event) {
        m_mouseButtons[event.mouseButton()] = InputState::Pressed;
    }

    void InputManager::processMouseButtonReleasedEvent(MouseButtonReleasedEvent& event) {
        m_mouseButtons[event.mouseButton()] = InputState::Released;
    }

    void InputManager::processMouseMovedEvent(MouseMovedEvent& event) {
        m_cursorPos.x = event.x();
        m_cursorPos.y = event.y();
    }

    void InputManager::processMouseScrolledEvent(MouseScrolledEvent& event) {
        m_scrollOffset.x = event.xOffset();
        m_scrollOffset.y = event.yOffset();
    }
}