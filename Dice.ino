//Dice.ino

byte ledPin[] = {13, 3, 4, 5, 6, 7, 8}; //die Onboard LED ist 0 im Array
byte button = 12; //da ist der Taster dran

void setup() {
//LED Pins auf Ausgang
	for (int i = 0; i < 7; i++) {
		pinMode(ledPin[i], OUTPUT);
	}

//button Pin auf Eingang
	pinMode(button, INPUT);

//alle LEDs aus
	for (int i = 0; i < 7; i++) {
		digitalWrite(ledPin[i], LOW);
		//randomSeed(millis());
	}
	randomSeed(analogRead(0)); // Noise als Initialisierung
	Serial.begin(9600); //zur Ausgabe der Zufallszahl auf der Konsole
}

void loop() {
//Button auslesen
	int state = digitalRead(button);
	if (state == HIGH) {
		rollthedice();  //würfeln
  	}
}

void rollthedice() {
	int dice = random(1, 7); //komisch, aber random(1,6) liefert keine 6! Arduino und Clones verhalten sich hier gleich
	Serial.println(dice); //gibt die Zufallzahl auf der Konsole aus
	clearLed();
	delay(1000);
	showLed(dice);	
}

void clearLed() {
	for (int i = 1; i < 7; i++) {
		digitalWrite(ledPin[i], LOW);
	}
}

void showLed(int eyes) {
	for (int i = 1; i < (eyes + 1); i++) {
		digitalWrite(ledPin[i], HIGH);
	}
}
