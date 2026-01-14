#include "MainComponent.h"

MainComponent::MainComponent()
{
    setSize (800, 600);
}

MainComponent::~MainComponent()
{
}

void MainComponent::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colours::black); // Layar Hitam
    
    g.setFont (20.0f);
    g.setColour (juce::Colours::white);
    g.drawText ("Motif XS Editor - Ready to Code!", getLocalBounds(), juce::Justification::centred, true);
}

void MainComponent::resized()
{
}