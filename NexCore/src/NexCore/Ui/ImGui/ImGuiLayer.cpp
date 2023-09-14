#include <NexCore/Ui/ImGui/ImGuiLayer.h>

#include <GLFW/glfw3.h>

#include <imgui.h>
#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>

#include <NexCore/Core/Application.h>

namespace nex {
    void ImGuiLayer::init() {
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO();
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;
        io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;

        ImGui_ImplGlfw_InitForOpenGL(static_cast<GLFWwindow*>(Application::Get().window().getNativeWindow()), true); 
        ImGui_ImplOpenGL3_Init("#version 330");
    }

    void ImGuiLayer::shutdown() {
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplOpenGL3_Shutdown();
        ImGui::DestroyContext();
    }

    bool ImGuiLayer::onEvent(CoreEvent& event) {
        ImGuiIO& io = ImGui::GetIO();

        return event.hasCategory(EventCategoryKeyboard) & io.WantCaptureKeyboard ||
               event.hasCategory(EventCategoryMouse)    & io.WantCaptureMouse;
    }

    void ImGuiLayer::onFrameStarted() {
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
    }

    void ImGuiLayer::onFrameEnded() {
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    }
}