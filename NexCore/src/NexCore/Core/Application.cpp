#include <NexCore/Core/Application.h>

#include <algorithm>

namespace nex {
    template<>
    Application* Singleton<Application>::s_instance = nullptr;

    Application::Application(const char* title, int width, int height)
        : Singleton<Application>()
    {
        m_window = std::unique_ptr<Window>(Window::Create({ title, width, height }));
        m_window->setEventListener(this);

        m_inputManager = std::unique_ptr<InputManager>(new InputManager);
        m_eventListeners.push_back(m_inputManager.get());
    }

    void Application::start() {
        m_isRunning = true;

        while (m_isRunning) {
            frameStarted();
            framePrepare();
            
            m_window->onUpdate();

            frameEnded();
        }
    }

    void Application::frameStarted() {
        for (FrameListener* listener : m_frameListeners) {
            listener->onFrameStarted();
        }
    }

    void Application::framePrepare() {
        for (FrameListener* listener : m_frameListeners) {
            listener->onFramePrepare();
        }
    }

    void Application::frameEnded() {
        for (FrameListener* listener : m_frameListeners) {
            listener->onFrameEnded();
        }
    }
    
    bool Application::onEvent(CoreEvent& event) {
        if (event.eventType() == CoreEventType::WindowClose) {
            onWindowClose(static_cast<WindowCloseEvent&>(event));
        }

        for (CoreEventListener* listener : m_eventListeners) {
            if (listener->onEvent(event)) {
                return true;
            }
        }

        return false;
    }
    
    void Application::pushFrameListener(FrameListener* listener) {
        m_frameListeners.push_back(listener);
    }

    void Application::removeFrameListener(FrameListener* listener) {
        auto iter = std::find(m_frameListeners.begin(), m_frameListeners.end(), listener);
        if (iter != m_frameListeners.end()) {
            m_frameListeners.erase(iter);
        }
    }
    
    void Application::pushCoreEventListener(CoreEventListener* listener) {
        m_eventListeners.push_back(listener);
    }

    void Application::overlayCoreEventListener(CoreEventListener* listener) {
        m_eventListeners.insert(m_eventListeners.begin(), listener);
    }

    void Application::removeCoreEventListener(CoreEventListener* listener) {
        auto iter = std::find(m_eventListeners.begin(), m_eventListeners.end(), listener);
        if (iter != m_eventListeners.end()) {
            m_eventListeners.erase(iter);
        }
    }

    void Application::onWindowClose(WindowCloseEvent& closeEvent) {
        m_isRunning = false;
    }
}