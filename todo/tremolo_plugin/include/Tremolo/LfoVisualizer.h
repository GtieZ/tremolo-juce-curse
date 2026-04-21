namespace tremolo {
class LfoVisualizer : public juce::Component {
public:
    enum class LfoWaveform : size_t {
        sine = 0,
        triangle = 1
    };

    void resized() override {
        const auto scale = 0.1f;
        const int waveEdge = 5;
        const int waveStartPoint = waveEdge * -1;
        const auto halfHeight = getHeight() / 2;
        const auto amplitude = halfHeight - strokeWidth / 2;

        // !--we are calculation the starting point using sine function... probably we should add logic later according to waveForm
        wave.startNewSubPath(waveStartPoint - waveEdge, amplitude * std::sin(waveStartPoint * scale) + halfHeight);

        for(const auto x : std::views::iota(waveStartPoint + 1, getWidth() + waveEdge)) {
            float ft, y;

            if(waveForm == LfoWaveform::sine) {
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
        g.strokePath(wave, juce::PathStrokeType{strokeWidth});
    }


    void setStrokeWidth(float width) {
        strokeWidth = width;
        resized();
        repaint();
    }

    void setLfoWaveform(LfoWaveform waveType) {
        waveForm = waveType;
        resized();
        repaint();
    }


private:    
    float strokeWidth = 4.f;

    juce::Path wave;

    LfoWaveform waveForm = LfoWaveform::sine;

}; // LfoVisualizer class
} //namespace tremolo