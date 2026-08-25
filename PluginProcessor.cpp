#include "PluginProcessor.h"
#include "PluginEditor.h"

juce::AudioProcessorEditor* BrowserVSTAudioProcessor::createEditor()
{
    return new BrowserVSTAudioProcessorEditor (*this);
}

juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new BrowserVSTAudioProcessor();
}