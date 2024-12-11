/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
NewProjectAudioProcessorEditor::NewProjectAudioProcessorEditor (NewProjectAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    float minValue = 0.0f;
    float maxValue = 127.0f;
    float intervalue = 1.0f;
    //Plug in size.
    setSize (200, 200);

    //Midi Slider parameters.
    midiVolume.addListener(this);
    midiVolume.setSliderStyle(juce::Slider::LinearBarVertical);
    midiVolume.setRange(minValue, maxValue, intervalue);
    midiVolume.setTextBoxStyle(juce::Slider::NoTextBox, false, 90, 0);
    midiVolume.setPopupDisplayEnabled(true, true, this, 1000);
    midiVolume.setTextValueSuffix(" Volume");
    midiVolume.setValue(intervalue);

    //Add and make real
    addAndMakeVisible(&midiVolume);
}

NewProjectAudioProcessorEditor::~NewProjectAudioProcessorEditor()
{
}

//==============================================================================
void NewProjectAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (juce::Colours::whitesmoke);

    g.setColour (juce::Colours::white);
    g.setFont (juce::FontOptions (15.0f));
    g.drawFittedText ("Midi Volume", 0,0, getWidth(), 30, juce::Justification::centred, 1);
}

void NewProjectAudioProcessorEditor::resized()
{
    //set the bounds of object here.
    midiVolume.setBounds(40, 30, 20, getHeight() - 60);
}

void NewProjectAudioProcessorEditor::sliderValueChanged(juce::Slider* slider)
{
    audioProcessor.noteOnVal = midiVolume.getValue();
}

