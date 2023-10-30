#include <Arduino.h>

#define PinDeInterrupcion 13
#define DisparoDelSCR 4
#define Potenciometro A0

int ValorDelPotenciometro = 0;
int Retardo = 0;
int TiempoDisparoDelSCR = 100;

void ICACHE_RAM_ATTR InterrupcionExternaCrucePorCero();

void InterrupcionExternaCrucePorCero()
{
	delayMicroseconds(Retardo);
	digitalWrite(DisparoDelSCR, HIGH);
	delayMicroseconds(TiempoDisparoDelSCR);
	digitalWrite(DisparoDelSCR, LOW);
}

void setup()
{
	pinMode(PinDeInterrupcion, INPUT_PULLUP);
	attachInterrupt(digitalPinToInterrupt(PinDeInterrupcion), InterrupcionExternaCrucePorCero, RISING);
	pinMode(DisparoDelSCR, OUTPUT);
	pinMode(Potenciometro, INPUT);
}

void loop()
{
	ValorDelPotenciometro = analogRead(Potenciometro);
	Retardo = map(ValorDelPotenciometro, 0, 1023, 1150, 8150);
}