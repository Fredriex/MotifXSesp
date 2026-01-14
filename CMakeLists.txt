cmake_minimum_required(VERSION 3.15)
project(MotifXS_Editor VERSION 0.0.1)

# Ganti path ini ke lokasi JUCE Anda
add_subdirectory("C:/sdk/JUCE" build) 

# Membuat Aplikasi GUI (Standalone)
juce_add_gui_app(MotifXS_Editor
    COMPANY_NAME "SQHub"
    PRODUCT_NAME "MotifXSesp"
)

target_sources(MotifXS_Editor
    PRIVATE
        Source/Main.cpp
        Source/MainComponent.cpp
        Source/MainComponent.h
        Source/DataModel.h
        Source/AudioEngine.h
)

target_link_libraries(MotifXS_Editor
    PRIVATE
        juce::juce_core
        juce::juce_data_structures
        juce::juce_events
        juce::juce_graphics
        juce::juce_gui_basics
        juce::juce_gui_extra
        juce::juce_audio_basics
        juce::juce_audio_devices # Penting untuk MIDI & Audio
        juce::juce_audio_formats
        juce::juce_audio_processors
        juce::juce_audio_utils
)