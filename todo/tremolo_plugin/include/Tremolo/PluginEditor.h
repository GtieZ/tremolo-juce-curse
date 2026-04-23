#pragma once

namespace tremolo {
class PluginEditor : public juce::AudioProcessorEditor {
public:
  explicit PluginEditor(PluginProcessor&);

  void resized() override;

private:

  class RateSliderListener : public juce::Slider::Listener {
  public:
    RateSliderListener(juce::AudioParameterFloat& p, juce::Slider& s) : parameter{p}, slider{s} {
      s.addListener(this);
    }

    ~RateSliderListener() override {
      slider.removeListener(this);
    }

    void sliderValueChanged(juce::Slider* s) override {
      parameter = static_cast<float>(s->getValue());
    }

  private:
    juce::AudioParameterFloat& parameter;
    juce::Slider& slider;
  };


  juce::ImageComponent background;
  juce::ImageComponent logo;

  juce::ImageComponent logo2;
  juce::ImageComponent logo3;

  juce::Slider rateSlider;
  juce::SliderParameterAttachment rateAttachment;

  LfoVisualizer lfoVisualizer;

  juce::Slider visualizerThickSlider;

  
  JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PluginEditor)
};
}  // namespace tremolo
