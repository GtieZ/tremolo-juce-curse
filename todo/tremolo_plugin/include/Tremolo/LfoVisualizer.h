namespace tremolo {
class LfoVisualizer : public juce::Component {
public:
    void resized() override {
        const auto scale = 0.1f;
        const int waveEdge = 5;
        const int waveStartPoint = waveEdge * -1;
        const auto halfHeight = getHeight() / 2;
        const auto amplitude = halfHeight - strokeWidth / 2;

        wave.startNewSubPath(waveStartPoint - waveEdge, amplitude * std::sin(waveStartPoint * scale) + halfHeight);

        for(const auto x : std::views::iota(waveStartPoint + 1, getWidth() + waveEdge)) {
            float ft, y;

            if(true) {
                ft = x * scale;
                y = amplitude * std::sin(x * scale) + halfHeight;
            }
            else {
                ft = x / juce::MathConstants<float>::twoPi * scale;
                y = (4 * std::abs(ft - std::floor(ft + 0.5f)) - 1.f) * amplitude + halfHeight;
            }

            wave.lineTo(x, y);
        }
    }

    //TODO: Implement Triangle waveshape:use a new function LfoVisualizer::setLfoWaveform(LfoWaveform) similar to Tremolo::setLfoWaveform(LfoWaveform) 


    void paint(juce::Graphics& g) override {
        g.setColour(juce::Colours::orange);
        //g.strokePath(sine, juce::PathStrokeType{strokeWidth});

        g.strokePath(wave, juce::PathStrokeType{strokeWidth});


    }


    void setStrokeWidth(float width) {
        strokeWidth = width;
        resized();
        repaint();
    }


private:    
    float strokeWidth = 4.f;

    juce::Path wave;



}; // LfoVisualizer class
} //namespace tremolo