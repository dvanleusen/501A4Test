/**
* Assignment 4
* @author Daniel Van Leusen
* Student id: 10064708
* E-mail: danvanleusen@yahoo.co.uk
* @version Dec 8, 2016
* <p>
* This is a simple object with only primitive for instance variable.
*/

#include "501A4.h"
#include <stdio.h>
#include <assert.h>
#ifdef USE_Test

char* readFile(char * filename)
{
	FILE* file = fopen(filename, "rb");
	
	if (file != NULL) {
		//get file bytes length
		fseek(file, 0, SEEK_END);
		long int  size = ftell(file);
		char *r=new char[size];
		fread(r, sizeof(BYTE), size, file);
		return r;
	}
	else return "";
}

void testWaveFile(char* inputFileName, char* outputFileName) {
	
	//char* filename = "test.wav";
	WaveFile w_DryRecording;
	w_DryRecording.ReadWaveFile(inputFileName);
	w_DryRecording.WriteWaveFile(outputFileName);
	WaveFile w_Test;
	w_Test.ReadWaveFile(outputFileName);
	LPBYTE lpwD = w_DryRecording.GetData();
	long lpwDSize = (long)w_DryRecording.GetSize();
	LPBYTE lpwT = w_Test.GetData();
	long lpwTSize = (long)w_Test.GetSize();
	bool b = true;
	if (lpwDSize != lpwTSize)
		b = false;
	else {
		for (int i = 0; i<lpwDSize; i++)
			if (lpwT[i] != lpwT[i]) {
				b = false;
				break;
			}
	}
	assert(b);
}
void testConvolve(char* inputFileName, char* outputFileName,bool bLevel1) {
	WaveFile w_DryRecording;
	w_DryRecording.ReadWaveFile(inputFileName);
	w_DryRecording.Convolve("im_BIGHALLE001M2S.wav","test.wav", bLevel1);
}
void main(int argc, char *argv[])
{
	char* inFileName = "DrumsDry.wav";
	char* outFileName = "test.wav";
	//testWaveFile(inFileName, outFileName);
	testConvolve(inFileName, outFileName,true);
}
#endif