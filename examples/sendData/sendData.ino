#include <SNnube.h>

#define DELAYTIME 100
#define MAX_SIZE 150

unsigned long lastConnectionTime = 0;
const unsigned long postingInterval = 5L * 1000L;

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

SNnube client("algonose");

char buffer[MAX_SIZE];

void setup() {
	Serial.begin(9600);

	client.Begin(mac);

	Serial.println("1");
	delay(1000);
	Serial.println("2");
	delay(1000);
	Serial.println("3");
	delay(1000);
}

void loop() {
	if (millis() - lastConnectionTime > postingInterval) {
		Request();
		lastConnectionTime = millis();
	}
	delay(DELAYTIME);
}

void Request() {
	char param1[] = "temp";
	char param1val[] = "12";
	char param2[] = "humed";
	char param2val[] = "89";

	client.AddParameter(param1, param1val);
	client.AddParameter(param2, param2val);
	client.AddParameter(F("tercer"), "1024");

	client.Send();

	delay(1000);

	client.Read(buffer, MAX_SIZE);

	delay(1000);

	client.Close();
}