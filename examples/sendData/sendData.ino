#include <SNnube.h>

#define DELAYTIME 100
#define MAX_SIZE 150

// Variable auxiliar
unsigned long lastConnectionTime = 0;

// intervalo de llamado a la funcion Request
const unsigned long postingInterval = 5L * 1000L;

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED }; // mac
IPAddress ip(192,168,137,2); // ip

// Declaramos el objeto SNnube con nuestra llave de acceso
SNnube client("llave");

// Definimos un buffer donde se guarda la respuesta del servidor (opcional)
char buffer[MAX_SIZE];

void setup() {
	// Iniciamos el puerto de comunicacion serie
	Serial.begin(9600);
	Serial.println("Iniciando");

	// Iniciamos el objeto SNnube
	if (client.Begin(mac) == 0) {
		Serial.println("No se pudo conectar");

		// Si no pudo obtener una ip automaticamente
		// definimos la ip que va a tener
		client.Begin(mac, ip);
	}
	else {
		Serial.println("Conectado");
	}

	delay(2000);
}

void loop() {
	// Cada x segundos, se llama a la funcion Request
	if (millis() - lastConnectionTime > postingInterval) {
		Request();
		lastConnectionTime = millis();
	}

	delay(DELAYTIME);
}

void Request() {
	// Añadimos las variables a enviar
	// Primero va el nombre de la variable tal cual esta definida en la pagina
	// El segundo es el valor de la variable
	client.AddParameter("temp", 12);
	client.AddParameter("humed", 57);

	// Enviamos la informacion
	client.Send();

	delay(1000);

	// Leemos la respuesta del servidor
	client.Read(buffer, MAX_SIZE);

	delay(1000);

	// Cerramos la conexion
	client.Close();
}