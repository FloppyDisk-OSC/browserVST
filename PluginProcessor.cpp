#include "PluginProcessor.h"
#include "PluginEditor.h"

BrowserVSTAudioProcessor::BrowserVSTAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                       #if ! JucePlugin_IsMidiEffect
                        #if ! JucePlugin_IsSynth
                         .withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
                        #endif
                         .withOutput ("Output", juce::AudioChannelSet::stereo(), true)
                       #endif
                       )
#endif
{
}

BrowserVSTAudioProcessor::~BrowserVSTAudioProcessor() {}

const juce::String BrowserVSTAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool BrowserVSTAudioProcessor::acceptsMidi() const { return false; }
bool BrowserVSTAudioProcessor::producesMidi() const { return false; }
bool BrowserVSTAudioProcessor::isMidiEffect() const { return false; }
double BrowserVSTAudioProcessor::getTailLengthSeconds() const { return 0.0; }

int BrowserVSTAudioProcessor::getNumPrograms() { return 1; }
int BrowserVSTAudioProcessor::getCurrentProgram() { return 0; }
void BrowserVSTAudioProcessor::setCurrentProgram (int) {}
const juce::String BrowserVSTAudioProcessor::getProgramName (int) { return {}; }
void BrowserVSTAudioProcessor::changeProgramName (int, const juce::String&) {}

void BrowserVSTAudioProcessor::prepareToPlay (double, int) {}
void BrowserVSTAudioProcessor::releaseResources() {}

bool BrowserVSTAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;

    return true;
}

void BrowserVSTAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer&)
{
    juce::ScopedNoDenormals noDenormals;
    buffer.clear();
}

bool BrowserVSTAudioProcessor::hasEditor() const { return true; }

juce::AudioProcessorEditor* BrowserVSTAudioProcessor::createEditor()
{
    return new BrowserVSTAudioProcessorEditor (*this);
}

void BrowserVSTAudioProcessor::getStateInformation (juce::MemoryBlock&) {}
void BrowserVSTAudioProcessor::setStateInformation (const void*, int) {}

juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new BrowserVSTAudioProcessor();
}
