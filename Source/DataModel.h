#pragma once
// --- PERUBAHAN DI SINI: Panggil modul spesifik ---
#include <juce_core/juce_core.h>
#include <juce_data_structures/juce_data_structures.h>

namespace MotifData
{
    // Struktur untuk 1 Part (Layer)
    struct MotifPart
    {
        juce::String partName = "Init Part";
        
        // Parameter Suara (Bank Select & Program Change)
        int msb = 63; 
        int lsb = 0;
        int programNumber = 0; // 0-127 (di UI biasanya 1-128)
        
        // Parameter Mixing
        int volume = 100;      // CC 7
        int pan = 64;          // CC 10 (Center)
        int reverbSend = 40;   // CC 91
        int chorusSend = 0;    // CC 93
        
        // Parameter Note Limit (Untuk Split)
        int noteLimitLow = 0;  // C-2
        int noteLimitHigh = 127; // G8
        
        // Kategori untuk Preview (Piano/Bass/Strings)
        juce::String category = "Piano"; 
    };

    // Struktur Performance (Gabungan 4 Part)
    struct MotifPerformance
    {
        juce::String performanceName = "Init Performance";
        MotifPart parts[4]; // Motif XS punya 4 Part di Performance Mode
    };
}