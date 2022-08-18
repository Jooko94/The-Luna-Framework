#pragma once


//Moved from the cpp file
#include "LfwAPI/Core/Window.h"
#include "LfwAPI/Core/WindowInterface.h"
#include "LfwAPI/EventHandler/MainEventBaseClass.h"
#include "LfwAPI/EventHandler/KeyEvents/KeyButtonBaseEvent.h"
#include "LfwAPI/EventHandler/KeyEvents/KeyPressed.h"
#include "LfwAPI/EventHandler/KeyEvents/KeyReleased.h"
#include "LfwAPI/EventHandler/KeyEvents/KeyTyped.h"


#include "GLFW/glfw3.h"

namespace LFW {

	class WindowLogic : public WindowInterface
	{
	public:
		WindowLogic(const Window& details);
		virtual ~WindowLogic();

		void SetWindowData(const Window& data);
		void OnUpdate() override;

		uint32_t GetWidth() override { return m_Data.Width; }
		uint32_t GetHeight() override { return m_Data.Height; }

		void SetEventCallback(const EventCallBackFn& callback) override { m_Data.EventCallback = callback; }

		//Setup for callback
		void SetCallbackResize();
		void SetCallbackClose();
		void SetCallbackKeyboard();
		void SetCallbackChars();
		void SetCallbackMouseBtn();
		void SetCallbackMouseScroll();
		void SetCallbackCursorPos();

		void SetVSync(bool enabled) override;
		bool VSyncActive() const override;
		virtual void* GetOriginalWindow() const { return m_Window; }

	private:
		virtual void Init(const Window& data);
		virtual void Shutdown();

	private:
		GLFWwindow* m_Window;

	private:
		struct WindowData
		{
			std::string Title;
			uint32_t Width;
			uint32_t Height;
			bool VSync;

			EventCallBackFn EventCallback;
		};

		WindowData m_Data;
	};
}