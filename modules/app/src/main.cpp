#include "app_design.h"
#include "imgui.h"

class MyApp:public App{
    public:
        MyApp() = default;
        ~MyApp() = default;

        virtual void StartUp() final{
            if(!image_loaded){
                bool ret = LoadTextureFromFile("MyImage01.jpg", &my_image_texture, &my_image_width, &my_image_height);
                IM_ASSERT(ret);
                image_loaded = true;
            }
        }

        virtual void Update() final{
            if (show_demo_window)
                ImGui::ShowDemoWindow(&show_demo_window);

            // 2. Show a simple window that we create ourselves. We use a Begin/End pair to create a named window.
            {
                static float f = 0.0f;
                static int counter = 0;

                ImGui::Begin("Almondeo Media Player");                          // Create a window called "Hello, world!" and append into it.
                if(show_menu)
                    ShowAppMainMenuBar();

                ImGui::Text("This is some useful text.");               // Display some text (you can use a format strings too)
                ImGui::Checkbox("Demo Window", &show_demo_window);      // Edit bools storing our window open/close state
                //ImGui::Checkbox("Another Window", &show_another_window);

                ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f
                ImGui::ColorEdit3("clear color", (float*)&clear_color); // Edit 3 floats representing a color

                if (ImGui::Button("Button"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
                    counter++;
                ImGui::SameLine();
                ImGui::Text("counter = %d", counter);
                ImGuiIO& io = ImGui::GetIO();
                ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / io.Framerate, io.Framerate);
                ImGui::End();

                if(image_loaded){
                    ImGui::Begin("OpenGL Texture Text");
                    ImGui::Text("pointer = %p", my_image_texture);
                    ImGui::Text("size = %d x %d", my_image_width, my_image_height);
                    ImGui::Image((void*)(intptr_t)my_image_texture, ImVec2(my_image_width, my_image_height));
                    ImGui::End();
                }

            }
        }
        static void ShowAppMainMenuBar(){
            if(ImGui::BeginMenuBar()){
                if(ImGui::BeginMenu("File")){
                    ShowAppMenuFile();
                    ImGui::EndMenu();
                }
                ImGui::EndMainMenuBar();
            }
        }
        static void ShowAppMenuFile(){
            //IMGUI_DEMO_MARKER("ExamplesMenu");
            if(ImGui::MenuItem("New")){}
            if(ImGui::MenuItem("Open", "Ctrl+O")){}
            if(ImGui::BeginMenu("Open Recent")){
                ImGui::MenuItem("fish_hat.c");
                ImGui::EndMenu();
            }
            if(ImGui::MenuItem("Save", "Ctrl+S")){}
            if(ImGui::MenuItem("Save As..")){}
        }

    private:
        bool show_demo_window = true;
        bool show_menu = true;
        int my_image_width = 0;
        int my_image_height = 0;
        GLuint my_image_texture = 0;
        bool image_loaded = false;
};

int main(int, char**){
    MyApp app;
    app.Run();

    return 0;
}
