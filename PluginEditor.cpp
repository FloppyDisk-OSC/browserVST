#include "PluginProcessor.h"
#include "PluginEditor.h"

BrowserVSTAudioProcessorEditor::BrowserVSTAudioProcessorEditor (BrowserVSTAudioProcessor& p)
    : AudioProcessorEditor (&p)
{
    webView.goToURL("https://penguinmod.com");
    
    addAndMakeVisible(webView);
    setSize (800, 600);
}

BrowserVSTAudioProcessorEditor::~BrowserVSTAudioProcessorEditor() {}

void BrowserVSTAudioProcessorEditor::resized()
{
    webView.setBounds(getLocalBounds());
}