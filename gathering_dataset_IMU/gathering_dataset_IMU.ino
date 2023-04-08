#include <Arduino_LSM9DS1.h>

const int numSamples = 250;
int finalsamples = 0;
char ans;

void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
 while (!Serial) 
 if (!IMU.begin()) {
 Serial.println("Failed to initialize IMU!");
 while (1);
 }
 Serial.println("aX,aY,aZ,gX,gY,gZ");
}

void loop() {
  // put your main code here, to run repeatedly:
  float ax, ay, az, gx, gy, gz;

  //Serial.println('Are you ready to print the data: ')

  while (finalsamples < numSamples) {

    if (IMU.accelerationAvailable() && IMU.gyroscopeAvailable()) {

      IMU.readAcceleration(ax, ay, az);
      IMU.readGyroscope(gx, gy, gz);

      finalsamples++;

      Serial.print(ax, 3);
      Serial.print(',');
      Serial.print(ay, 3);
      Serial.print(',');
      Serial.print(az, 3);
      Serial.print(',');
      Serial.print(gx, 3);
      Serial.print(',');
      Serial.print(gy, 3);
      Serial.print(',');
      Serial.print(gz, 3);
      Serial.println();

      if (finalsamples == numSamples) {
        Serial.end();
      }
    }
  }
}
