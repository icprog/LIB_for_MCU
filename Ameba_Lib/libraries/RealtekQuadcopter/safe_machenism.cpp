/*
The safe_machenism.cpp is placed under the MIT license

Copyright (c) 2016 Wu Tung Cheng, Realtek

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

Notes:
1. This quadcopter project is adapted from Raspberry Pilot (Github: https://github.com/jellyice1986/RaspberryPilot).

*/

#include "safe_machenism.h"


static int packetAccCounter;


bool packetAccCounterInit(){
	resetPacketAccCounter();
	return true;
}
void decreasePacketAccCounter(){
	packetAccCounter--;
	if(packetAccCounter<MIN_COUNTER)
		packetAccCounter=0;	
}

void increasePacketAccCounter(){
	packetAccCounter++;
	if(packetAccCounter>MAX_COUNTER)
		packetAccCounter=MAX_COUNTER;
	//printf("getPacketAccCounter=%d\n",getPacketAccCounter());
}

void resetPacketAccCounter(){
	packetAccCounter=0;
}

int getPacketAccCounter(){
	return packetAccCounter<0?0:packetAccCounter;
}

