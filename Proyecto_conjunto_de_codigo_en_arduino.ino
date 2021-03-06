/* Main.ino file generated by New Project  wizard Arduino Mega 2560

   Created:   March 2022
   Processor: ATmega2560
   Compiler:  Arduino AVR
*/




// Arduino example code Ultrasonic
#define ECHOPIN 8                            // Pin to receive echo pulse
#define TRIGPIN 9                            // Pin to send trigger pulse
// Arduino example code Ultrasonic


// Arduino example code  Thermocouple
int     analogPin = A0;
int     val = 0;      // variable to store the value read
float   temperature;  // Temperature value in celsius degree.
float   gain = 0.00488;
float   ref  =  1.25313;
// Arduino example code  Thermocouple


// Arduino example code  Thermistor
// which analog pin to connect
#define THERMISTORPIN 1
// resistance at 25 degrees C
#define THERMISTORNOMINAL 200
// temp. for nominal resistance (almost always 25 C)
#define TEMPERATURENOMINAL 25
// how many samples to take and average, more takes longer
// but is more 'smooth'
#define NUMSAMPLES 5
// The beta coefficient of the thermistor (usually 3000-4000)
#define BCOEFFICIENT 3950
// the value of the 'other' resistor
#define SERIESRESISTOR 10000
int samples[NUMSAMPLES];
// Arduino example code  Thermistor


//Arduino example code  Shunt current sensor Plan A  
  //Abhishek Tiwari
int analog = 0; //Avoid Garbage Values
int analog2 = 0;//Avoid Garbage Values
float Volt; // measured Voltage
float R1 = 56000; // pull up resistor 56k
float R2 = 11500; // pull down resistor 11.5k(4.7k+6.8k)
float current;

//Arduino example code  Shunt current sensor Plan A


//Arduino example code  Shunt current sensor Plan AA
  
int current_sense  = A6;
  
//Arduino example code  Shunt current sensor Plan AA


//Arduino example code  Shunt current sensor Plan B

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4); //sometimes the adress is not 0x3f. Change to 0x27 if it dosn't work.

int analogInput300 = A8; //Connect the output of the 300 gain amplifier to this pin
int analogInput50 = A9; //Connect the output of the 50 gain amplifier to this pin
int button1 = 52;
int button2 = 53;

int readAmpsADC = 0;
float voltage = 0.0;
float amps = 0.0;
int scale = 0;
int offset = 0;

//Arduino example code  Shunt current sensor Plan B


  //Arduino example code  Voltage sensor Plan B
  
int analogInput=A5;
float vout;
float vin;
float r1 = 100000.0;
float r2 = 10000.0;
int value;

  
  //Arduino example code  Voltage sensor Plan B



//Arduino example code LM35 electronic temp sensor  

int Value;
int tempPin = A4;
 
//Arduino example code LM35 electronic temp sensor 


//Arduino example code DHT electronic temp sensor

#include <DHT.h>

#define DHTPIN 13     // what pin we're connected to

#define DHTTYPE DHT11   // DHT 22  (AM2302)
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

// Connect pin 1 (on the left) of the sensor to +5V
// NOTE: If using a board with 3.3V logic like an Arduino Due connect pin 1
// to 3.3V instead of 5V!
// Connect pin 2 of the sensor to whatever your DHTPIN is
// Connect pin 4 (on the right) of the sensor to GROUND
// Connect a 10K resistor from pin 2 (data) to pin 1 (power) of the sensor

// Initialize DHT sensor for normal 16mhz Arduino
// **** NOTE: the Proteus virtual board runs at 8MHz so the threshols parameter should be passed is 4 ****
DHT dht(DHTPIN, DHTTYPE, 6);
// NOTE: For working with a faster chip, like an Arduino Due or Teensy, you
// might need to increase the threshold for cycle counts considered a 1 or 0.
// You can do this by passing a 3rd parameter for this threshold.  It's a bit
// of fiddling to find the right value, but in general the faster the CPU the
// higher the value.  The default for a 16mhz AVR is a value of 6.  For an
// Arduino Due that runs at 84mhz a value of 30 works.
// Example to initialize DHT sensor for Arduino Due:
//DHT dht(DHTPIN, DHTTYPE, 30);

