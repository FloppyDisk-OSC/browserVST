cmake_minimum_required(VERSION 3.22)
project(BrowserVST VERSION 1.0.0)

# Point CMake to JUCE directory
add_subdirectory(JUCE ${CMAKE_CURRENT_BINARY_DIR}/JUCE)

juce_add_plugin(BrowserVST
    IS_SYNTH FALSE
    NEEDS_MIDI_INPUT FALSE
    NEEDS_MIDI_OUTPUT FALSE
    IS_MIDI_EFFECT FALSE
    EDITOR_WANTS_KEYBOARD_FOCUS TRUE
    COPY_PLUGIN_AFTER_BUILD FALSE
    PLUGIN_MANUFACTURER_CODE DevX
    PLUGIN_CODE Bvst
    FORMATS VST3
    PRODUCT_NAME "Browser VST"
)

# Fix VST3/VST2 automation replacement error
target_compile_definitions(BrowserVST
    PRIVATE
        JUCE_VST3_CAN_REPLACE_VST2=0
)

target_sources(BrowserVST
    PRIVATE
        PluginProcessor.h
        PluginProcessor.cpp
        PluginEditor.h
        PluginEditor.cpp
)

target_link_libraries(BrowserVST
    PRIVATE
        juce::juce_audio_utils
        juce::juce_gui_extra
    PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_lto_flags
        juce::juce_recommended_warning_flags
)
