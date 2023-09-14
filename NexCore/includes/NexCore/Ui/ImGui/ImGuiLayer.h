#ifndef __NexCore_Ui_ImGui_ImGuiLayer_H__
#define __NexCore_Ui_ImGui_ImGuiLayer_H__

#include <NexCore/Core/CoreEvent.h>
#include <NexCore/Core/FrameListener.h>

namespace nex {
    class ImGuiLayer: public CoreEventListener, public FrameListener {
    public:
        void init();
        void shutdown();

        bool onEvent(CoreEvent& event) override;

        void onFrameStarted() override;
        void onFrameEnded() override;
    };
}

#endif // __NexCore_ImGui_ImGuiLayer_H__