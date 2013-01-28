#ifndef MIDI_H
#define MIDI_H

#include "RtMidi.h"
#include "ofMain.h"
#include "ofEvents.h"

class ofxRtFloatValue{
public:
	ofxRtFloatValue(int _port, float _value){
		port = _port;
		value = _value;
	};
	float value;
	int port;
};

class ofxRtMidi
{
public:	
	ofxRtMidi();
	~ofxRtMidi();
	
	void setup(int port=1);
	void update();
	float getFloatValue(int port);
	
	ofEvent<ofxRtFloatValue> floatEvent;
	
private:
	RtMidiIn *midiin;
	std::map<int, int> values;
};

#endif // MIDI_H
