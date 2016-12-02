#ifndef _SNnube_
#define _SNnube_

#include <Arduino.h>
#include <SoftwareSerial.h>
#include <SPI.h>
#include <Ethernet.h>
#include "EthernetClient.h"
#include "string.h"

extern "C" {
	#include "string.h"
}

class SNnube
{
	public:
		SNnube();
		SNnube(const char *llave);
		~SNnube();

		void AddParameter(const char* key, const String &value);
		void AddParameter(const char* key, const char* value);
		void AddParameter(const char* key, char* value);
		void AddParameter(const char* key, char value);
		void AddParameter(const char* key, unsigned char value);
		void AddParameter(const char* key, int value);
		void AddParameter(const char* key, unsigned int value);
		void AddParameter(const char* key, long value);
		void AddParameter(const char* key, unsigned long value);
		void AddParameter(const char* key, float value);
		void AddParameter(const char* key, double value);
		void AddParameter(const char* key, const __FlashStringHelper * value);

		void AddParameter(const __FlashStringHelper * key, const String &value);
		void AddParameter(const __FlashStringHelper * key, const char* value);
		void AddParameter(const __FlashStringHelper * key, char* value);
		void AddParameter(const __FlashStringHelper * key, char value);
		void AddParameter(const __FlashStringHelper * key, unsigned char value);
		void AddParameter(const __FlashStringHelper * key, int value);
		void AddParameter(const __FlashStringHelper * key, unsigned int value);
		void AddParameter(const __FlashStringHelper * key, long value);
		void AddParameter(const __FlashStringHelper * key, unsigned long value);
		void AddParameter(const __FlashStringHelper * key, float value);
		void AddParameter(const __FlashStringHelper * key, double value);
		void AddParameter(const __FlashStringHelper * key, const __FlashStringHelper * value);

		int Begin(uint8_t *mac_address);
		void Begin(uint8_t *mac_address, IPAddress ip);
		void Close();
		void Read(char* resp, int maxLen);
		int Send();
		void SetLlave(const char* llave);

	private:
		const char* _llave;
		int _paramCount;
		String _data;
		EthernetClient _client;

		void AddParameterFirst(const char* key);
		void AddParameterFirst(const __FlashStringHelper * key);
		void AddParameterSecond();
};

#endif