#pragma once

#include "LunaAPI/Core/Defines.h"
#include "LunaAPI/Core/Window.h" 
#include "LunaAPI/Core/WindowInterface.h" 
#include "LunaAPI/EventHandler/MainEventBaseClass.h"
#include "LunaAPI/UI/UI.h"
#include "LunaAPI/Core/DeltaTime.h"
#include "LunaAPI/Renderer/Framebuffer.h"

//MOUSE
#include "LunaAPI/EventHandler/MouseEvents/MouseButtonBaseEvent.h"
#include "LunaAPI/EventHandler/MouseEvents/MouseButtonPressed.h"
#include "LunaAPI/EventHandler/MouseEvents/MouseButtonReleased.h"
#include "LunaAPI/EventHandler/MouseEvents/MouseMove.h"
#include "LunaAPI/EventHandler/MouseEvents/MouseWheelScroll.h"

//WINDOW
#include "LunaAPI/EventHandler/WindowEvents/WindowClose.h"
#include "LunaAPI/EventHandler/WindowEvents/WindowResize.h"
#include "LunaAPI/EventHandler/EventDispatcher/EventDispatcher.h"

#include "GLFW/glfw3.h"


namespace LFW {

	class Application
	{
	public:
		Application(const std::string name);
		~Application() = default;

		//------------
		//API for the main.cpp (app dev) -> All user interaction happens from here!
		//------------

		void ShowImGuiDemoWindow();
		float GetElapsedRuntime();
		bool IsRunning();
		void Clear(float r, float g, float b, float transparent);
		void Clear(glm::vec4& temp); 

		void Render(Sprite sprite);
		void Display();
		void DrawUI();


		//Sets visiblity of mouse cursor
		void SetMouseCursorVisibility(bool visible);

		//Sets the title of the LFW application
		void SetTitle(std::string title);

		//Sets the icon of the LFW application
		void SetIcon(std::string path);

		//Add deltatime later
		void CheckInputForCamera();

		void SetCameraToFollowTransform(glm::vec3 transform);


		static void BuildUI(); //Outside of class in its own namespace?


	// - DISCLAIMER! -
	//Used internally, use on own risk. Change to private later.
	public:
		inline static Application& Get() { return *s_Instance; }
		WindowInterface& GetWindow() const { return *m_Window; }
		void OnGUIClose();

	private:
		void OnEvent(Event& event);
		bool OnWindowCloseEvent(WindowCloseEvent& e);
		bool OnWindowResizeEvent(WindowResizeEvent& e);

		void UpdateGUI();
		void EndRendering();
		void UpdateWindow();

	private:
		static Application* s_Instance;
		bool m_IsRunning = true;
		std::unique_ptr<WindowInterface> m_Window;
		std::unique_ptr<UI> m_UI;
	};
}