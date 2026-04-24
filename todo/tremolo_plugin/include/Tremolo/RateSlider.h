#pragma once

namespace tremolo {
class RateSlider : public juce::Slider {
public:
    void paint(juce::Graphics& g) override {
        auto sliderPos =(float) valueToProportionOfLength(getValue());
        jassert(sliderPos >= 0 && sliderPos <= 1.0f);

        const auto rotaryParams = getRotaryParameters();
        const auto rotaryStartAngle = rotaryParams.startAngleRadians;
        const auto rotaryEndAngle = rotaryParams.endAngleRadians;

        auto fill    = juce::Colours::orange;
        auto toAngle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);
      
        if(isEnabled()) {
            juce::Path valueArc;
            valueArc.addPieSegment(getLocalBounds().toFloat(), rotaryStartAngle, toAngle, 0.f);
            g.setColour(fill);
            g.fillPath(valueArc);
        }
    } // paint

}; // class RateSlider
} // namespace tremolo