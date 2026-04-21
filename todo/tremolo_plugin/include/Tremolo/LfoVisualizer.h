namespace tremolo {
class LfoVisualizer : public juce::Component {
public:
    void resized() override {
        const int sineEdge = 5;
        const int sineStartPoint = sineEdge * -1;
        const auto halfHeight = getHeight() / 2;
        const auto amplitude = halfHeight - strokeWidth / 2;

        sine.startNewSubPath(sineStartPoint - sineEdge, amplitude * std::sin(sineStartPoint * 0.1f) + halfHeight);

        for(const auto x : std::views::iota(sineStartPoint + 1, getWidth() + sineEdge)) {
            sine.lineTo(x, amplitude * std::sin(0.1f * x) + halfHeight);
        }
    }

    //TODO: Implement Triangle waveshape:use a new function LfoVisualizer::setLfoWaveform(LfoWaveform) similar to Tremolo::setLfoWaveform(LfoWaveform) 


    void paint(juce::Graphics& g) override {
        g.setColour(juce::Colours::orange);
        g.strokePath(sine, juce::PathStrokeType{strokeWidth});
    }


    void setStrokeWidth(float width) {
        strokeWidth = width;
        resized();
        repaint();
    }


private:    
    float strokeWidth = 4.f;

    juce::Path sine;


}; // LfoVisualizer class
} //namespace tremolo