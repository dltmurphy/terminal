#pragma once
#include "SettingsHost.g.h"
#include "../../cascadia/inc/cppwinrt_utils.h"
#include <winrt/Windows.Media.h>

namespace winrt::TerminalApp::implementation
{
    struct SettingsHost : SettingsHostT<SettingsHost>
    {
        SettingsHost();

        Windows::UI::Xaml::UIElement GetRoot();
        void Close();
        hstring GetTitle();
        Windows::Foundation::Size MinimumSize() const;

        bool IsFocused();
        void Focus();

        DECLARE_EVENT_WITH_TYPED_EVENT_HANDLER(CloseRequested, _closeRequestedHandlers, TerminalApp::IControlHost, TerminalApp::ClosedEventArgs);
        DECLARE_EVENT_WITH_TYPED_EVENT_HANDLER(TitleChanged, _titleChangedHandlers, TerminalApp::IControlHost, Microsoft::Terminal::TerminalControl::TitleChangedEventArgs);

        // private:
        // Windows::UI::Xaml::Controls::WebView _webView{ nullptr };
    };
}
namespace winrt::TerminalApp::factory_implementation
{
    struct SettingsHost : SettingsHostT<SettingsHost, implementation::SettingsHost>
    {
    };
}
