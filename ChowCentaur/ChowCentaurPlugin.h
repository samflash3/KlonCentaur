#pragma once

#include "InputBufferProcessor.h"
#include "OutputStageProcessor.h"
#include "ToneFilterProcessor.h"
#include <JuceHeader.h>

#include "BypassProcessor.h"
#include "GainStageMLProc.h"
#include "GainStageProc.h"

class ChowCentaur : public chowdsp::PluginBase<ChowCentaur>
{
public:
    ChowCentaur();
    ~ChowCentaur();

    static void addParameters (Parameters& params);
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;
    void processAudioBlock (AudioBuffer<float>& buffer) override;

    AudioProcessorEditor* createEditor() override;
    void setStateInformation (const void* data, int sizeInBytes) override;

private:
    std::atomic<float>* trebleParam = nullptr;
    std::atomic<float>* levelParam = nullptr;
    std::atomic<float>* mlParam = nullptr;
    std::atomic<float>* bypassParam = nullptr;

    BypassProcessor bypass;
    InputBufferProcessor inProc[2];
    ToneFilterProcessor tone[2];
    OutputStageProc outProc[2];

    GainStageProc gainStageProc;
    GainStageMLProc gainStageMLProc;

    AudioBuffer<float> fadeBuffer;
    bool useMLPrev = false;

    using StereoIIR = dsp::ProcessorDuplicator<dsp::IIR::Filter<float>, dsp::IIR::Coefficients<float>>;
    StereoIIR dcBlocker;

    chowdsp::ChowLNF myLNF;
    foleys::MagicPlotSource* scope = nullptr;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ChowCentaur)
};
