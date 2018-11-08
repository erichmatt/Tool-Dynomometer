import processing.serial.*;

Serial port1;
String val;

boolean connection = false;

void setup() {
  size(500, 500);
  background(0);
  String portname = Serial.list()[0];
  port1 = new Serial(this, portname, 9600);
}

int t = 0;
int y = 0;

void Serialstuff(Serial port1) {
  val = port1.readStringUntil('\n');
  if (val != null) {

    val = trim(val);
    y = int(val)/100;
  }
}

void draw() {
  translate(0, height/2);
  //rotate(180);
  t++;
  Serialstuff(port1);
  strokeWeight(6);
  stroke(255);
  point(t, y);

  if (keyPressed == true || t == width) { 
    background(0); 
    t = 0;
  }
}
