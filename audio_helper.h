#include <sndfile.h>
#include <portaudio.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define OUT_CHANNELS 2
#define IN_CHANNELS 2
#define SAMPLE_RATE 48000
#define BUFFER 256
#define MONO 1
#define STEREO 2

#define PI 3.14159265358979323846264338327950288

using namespace std;

typedef struct {
    SNDFILE *file;
    SF_INFO info;
} SF_Container;

typedef enum _WindowType {
    Rect,
    Hamming,
    Hann,
    Cosine
} WindowType;

typedef enum {
	File,
	Mic // "Line" is taken...
} InputSource;

PaStreamParameters getStreamParams(bool output);
float window(float sample, int index, int width, WindowType windowType);
bool printError(PaError error, string msg);

bool startAudio(PaStream *stream, const char* filename, const char* windowname);
void endAudio(PaStream *stream);
