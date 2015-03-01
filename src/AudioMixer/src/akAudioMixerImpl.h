
#pragma once

#include <AudioMixer/akAudioMixer.h>
#include <AudioMixer/akMixControl.h>
#include "akAudioSourceMixer.h"
#include "akDataTable.h"
#include <vector>
#include <tuple>

namespace akAudioMixer
{
    class AudioSource;
}

class AudioMixerImpl: public akAudioMixer::AudioMixer
{
public:
    AudioMixerImpl();

    bool Initialize(const akAudioMixer::AudioMixerConfig& cfg);

    MixHandle AddSource(const akAudioMixer::AudioSource& source);
    akAudioMixer::MixControl* GetMixControl(MixHandle handle);

    akAudioMixer::AudioBuffer Update(const uint32_t deltaNumSamples);
    akAudioMixer::AudioBuffer GetOutputBuffer();

private:
    uint32_t CalcSamplesToMix(uint64_t mixerTime, uint64_t userTime,
                              uint32_t deltaTime, uint32_t mixAheadAmount);
    static bool IsValidConfig(const akAudioMixer::AudioMixerConfig& cfg);

private:
    akAudioMixer::AudioMixerConfig m_cfg;

    std::vector<int16_t> m_mixBuffer;

    uint64_t m_mixerTime;
    uint64_t m_userTime;
    uint32_t m_numMixAheadSamples;
    uint32_t m_mixHandleIndexCounter;

    AudioSourceMixer m_sourceMixer;

    using SourceMixPair = std::pair<akAudioMixer::AudioSource, akAudioMixer::MixControl>;
    DataTable<SourceMixPair> m_sources;
};
