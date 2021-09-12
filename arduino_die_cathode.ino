/**
 * Arduino Die Roller
 * 
 * Hardware:
 * - Arduino
 * - Common Cathode 7 Segment Display
 * - 21 jumper wires (male to male)
 * - tactile button
 * - 10k ohm resistor
 * - 1k ohm resistor
 * 
 * Tested with Arduino Nano, but compatible with all Arduino boards.
 * See README for pinout used with this code.
 * 
 * (c) Romein van Buren 2021.
 * MIT lisenced.
 */

/**
 * Define segment pins
 */
int seg_a = 11;
int seg_b = 10;
int seg_c = 9;
int seg_d = 8;
int seg_e = 7;
int seg_f = 6;
int seg_g = 5;

/**
 * Sensor pin
 */
int btn = 2;

/**
 * Our integer which will be displayed on the sevseg display
 */
int i = 0;

/**
 * Setup
 */
void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(A0));
  Serial.println("EVENT: Startup complete");

  /**
   * Init pins
   */
  pinMode(seg_a, OUTPUT); 
  pinMode(seg_b, OUTPUT);
  pinMode(seg_c, OUTPUT);
  pinMode(seg_d, OUTPUT);
  pinMode(seg_e, OUTPUT);
  pinMode(seg_f, OUTPUT);
  pinMode(seg_g, OUTPUT);
}

/**
 * Loop
 */
void loop() {
  loading();
  
  if(digitalRead(btn) == HIGH) {

    /**
     * Choose a random number
     */
    i = random(1, 7);
    Serial.print("EVENT: Button pressed. Chose: ");
    Serial.println(i);

    /**
     * "Roll" the die
     */
    loading();
    Serial.println("EVENT: Roll complete");

    /**
     * Display the output
     */
    output();
    Serial.println("EVENT: Output displayed");
  }
}

/**
 * Light up corresponding LED on the sevseg display
 */
void output() {
  if(i == 1){
   digitalWrite(seg_a, LOW);
   digitalWrite(seg_b, HIGH);
   digitalWrite(seg_c, HIGH);
   digitalWrite(seg_d, LOW);
   digitalWrite(seg_e, LOW);
   digitalWrite(seg_f, LOW);
   digitalWrite(seg_g, LOW);
   delay(1000);
  }
  else if(i == 2){
   digitalWrite(seg_a, HIGH);
   digitalWrite(seg_b, HIGH);
   digitalWrite(seg_c, LOW);
   digitalWrite(seg_d, HIGH);
   digitalWrite(seg_e, HIGH);
   digitalWrite(seg_f, LOW);
   digitalWrite(seg_g, HIGH);
   delay(1000);
  } 
  else if(i == 3){
   digitalWrite(seg_a, HIGH);
   digitalWrite(seg_b, HIGH);
   digitalWrite(seg_c, HIGH);
   digitalWrite(seg_d, HIGH);
   digitalWrite(seg_e, LOW);
   digitalWrite(seg_f, LOW);
   digitalWrite(seg_g, HIGH);
   delay(1000);
  }  
  else if(i == 4){
   digitalWrite(seg_a, LOW);
   digitalWrite(seg_b, HIGH);
   digitalWrite(seg_c, HIGH);
   digitalWrite(seg_d, LOW);
   digitalWrite(seg_e, LOW);
   digitalWrite(seg_f, HIGH);
   digitalWrite(seg_g, HIGH);
   delay(1000);
  }
  else if(i == 5){
   digitalWrite(seg_a, HIGH);
   digitalWrite(seg_b, LOW);
   digitalWrite(seg_c, HIGH);
   digitalWrite(seg_d, HIGH);
   digitalWrite(seg_e, LOW);
   digitalWrite(seg_f, HIGH);
   digitalWrite(seg_g, HIGH);
   delay(1000);
  }
  else if(i == 6){
   digitalWrite(seg_a, HIGH);
   digitalWrite(seg_b, LOW);
   digitalWrite(seg_c, HIGH);
   digitalWrite(seg_d, HIGH);
   digitalWrite(seg_e, HIGH);
   digitalWrite(seg_f, HIGH);
   digitalWrite(seg_g, HIGH);
   delay(1000);
  }
}

/**
 * Loading indicator
 */
void loading() {
  digitalWrite(seg_a, HIGH);
  digitalWrite(seg_b, LOW);
  digitalWrite(seg_c, LOW);
  digitalWrite(seg_d, LOW);
  digitalWrite(seg_e, LOW);
  digitalWrite(seg_f, LOW);
  digitalWrite(seg_g, LOW);
  delay(100);
  
  digitalWrite(seg_a, LOW);
  digitalWrite(seg_b, HIGH);
  digitalWrite(seg_c, LOW);
  digitalWrite(seg_d, LOW);
  digitalWrite(seg_e, LOW);
  digitalWrite(seg_f, LOW);
  digitalWrite(seg_g, LOW);
  delay(100);

  digitalWrite(seg_a, LOW);
  digitalWrite(seg_b, LOW);
  digitalWrite(seg_c, HIGH);
  digitalWrite(seg_d, LOW);
  digitalWrite(seg_e, LOW);
  digitalWrite(seg_f, LOW);
  digitalWrite(seg_g, LOW);
  delay(100);

  digitalWrite(seg_a, LOW);
  digitalWrite(seg_b, LOW);
  digitalWrite(seg_c, LOW);
  digitalWrite(seg_d, HIGH);
  digitalWrite(seg_e, LOW);
  digitalWrite(seg_f, LOW);
  digitalWrite(seg_g, LOW);
  delay(100);

  digitalWrite(seg_a, LOW);
  digitalWrite(seg_b, LOW);
  digitalWrite(seg_c, LOW);
  digitalWrite(seg_d, LOW);
  digitalWrite(seg_e, HIGH);
  digitalWrite(seg_f, LOW);
  digitalWrite(seg_g, LOW);
  delay(100);

  digitalWrite(seg_a, LOW);
  digitalWrite(seg_b, LOW);
  digitalWrite(seg_c, LOW);
  digitalWrite(seg_d, LOW);
  digitalWrite(seg_e, LOW);
  digitalWrite(seg_f, HIGH);
  digitalWrite(seg_g, LOW);
  delay(100);
}
