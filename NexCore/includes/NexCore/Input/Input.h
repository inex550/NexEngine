#ifndef __NexCore_Input_Input_H__
#define __NexCore_Input_Input_H__

#include <NexCore/Input/InputManager.h>

namespace nex {
    class Input {
    public:
        static bool isKeyPressed(KeyCodes key) {
            return InputManager::Get().getKeyInputState(key) == InputState::Pressed;
        }

        static bool isKeyReleased(KeyCodes key) {
            return InputManager::Get().getKeyInputState(key) == InputState::Released;
        }

        static bool isMouseButtonPressed(MouseButtonCodes mouseButton) {
            return InputManager::Get().getMouseButtonInputState(mouseButton) == InputState::Pressed;
        }

        static bool isMouseButtonReleased(MouseButtonCodes mouseButton) {
            return InputManager::Get().getMouseButtonInputState(mouseButton) == InputState::Released;
        }

        static Vec2f mouseScreenPosition() {
            return InputManager::Get().cursorPos();
        }

        static Vec2f mouseScrollOffset() {
            return InputManager::Get().scrollOffset();
        }
    };
}

#endif // __NexCore_Input_Input_H__