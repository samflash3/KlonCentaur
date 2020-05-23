#ifndef GAINSTAGEML_H_INCLUDED
#define GAINSTAGEML_H_INCLUDED

#include "MLUtils/dense.h"
#include "MLUtils/gru.h"
#include "MLUtils/gru.cpp"

class GainStageML
{
public:
    GainStageML()
    {
        gruLayer.setWVals(GRUKernelWeights);
        gruLayer.setUVals(GRURecurrentWeights);
        gruLayer.setBVals(GRUBias);

        denseLayer.setWeights(DenseWeights);
        denseLayer.setBias(DenseBias);
    }

    void reset()
    {
        gruLayer.reset();
    }

    inline float processSample(float x)
    {
        float input[1] = { x };
        gruLayer.forward(input, hidden);
        return denseLayer.forward(hidden);
    }

    void processBlock(float* block, const int numSamples)
    {
        for(int n = 0; n < numSamples; ++n)
            block[n] = processSample(block[n]);
    }

private:
    float hidden[16] = {0};

    GRULayer<1, 16, float> gruLayer;
    Dense1<16, float> denseLayer;

    const float GRUKernelWeights[1][48] = {{
        -0.3793975f,  -0.3267108f,  -0.31897095f,  0.40224496f,  0.0669373f,   0.2080555,
        -0.20643501f,  0.10540868f, -0.18400142f, -0.09477121f,  0.06309047f,  0.42389688,
         0.341932f,    0.5427513f,   0.10521009f, -0.44925502f, -0.3765811f,   0.2560529,
        -0.07844678f, -0.30062547f, -0.2675452f,   0.1386037f,  -0.4138159f,  -0.13829869,
         0.02696979f, -0.02859844f, -0.28516147f,  0.20677644f, -0.38817903f, -0.1128876,
         0.01040488f, -0.10043316f, -0.49431595f,  0.05050121f, -0.448818f,   -0.41196188,
         0.20587409f,  0.50547487f, -0.13013639f,  0.2391868f,  -0.21479174f, -0.03647669,
        -0.17973267f, -0.29535532f,  0.4427527f,  -0.18274613f,  0.19155705f,  0.51248795
    }};