//Arduino example code DHT electronic temp sensor


// Arduino example code Encoder

#define outputA 11
#define outputB 12
#define button 10

int counter = 50;
int aState;
int aLastState;

// the follow variables is a long because the time, measured in miliseconds
// will quickly become a bigger number than can be stored in an int.

long interval = 20; // interval at which to blink (milliseconds)

// Arduino example code Encoder



// Arduino example code LDR Sensor ####################################

const long LDR_A = 1000;     //Resistencia en oscuridad en KO
const int LDR_B = 15;        //Resistencia a la luz (10 Lux) en KO
const int LDR_Rc = 10;       //Resistencia calibracion en KO
const int LDRPin = A11;   //Pin del LDR

int LDR_V;
int LDR_ilum;

// Arduino example code LDR Sensor ####################################


// Arduino example code Anemometro ###################################

float ANPin= A12;
float AN_V;
float AN_vel;

// Arduino example code Anemometro ###################################

void setup() {

  Serial.begin(9600);

  // Arduino example code Ultrasonic
  pinMode(ECHOPIN, INPUT);
  pinMode(TRIGPIN, OUTPUT);
  // Arduino example code Ultrasonic

  //Arduino example code  Voltage sensor Plan B
  
  pinMode(analogInput, INPUT);

  //Arduino example code  Voltage sensor Plan B
  
  
  //Arduino example code DHT electronic temp sensor       

  dht.begin();

//Arduino example code DHT electronic temp sensor       



 // Arduino example code Encoder

pinMode (outputA, INPUT);
pinMode (outputB, INPUT);
pinMode (button, INPUT);

// Reads the initial state of the output A
aLastState = digitalRead(outputA);

// Arduino example code Encoder  
  
  
  //Arduino example code  Shunt current sensor Plan B 
  pinMode(analogInput300, INPUT);
  pinMode(analogInput50, INPUT);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);      
  lcd.init();
  lcd.backlight();
  delay(1);                      /* no poner atencion a esta seccion */
  lcd.setCursor(0,0);
  lcd.print(" Current Meter");
  delay(1);
  lcd.setCursor(0,1);
  lcd.print(" UTN ");

  delay(1);
  offset = analogRead(analogInput300);

}
float fmap(float x, float in_min, float in_max, float out_min, float out_max) 
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
  //Arduino example code  Shunt current sensor Plan B  
  

