/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
GainAudioProcessorEditor::GainAudioProcessorEditor (GainAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{

    GainSlider.setTextValueSuffix("dB");
    GainSlider.setSliderStyle(juce::Slider::SliderStyle::LinearBar);
    addAndMakeVisible(GainSlider);
    AttachmentGainSlider = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.Parameters, "GAIN", GainSlider);


    setSize (400, 100);
}

GainAudioProcessorEditor::~GainAudioProcessorEditor()
{
}

//==============================================================================
void GainAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    //g.setColour (juce::Colours::white);
    //g.setFont (15.0f);
    //g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
}

void GainAudioProcessorEditor::resized()
{
    //GainSlider.setBounds(10, 1, 500, 100);
    GainSlider.setBounds(getLocalBounds());
    
}
