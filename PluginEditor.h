#pragma once
#include "PluginProcessor.h"

class BrowserVSTAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    BrowserVSTAudioProcessorEditor (BrowserVSTAudioProcessor&);
    ~BrowserVSTAudioProcessorEditor() override;

    void resized() override;

private:
    juce::WebBrowserComponent webView;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (BrowserVSTAudioProcessorEditor)
};