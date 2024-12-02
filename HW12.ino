int yes = 10;
int no = 4;

int nClicks;
int pv2;

void setup() {
  Serial.begin(9600);
  pinMode(yes, OUTPUT);
  pinMode(no, OUTPUT);
  pinMode(12, INPUT);

  nClicks = 0;
  pv2 = 0;
}

void loop() {
  int energy = analogRead(A3);
  int light = analogRead(A1);
  int v2 = digitalRead(12);

  if (v2 == 1 && pv2 == 0) {
    nClicks++;
  }

  pv2 = v2;

 if (nClicks == 3 && energy == 4095 && light == 0) {
    digitalWrite(yes, HIGH);
    digitalWrite(no, LOW);
  } else {
    digitalWrite(no, HIGH);
    digitalWrite(yes, LOW);
  }

  // Serial.println(nClicks);
  // Serial.println(light);
  // Serial.println(energy);
  delay(1);
}
