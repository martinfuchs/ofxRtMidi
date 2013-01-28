#include "ofxRtMidi.h"


ofxRtMidi::ofxRtMidi()
{

}

ofxRtMidi::~ofxRtMidi()
{
	delete midiin;
}

/*void midiCallback( double deltatime, std::vector< unsigned char > *message, void *userData )
{
  /*unsigned int nBytes = message->size();
  for ( unsigned int i=0; i<nBytes; i++ )
    std::cout << "Byte " << i << " = " << (int)message->at(i) << ", ";
  if ( nBytes > 0 )
    std::cout << "stamp = " << deltatime << std::endl;

	if(message->size()>2){
		//cout << (int)message->at(2) << endl;
	}
}*/

void ofxRtMidi::setup(int port)
{
	try {
		// RtMidiIn constructor
		midiin = new RtMidiIn();

		std::string portName;
		unsigned int nPorts = midiin->getPortCount();
		if ( nPorts == 0 ) {
			ofLogError("No input ports available!");
			return;
		}
		
		cout << midiin->getPortCount() << endl;

		midiin->openPort(port);

		// Set our callback function.  This should be done immediately after
		// opening the port to avoid having incoming messages written to the
		// queue instead of sent to the callback function.
		// midiin->setCallback( &midiCallback );
		// Don't ignore sysex, timing, or active sensing messages.
		midiin->ignoreTypes( false, false, false );

	} catch ( RtError &error ) {
		error.printMessage();
	}
}

void ofxRtMidi::update()
{
	std::vector<unsigned char> msg;
	do {
		midiin->getMessage(&msg);
		if(msg.size()>2) {
			int port = (int)msg[1];
			int val = (int)msg[2];
			
			//cout << "MIDI IN port: "<< port << ", value: " << val << endl;
			values[port] = val;
			ofxRtFloatValue fEvent(port, ofMap(val, 0, 127, 0, 1));
			ofNotifyEvent(floatEvent,fEvent,this);
		}
	} while(msg.size()!=0);
}

float ofxRtMidi::getFloatValue(int port){
	return ofMap(values[port], 0, 127, 0, 1);
}
