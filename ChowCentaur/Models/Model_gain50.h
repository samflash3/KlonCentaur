#ifndef MODELGAIN50_H_INCLUDED
#define MODELGAIN50_H_INCLUDED

#include "GainStageML.h"

GainStageModel<8, float> ModelGain50 = {
    {{ // GRUKernelWeights
        -0.527477f,   -0.4532593f,   1.6960614f,  -0.34556326f,  0.4297649f,  -1.4093574f,
        -1.1323147f,  -1.622446f,   -0.22179674f,  0.6159499f,  -0.3769271f,   0.13822769f,
         0.17010325f,  1.4252387f,  -0.02522892f, -0.03733066f, -0.4337218f,  -0.34290183f,
        -0.8891562f,   0.53998697f, -0.45091423f,  0.17824934f, -0.11493694f,  0.05646428f,
    }},

    {{ // GRURecurrentWeights
        -1.6323532f,   0.8832335f,   0.82500166f, -1.583886f,    0.7579658f,  -1.4049315f,
         0.42582518f, -0.36533168f, -0.11343176f, -0.64920133f, -0.00634785f, -0.03717555f,
        -0.39614415f, -0.01582852f, -0.2923631f,  -0.62748337f,  0.75232947f, -0.4019652f,
        -0.29438385f, -0.41237828f, -0.0167868f,   0.00995096f, -0.20443867f, -0.24044925f, },
       {-0.8484256f,   0.02383177f,  0.30936688f,  0.52651054f, -1.0704974f,  -0.3370439f,
         0.94061446f,  2.241617f,    0.03832133f, -0.21539631f,  0.01225581f,  0.28095603f,
        -0.7911859f,   0.04836631f, -0.5801711f,  -0.07856782f,  0.59898895f,  0.7014969f,
         0.13739498f, -0.30389938f,  0.14431886f,  0.44414598f,  0.84643954f,  0.26713094f, },
       {-0.21057957f, -0.48711145f,  1.4242747f,  -0.5730254f,  -0.40838575f, -0.9116315f,
         0.6886472f,   0.48791632f,  0.5318742f,  -0.7452276f,  -0.01992542f, -0.41199723f,
        -0.5716194f,  -0.9167191f,  -0.7804004f,  -0.6746099f,  -0.11927565f,  0.6815174f,
         0.4566301f,   0.20936231f,  0.57089835f, -0.8658827f,   0.7572276f,   0.23725294f, },
       {-1.2548069f,   0.6063727f,   0.4197761f,  -1.0062231f,   0.74953496f,  0.39295584f,
         0.6912501f,   0.8333996f,  -0.2836925f,  -0.54465365f,  0.01682262f, -0.30280748f,
        -0.19413334f,  0.11433873f, -0.6146446f,  -0.3110674f,  -0.28674668f,  0.23222363f,
         0.6018925f,   0.55321413f,  0.20710474f,  0.1143731f,  -0.04453988f, -0.2581391f,  },
       { 0.37089577f,  0.25766703f,  0.43746668f, -0.2434833f,  -0.54126877f, -0.5931884f,
         0.6228156f,   1.5301939f,  -0.24981959f, -0.5762369f,  -0.80619746f, -0.32335016f,
        -0.36730856f,  0.18326482f, -0.49486315f, -0.05692653f,  0.0991744f,   0.41699046f,
        -0.293335f,   -0.2664309f,   0.13070919f,  0.2575306f,   0.786449f,    0.69670767f, },
       { 0.6592544f,  -0.8329152f,  -0.9359952f,  -0.09724358f,  0.3211133f,   0.5889076f,
        -1.5068736f,  -0.54361856f,  0.56978595f,  1.0097951f,   0.6101386f,   0.70123523f,
        -0.2028823f,   0.71123725f,  0.9762591f,   0.39416403f, -0.13564438f, -0.23545864f,
         0.23338252f,  0.25606415f,  0.37845716f,  0.39840034f, -0.19807948f,  0.10822747f, },
       {-1.068308f,    0.4243879f,   1.1134671f,  -0.00671427f, -0.7231945f,  -0.06374886f,
         0.28859028f,  2.027734f,   -0.1196614f,  -0.28881973f, -0.2253876f,  -0.63545585f,
        -0.32905778f,  0.46152425f, -1.2150424f,   0.20689027f,  0.33270195f,  0.26421973f,
        -0.2611271f,  -0.0463513f,   0.36296165f,  0.33976167f,  0.67268586f,  0.42130515f, },
       { 1.0024545f,  -0.8979219f,  -0.4606817f,   1.6288778f,  -0.43615434f, -0.16547397f,
        -1.3286374f,   0.19710565f, -0.13484326f,  0.01228035f,  0.5828099f,   0.05065876f,
        -0.27321652f,  0.70810837f,  0.24837847f,  0.40342274f,  0.1200042f,   0.4677693f,
        -0.29551736f, -0.38835278f, -0.08476584f,  0.7099492f,   0.295669f,    0.05786236f, }
    },

    {{ // GRUBias
         0.77966547f,  0.23512185f, -0.30826998f,  1.1687665f,   0.06954563f,  0.7323267f,
        -0.4367138f,   0.46684164f,  0.46928874f,  0.15666138f,  0.742312f,    0.38943726f,
         0.0305368f,   0.24815367f,  0.2564296f,   0.12721594f, -0.12097383f,  0.09491241f,
        -0.05494418f, -0.2304874f,   0.14544603f,  0.18934879f, -0.0163425f,   0.04551909f, },
      {  0.72595227f,  0.27653664f, -0.34618953f,  1.2172856f,   0.13265584f,  0.76815516f,
        -0.42085463f,  0.47575158f,  0.4428186f,   0.14147358f,  0.6907643f,   0.43244076f,
        -0.00532867f,  0.21272086f,  0.28124544f,  0.20547734f, -0.20713802f, -0.1608577f,
        -0.00502483f, -0.2992689f,  -0.2145608f,   0.17782384f, -0.11648957f,  0.19886497f, }
    },

    { // DenseWeights
         1.0067502f, -0.421847f,  -0.12050608f,-0.81658554f,
         0.33933163f, 0.56491584f, 0.15144044f, 0.29753608f,
    },

    -0.1190295f // DenseBias
};

#endif // MODELGAIN50_H_INCLUDED
