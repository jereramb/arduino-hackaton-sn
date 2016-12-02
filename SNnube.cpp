#include "SNnube.h"

SNnube::SNnube() : _paramCount(0) {}

SNnube::SNnube(const char *llave) : _llave(llave), _paramCount(0) {}

SNnube::~SNnube() {}

void SNnube::AddParameterFirst(const char* key) {
	if (_paramCount == 0) {
		_data = "{";
	}
	else {
		_data += ",";
	}

	_data += "\"";
	_data += key;
	_data += "\":\"";
}

void SNnube::AddParameterFirst(const __FlashStringHelper * key) {
	if (_paramCount == 0) {
		_data = "{";
	}
	else {
		_data += ",";
	}

	_data += "\"";
	_data += key;
	_data += "\":\"";
}

void SNnube::AddParameterSecond() {
	_data += "\"";
	_paramCount++;
}

void SNnube::AddParameter(const char* key, const String &value) {
	AddParameterFirst(key);
	_data += value;
	AddParameterSecond();
}

void SNnube::AddParameter(const char* key, const char* value) {
	AddParameterFirst(key);
	_data += value;
	AddParameterSecond();
}

void SNnube::AddParameter(const char* key, char* value) {
	AddParameterFirst(key);
	_data += value;
	AddParameterSecond();
}

void SNnube::AddParameter(const char* key, char value) {
	AddParameterFirst(key);
	_data += value;
	AddParameterSecond();
}

void SNnube::AddParameter(const char* key, unsigned char value) {
	AddParameterFirst(key);
	_data += value;
	AddParameterSecond();
}

void SNnube::AddParameter(const char* key, int value) {
	AddParameterFirst(key);
	_data += value;
	AddParameterSecond();
}

void SNnube::AddParameter(const char* key, unsigned int value) {
	AddParameterFirst(key);
	_data += value;
	AddParameterSecond();
}

void SNnube::AddParameter(const char* key, long value) {
	AddParameterFirst(key);
	_data += value;
	AddParameterSecond();
}

void SNnube::AddParameter(const char* key, unsigned long value) {
	AddParameterFirst(key);
	_data += value;
	AddParameterSecond();
}

void SNnube::AddParameter(const char* key, float value) {
	AddParameterFirst(key);
	_data += value;
	AddParameterSecond();
}

void SNnube::AddParameter(const char* key, double value) {
	AddParameterFirst(key);
	_data += value;
	AddParameterSecond();
}

void SNnube::AddParameter(const char* key, const __FlashStringHelper * value) {
	AddParameterFirst(key);
	_data += value;
	AddParameterSecond();
}

void SNnube::AddParameter(const __FlashStringHelper * key, const String &value) {
	AddParameterFirst(key);
	_data += value;
	AddParameterSecond();
}

void SNnube::AddParameter(const __FlashStringHelper * key, const char* value) {
	AddParameterFirst(key);
	_data += value;
	AddParameterSecond();
}

void SNnube::AddParameter(const __FlashStringHelper * key, char* value) {
	AddParameterFirst(key);
	_data += value;
	AddParameterSecond();
}

void SNnube::AddParameter(const __FlashStringHelper * key, char value) {
	AddParameterFirst(key);
	_data += value;
	AddParameterSecond();
}

void SNnube::AddParameter(const __FlashStringHelper * key, unsigned char value) {
	AddParameterFirst(key);
	_data += value;
	AddParameterSecond();
}

void SNnube::AddParameter(const __FlashStringHelper * key, int value) {
	AddParameterFirst(key);
	_data += value;
	AddParameterSecond();
}

void SNnube::AddParameter(const __FlashStringHelper * key, unsigned int value) {
	AddParameterFirst(key);
	_data += value;
	AddParameterSecond();
}

void SNnube::AddParameter(const __FlashStringHelper * key, long value) {
	AddParameterFirst(key);
	_data += value;
	AddParameterSecond();
}

void SNnube::AddParameter(const __FlashStringHelper * key, unsigned long value) {
	AddParameterFirst(key);
	_data += value;
	AddParameterSecond();
}

void SNnube::AddParameter(const __FlashStringHelper * key, float value) {
	AddParameterFirst(key);
	_data += value;
	AddParameterSecond();
}

void SNnube::AddParameter(const __FlashStringHelper * key, double value) {
	AddParameterFirst(key);
	_data += value;
	AddParameterSecond();
}

void SNnube::AddParameter(const __FlashStringHelper * key, const __FlashStringHelper * value) {
	AddParameterFirst(key);
	_data += value;
	AddParameterSecond();
}

int SNnube::Begin(uint8_t *mac_address) {
	return Ethernet.begin(mac_address);
}

void SNnube::Begin(uint8_t *mac_address, IPAddress ip) {
	Ethernet.begin(mac_address, ip); 
}

void SNnube::Close() {
	if (!_client.connected()) {
		_client.stop();
	}
	else {
		_client.stop();
	}
}

void SNnube::Read(char* resp, int maxLen) {
	bool cont = true;
	int i = 0;
	unsigned int timeout = 3000;
	unsigned long int prevTimel = millis();

	while (cont && ((millis() - prevTimel) < timeout) && (i < (maxLen - 2))) {
		if (_client.available() > 0) {
			resp[i] = _client.read();
			i++;
		}

		if (i > 0) {
			if (resp[i-1] == '\n') {
				cont = false;
			}
		}
	}

	if (i > 0) {
		resp[i-1] = '\0';
	}

	while(_client.available() > 0) {
		_client.read();
	}
}

int SNnube::Send() {
	if (_paramCount > 0) {
		AddParameter("llave", _llave);
		_data += "}";
	}
	else {
		return -1;
	}

	// IPAddress ip(192, 168, 1, 10);
	char server[] = "snenlanube.com.ar";

	if (_client.connect(server, 9000)) {
		_client.print(_data);
	}

	_data = "";
	_paramCount = 0;
}

void SNnube::SetLlave(const char* llave) {
	_llave = llave;
}