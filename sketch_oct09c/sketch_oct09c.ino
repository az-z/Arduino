  // put your setup code here, to run once:
  int drive_gb = 100;
long drive_mb;                  // we changed the type from "int" to "long"

void setup()                    // run once, when the sketch starts
{
  Serial.begin(9600);           // set up Serial library at 9600 bps
//  Serial.begin()
  Serial.print("Your HD is ");
  Serial.print(drive_gb);
  Serial.println(" GB large.");

  //drive_mb = drive_gb;
  drive_mb = (long )drive_gb * 1024 ;

  Serial.print("It can store ");
  Serial.print(drive_mb);
  Serial.println(" Megabytes!");
}


void loop() {
  // put your main code here, to run repeatedly:

}
