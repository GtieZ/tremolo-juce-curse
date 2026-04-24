namespace tremolo {
PluginEditor::PluginEditor(PluginProcessor& p) : AudioProcessorEditor(&p), rateAttachment(p.getParameterRefs().rate, rateSlider) {

  background.setImage(juce::ImageCache::getFromMemory(assets::Background_png, assets::Background_pngSize));
  
  logo.setImage(juce::ImageCache::getFromMemory(assets::Logo_png, assets::Logo_pngSize));
  logo2.setImage(juce::ImageCache::getFromMemory(assets::Logo_png, assets::Logo_pngSize));
  logo3.setImage(juce::ImageCache::getFromMemory(assets::Logo_png, assets::Logo_pngSize));

  
  addAndMakeVisible(background);
  
  addAndMakeVisible(logo);
  addAndMakeVisible(logo2);
  addAndMakeVisible(logo3);

  rateSlider.setSliderStyle(juce::Slider::SliderStyle::Rotary);
  rateSlider.setTextBoxStyle(juce::Slider::NoTextBox, false, 0, 0);
  rateSlider.setPopupDisplayEnabled(true, true, this);
  rateSlider.setTextValueSuffix(" Hz");
  addAndMakeVisible(rateSlider);


  addAndMakeVisible(lfoVisualizer);

  visualizerThickSlider.setRange(1, 10, 1);
  visualizerThickSlider.setValue(4, juce::dontSendNotification);
  visualizerThickSlider.onValueChange = [this] {
    lfoVisualizer.setStrokeWidth(visualizerThickSlider.getValue());
  };
  addAndMakeVisible(visualizerThickSlider);



  // Make sure that before the constructor has finished, you've set the
  // editor's size to whatever you need it to be.
  setSize(540, 270 + 30);

}

void PluginEditor::resized() {
  const auto bounds = getLocalBounds();

  auto backgrondBounds = bounds;
  backgrondBounds.removeFromBottom(30);
  background.setBounds(backgrondBounds);


  logo.setBounds({16, 16, 105, 24});
  logo2.setBounds({ (bounds.getWidth() - 105) / 2,   16 , 105, 24 });
  logo3.setBounds({ bounds.getWidth() - 105 - 16, 16, 105, 24 });

  auto rateSliderBounds = bounds;
  rateSliderBounds.removeFromLeft(230);
  rateSliderBounds.removeFromRight(230);
  rateSliderBounds.removeFromTop(40);
  rateSliderBounds.removeFromBottom(150 + 30);
  rateSlider.setBounds(rateSliderBounds);


  lfoVisualizer.setBounds({ 18, 149, 504, 92 });

  auto visualizerThickSliderBounds = bounds;
  visualizerThickSliderBounds.removeFromTop(270);
  visualizerThickSliderBounds.removeFromRight(visualizerThickSliderBounds.getWidth() / 2);
  visualizerThickSlider.setBounds(visualizerThickSliderBounds);



}
}  // namespace tremolo
