
namespace tremolo {
namespace {
auto& addParameterToProcessor(juce::AudioProcessor& processor, auto parameter) {
  auto& parameterReference = *parameter;
  processor.addParameter(parameter.release());

  return parameterReference;
}

juce::AudioParameterFloat& createMasterVolumeParameter(
    juce::AudioProcessor& processor) {
  constexpr auto versionHint = 1;

  auto parameter = std::make_unique<juce::AudioParameterFloat>(
      juce::ParameterID{"output.gain", versionHint}, "Master Volume",
      juce::NormalisableRange{-12.f, 12.f, 0.1f, 1.f}, 0.f,
      juce::AudioParameterFloatAttributes{}.withLabel("dB")

  );

  return addParameterToProcessor(processor, std::move(parameter));
}

juce::AudioParameterFloat& createModulationRateParameter(
    juce::AudioProcessor& processor) {
  constexpr auto versionHint = 1;

  auto parameter = std::make_unique<juce::AudioParameterFloat>(
      juce::ParameterID{"modulation.rate", versionHint}, "Modulation rate",
      juce::NormalisableRange{0.1f, 20.f, 0.01f, 0.4f}, 5.f,
      juce::AudioParameterFloatAttributes{}.withLabel("Hz"));

  return addParameterToProcessor(processor, std::move(parameter));
}

juce::AudioParameterBool& createBypassedParameter(
    juce::AudioProcessor& processor) {
  constexpr auto versionHint = 1;

  auto parameter = std::make_unique<juce::AudioParameterBool>(
      juce::ParameterID{"bypassed", versionHint}, "Bypass", false);

  return addParameterToProcessor(processor, std::move(parameter));
}
}  // namespace

Parameters::Parameters(juce::AudioProcessor& processor)
    // TODO: create parameters
    // TODO: retrieve references to parameters
    // TODO: add parameters to the processor
    : rate{createModulationRateParameter(processor)},
      bypassed{createBypassedParameter(processor)},
      masterVolume{createMasterVolumeParameter(processor)} {}
}  // namespace tremolo