    const float GRURecurrentWeights[16][48] = {{
        -3.90160114e-01, -7.30664551e-01, -9.31405574e-02, -3.09338927e-01,
        -1.26576349e-01,  1.98879749e-01,  1.42259793e-02,  8.62972811e-02,
        -4.22690183e-01, -6.15775213e-02, -7.35510349e-01, -4.71591502e-01,
         4.26028669e-02, -4.09080386e-01, -5.96562147e-01, -1.41985372e-01,
        -2.21251160e-01, -1.05778947e-01, -8.86716098e-02,  1.79953545e-01,
         5.25980368e-02, -2.82600392e-02,  1.39881268e-01,  3.12467784e-01,
         4.69188094e-02,  1.75304353e-01,  3.34414393e-02,  9.58278254e-02,
         1.75794140e-02,  9.97962207e-02, -5.91110922e-02, -8.41346290e-03,
         2.54754245e-01, -2.86353439e-01, -1.53609231e-01,  1.76966131e-01,
        -2.96224833e-01, -2.12274030e-01, -5.96549101e-02,  2.55223840e-01,
         4.46401611e-02,  9.64256898e-02,  2.58574337e-01,  3.56198736e-02,
         9.24575552e-02,  7.05283359e-02,  3.28963250e-01, -5.66310510e-02 },
       { 1.25680342e-01,  1.05109580e-01, -2.38898948e-01, -6.50459826e-02,
         1.63096219e-01,  1.34188548e-01, -2.69374758e-01, -3.10804471e-02,
         2.07676038e-01, -2.39307120e-01, -4.59420919e-01, -3.75603586e-01,
        -2.72586904e-02,  4.55999933e-02,  3.55713576e-01, -2.71782666e-01,
        -3.13012272e-01, -1.81385949e-01, -1.39830321e-01,  2.23562405e-01,
        -1.01185180e-01, -5.71073219e-02, -2.52253383e-01,  9.01087373e-02,
        -2.48623878e-01, -1.56996995e-01,  4.73611616e-02, -4.07389730e-01,
        -2.02389449e-01, -3.60493600e-01, -1.05772927e-01,  4.73918915e-02,
        -2.50357509e-01, -8.64880607e-02, -8.17857403e-03, -1.17348945e-02,
         5.73314764e-02,  1.01748064e-01, -3.17312717e-01, -1.30411699e-01,
         1.10712141e-01,  1.65947527e-01, -1.57158002e-01, -3.43414307e-01,
         1.10089980e-01, -2.24265993e-01, -2.28435889e-01,  1.80517033e-01 },
       { 4.09150362e-01, -5.66033006e-01, -1.22920118e-01, -3.86453271e-01,
        -2.26016536e-01, -2.37019479e-01,  2.78578699e-01, -1.50935967e-02,
        -2.09283665e-01,  1.06133245e-01,  1.51600212e-01,  1.20991923e-01,
         2.35097148e-02, -1.04547061e-01, -2.74326682e-01,  6.16630428e-02,
        -3.13316107e-01,  1.65086731e-01,  2.27669448e-01,  2.28791326e-01,
         3.53254117e-02,  1.43502235e-01,  1.60161674e-01,  1.66737571e-01,
         2.56907552e-01,  3.28397423e-01,  2.05872014e-01, -1.59915108e-02,
         6.65251389e-02,  9.30009484e-02,  2.53173828e-01,  3.59558612e-01,
         4.38444197e-01,  5.26391305e-02,  1.66360334e-01,  3.64785753e-02,
        -9.35075730e-02, -1.48117766e-01,  1.63303792e-01,  1.25347540e-01,
        -1.37507975e-01,  1.66288584e-01,  1.52153015e-01,  1.46957412e-01,
        -2.40667269e-01,  2.49538258e-01,  3.91256869e-01, -3.49947125e-01 },
       { 3.77693832e-01, -2.62084723e-01, -2.81549037e-01,  1.16247386e-01,
        -1.88873455e-01, -2.92173624e-01,  3.77451599e-01,  1.69870690e-01,
         4.85712104e-02,  4.22285467e-01,  3.97104353e-01,  3.96067172e-01,
         1.34239784e-02, -2.11469844e-01, -2.95870066e-01,  1.96025372e-01,
         7.94676244e-02,  1.61902338e-01,  1.51962668e-01, -9.01086330e-02,
         5.80526702e-02, -2.45281990e-05, -3.41184549e-02,  1.43654183e-01,
         8.64811540e-02, -9.62648541e-02, -6.30917773e-02,  1.64022639e-01,
         2.74633259e-01, -2.74405424e-02,  8.20644572e-02,  5.24312630e-02,
         2.42400602e-01, -4.05325502e-01, -1.56540602e-01,  3.03789526e-01,
        -3.11999530e-01, -4.46119815e-01,  1.23550132e-01,  4.04090434e-01,
         2.25823298e-01, -4.27446775e-02,  2.96922475e-01,  1.43124491e-01,
        -2.57396519e-01,  2.03733444e-01,  2.42218122e-01, -2.06678569e-01 },
       {-2.72297144e-01,  4.26580608e-01,  2.61206508e-01,  3.34427625e-01,
         3.82618085e-02, -2.04321399e-01, -4.42362517e-01, -1.70995295e-02,
        -3.29102725e-02,  2.74595439e-01, -3.08918227e-02, -2.79548883e-01,
         2.77804071e-03,  2.89423585e-01,  4.85666037e-01, -1.46551933e-02,
         1.02902494e-01, -4.85367849e-02,  8.69773999e-02, -2.60926504e-02,
        -3.28023821e-01,  2.10643224e-02, -1.64529055e-01,  1.04797073e-02,
        -2.30846763e-01, -1.19178578e-01,  8.37070197e-02, -2.96212465e-01,
         1.87978804e-01,  8.18715170e-02,  1.46782950e-01,  8.19222480e-02,
        -4.20650125e-01,  7.57774562e-02, -2.05617666e-01, -9.80341714e-03,
         1.09254397e-01,  2.11848632e-01, -7.30332881e-02, -1.56663835e-01,
        -3.63069683e-01,  3.25545311e-01, -1.50133535e-01, -6.14050590e-02,
         1.41352788e-01, -1.78061306e-01, -2.28603914e-01,  2.66199589e-01 },
       {-6.78492486e-01,  8.14515650e-01, -2.34110877e-01,  5.27281404e-01,
         5.01312204e-02, -1.48982212e-01, -3.52819026e-01, -1.97478205e-01,
         2.13255376e-01,  1.65710986e-01, -1.02983296e-01,  1.88709110e-01,
         9.70451608e-02,  4.50019062e-01,  4.63304341e-01, -5.82459211e-01,
         6.75315484e-02, -1.28037527e-01, -4.36470598e-01,  3.41707990e-02,
         2.36465201e-01, -7.94126838e-02,  2.85385605e-02, -1.23566389e-01,
        -2.11941302e-01,  1.61061168e-01, -1.73801407e-02, -1.45383850e-01,
        -1.09374858e-01, -8.93060118e-02,  9.76010785e-02, -1.87172964e-01,
        -3.08846712e-01,  1.73050299e-01, -2.79525369e-01, -8.34921151e-02,
         5.21581650e-01,  1.55594930e-01, -6.82189986e-02, -2.62753546e-01,
        -1.79450035e-01,  1.41656011e-01, -2.07042843e-01,  4.50233854e-02,
         2.24243253e-01, -3.70074987e-01, -2.38912165e-01,  1.99288264e-01 },
       {-5.45527190e-02, -7.18655065e-02, -1.36157051e-01,  2.78186165e-02,
        -2.77915653e-02, -1.69831231e-01, -6.38637096e-02,  3.19312583e-03,
        -1.59181654e-01,  3.20932955e-01,  1.97477311e-01,  1.62018582e-01,
         9.67685729e-02, -3.71062607e-02, -7.42730021e-01, -2.39255741e-01,
         3.22354436e-01,  4.58450168e-01, -8.15758705e-02,  2.85838813e-01,
         1.98193192e-02,  4.62453626e-02,  1.81177929e-01,  8.63831639e-02,
        -8.05165470e-02, -5.99531131e-03,  1.66223407e-01, -1.83391366e-02,
        -5.06928153e-02,  1.06721193e-01,  1.96943104e-01,  4.22622934e-02,
         1.35213435e-01,  3.05425283e-02,  1.40836760e-01,  2.48635620e-01,
        -9.50940698e-02,  5.79791218e-02,  3.16661417e-01,  2.02577971e-02,
         3.64282489e-01, -1.53651312e-01,  2.18746841e-01, -7.94860814e-03,
        -5.60156293e-02,  4.69446570e-01,  1.11466825e-01, -1.54329732e-01 },
       {-2.04848483e-01,  3.63161534e-01, -1.12891771e-01,  2.45715275e-01,
        -1.16874330e-01,  1.61522049e-02, -3.33362192e-01,  1.87102258e-01,
        -2.68446445e-01,  4.99199688e-01, -8.45387280e-02,  2.40437493e-01,
         1.94246128e-01,  2.11107329e-01,  2.92768419e-01, -3.37150276e-01,
         1.05880789e-01,  2.95431286e-01, -4.43020016e-01, -4.24593724e-02,
        -2.84581389e-02,  9.16360691e-02, -4.73147810e-01,  9.50673223e-02,
         2.12168425e-01, -4.12630066e-02,  2.77687404e-02,  3.72018039e-01,
        -2.36894516e-03, -3.07353977e-02,  1.72301322e-01,  1.87700726e-02,
        -2.78590858e-01,  2.39209924e-03, -9.73915774e-03, -3.37182544e-02,
         3.99026215e-01,  5.11431873e-01, -1.19268999e-01,  1.09175369e-01,
        -1.51070833e-01, -2.15666629e-02, -5.24931699e-02,  1.02820329e-01,
         2.85426259e-01, -2.94216983e-02,  1.80206850e-01,  2.00245708e-01 },
       { 6.58373162e-02, -1.07706167e-01, -3.81593436e-01, -2.15341017e-01,
        -1.82971939e-01,  7.28337765e-02,  3.86566520e-01,  2.23671690e-01,
        -4.36364263e-01,  1.47490948e-01, -5.14297150e-02,  9.46653560e-02,
        -6.89294264e-02, -6.64098412e-02, -3.03800464e-01, -2.56143898e-01,
        -1.77746043e-01,  1.16760014e-02,  2.95581937e-01, -5.04967049e-02,
         1.04279630e-01,  3.70255373e-02,  4.53882180e-02,  5.69557250e-02,
        -6.35805205e-02,  1.94466516e-01,  2.13529076e-02,  2.10573956e-01,
         1.80456385e-01,  2.00402007e-01,  4.20191377e-01, -6.28395453e-02,
         2.72566468e-01, -2.18870908e-01,  5.47729433e-02,  1.70272321e-01,
        -2.84519881e-01,  3.74640431e-03,  2.70351529e-01, -7.02490583e-02,
         2.09582135e-01, -3.65698487e-01,  3.64406444e-02,  1.32230163e-01,
        -1.25438690e-01,  1.82242900e-01,  1.71994686e-01,  1.82135969e-01 },
       { 5.31075835e-01, -2.55112648e-01,  3.54137897e-01, -1.02413543e-01,
         5.08719623e-01,  6.49360120e-01,  2.42843330e-01, -1.72774792e-02,
        -1.55879095e-01, -4.12918359e-01, -2.01227874e-01, -3.56435895e-01,
         2.14703187e-01,  4.64024991e-02, -2.43767217e-01,  2.64542252e-01,
        -2.46735573e-01, -2.48297140e-01,  4.03926969e-02, -1.31212771e-01,
         4.57521081e-02, -2.04123244e-01,  1.03111854e-02,  1.80300683e-01,
        -5.20286709e-02, -1.18728109e-01, -9.34929550e-02,  1.61325186e-01,
         8.51628855e-02, -1.52907670e-02,  1.26688972e-01,  2.65833259e-01,
         2.21706569e-01, -4.20154259e-02,  3.51193339e-01,  1.87819883e-01,
        -1.08213738e-01, -6.27669334e-01,  2.54368149e-02,  1.23359978e-01,
         7.25102276e-02,  1.55041769e-01, -6.74654394e-02, -7.75749385e-02,
        -9.64166299e-02,  4.65983361e-01, -1.77053232e-02, -1.34354725e-01 },
       {-4.96975183e-02, -2.30659187e-01,  1.25595227e-01,  1.40199989e-01,
         3.40160988e-02,  1.31064564e-01,  1.89116150e-01,  4.59202647e-01,
         8.62693414e-03,  3.52043629e-01,  2.86098659e-01,  5.09172857e-01,
         3.49399984e-01,  3.51567715e-01, -2.28010982e-01, -5.79954013e-02,
        -2.87237495e-01,  8.29430372e-02,  1.25658065e-01, -1.19379327e-01,
        -2.33354524e-01,  2.14174330e-01,  1.04333460e-01, -4.72253673e-02,
        -3.96512970e-02,  1.26063377e-01, -1.22555755e-01,  9.10281092e-02,
        -4.12267335e-02, -1.46022350e-01, -1.64520487e-01,  2.86945906e-02,
         2.17896596e-01, -1.67073712e-01, -1.36261687e-01,  1.93331763e-01,
        -3.01520471e-02,  6.10256158e-02,  1.81615546e-01,  2.78981119e-01,
         2.93046057e-01, -2.34774932e-01, -6.11297339e-02,  3.02039862e-01,
        -1.86704516e-01,  8.30125660e-02,  1.74464554e-01, -4.79026474e-02 },
       { 2.80911326e-01,  5.02217293e-01,  3.52426060e-02, -6.71172142e-02,
        -2.29076426e-02,  3.87746133e-02,  1.42623857e-01,  3.23151648e-01,
         6.02775030e-02,  2.90141582e-01,  4.15758312e-01,  4.80360955e-01,
         1.43718988e-01,  1.25898004e-01,  1.90240353e-01,  2.91933417e-01,
         1.62123173e-01, -4.08413559e-02, -6.56572133e-02, -8.36351588e-02,
        -9.05927122e-02,  7.40692951e-03,  1.40143275e-01,  1.83396995e-01,
        -1.21233076e-01, -1.45786302e-02,  3.54123890e-01,  7.93213546e-02,
         2.18611695e-02,  2.09090024e-01, -1.67527512e-01,  4.11671489e-01,
        -1.10272460e-01,  2.24062819e-02,  1.20117441e-01,  1.41793504e-01,
        -1.79076761e-01, -1.86985761e-01,  1.23107940e-01,  3.37262988e-01,
         1.55202165e-01, -1.67018160e-01,  1.69187486e-01,  4.41328496e-01,
        -2.43279159e-01,  5.27096204e-02,  2.53707975e-01,  5.12786061e-02 },
       {-1.18837684e-01,  4.92934436e-01, -1.81084797e-01, -8.77254382e-02,
         3.11640531e-01,  1.10221416e-01, -1.26290351e-01, -3.95517141e-01,
        -1.93847269e-02, -2.40907744e-01, -1.63113877e-01, -4.11806941e-01,
         3.22634131e-01,  2.46722624e-01,  2.84569681e-01, -2.61283636e-01,
        -2.20138893e-01, -1.96673438e-01, -2.99484283e-01, -8.41368064e-02,
        -1.19017750e-01, -3.34218800e-01, -4.43124846e-02, -1.09532410e-02,
         9.84006599e-02, -1.89943433e-01, -9.12608355e-02, -3.29525739e-01,
         3.51028331e-02, -7.85099640e-02, -1.74367413e-01, -3.40210617e-01,
         1.17329635e-01,  3.02651376e-01, -2.51345247e-01, -1.60369620e-01,
         2.32327521e-01,  7.47699738e-02, -1.51743025e-01, -4.81969863e-02,
        -1.48654521e-01,  4.77920361e-02, -1.93230659e-01, -6.03940487e-02,
         1.51638478e-01, -1.37380600e-01, -2.62113303e-01,  3.73796105e-01 },
       { 4.74308610e-01, -5.20797133e-01,  1.47638485e-01,  1.27737001e-01,
        -1.74335077e-01,  1.74258709e-01,  6.01210296e-01,  1.80036992e-01,
        -2.42642343e-01, -9.51192901e-03,  4.09528077e-01,  2.05021799e-01,
         1.52515128e-01, -3.37770395e-02, -4.14977223e-01,  1.82161108e-01,
        -3.40352207e-02, -2.17455670e-01,  3.66402447e-01,  1.45649403e-01,
        -1.84298262e-01, -8.96999165e-02, -2.69192886e-02,  1.56893611e-01,
        -5.74747249e-02,  4.46346076e-03,  6.31902367e-03, -2.50534201e-03,
        -1.32280970e-02,  1.30437076e-01, -1.05394937e-01, -7.41342902e-02,
         2.26035804e-01, -1.46315023e-01,  2.99067378e-01,  2.98901111e-01,
         7.52884373e-02, -2.99243689e-01,  1.98988453e-01,  5.79029396e-02,
         1.85372129e-01, -4.40656245e-02,  3.85091454e-01,  1.50905028e-02,
        -5.38063496e-02, -1.09706186e-01,  1.17869742e-01, -3.70424747e-01 },
       {-3.53055120e-01,  2.04105005e-01,  1.38903439e-01, -7.26995915e-02,
         1.25884205e-01, -1.42258748e-01, -1.45678893e-01,  3.30193698e-01,
        -8.37806314e-02,  2.85129458e-01,  3.37910354e-01,  1.07852437e-01,
        -1.08953053e-02,  2.54803151e-01, -1.83341652e-01,  1.26949046e-03,
        -1.53155342e-01, -5.64231500e-02, -5.48920259e-02, -1.51735302e-02,
         2.48191074e-01, -1.99820146e-01,  5.04493937e-02, -2.44791806e-01,
         1.87953144e-01, -1.88399985e-01, -3.92821312e-01, -2.06704259e-01,
        -2.99901068e-02, -1.71511665e-01, -1.13681100e-01, -8.79121646e-02,
        -5.53178266e-02, -1.49283558e-01,  1.80508465e-01,  1.48453802e-01,
         9.59018245e-02,  1.31429404e-01,  3.52191389e-01,  2.55550146e-01,
         1.15379669e-01, -1.89203545e-01,  1.71001717e-01,  2.28004642e-02,
         1.36601120e-01, -1.85643405e-01,  3.34210664e-01,  2.68508196e-01 },
       {-2.35377282e-01,  5.62548101e-01,  3.03341448e-01,  4.24131006e-02,
         3.06852639e-01,  5.18002138e-02, -1.92208648e-01, -6.52644932e-02,
         4.14845824e-01, -1.66014861e-02,  4.04137224e-02,  2.05770493e-01,
         1.35261996e-03,  3.39292079e-01,  3.96421880e-01, -5.03782965e-02,
         3.28042775e-01, -1.56112626e-01, -2.28014886e-01,  1.73849329e-01,
        -2.03851938e-01, -2.80531257e-01, -9.48028043e-02, -4.05488044e-01,
         1.57422870e-02, -2.78360695e-01, -3.02818447e-01, -3.09924632e-02,
        -3.31824571e-01, -4.91282009e-02,  2.59295940e-01, -1.26372660e-02,
        -2.04344407e-01,  2.75805742e-01, -4.20152247e-01,  1.42263398e-01,
         4.00597215e-01,  2.05941886e-01, -9.62709039e-02,  9.41373780e-03,
        -2.48943716e-01,  6.69425577e-02, -1.45808250e-01, -1.79453865e-01,
        -1.24045581e-01, -4.27095413e-01, -2.17821628e-01,  1.01137787e-01 }
    };

