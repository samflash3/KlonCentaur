#ifndef MODELGAIN1008_H_INCLUDED
#define MODELGAIN1008_H_INCLUDED

#include "../SharedCode/GainStageML.h"

GainStageModel<8, float> ModelGain100 = {
    {{ // GRUKernelWeights
        -1.3560146f,  -0.6899537f,   0.5996209f,   3.3080087f,   0.71942973f,  0.15158644f,
        -1.0168368f,  -0.45430678f,  0.42060328f,  0.29716218f,  0.61462986f, -1.0978606f,
        -1.6727569f,   0.25864124f,  1.5742402f,   0.40305138f,  0.78114045f,  0.1984003f,
         0.24447855f, -1.1094464f,  -1.0232965f,  -0.15778358f, -1.136269f,    0.6774159f,
    }},

    {{ // GRURecurrentWeights
        -0.8467849f,  -0.05656233f,  1.3114988f,   0.56563944f, -0.85233194f, -0.90717506f,
         0.08507507f,  0.20046778f, -0.37947264f, -0.08695767f,  0.26822817f, -1.2797947f,
        -1.0495136f,  -0.43411076f,  0.09254882f, -0.49064702f,  0.4985486f,  -0.1160194f,
        -0.23382713f, -1.163358f,   -1.0268961f,  -0.7646209f,  -0.15917568f, -0.3094923f,  },
       {-1.205214f,   -0.8617637f,   0.44038504f,  0.69337124f, -0.15821068f,  2.086719f,
        -1.5170877f,  -0.08802418f, -0.50811946f, -0.25066411f,  0.5059704f,  -0.7791125f,
        -0.07984361f,  0.12449494f,  0.12309039f, -0.04127842f, -0.75184125f,  0.8395755f,
         0.3681776f,   0.03136235f,  0.57590234f,  0.08862831f, -0.39173988f, -0.7298232f,  },
       {-0.44447178f, -1.3182265f,  -0.5205226f,   0.9936116f,   1.921956f,    1.4587158f,
        -1.086253f,   -0.48795593f, -1.169246f,    0.72126985f, -0.42399156f, -1.6038315f,
         0.17506589f, -0.02912025f,  0.9496147f,   0.08260025f, -0.0136793f,  -0.48097184f,
         0.72937196f,  0.42080414f,  0.44596937f,  0.07408107f,  0.10189103f,  0.03589377f, },
       {-0.9935147f,   0.39267573f, -0.1310785f,   1.8948647f,  -0.54094964f,  1.9584037f,
        -0.58205473f, -0.13708597f,  0.34902114f, -0.00632595f, -1.1983169f,   1.3763168f,
         0.9471199f,   1.2733017f,   0.5267341f,   0.09735841f,  0.16510494f, -0.60223204f,
        -0.07890219f,  0.5527642f,   0.6687216f,   0.44602343f,  0.40772754f,  0.13714817f, },
       {-0.3154589f,   0.8426439f,  -0.4500593f,   2.6812353f,  -0.5766651f,   2.4940655f,
        -0.2696593f,  -0.4908779f,   0.17171487f, -0.30476663f, -1.0677282f,   0.55871266f,
         1.1579589f,   1.5696218f,   0.8207171f,  -0.14633922f,  0.24826483f, -0.33994308f,
         1.0679123f,   1.1987486f,   0.73156816f,  0.75920045f,  0.40804672f,  0.2910605f,  },
       {-2.1706443f,   1.0300651f,   0.10614368f,  1.4604242f,   0.4590703f,   2.4540813f,
         0.44320664f, -1.5565733f,  -0.10117695f, -0.2029321f,   0.6741044f,   1.7220956f,
         0.43529427f,  1.2846589f,   0.40333644f,  0.21153966f, -0.42560455f,  0.20142715f,
         0.1470348f,   0.15211587f, -0.31649172f,  0.94701433f, -0.03239518f,  0.4348278f,  },
       {-0.49536538f, -1.3048961f,  -0.04162576f,  1.1967168f,   1.5832433f,  -1.0034142f,
        -1.1591355f,  -0.07818494f, -0.24913977f, -0.3917656f,  -0.18842477f,  0.34531638f,
        -0.8692576f,  -0.6926088f,  -0.16410719f,  0.16689476f,  0.26288077f, -0.22985637f,
         0.09936274f, -0.36561266f, -0.7818727f,  -0.01243425f,  0.28281733f,  0.57455635f, },
       {-0.29142192f, -0.5359895f,   1.9536498f,   1.2511169f,   0.14587139f, -1.6930572f,
        -0.09011165f,  1.0572305f,  -0.80300415f, -0.586327f,   -0.34894946f, -0.6124902f,
        -0.5745612f,  -1.2431145f,   0.20139776f, -0.8241204f,  -0.00411688f, -0.22170891f,
         0.14284302f, -0.8811688f,  -0.9401197f,  -0.12339453f,  0.01830158f,  0.54138416f, }
    },

    {{ // GRUBias
        -0.14848903f,  1.113277f,    0.90189815f, -0.79968953f, -1.6275461f,  -0.10915942f,
         0.81447405f,  0.30755594f,  0.5127445f,   0.49443272f,  0.49299663f, -0.10389564f,
         0.68477505f,  0.12642068f,  0.40713152f,  0.5183419f,   0.02533106f, -0.16002141f,
        -0.0114329f,   0.10006962f, -0.18073757f, -0.0217502f,  -0.2736654f,   0.09427667f, },
      { -0.14602408f,  1.0661982f,   0.83356464f, -0.77092147f, -1.6300802f,  -0.10168039f,
         0.8908542f,   0.26145482f,  0.44484806f,  0.4394863f,   0.5305568f,  -0.13952191f,
         0.71533257f,  0.19360557f,  0.3959703f,   0.43519148f,  0.08078653f,  0.00965601f,
        -0.20179468f,  0.20059252f,  0.21234642f,  0.09101236f, -0.37295693f,  0.08460861f, }
    },

    { // DenseWeights
        -0.619084f,  -0.32572433f, 0.36176503f,-0.12590216f,
        -0.07331878f, 0.1363641f,  0.24145526f, 1.6306293f,
    },

    0.05087356f // DenseBias
};

#endif // MODELGAIN1008_H_INCLUDED
