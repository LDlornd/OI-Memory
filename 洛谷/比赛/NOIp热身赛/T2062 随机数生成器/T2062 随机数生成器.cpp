#include<cstdio>
#include<iostream>
using namespace std;
typedef long long int ll;
const int val=1000000;
int n;
double E[100000]={0,15.392726,16.085873,16.491338,16.779020,17.002164,17.184486,17.338636,17.472168,17.589951,17.695311,17.790621,17.877633,17.957676,18.031784,18.100776,18.165315,18.225940,18.283098,18.337165,18.388458,18.437249,18.483769,18.528220,18.570780,18.611602,18.650823,18.688563,18.724931,18.760022,18.793924,18.826713,18.858462,18.889234,18.919087,18.948074,18.976245,19.003644,19.030312,19.056288,19.081606,19.106298,19.130396,19.153926,19.176916,19.199389,19.221368,19.242874,19.263927,19.284547,19.304749,19.324552,19.343970,19.363018,19.381710,19.400059,19.418078,19.435777,19.453169,19.470264,19.487071,19.503600,19.519861,19.535861,19.551609,19.567113,19.582381,19.597419,19.612234,19.626833,19.641221,19.655406,19.669392,19.683186,19.696791,19.710214,19.723460,19.736532,19.749435,19.762174,19.774753,19.787175,19.799445,19.811567,19.823543,19.835377,19.847074,19.858634,19.870063,19.881363,19.892536,19.903586,19.914515,19.925326,19.936021,19.946603,19.957074,19.967437,19.977694,19.987846,19.997896,20.007847,20.017699,20.027455,20.037117,20.046687,20.056165,20.065555,20.074857,20.084074,20.093207,20.102256,20.111225,20.120114,20.128925,20.137658,20.146316,20.154900,20.163411,20.171850,20.180218,20.188517,20.196747,20.204911,20.213008,20.221040,20.229008,20.236913,20.244756,20.252539,20.260261,20.267924,20.275528,20.283075,20.290566,20.298001,20.305381,20.312707,20.319980,20.327200,20.334369,20.341486,20.348553,20.355571,20.362540,20.369460,20.376333,20.383159,20.389938,20.396673,20.403362,20.410006,20.416607,20.423164,20.429679,20.436151,20.442582,20.448972,20.455321,20.461630,20.467900,20.474131,20.480323,20.486476,20.492593,20.498672,20.504714,20.510720,20.516690,20.522625,20.528525,20.534390,20.540221,20.546018,20.551782,20.557512,20.563210,20.568876,20.574510,20.580112,20.585683,20.591223,20.596733,20.602212,20.607662,20.613082,20.618473,20.623835,20.629168,20.634473,20.639750,20.645000,20.650222,20.655416,20.660584,20.665726,20.670841,20.675930,20.680993,20.686031,20.691044,20.696031,20.700994,20.705932,20.710846,20.715736,20.720602,20.725445,20.730264,20.735060,20.739834,20.744584,20.749312,20.754018,20.758702,20.763364,20.768005,20.772624,20.777221,20.781798,20.786354,20.790889,20.795404,20.799898,20.804372,20.808827,20.813261,20.817676,20.822072,20.826448,20.830806,20.835144,20.839464,20.843765,20.848047,20.852312,20.856558,20.860786,20.864997,20.869190,20.873365,20.877523,20.881664,20.885788,20.889894,20.893984,20.898058,20.902115,20.906155,20.910179,20.914187,20.918179,20.922155,20.926116,20.930060,20.933990,20.937904,20.941802,20.945686,20.949554,20.953408,20.957247,20.961071,20.964880,20.968675,20.972456,20.976223,20.979975,20.983713,20.987438,20.991148,20.994845,20.998528,21.002198,21.005854,21.009497,21.013127,21.016744,21.020347,21.023938,21.027516,21.031081,21.034633,21.038173,21.041700,21.045215,21.048718,21.052208,21.055687,21.059153,21.062607,21.066049,21.069480,21.072899,21.076306,21.079702,21.083086,21.086458,21.089820,21.093170,21.096509,21.099836,21.103153,21.106459,21.109754,21.113038,21.116311,21.119574,21.122826,21.126067,21.129299,21.132519,21.135729,21.138929,21.142119,21.145299,21.148468,21.151628,21.154778,21.157917,21.161047,21.164167,21.167278,21.170379,21.173470,21.176551,21.179624,21.182686,21.185740,21.188784,21.191819,21.194845,21.197861,21.200869,21.203867,21.206857,21.209837,21.212809,21.215772,21.218726,21.221672,21.224609,21.227537,21.230457,21.233368,21.236271,21.239165,21.242051,21.244929,21.247798,21.250659,21.253512,21.256357,21.259194,21.262023,21.264844,21.267657,21.270462,21.273259,21.276049,21.278830,21.281604,21.284370,21.287129,21.289880,21.292624,21.295360,21.298088,21.300809,21.303523,21.306229,21.308928,21.311620,21.314305,21.316982,21.319652,21.322315,21.324971,21.327620,21.330262,21.332897,21.335526,21.338147,21.340761,21.343369,21.345970,21.348564,21.351151,21.353732,21.356306,21.358873,21.361434,21.363988,21.366536,21.369077,21.371612,21.374140,21.376663,21.379178,21.381688,21.384191,21.386688,21.389178,21.391663,21.394141,21.396613,21.399079,21.401539,21.403993,21.406441,21.408883,21.411319,21.413750,21.416174,21.418592,21.421005,21.423411,21.425812,21.428208,21.430597,21.432981,21.435359,21.437732,21.440098,21.442460,21.444815,21.447166,21.449510,21.451849,21.454183,21.456511,21.458834,21.461152,21.463464,21.465771,21.468072,21.470368,21.472659,21.474945,21.477226,21.479501,21.481771,21.484036,21.486296,21.488551,21.490801,21.493045,21.495285,21.497519,21.499749,21.501974,21.504194,21.506408,21.508618,21.510823,21.513024,21.515219,21.517410,21.519595,21.521776,21.523953,21.526124,21.528291,21.530453,21.532611,21.534764,21.536912,21.539055,21.541195,21.543329,21.545459,21.547584,21.549705,21.551822,21.553934,21.556041,21.558144,21.560243,21.562337,21.564427,21.566512,21.568593,21.570670,21.572743,21.574811,21.576875,21.578935,21.580990,21.583042,21.585089,21.587132,21.589170,21.591205,21.593235,21.595262,21.597284,21.599302,21.601316,21.603326,21.605332,21.607334,21.609332,21.611326,21.613316,21.615302,21.617285,21.619263,21.621237,21.623208,21.625174,21.627137,21.629096,21.631051,21.633002,21.634949,21.636893,21.638833,21.640769,21.642701,21.644630,21.646555,21.648476,21.650394,21.652308,21.654218,21.656124,21.658027,21.659927,21.661823,21.663715,21.665603,21.667488,21.669370,21.671248,21.673122,21.674993,21.676860,21.678724,21.680585,21.682442,21.684295,21.686146,21.687992,21.689836,21.691675,21.693512,21.695345,21.697175,21.699002,21.700825,21.702645,21.704461,21.706274,21.708084,21.709891,21.711694,21.713495,21.715291,21.717085,21.718876,21.720663,21.722447,21.724228,21.726006,21.727780,21.729552,21.731320,21.733086,21.734848,21.736607,21.738363,21.740115,21.741865,21.743612,21.745356,21.747096,21.748834,21.750568,21.752300,21.754029,21.755754,21.757477,21.759197,21.760913,21.762627,21.764338,21.766046,21.767751,21.769453,21.771152,21.772849,21.774542,21.776233,21.777921,21.779606,21.781288,21.782967,21.784643,21.786317,21.787988,21.789656,21.791321,21.792984,21.794643,21.796300,21.797955,21.799606,21.801255,21.802901,21.804544,21.806185,21.807823,21.809459,21.811091,21.812721,21.814348,21.815973,21.817595,21.819215,21.820831,21.822446,21.824057,21.825666,21.827273,21.828877,21.830478,21.832077,21.833673,21.835266,21.836857,21.838446,21.840032,21.841616,21.843197,21.844775,21.846351,21.847925,21.849496,21.851065,21.852631,21.854194,21.855756,21.857315,21.858871,21.860425,21.861977,21.863526,21.865073,21.866617,21.868159,21.869699,21.871236,21.872771,21.874303,21.875834,21.877361,21.878887,21.880410,21.881931,21.883450,21.884966,21.886480,21.887992,21.889501,21.891008,21.892513,21.894016,21.895516,21.897014,21.898510,21.900004,21.901495,21.902985,21.904472,21.905956,21.907439,21.908919,21.910397,21.911874,21.913347,21.914819,21.916289,21.917756,21.919221,21.920684,21.922145,21.923604,21.925061,21.926515,21.927967,21.929418,21.930866,21.932312,21.933756,21.935198,21.936638,21.938076,21.939512,21.940945,21.942377,21.943807,21.945234,21.946660,21.948083,21.949505,21.950924,21.952341,21.953757,21.955170,21.956582,21.957991,21.959399,21.960804,21.962208,21.963609,21.965009,21.966406,21.967802,21.969196,21.970588,21.971977,21.973365,21.974751,21.976135,21.977518,21.978898,21.980276,21.981653,21.983027,21.984400,21.985771,21.987140,21.988507,21.989872,21.991235,21.992597,21.993956,21.995314,21.996670,21.998024,21.999376,22.000727,22.002075,22.003422,22.004767,22.006110,22.007452,22.008791,22.010129,22.011465,22.012799,22.014132,22.015463,22.016791,22.018119,22.019444,22.020768,22.022089,22.023410,22.024728,22.026045,22.027360,22.028673,22.029984,22.031294,22.032602,22.033908,22.035213,22.036516,22.037817,22.039117,22.040415,22.041711,22.043005,22.044298,22.045589,22.046879,22.048167,22.049453,22.050737,22.052020,22.053301,22.054581,22.055859,22.057135,22.058410,22.059683,22.060954,22.062224,22.063493,22.064759,22.066024,22.067288,22.068549,22.069810,22.071068,22.072325,22.073581,22.074835,22.076087,22.077338,22.078587,22.079835,22.081081,22.082325,22.083568,22.084810,22.086050,22.087288,22.088525,22.089760,22.090994,22.092227,22.093457,22.094687,22.095914,22.097141,22.098365,22.099589,22.100810,22.102031,22.103249,22.104467,22.105682,22.106897,22.108110,22.109321,22.110531,22.111739,22.112946,22.114152,22.115356,22.116559,22.117760,22.118960,22.120158,22.121355,22.122550,22.123744,22.124937,22.126128,22.127318,22.128506,22.129693,22.130879,22.132063,22.133246,22.134427,22.135607,22.136785,22.137963,22.139138,22.140313,22.141486,22.142657,22.143828,22.144997,22.146164,22.147330,22.148495,22.149659,22.150821,22.151981,22.153141,22.154299,22.155456,22.156611,22.157765,22.158918,22.160069,22.161219,22.162368,22.163516,22.164662,22.165807,22.166950,22.168092,22.169233,22.170373,22.171511,22.172648,22.173784,22.174918,22.176051,22.177183,22.178314,22.179443,22.180571,22.181698,22.182823,22.183948,22.185071,22.186192,22.187313,22.188432,22.189550,22.190667,22.191782,22.192896,22.194009,22.195121,22.196231,22.197341,22.198449,22.199556,22.200661,22.201766,22.202869,22.203971,22.205071,22.206171,22.207269,22.208366,22.209462,22.210557,22.211650,22.212743,22.213834,22.214924,22.216012,22.217100,22.218186,22.219271,22.220355,22.221438,22.222520,22.223600,22.224680,22.225758,22.226835,22.227911,22.228985,22.230059,22.231131,22.232203,22.233273,22.234342,22.235410,22.236476,22.237542,22.238606,22.239669,22.240731,22.241793,22.242852,22.243911,22.244969,22.246025,22.247081,22.248135,22.249188,22.250240,22.251291,22.252341,22.253390,22.254438,22.255484,22.256530,22.257574,22.258617,22.259660,22.260701,22.261741,22.262780,22.263818,22.264854,22.265890,22.266925,22.267958,22.268991,22.270022,22.271053,22.272082,22.273110,22.274138,22.275164,22.276189,22.277213,22.278236,22.279258,22.280279,22.281299,22.282318,22.283335,22.284352,22.285368,22.286383,22.287396,22.288409,22.289421,22.290431,22.291441,22.292449,22.293457,22.294463,22.295469,22.296473,22.297477,22.298479,22.299481,22.300482,22.301481,22.302480,22.303477,22.304474,22.305469,22.306464,22.307457,22.308450,22.309441,22.310432,22.311421,22.312410,22.313398,22.314384,22.315370,22.316355,22.317339,22.318321,22.319303,22.320284,22.321264,22.322243,22.323221,22.324198,22.325174,22.326149,22.327123,22.328097,22.329069,22.330040,22.331011,22.331980,22.332949,22.333916,22.334883,22.335849,22.336813,22.337777,22.338740,22.339702,22.340663,22.341623,22.342583,22.343541,22.344498,22.345455,22.346410,22.347365,22.348319,22.349272,22.350224,22.351175,22.352125,22.353074,22.354022,22.354970,22.355916,22.356862,22.357807,22.358750,22.359693,22.360635,22.361577,22.362517,22.363456,22.364395,22.365332,22.366269,22.367205,22.368140,22.369074,22.370008,22.370940,22.371871,22.372802,22.373732,22.374661,22.375589,22.376516,22.377443,22.378368,22.379293,22.380216,22.381139,22.382061,22.382983,22.383903,22.384823,22.385741,22.386659,22.387576,22.388492,22.389408,22.390322,22.391236,22.392149,22.393061,22.393972,22.394882,22.395792,22.396700,22.397608,22.398515,22.399421,22.400327,22.401231,22.402135,22.403038,22.403940,22.404842,22.405742,22.406642,22.407541,22.408439,22.409336,22.410232,22.411128,22.412023,22.412917,22.413810,22.414703,22.415594,22.416485,22.417375,22.418265,22.419153,22.420041,22.420928,22.421814,22.422699,22.423584,22.424467,22.425350,22.426233,22.427114,22.427995,22.428875,22.429754,22.430632,22.431510,22.432387,22.433263,22.434138,22.435012,22.435886,22.436759,22.437631,22.438503,22.439374,22.440243,22.441113,22.441981,22.442849,22.443716,22.444582,22.445447,22.446312,22.447176,22.448039,22.448902,22.449763,22.450624,22.451484,22.452344,22.453203,22.454061,22.454918,22.455774,22.456630,22.457485,22.458340,22.459193,22.460046,22.460898,22.461750,22.462600,22.463450,22.464300,22.465148,22.465996,22.466843,22.467689,22.468535,22.469380,22.470224,22.471068,22.471911,22.472753,22.473594,22.474435,22.475275,22.476114,22.476953,22.477791,22.478628,22.479464,22.480300,22.481135,22.481969,22.482803,22.483636,22.484468,22.485300,22.486131,22.486961,22.487791,22.488619,22.489448,22.490275,22.491102,22.491928,22.492753,22.493578,22.494402,22.495226,22.496048,22.496870,22.497692,22.498512,22.499332,22.500152,22.500970,22.501788,22.502606,22.503422,22.504238,22.505054,22.505868,22.506682,22.507496,22.508308,22.509120,22.509932,22.510742,22.511552,22.512362,22.513171,22.513979,22.514786,22.515593,22.516399,22.517204,22.518009,22.518813,22.519617,22.520420,22.521222,22.522024,22.522825,22.523625,22.524425,22.525224,22.526022,22.526820,22.527617,22.528414,22.529209,22.530005,22.530799,22.531593,22.532387,22.533179,22.533971,22.534763,22.535554,22.536344,22.537133,22.537922,22.538711,22.539498,22.540285,22.541072,22.541858,22.542643,22.543428,22.544212,22.544995,22.545778,22.546560,22.547342,22.548123,22.548903,22.549683,22.550462,22.551240,22.552018,22.552795,22.553572,22.554348,22.555124,22.555899,22.556673,22.557447,22.558220,22.558992,22.559764,22.560535,22.561306,22.562076,22.562846,22.563615,22.564383,22.565151,22.565918,22.566685,22.567451,22.568216,22.568981,22.569745,22.570509,22.571272,22.572034,22.572796,22.573557,22.574318,22.575078,22.575838,22.576597,22.577355,22.578113,22.578871,22.579627,22.580383,22.581139,22.581894,22.582648,22.583402,22.584156,22.584908,22.585660,22.586412,22.587163,22.587914,22.588663,22.589413,22.590162,22.590910,22.591657,22.592405,22.593151,22.593897,22.594643,22.595387,22.596132,22.596876,22.597619,22.598361,22.599104,22.599845,22.600586,22.601327,22.602066,22.602806,22.603545,22.604283,22.605021,22.605758,22.606495,22.607231,22.607966,22.608701,22.609436,22.610170,22.610903,22.611636,22.612368,22.613100,22.613831,22.614562,22.615292,22.616022,22.616751,22.617480,22.618208,22.618935,22.619662,22.620389,22.621115,22.621840,22.622565,22.623289,22.624013,22.624737,22.625459,22.626182,22.626903,22.627625,22.628345,22.629066,22.629785,22.630504,22.631223,22.631941,22.632659,22.633376,22.634093,22.634809,22.635524,22.636239,22.636954,22.637668,22.638381,22.639094,22.639807,22.640519,22.641230,22.641941,22.642652,22.643362,22.644071,22.644780,22.645489,22.646197,22.646904,22.647611,22.648317,22.649023,22.649729,22.650434,22.651138,22.651842,22.652546,22.653249,22.653951,22.654653,22.655355,22.656056,22.656756,22.657456,22.658156,22.658855,22.659554,22.660252,22.660949,22.661646,22.662343,22.663039,22.663735,22.664430,22.665125,22.665819,22.666513,22.667206,22.667899,22.668591,22.669283,22.669974,22.670665,22.671355,22.672045,22.672734,22.673423,22.674112,22.674800,22.675487,22.676174,22.676861,22.677547,22.678233,22.678918,22.679603,22.680287,22.680971,22.681654,22.682337,22.683019,22.683701,22.684382,22.685063,22.685744,22.686424,22.687104,22.687783,22.688461,22.689139,22.689817,22.690495,22.691171,22.691848,22.692524,22.693199,22.693874,22.694549,22.695223,22.695896,22.696569,22.697242,22.697914,22.698586,22.699258,22.699929,22.700599,22.701269,22.701939,22.702608,22.703276,22.703945,22.704612,22.705280,22.705947,22.706613,22.707279,22.707945,22.708610,22.709274,22.709939,22.710602,22.711266,22.711929,22.712591,22.713253,22.713915,22.714576,22.715237,22.715897,22.716557,22.717216,22.717875,22.718534,22.719192,22.719850,22.720507,22.721164,22.721820,22.722476,22.723131,22.723787,22.724441,22.725095,22.725749,22.726403,22.727056,22.727708,22.728360,22.729012,22.729663,22.730314,22.730964,22.731614,22.732264,22.732913,22.733562,22.734210,22.734858,22.735505,22.736152,22.736799,22.737445,22.738091,22.738736,22.739381,22.740026,22.740670,22.741314,22.741957,22.742600,22.743242,22.743884,22.744526,22.745167,22.745808,22.746449,22.747089,22.747728,22.748367,22.749006,22.749644,22.750282,22.750920,22.751557,22.752194,22.752830,22.753466,22.754102,22.754737,22.755371,22.756006,22.756640,22.757273,22.757906,22.758539,22.759171,22.759803,22.760435,22.761066,22.761697,22.762327,22.762957,22.763586,22.764216,22.764844,22.765473,22.766101,22.766728,22.767355,22.767982,22.768608,22.769234,22.769860,22.770485,22.771110,22.771734,22.772358,22.772982,22.773605,22.774228,22.774851,22.775473,22.776094,22.776716,22.777337,22.777957,22.778577,22.779197,22.779816,22.780435,22.781054,22.781672,22.782290,22.782908,22.783525,22.784141,22.784758,22.785374,22.785989,22.786605,22.787219,22.787834,22.788448,22.789062,22.789675,22.790288,22.790900,22.791512,22.792124,22.792736,22.793347,22.793957,22.794568,22.795178,22.795787,22.796397,22.797005,22.797614,22.798222,22.798830,22.799437,22.800044,22.800651,22.801257,22.801863,22.802468,22.803073,22.803678,22.804283,22.804887,22.805490,22.806094,22.806697,22.807299,22.807901,22.808503,22.809105,22.809706,22.810307,22.810907,22.811507,22.812107,22.812706,22.813305,22.813904,22.814502,22.815100,22.815697,22.816295,22.816892,22.817488,22.818084,22.818680,22.819275,22.819870,22.820465,22.821059,22.821653,22.822247,22.822840,22.823433,22.824026,22.824618,22.825210,22.825802,22.826393,22.826984,22.827574,22.828164,22.828754,22.829343,22.829933,22.830521,22.831110,22.831698,22.832286,22.832873,22.833460,22.834047,22.834633,22.835219,22.835805,22.836390,22.836975,22.837559,22.838144,22.838728,22.839311,22.839895,22.840478,22.841060,22.841642,22.842224,22.842806,22.843387,22.843968,22.844548,22.845129,22.845709,22.846288,22.846867,22.847446,22.848025,22.848603,22.849181,22.849758,22.850336,22.850912,22.851489,22.852065,22.852641,22.853217,22.853792,22.854367,22.854941,22.855515,22.856089,22.856663,22.857236,22.857809,22.858382,22.858954,22.859526,22.860097,22.860669,22.861239,22.861810,22.862380,22.862950,22.863520,22.864089,22.864658,22.865227,22.865795,22.866363,22.866931,22.867498,22.868065,22.868632,22.869199,22.869765,22.870330,22.870896,22.871461,22.872026,22.872590,22.873155,22.873718,22.874282,22.874845,22.875408,22.875971,22.876533,22.877095,22.877657,22.878218,22.878779,22.879340,22.879900,22.880460,22.881020,22.881579,22.882138,22.882697,22.883256,22.883814,22.884372,22.884929,22.885487,22.886043,22.886600,22.887156,22.887712,22.888268,22.888824,22.889379,22.889933,22.890488,22.891042,22.891596,22.892150,22.892703,22.893256,22.893808,22.894361,22.894913,22.895464,22.896016,22.896567,22.897118,22.897668,22.898218,22.898768,22.899318,22.899867,22.900416,22.900965,22.901513,22.902061,22.902609,22.903157,22.903704,22.904251,22.904797,22.905344,22.905890,22.906435,22.906981,22.907526,22.908071,22.908615,22.909160,22.909703,22.910247,22.910790,22.911333,22.911876,22.912419,22.912961,22.913503,22.914044,22.914585,22.915126,22.915667,22.916208,22.916748,22.917287,22.917827,22.918366,22.918905,22.919444,22.919982,22.920520,22.921058,22.921595,22.922133,22.922670,22.923206,22.923743,22.924279,22.924814,22.925350,22.925885,22.926420,22.926955,22.927489,22.928023,22.928557,22.929090,22.929623,22.930156,22.930689,22.931221,22.931753,22.932285,22.932817,22.933348,22.933879,22.934409,22.934940,22.935470,22.936000,22.936529,22.937058,22.937587,22.938116,22.938644,22.939172,22.939700,22.940228,22.940755,22.941282,22.941809,22.942335,22.942862,22.943387,22.943913,22.944438,22.944964,22.945488,22.946013,22.946537,22.947061,22.947585,22.948108,22.948631,22.949154,22.949677,22.950199,22.950721,22.951243,22.951764,22.952286,22.952807,22.953327,22.953848,22.954368,22.954888,22.955407,22.955927,22.956446,22.956965,22.957483,22.958002,22.958520,22.959037,22.959555,22.960072,22.960589,22.961105,22.961622,22.962138,22.962654,22.963169,22.963685,22.964200,22.964715,22.965229,22.965743,22.966257,22.966771,22.967285,22.967798,22.968311,22.968824,22.969336,22.969848,22.970360,22.970872,22.971383,22.971894,22.972405,22.972916,22.973426,22.973936,22.974446,22.974955,22.975465,22.975974,22.976483,22.976991,22.977499,22.978007,22.978515,22.979023,22.979530,22.980037,22.980543,22.981050,22.981556,22.982062,22.982568,22.983073,22.983578,22.984083,22.984588,22.985092,22.985597,22.986100,22.986604,22.987107,22.987611,22.988114,22.988616,22.989119,22.989621,22.990123,22.990624,22.991126,22.991627,22.992128,22.992628,22.993129,22.993629,22.994129,22.994628,22.995128,22.995627,22.996126,22.996624,22.997123,22.997621,22.998119,22.998616,22.999114,22.999611,23.000108,23.000604,23.001101,23.001597,23.002093,23.002588,23.003084,23.003579,23.004074,23.004569,23.005063,23.005557,23.006051,23.006545,23.007038,23.007532,23.008025,23.008517,23.009010,23.009502,23.009994,23.010486,23.010977,23.011469,23.011960,23.012450,23.012941,23.013431,23.013921,23.014411,23.014901,23.015390,23.015879,23.016368,23.016857,23.017345,23.017833,23.018321,23.018809,23.019296,23.019784,23.020271,23.020757,23.021244,23.021730,23.022216,23.022702,23.023187,23.023673,23.024158,23.024643,23.025127,23.025612,23.026096,23.026580,23.027063,23.027547,23.028030,23.028513,23.028996,23.029478,23.029961,23.030443,23.030924,23.031406,23.031887,23.032369,23.032849,23.033330,23.033810,23.034291,23.034771,23.035250,23.035730,23.036209,23.036688,23.037167,23.037646,23.038124,23.038602,23.039080,23.039558,23.040035,23.040512,23.040989,23.041466,23.041943,23.042419,23.042895,23.043371,23.043846,23.044322,23.044797,23.045272,23.045747,23.046221,23.046695,23.047169,23.047643,23.048117,23.048590,23.049063,23.049536,23.050009,23.050481,23.050954,23.051426,23.051898,23.052369,23.052841,23.053312,23.053783,23.054253,23.054724,23.055194,23.055664,23.056134,23.056603,23.057073,23.057542,23.058011,23.058480,23.058948,23.059416,23.059884,23.060352,23.060820,23.061287,23.061755,23.062221,23.062688,23.063155,23.063621,23.064087,23.064553,23.065019,23.065484,23.065949,23.066414,23.066879,23.067344,23.067808,23.068272,23.068736,23.069200,23.069663,23.070127,23.070590,23.071053,23.071515,23.071978,23.072440,23.072902,23.073364,23.073825,23.074287,23.074748,23.075209,23.075669,23.076130,23.076590,23.077050,23.077510,23.077970,23.078429,23.078889,23.079348,23.079806,23.080265,23.080723,23.081182,23.081640,23.082097,23.082555,23.083012,23.083469,23.083926,23.084383,23.084840,23.085296,23.085752,23.086208,23.086664,23.087119,23.087574,23.088029,23.088484,23.088939,23.089393,23.089848,23.090302,23.090755,23.091209,23.091662,23.092116,23.092569,23.093021,23.093474,23.093926,23.094379,23.094831,23.095282,23.095734,23.096185,23.096636,23.097087,23.097538,23.097989,23.098439,23.098889,23.099339,23.099789,23.100238,23.100688,23.101137,23.101586,23.102035,23.102483,23.102931,23.103380,23.103827,23.104275,23.104723,23.105170,23.105617,23.106064,23.106511,23.106957,23.107404,23.107850,23.108296,23.108741,23.109187,23.109632,23.110077,23.110522,23.110967,23.111412,23.111856,23.112300,23.112744,23.113188,23.113631,23.114075,23.114518,23.114961,23.115404,23.115846,23.116289,23.116731,23.117173,23.117615,23.118056,23.118498,23.118939,23.119380,23.119821,23.120261,23.120702,23.121142,23.121582,23.122022,23.122462,23.122901,23.123340,23.123779,23.124218,23.124657,23.125095,23.125534,23.125972,23.126410,23.126848,23.127285,23.127722,23.128160,23.128597,23.129033,23.129470,23.129906,23.130343,23.130779,23.131214,23.131650,23.132085,23.132521,23.132956,23.133391,23.133825,23.134260,23.134694,23.135128,23.135562,23.135996,23.136429,23.136863,23.137296,23.137729,23.138162,23.138594,23.139027,23.139459,23.139891,23.140323,23.140755,23.141186,23.141618,23.142049,23.142480,23.142910,23.143341,23.143771,23.144202,23.144632,23.145061,23.145491,23.145920,23.146350,23.146779,23.147208,23.147636,23.148065,23.148493,23.148922,23.149350,23.149777,23.150205,23.150632,23.151060,23.151487,23.151914,23.152340,23.152767,23.153193,23.153619,23.154045,23.154471,23.154897,23.155322,23.155748,23.156173,23.156598,23.157022,23.157447,23.157871,23.158295,23.158719,23.159143,23.159567,23.159990,23.160413,23.160837,23.161260,23.161682,23.162105,23.162527,23.162949,23.163371,23.163793,23.164215,23.164636,23.165058,23.165479,23.165900,23.166321,23.166741,23.167162,23.167582,23.168002,23.168422,23.168842,23.169261,23.169681,23.170100,23.170519,23.170938,23.171356,23.171775,23.172193,23.172611,23.173029,23.173447,23.173865,23.174282,23.174699,23.175117,23.175533,23.175950,23.176367,23.176783,23.177199,23.177616,23.178031,23.178447,23.178863,23.179278,23.179693,23.180108,23.180523,23.180938,23.181352,23.181767,23.182181,23.182595,23.183009,23.183422,23.183836,23.184249,23.184662,23.185075,23.185488,23.185901,23.186313,23.186725,23.187137,23.187549,23.187961,23.188373,23.188784,23.189195,23.189607,23.190017,23.190428,23.190839,23.191249,23.191660,23.192070,23.192480,23.192889,23.193299,23.193708,23.194118,23.194527,23.194936,23.195344,23.195753,23.196161,23.196570,23.196978,23.197386,23.197793,23.198201,23.198608,23.199016,23.199423,23.199830,23.200236,23.200643,23.201049,23.201456,23.201862,23.202268,23.202673,23.203079,23.203484,23.203890,23.204295,23.204700,23.205104,23.205509,23.205913,23.206318,23.206722,23.207126,23.207530,23.207933,23.208337,23.208740,23.209143,23.209546,23.209949,23.210352,23.210754,23.211156,23.211559,23.211961,23.212363,23.212764,23.213166,23.213567,23.213968,23.214369,23.214770,23.215171,23.215572,23.215972,23.216372,23.216772,23.217172,23.217572,23.217972,23.218371,23.218770,23.219169,23.219568,23.219967,23.220366,23.220764,23.221163,23.221561,23.221959,23.222357,23.222754,23.223152,23.223549,23.223946,23.224343,23.224740,23.225137,23.225534,23.225930,23.226326,23.226723,23.227119,23.227514,23.227910,23.228305,23.228701,23.229096,23.229491,23.229886,23.230281,23.230675,23.231070,23.231464,23.231858,23.232252,23.232646,23.233039,23.233433,23.233826,23.234219,23.234612,23.235005,23.235398,23.235790,23.236183,23.236575,23.236967,23.237359,23.237751,23.238142,23.238534,23.238925,23.239316,23.239707,23.240098,23.240489,23.240879,23.241270,23.241660,23.242050,23.242440,23.242830,23.243219,23.243609,23.243998,23.244387,23.244776,23.245165,23.245554,23.245943,23.246331,23.246719,23.247107,23.247495,23.247883,23.248271,23.248658,23.249046,23.249433,23.249820,23.250207,23.250594,23.250980,23.251367,23.251753,23.252139,23.252525,23.252911,23.253297,23.253683,23.254068,23.254453,23.254838,23.255223,23.255608,23.255993,23.256377,23.256762,23.257146,23.257530,23.257914,23.258298,23.258682,23.259065,23.259449,23.259832,23.260215,23.260598,23.260980,23.261363,23.261746,23.262128,23.262510,23.262892,23.263274,23.263656,23.264037,23.264419,23.264800,23.265181,23.265562,23.265943,23.266324,23.266705,23.267085,23.267465,23.267846,23.268226,23.268605,23.268985,23.269365,23.269744,23.270123,23.270503,23.270882,23.271260,23.271639,23.272018,23.272396,23.272774,23.273153,23.273531,23.273908,23.274286,23.274664,23.275041,23.275418,23.275796,23.276173,23.276549,23.276926,23.277303,23.277679,23.278055,23.278432,23.278808,23.279183,23.279559,23.279935,23.280310,23.280686,23.281061,23.281436,23.281811,23.282185,23.282560,23.282934,23.283309,23.283683,23.284057,23.284431,23.284805,23.285178,23.285552,23.285925,23.286298,23.286671,23.287044,23.287417,23.287790,23.288162,23.288535,23.288907,23.289279,23.289651,23.290023,23.290394,23.290766,23.291137,23.291509,23.291880,23.292251,23.292622,23.292992,23.293363,23.293733,23.294104,23.294474,23.294844,23.295214,23.295583,23.295953,23.296323,23.296692,23.297061,23.297430,23.297799,23.298168,23.298537,23.298905,23.299273,23.299642,23.300010,23.300378,23.300746,23.301113,23.301481,23.301848,23.302216,23.302583,23.302950,23.303317,23.303684,23.304050,23.304417,23.304783,23.305149,23.305515,23.305881,23.306247,23.306613,23.306979,23.307344,23.307709,23.308074,23.308439,23.308804,23.309169,23.309534,23.309898,23.310263,23.310627,23.310991,23.311355,23.311719,23.312082,23.312446,23.312809,23.313173,23.313536,23.313899,23.314262,23.314625,23.314987,23.315350,23.315712,23.316074,23.316437,23.316799,23.317160,23.317522,23.317884,23.318245,23.318607,23.318968,23.319329,23.319690,23.320051,23.320411,23.320772,23.321132,23.321493,23.321853,23.322213,23.322573,23.322932,23.323292,23.323652,23.324011,23.324370,23.324729,23.325088,23.325447,23.325806,23.326165,23.326523,23.326881,23.327240,23.327598,23.327956,23.328314,23.328671,23.329029,23.329386,23.329744,23.330101,23.330458,23.330815,23.331172,23.331528,23.331885,23.332241,23.332598,23.332954,23.333310,23.333666,23.334022,23.334377,23.334733,23.335088,23.335444,23.335799,23.336154,23.336509,23.336864,23.337218,23.337573,23.337927,23.338282,23.338636,23.338990,23.339344,23.339698,23.340051,23.340405,23.340758,23.341112,23.341465,23.341818,23.342171,23.342523,23.342876,23.343229,23.343581,23.343933,23.344286,23.344638,23.344990,23.345341,23.345693,23.346045,23.346396,23.346747,23.347098,23.347450,23.347800,23.348151,23.348502,23.348853,23.349203,23.349553,23.349904,23.350254,23.350604,23.350953,23.351303,23.351653,23.352002,23.352352,23.352701,23.353050,23.353399,23.353748,23.354096,23.354445,23.354794,23.355142,23.355490,23.355838,23.356186,23.356534,23.356882,23.357230,23.357577,23.357925,23.358272,23.358619,23.358966,23.359313,23.359660,23.360006,23.360353,23.360699,23.361046,23.361392,23.361738,23.362084,23.362430,23.362776,23.363121,23.363467,23.363812,23.364157,23.364502,23.364847,23.365192,23.365537,23.365882,23.366226,23.366571,23.366915,23.367259,23.367603,23.367947,23.368291,23.368635,23.368978,23.369322,23.369665,23.370008,23.370351,23.370694,23.371037,23.371380,23.371723,23.372065,23.372408,23.372750,23.373092,23.373434,23.373776,23.374118,23.374460,23.374801,23.375143,23.375484,23.375825,23.376166,23.376507,23.376848,23.377189,23.377530,23.377870,23.378211,23.378551,23.378891,23.379231,23.379571,23.379911,23.380251,23.380590,23.380930,23.381269,23.381608,23.381948,23.382287,23.382626,23.382964,23.383303,23.383642,23.383980,23.384319,23.384657,23.384995,23.385333,23.385671,23.386009,23.386346,23.386684,23.387021,23.387359,23.387696,23.388033,23.388370,23.388707,23.389043,23.389380,23.389717,23.390053,23.390389,23.390726,23.391062,23.391398,23.391733,23.392069,23.392405,23.392740,23.393076,23.393411,23.393746,23.394081,23.394416,23.394751,23.395086,23.395420,23.395755,23.396089,23.396424,23.396758,23.397092,23.397426,23.397760,23.398093,23.398427,23.398760,23.399094};
double sum,k;
int main(){
	scanf("%d",&n);
	sum=E[n/val];
	for(int i=n/val*val+1;i<=n;++i){
		if(i!=1) k=(sum+i)/(i-1);
		else k=0;
		sum+=k;
	}
	printf("%.5lf",k);
	return 0;
}