    const float GRUBias[2][48] = {{
        3.0332676e-01,  8.7678559e-02,  3.3300336e-02,  6.2067866e-02,
       -1.2543920e-01, -2.0356470e-01,  1.8790770e-01,  1.8964103e-01,
        1.7522693e-01,  1.3803342e-01,  3.6762840e-01,  3.0390581e-01,
       -4.7900006e-02, -2.0413913e-04,  7.0803322e-02,  9.9775225e-02,
        2.4341816e-01,  2.4875177e-01,  1.4832567e-01,  1.6529295e-01,
        2.2789533e-01,  1.6477188e-01,  1.5434444e-01,  2.3035136e-01,
        1.4724217e-01,  7.6906711e-02,  2.5280195e-01,  7.4333407e-02,
        1.7522621e-01,  1.8931341e-01,  2.6693398e-01,  3.0504638e-01,
       -4.8370365e-02, -3.8370401e-02, -1.6242640e-02,  2.1239549e-03,
        1.3341595e-01, -1.5225066e-02,  1.5177667e-02, -6.3769981e-02,
        5.8187716e-02, -6.2504224e-02, -1.4375131e-01, -1.2501136e-02,
       -6.2126093e-02, -7.6121353e-02, -2.9857835e-02,  4.4060670e-02 },
      { 2.1705574e-01,  3.9043959e-02, -3.6411785e-02,  4.1483492e-03,
       -1.4859119e-01, -1.6303179e-01,  1.2437724e-01,  1.8568286e-01,
        1.4042208e-01,  1.6663289e-01,  3.0390847e-01,  2.6066402e-01,
       -5.0989393e-02, -5.3180195e-02,  9.1532990e-02,  1.4991164e-01,
        2.0039906e-01,  2.3663820e-01,  1.2816088e-01,  1.2589090e-01,
        1.7196284e-01,  2.5272512e-01,  1.5547004e-01,  1.8663403e-01,
        1.7976543e-01, -3.3057043e-03,  1.9795287e-01,  1.2841094e-01,
        1.6957292e-01,  2.3178571e-01,  2.3630707e-01,  2.2902408e-01,
       -1.4838147e-01, -1.3969107e-01,  9.8110572e-02,  2.7979646e-02,
       -2.5524657e-02,  9.7877225e-03,  4.5206744e-02,  6.1387207e-02,
       -1.7676599e-02, -4.9675074e-03,  5.1619697e-02,  6.1684959e-02,
       -9.2183493e-02,  5.4889917e-03,  3.6046375e-02,  4.5861478e-04 }
    };

    const float DenseWeights[16] = {
        0.40873134f, -0.72363925f, 0.5138193f,  0.7519815f,
        -0.2700763f, -0.19126508f, 0.52690506f, 0.45529118f,
         0.5962171f, -0.59494317f, 0.5143368f,  0.5143378f,
        -0.3290402f,  0.80185306f, 0.6676823f, -0.5368551f };
    
    const float DenseBias = 0.09284844f;


};

#endif // GAINSTAGEML_H_INCLUDED
