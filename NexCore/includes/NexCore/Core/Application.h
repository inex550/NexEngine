#ifndef __NexCore_Core_Application_H__
#define __NexCore_Core_Application_H__

#include <memory>
#include <vector>

#include <NexCore/Core/Core.h>
#include <NexCore/Core/Singleton.h>
#include <NexCore/Core/CoreEventTypes.h>
#include <NexCore/Core/FrameListener.h>
#include <NexCore/Core/Window.h>
#include <NexCore/Input/InputManager.h>

namespace nex {
    class Application : public Singleton<Application>, CoreEventListener {
    public:
        Application(const char* title, int width = 1280, int height = 720);
        virtual ~Application() = default;

        void start();

        void pushFrameListener(FrameListener* listener);
        void removeFrameListener(FrameListener* listener);

        void frameStarted();
        void framePrepare();
        void frameEnded();

        Window& window() { return *m_window; }

        static Application& Get() { return Singleton<Application>::Get(); }
        static Application* GetPtr() { return Singleton<Application>::GetPtr(); }

    protected:
        void pushCoreEventListener(CoreEventListener* listener);
        void overlayCoreEventListener(CoreEventListener* listener);
        void removeCoreEventListener(CoreEventListener* listener);
    
    private:
        bool onEvent(CoreEvent& event) override;

        void onWindowClose(WindowCloseEvent& closeEvent);

    private:
        std::unique_ptr<Window> m_window;

        // Singletons (Managers)
        std::unique_ptr<InputManager> m_inputManager;

        // Listeners
        std::vector<FrameListener*> m_frameListeners;
        std::vector<CoreEventListener*> m_eventListeners;

        bool m_isRunning = false;
    };
}

#endif // __NexCore_Core_Application_H__