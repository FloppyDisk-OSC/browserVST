cmake_minimum_required(VERSION 3.22)
project(BrowserVST VERSION 1.0.0)

add_subdirectory(JUCE ${CMAKE_CURRENT_BINARY_DIR}/JUCE)

juce_add_plugin(BrowserVST
    IS_SYNTH FALSE
    NEEDS_MIDI_INPUT FALSE
    NEEDS_MIDI_OUTPUT FALSE
    IS_MIDI_EFFECT FALSE
    EDITOR_WANTS_KEYBOARD_FOCUS TRUE
    COPY_PLUGIN_AFTER_BUILD TRUE
    PLUGIN_MANUFACTURER_CODE DevX
    PLUGIN_CODE Bvst
    FORMATS VST3 AU
    PRODUCT_NAME "Browser VST"
)

juce_generate_juce_header(BrowserVST)

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