void loop() {


 // Arduino example code LDR Sensor ####################################

 LDR_V = analogRead(LDRPin);         

LDR_ilum = ((long)LDR_V*LDR_A*10)/((long)LDR_B*LDR_Rc*(1024-LDR_V));  

AN_V = analogRead(ANPin);  
AN_vel= (AN_V*0.196); 

Serial.print("Luminocidad:  ");
Serial.print(LDR_ilum);  
Serial.print(" lx, ");

Serial.print("\t");
delay(1);

// Arduino example code LDR Sensor ####################################


// Arduino example code Anemometro ###################################

Serial.print("velocidad: ");
Serial.print(AN_vel);
Serial.print(" Km/h, ");
Serial.print("\t");

 delay(1);
// Arduino example code Anemometro ###################################


  // Arduino example code Ultrasonic
  digitalWrite(TRIGPIN, LOW);                   // Set the trigger pin to low for 2uS
  delayMicroseconds(1);
  digitalWrite(TRIGPIN, HIGH);                  // Send a 10uS high to trigger ranging
  delay(1);
  digitalWrite(TRIGPIN, LOW);                   // Send pin low again
  int distance = pulseIn(ECHOPIN, HIGH);        // Read in times pulse
  distance = distance / 58;                     // Calculate distance from time of pulse
  Serial.print("Echo ");
  Serial.print(distance);
  Serial.print(" cm ");
  Serial.print("\t");
  delay(1);                                    // Wait 50mS before next ranging
  // Arduino example code Ultrasonic


  // Arduino example code  Thermocouple
  val = analogRead(analogPin);                   // read the input pin
  temperature = ((float(val) * gain - ref) / 0.005); // convert to Celsius degree
  Serial.print("Termocouple: ");
  Serial.print(temperature);
  Serial.print(" ??C, ");
  /*Serial.print(temperature * 1.8 + 32.);
  Serial.print(" ??F ");
  Serial.print("\t");*/
  delay(1); // slow it down a bit
  // Arduino example code  Thermocouple

  

  // Arduino example code  Thermistor
  uint8_t i;
  float average;

  // take N samples in a row, with a slight delay
  for (i = 0; i < NUMSAMPLES; i++) {
    samples[i] = analogRead(THERMISTORPIN);
    delay(1);
  }

  // average all the samples out
  average = 0;
  for (i = 0; i < NUMSAMPLES; i++) {
    average += samples[i];
  }
  average /= NUMSAMPLES;

  //Serial.print("Average analog reading ");
 // Serial.print(average);
 // Serial.print("\t");

  // convert the value to resistance
  average = 1023 / average - 1;
  average = SERIESRESISTOR / average;
  //Serial.print("Thermistor resistance ");
 // Serial.print(average);
  //Serial.print("\t");

  float steinhart;
  steinhart = average / THERMISTORNOMINAL;     // (R/Ro)
  steinhart = log(steinhart);                  // ln(R/Ro)
  steinhart /= BCOEFFICIENT;                   // 1/B * ln(R/Ro)
  steinhart += 1.0 / (TEMPERATURENOMINAL + 273.15); // + (1/To)
  steinhart = 1.0 / steinhart;                 // Invert
  steinhart -= 273.15;                         // convert to C

  Serial.print("Thermistor:  ");
  Serial.print(steinhart);
  Serial.print(" ??C, ");
  Serial.print("\t");

  delay(1);
  // Arduino example code  Thermistor
  
  //Arduino example code  Shunt current sensor Plan A  

  analog = analogRead(A2); // initialise to read potentitial divider output voltage
  analog2 = analogRead(A3);
  Volt = (analog * (5.0/1024)*((R1 + R2)/R2)) - 0.16; // formula
  float voltageopamp = analog2 * (5.0 / 1024.0);// voltages by op amp from shunt
    current=(voltageopamp-0.05)/1;   //0.5v is 1A 
    float power=current*Volt;
    
  Serial.print("VDC  = ");
  Serial.print(Volt);
  Serial.print(" V, ");
  Serial.print("I DC  = ");
  //Serial.print(voltageopamp);
  Serial.print(current);
  Serial.print(" A, ");
  Serial.print("\t");
  /*Serial.print("Power = ");
  Serial.print(power);
  Serial.print(" W, ");
  Serial.print("\t");*/
  delay(1);  
  
  //Arduino example code  Shunt current sensor Plan A    
  
  
  //Arduino example code  Shunt current sensor Plan AA
  
  float omp_value = analogRead(current_sense); // in volts
  float Current = (omp_value * (5.0 / 1023.0)) * 0.54; // this line converts the readings into actual value
  Serial.print("I DC  = ");
  //Serial.print(voltageopamp);
  Serial.print(Current);
  Serial.print(" A, ");
  Serial.print("\t");
  delay(1);
  
  
  //Arduino example code  Shunt current sensor Plan AA   
  
  
  //Arduino example code  Shunt current sensor Plan B  
   if(digitalRead(button1) == 1) // scale 0A to 2A
  {
    scale = 0;
  }
  if(digitalRead(button2) == 2) // scale 2A to 10A.
  {
    scale = 1;
  }
  if (scale == 0)
  {
  readAmpsADC = analogRead(analogInput300) - offset;
  voltage = fabs(fmap(readAmpsADC, 0.0, 1024.0, 0.00, 5.0)); //this maps the measured voltage in volts from 0 t 5V
  amps = voltage * (10.0 / 3.7575); //Because we have 10A when the voltage is 22.871 for a 304.95 gain (0.075V * 304.95)
  // this is the gain using a 10kOhm R1 & 33 Ohm R2
  lcd.setCursor(0, 0);
  lcd.print("SCALE: 2A - 10A ");
  lcd.setCursor(0, 1);
  lcd.print(amps, 3);
  lcd.setCursor(15, 1);
  lcd.print("A");
  delay(1);
  //You can always fine tune the gain at the same time that you measure the current with the
  //arduino meter and a normal high precision multimeter to compare.
  }
  //Precission = --mA Scale 2A-10A
  if (scale == 1)
  {
  readAmpsADC = analogRead(analogInput50) - offset;
  voltage = fabs(fmap(readAmpsADC, 0.0, 1024.0, 0.00, 5.0)); // maps the measure volt  from to 0 - 5V
  amps = voltage *(10.0/3.832); //Because we have 10A when the voltage is 22.871 for a 51.1 gain (0.075V *51.1)
  // this is the gain using a 10kOhm R1 & a 3199.6 ohm R2
  lcd.setCursor(0,0);
  lcd.print("SCALE: 0A - 2A");
  lcd.setCursor(0,1);
  lcd.print(amps, 3);
  lcd.setCursor(15,1);
  lcd.print("A");
  delay(1);
  }
  //Arduino example code  Shunt current sensor Plan B  
  
 
  
  //Arduino example code  Voltage sensor Plan B
   /*
  lcd.setCursor(2, 0);
  lcd.print("DC Voltmeter");
  */
  value = analogRead(analogInput);
  vout = (value * 5) / 1023.0;
  vin = vout / (r2 / (r1 + r2));
  
  if (vin < 0.09)
  {
    vin = 0.0;

  }
  
  Serial.print("DC V = ");
  Serial.print(vin);
  Serial.print(" V, ");
  Serial.print("\t");
  delay(1); 
  /*
  lcd.setCursor(2, 1);
  lcd.print("Input :");
  lcd.print(vin);
  delay(1);
  lcd.clear();
  */
  //Arduino example code  Voltage sensor Plan B
  
  
  
  //Arduino example code LM35 electronic temp sensor
  
  Value = analogRead(tempPin);
  float mv = (Value/1024.0)*5000;
  float cel = mv/10;
 // float farh = (cel*9)/5 + 32;
  Serial.print("TEMP LM35 = ");
  Serial.print(cel);
  Serial.print(" ??C, ");
  Serial.print("\t");
  delay(1);
/* uncomment this to get temperature in farenhite
Serial.print("TEMPRATURE = ");
Serial.print(farh);
Serial.print("*F");
Serial.println();
*/
  
//Arduino example code LM35 electronic temp sensor  


 // Arduino example code Encoder

Serial.print("Count: ");
if (counter >= 10) {

Serial.print(counter);
Serial.print("\t");
}
if (counter <= 9) {

Serial.print("  ");
Serial.print(counter);
Serial.print("\t");
}

if (digitalRead(button) == LOW) {
counter = 50;
}

aState = digitalRead(outputA); // Reads the "current" state of the outputA
// If the previous and the current state of the outputA are different, that means a Pulse has occured
if (aState != aLastState) {
// If the outputB state is different to the outputA state, that means the encoder is rotating clockwise
if (digitalRead(outputB) != aState) {
counter ++;
} else {
counter --;
}

if (counter >= 100) {
counter = 0;
}
if (counter < 0) {
counter = 99;
}
}
aLastState = aState; // Updates the previous state of the outputA with the current stat
delay(1000);
// Arduino example code Encoder


//Arduino example code DHT electronic temp sensor       
  
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit
  float f = dht.readTemperature(true);
  
  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.print("Failed to read from DHT sensor!");
    return;
  }

  // Compute heat index
  // Must send in temp in Fahrenheit! 
  
  float hi = dht.computeHeatIndex(f, h);

 /* Serial.print("Humidity: DHT "); 
  Serial.print(h);
  Serial.print(" %\t");*/
  Serial.print(" Temp DHT: "); 
  Serial.print(t);
  Serial.println(" ??C, ");


 /* Serial.print("Farenheit index: ");
  Serial.print(hi);
  Serial.print(" ??F ");
  Serial.print("");
  Serial.print("\t");*/
  delay(1);
  
 //Arduino example code DHT electronic temp sensor
 

 
}
