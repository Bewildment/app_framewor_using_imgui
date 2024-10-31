#pragma once
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "GL/gl.h"
#include "GL/glu.h"
#include "GLFW/glfw3.h"

class App{
    public:
        App();
        virtual ~App();
        void Run();
        virtual void Update() = 0;
        virtual void StartUp() = 0;
        static void ShowAppMainMenuBar();
        static void ShowAppMenuFile();
        bool LoadTextureFromFile(const char* filename, GLuint* out_texture, int* out_width, int* out_height);
        ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
        GLFWimage decodeOneStep(const char* filename);
        //ImGuiIO& io = ImGui::GetIO();
    private:
        GLFWwindow* window;

};
