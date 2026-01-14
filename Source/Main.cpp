#include <juce_gui_basics/juce_gui_basics.h>
#include <juce_events/juce_events.h>
#include <juce_core/juce_core.h>
#include "MainComponent.h"

class MotifXSEditorApplication  : public juce::JUCEApplication
{
public:
    MotifXSEditorApplication() {}
    
    // ProjectInfo biasanya ada di JuceHeader, kita ganti string manual atau hapus referensi ProjectInfo
    // untuk menghindari error jika module generation belum sempurna.
    const juce::String getApplicationName() override       { return "MotifXSesp"; }
    const juce::String getApplicationVersion() override    { return "0.0.1"; }
    bool moreThanOneInstanceAllowed() override             { return true; }

    void initialise (const juce::String& commandLine) override
    {
        mainWindow.reset (new MainWindow (getApplicationName()));
    }

    void shutdown() override
    {
        mainWindow = nullptr;
    }

    void systemRequestedQuit() override
    {
        quit();
    }

    void anotherInstanceStarted (const juce::String& commandLine) override {}

    class MainWindow    : public juce::DocumentWindow
    {
    public:
        MainWindow (juce::String name)  : DocumentWindow (name,
                                                          juce::Desktop::getInstance().getDefaultLookAndFeel()
                                                                                      .findColour (juce::ResizableWindow::backgroundColourId),
                                                          DocumentWindow::allButtons)
        {
            setUsingNativeTitleBar (true);
            setContentOwned (new MainComponent(), true);
            setResizable (true, true);
            centreWithSize (getWidth(), getHeight());
            setVisible (true);
        }

        void closeButtonPressed() override
        {
            JUCEApplication::getInstance()->systemRequestedQuit();
        }

    private:
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainWindow)
    };

private:
    std::unique_ptr<MainWindow> mainWindow;
};

START_JUCE_APPLICATION (MotifXSEditorApplication)