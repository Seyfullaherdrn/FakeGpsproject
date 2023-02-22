
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

#define upButtonPin  2 
#define downButtonPin  3
#define rightButtonPin  5
#define leftButtonPin 4 
// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

#define NUMFLAKES     10 // Number of snowflakes in the animation example

#define LOGO_HEIGHT   16
#define LOGO_WIDTH    16
static const unsigned char PROGMEM logo_bmp[] =
{ B00000000, B11000000,
  B00000001, B11000000,
  B00000001, B11000000,
  B00000011, B11100000,
  B11110011, B11100000,
  B11111110, B11111000,
  B01111110, B11111111,
  B00110011, B10011111,
  B00011111, B11111100,
  B00001101, B01110000,
  B00011011, B10100000,
  B00111111, B11100000,
  B00111111, B11110000,
  B01111100, B11110000,
  B01110000, B01110000,
  B00000000, B00110000 };

int upPressCount = 0;       // This counter measures the amount of times the user pushes the "up" button.
int leftPressCount = 0; 
unsigned long eskiZaman=0;
unsigned long yeniZaman;

void setup() {
  Serial.begin(9600);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x32
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  // Show initial display buffer contents on the screen --
  // the library initializes this with an Adafruit splash screen.
  display.display();
  delay(2000); // Pause for 2 seconds

  // Clear the buffer
  display.clearDisplay();

  // Draw a single pixel in white
 // display.drawPixel(10, 10, SSD1306_WHITE);

  // Show the display buffer on the screen. You MUST call display() after
  // drawing commands to make them visible on screen!
  //display.display();
  delay(2000);
  // display.display() is NOT necessary after every single drawing command,
  // unless that's what you want...rather, you can batch up a bunch of
  // drawing operations and then update the screen all at once by calling
  // display.display(). These examples demonstrate both approaches...



  // Invert and restore display, pausing in-between
  display.invertDisplay(true);
  delay(1000);
  display.invertDisplay(false);
  delay(1000);

  Serial.print("connected");
 pinMode(leftButtonPin, INPUT);    // SETS THE leftButtonPin AS AN INPUT
  pinMode(rightButtonPin, INPUT);   // SETS THE rightButtonPin AS AN INPUT
  pinMode(upButtonPin, INPUT);      // SETS THE upButtonPin AS AN INPUT
  pinMode(downButtonPin, INPUT);    // SETS THE downButtonPin AS AN INPUT

}

void loop() {
   // put your main code here, to run repeatedly:
   yeniZaman = millis();
if(yeniZaman-eskiZaman > 100){
  if(digitalRead(leftButtonPin) == 1)                        // Once the button is released, the push is registered and the code below runs.
 {                                                 
   leftPressCount--;                                     // Both the up and down press counts will be reset to zero when the left button is pushed.
     // downPressCount = 0;
   //  Serial.println("sol");
   //  Serial.println(leftPressCount);
      }
if(digitalRead(rightButtonPin) == 1)                        // Once the button is released, the push is registered and the code below runs.
      {                                                 
       leftPressCount++;                                 // Both the up and down press counts will be reset to zero when the left button is pushed.
     // downPressCount = 0;
     Serial.println("sag");
     Serial.println(leftPressCount);
      }
if(digitalRead(upButtonPin) == 1)                        // Once the button is released, the push is registered and the code below runs.
      {                                                 
     upPressCount++;                                   // Both the up and down press counts will be reset to zero when the left button is pushed.
    
     // downPressCount = 0;
     Serial.println("yukari");
     Serial.println(upPressCount);
     //Serial.println(menuOption[upPressCount]);
      }
if(digitalRead(downButtonPin) == 1)                        // Once the button is released, the push is registered and the code below runs.
      {                                                 
                                        // Both the up and down press counts will be reset to zero when the left button is pushed.
    upPressCount--;
     // downPressCount = 0;
     Serial.println("asagi");
     Serial.println(upPressCount);
    // Serial.println(menuOption[upPressCount]);
      }
      eskiZaman = yeniZaman;
      delay(100);
     
      switch (upPressCount) // sayaca göre switch kodunu çalıştır
  {
     case -1: // sayaca 1 ise
      Serial.println("UKRAINE");
     upPressCount=6;
         break;
     case 0: // sayaca 1 ise
      display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(10,0);
     display.print(" GERMANY");
      display.display();
     // delay(2000);
      
      if (upPressCount==0){
         switch (leftPressCount) // sayaca göre switch kodunu çalıştır
  {
     case -1:
     leftPressCount=0;
     display.print(" 16E");
     display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(20,5);
   display.display();
      break;
     case 0: // sayaca 1 ise
     display.print(" 16E");
     display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(20,20);
   display.display();
      Serial.println(F("$GPGGA,125140.724,5149.251,N,01431.435,E,1,12,1.0,0.0,M,0.0,M,,*66"));
    Serial.println(F("$GPGSA,A,3,01,02,03,04,05,06,07,08,09,10,11,12,1.0,1.0,1.0*30"));
    Serial.println(F("$GPRMC,125140.724,A,5149.251,N,01431.435,E,252458.4,270.0,201221,000.0,W*4D")); // ekrana cümleyi yaz
      break;
    case 1: // sayaca 1 ise
     display.print(" 12E");
     display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(20,20);
   display.display();
      Serial.println(F("$GPGGA,125141.724,5149.251,N,01238.057,E,1,12,1.0,0.0,M,0.0,M,,*68"));
    Serial.println(F("$GPGSA,A,3,01,02,03,04,05,06,07,08,09,10,11,12,1.0,1.0,1.0*30"));
    Serial.println(F("$GPRMC,125141.724,A,5149.251,N,01238.057,E,322131.6,266.4,201221,000.0,W*4E"));
      break; // swtich den çık
    case 2: // sayaca 2 ise
      display.println(" 10E"); // ekrana cümleyi yaz
      display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(30,20);
   display.display();
      Serial.println(F("$GPGGA,125142.724,5140.267,N,01014.355,E,1,12,1.0,0.0,M,0.0,M,,*6A"));
    Serial.println(F("$GPGSA,A,3,01,02,03,04,05,06,07,08,09,10,11,12,1.0,1.0,1.0*30"));
    Serial.println(F("$GPRMC,125142.724,A,5140.267,N,01014.355,E,237818.8,265.5,201221,000.0,W*47"));
      break;// swtich den çık

    case 3: // sayaca 3 ise
     display.print("  8E"); // ekrana cümleyi yaz
     display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(20,20);
   display.display();
      Serial.println(F("$GPGGA,125143.724,5132.074,N,00828.887,E,1,12,1.0,0.0,M,0.0,M,,*6C"));
    Serial.println(F("$GPGSA,A,3,01,02,03,04,05,06,07,08,09,10,11,12,1.0,1.0,1.0*30"));
    Serial.println(F("$GPRMC,125143.724,A,5132.074,N,00828.887,E,254524.8,264.5,201221,000.0,W*47"));
      break;// swtich den çık

    case 4: // sayaca 5 ise
      display.print("  6E"); // ekrana cümleyi yaz
      display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(40,40);
   display.display();
     Serial.println(F("$GPGGA,125144.724,5121.386,N,00636.826,E,1,12,1.0,0.0,M,0.0,M,,*6D"));
    Serial.println(F("$GPGSA,A,3,01,02,03,04,05,06,07,08,09,10,11,12,1.0,1.0,1.0*30"));
    Serial.println(F("$GPRMC,125144.724,A,5121.386,N,00636.826,E,254524.8,264.5,201221,000.0,W*46"));
      break;// swtich den çık

    case 5 : // sayaca başka bir değer ise
    leftPressCount=4;
    display.print("   6E");
   display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(20,20);
   display.display();
  }
  display.clearDisplay();
      break;
      }
    case 1: // sayaca 1 ise
    
    display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(10,0);
     display.print(" HOLLAND ");
     display.display();
      if (upPressCount==1){
            switch (leftPressCount) // sayaca göre switch kodunu çalıştır
  {
     case -1:
     leftPressCount=0;
    display.print("  7E"); // ekrana cümleyi yaz
      display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(40,40);
   display.display();
   
      break;
     case 0: // sayaca 1 ise
    display.print("  7E"); // ekrana cümleyi yaz
      display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(40,40);
   display.display();
    Serial.println(F("$GPGGA,132229.945,5208.643,N,00658.975,E,1,12,1.0,0.0,M,0.0,M,,*61"));
    Serial.println(F("$GPGSA,A,3,01,02,03,04,05,06,07,08,09,10,11,12,1.0,1.0,1.0*30"));
    Serial.println(F("$GPRMC,132229.945,A,5208.643,N,00658.975,E,183761.4,268.9,201221,000.0,W*4C"));
      break;
    case 1: // sayaca 1 ise
      display.print("  5E"); // ekrana cümleyi yaz
      display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(40,40);
   display.display();
    Serial.println(F("$GPGGA,132230.945,5207.024,N,00535.918,E,1,12,1.0,0.0,M,0.0,M,,*62"));
    Serial.println(F("$GPGSA,A,3,01,02,03,04,05,06,07,08,09,10,11,12,1.0,1.0,1.0*30"));
    Serial.println(F("$GPRMC,132230.945,A,5207.024,N,00535.918,E,172559.6,267.6,201221,000.0,W*4A"));
      break; // swtich den çık

    case 2: // sayaca 2 ise
     display.print("  3E"); // ekrana cümleyi yaz
      display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(40,40);
   display.display();
    Serial.println(F("$GPGGA,132231.945,5203.782,N,00418.135,E,1,12,1.0,0.0,M,0.0,M,,*65"));
    Serial.println(F("$GPGSA,A,3,01,02,03,04,05,06,07,08,09,10,11,12,1.0,1.0,1.0*30"));
    Serial.println(F("$GPRMC,132231.945,A,5203.782,N,00418.135,E,172559.6,267.6,201221,000.0,W*4D"));
      break;// swtich den çık

   default : // sayaca başka bir değer ise
    leftPressCount=2;
      display.print("  3E"); // ekrana cümleyi yaz
      display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(40,40);
   display.display(); // ekrana cümleyi yaz
  }
  display.clearDisplay();
      break; // swtich den çık
      }
    case 2: // sayaca 2 ise
      display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(10,0);
     display.print(" SPAIN ");
     display.display();
      if (upPressCount==2){
       switch (leftPressCount) // sayaca göre switch kodunu çalıştır
  {
     case -1:
     leftPressCount=0;
     display.print("  3E"); // ekrana cümleyi yaz
      display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(40,40);
   display.display();
     
      break;
     case 0: // sayaca 1 ise
      display.print("  3E"); // ekrana cümleyi yaz
      display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(40,40);
   display.display();
    Serial.println(F("$GPGGA,054549.614,4125.444,N,00242.158,E,1,12,1.0,0.0,M,0.0,M,,*6A"));
    Serial.println(F("$GPGSA,A,3,01,02,03,04,05,06,07,08,09,10,11,12,1.0,1.0,1.0*30"));
    Serial.println(F("$GPRMC,054549.614,A,4125.444,N,00242.158,E,748274.4,269.2,211221,000.0,W*4C")); // ekrana cümleyi yaz
      break;
    case 1: // sayaca 1 ise
      display.print("  1W"); // ekrana cümleyi yaz
      display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(40,40);
   display.display(); // ekrana cümleyi yaz
      Serial.println(F("$GPGGA,054550.614,4121.485,N,00154.697,W,1,12,1.0,0.0,M,0.0,M,,*79"));
    Serial.println(F("$GPGSA,A,3,01,02,03,04,05,06,07,08,09,10,11,12,1.0,1.0,1.0*30"));
    Serial.println(F("$GPRMC,054550.614,A,4121.485,N,00154.697,W,491991.7,269.7,211221,000.0,W*5E"));
      break; // swtich den çık

    case 2: // sayaca 2 ise
     display.print("  5W"); // ekrana cümleyi yaz
      display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(40,40);
   display.display(); // ekrana cümleyi yaz
    Serial.println(F("$GPGGA,054551.614,4120.495,N,00456.631,W,1,12,1.0,0.0,M,0.0,M,,*73"));
    Serial.println(F("$GPGSA,A,3,01,02,03,04,05,06,07,08,09,10,11,12,1.0,1.0,1.0*30"));
    Serial.println(F("$GPRMC,054551.614,A,4120.495,N,00456.631,W,629893.9,279.8,211221,000.0,W*56"));
      break;// swtich den çık

    case 3: // sayaca 3 ise
      display.print("  9W"); // ekrana cümleyi yaz
      display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(40,40);
   display.display(); // ekrana cümleyi yaz
    Serial.println(F("$GPGGA,054552.614,4159.908,N,00844.707,W,1,12,1.0,0.0,M,0.0,M,,*7C"));
    Serial.println(F("$GPGSA,A,3,01,02,03,04,05,06,07,08,09,10,11,12,1.0,1.0,1.0*30"));
    Serial.println(F("$GPRMC,054552.614,A,4159.908,N,00844.707,W,629893.9,279.8,211221,000.0,W*59"));
      break;// swtich den çık
    default :
   display.print("  9W"); // ekrana cümleyi yaz
      display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(40,40);
   display.display();
    leftPressCount=3;
  }
  display.clearDisplay();
      break;// swtich den çık
  }
    case 3: // sayaca 3 ise
      display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(10,0);
     display.print(" RUSSIAN ");
     display.display();
      if (upPressCount==3){ 
       switch (leftPressCount) // sayaca göre switch kodunu çalıştır
  {
     case -1:
     leftPressCount=0;
    display.print("  120E"); // ekrana cümleyi yaz
      display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(40,40);
   display.display(); // ekrana cümleyi yaz
      break;
     case 0: // sayaca 1 ise
      display.print("  120E"); // ekrana cümleyi yaz
      display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(40,40);
   display.display();
      Serial.println(F("$GPGGA,052841.361,5936.628,N,12302.813,E,1,12,1.0,0.0,M,0.0,M,,*6D"));
    Serial.println(F("$GPGSA,A,3,01,02,03,04,05,06,07,08,09,10,11,12,1.0,1.0,1.0*30"));
    Serial.println(F("$GPRMC,052841.361,A,5936.628,N,12302.813,E,2096997.4,271.2,211221,000.0,W*72")); // ekrana cümleyi yaz
      break;
    case 1: // sayaca 1 ise
      display.print("  102E"); // ekrana cümleyi yaz
      display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(40,40);
   display.display(); // ekrana cümleyi yaz
      Serial.println(F("$GPGGA,052842.361,5957.868,N,10342.656,E,1,12,1.0,0.0,M,0.0,M,,*6A"));
    Serial.println(F("$GPGSA,A,3,01,02,03,04,05,06,07,08,09,10,11,12,1.0,1.0,1.0*30"));
    Serial.println(F("$GPRMC,052842.361,A,5957.868,N,10342.656,E,2178502.6,270.1,211221,000.0,W*74"));
      break; // swtich den çık

    case 2: // sayaca 2 ise
      display.print("  82E"); // ekrana cümleyi yaz
      display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(40,40);
   display.display(); // ekrana cümleyi yaz
      Serial.println(F("$GPGGA,052843.361,5957.868,N,08329.766,E,1,12,1.0,0.0,M,0.0,M,,*6D"));
    Serial.println(F("$GPGSA,A,3,01,02,03,04,05,06,07,08,09,10,11,12,1.0,1.0,1.0*30"));
    Serial.println(F("$GPRMC,052843.361,A,5957.868,N,08329.766,E,2187969.4,269.4,211221,000.0,W*7D"));
      break;// swtich den çık

    case 3: // sayaca 3 ise
      display.print("  63E"); // ekrana cümleyi yaz
      display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(40,40);
   display.display(); // ekrana cümleyi yaz
      Serial.println(F("$GPGGA,052844.361,5941.959,N,06316.875,E,1,12,1.0,0.0,M,0.0,M,,*61"));
    Serial.println(F("$GPGSA,A,3,01,02,03,04,05,06,07,08,09,10,11,12,1.0,1.0,1.0*30"));
    Serial.println(F("$GPRMC,052844.361,A,5941.959,N,06316.875,E,2174566.3,268.8,211221,000.0,W*74"));
      break;// swtich den çık

    case 4: // sayaca 5 ise
     display.print("  43E"); // ekrana cümleyi yaz
      display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(40,40);
   display.display(); // ekrana cümleyi yaz
     Serial.println(F("$GPGGA,052845.361,5915.161,N,04325.078,E,1,12,1.0,0.0,M,0.0,M,,*65"));
    Serial.println(F("$GPGSA,A,3,01,02,03,04,05,06,07,08,09,10,11,12,1.0,1.0,1.0*30"));
    Serial.println(F("$GPRMC,052845.361,A,5915.161,N,04325.078,E,1677584.7,268.7,211221,000.0,W*70"));
      break;// swtich den çık

    case 5 : // sayaca başka bir değer ise
    
     display.print("  23E"); // ekrana cümleyi yaz
      display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(40,40);
   display.display();
     Serial.println(F("$GPGGA,052846.361,5853.466,N,02818.047,E,1,12,1.0,0.0,M,0.0,M,,*68"));
    Serial.println(F("$GPGSA,A,3,01,02,03,04,05,06,07,08,09,10,11,12,1.0,1.0,1.0*30"));
    Serial.println(F("$GPRMC,052846.361,A,5853.466,N,02818.047,E,1677584.7,268.7,211221,000.0,W*7D"));
    case 6: 
    display.print("  23E"); // ekrana cümleyi yaz
      display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(40,40);
   display.display();
    leftPressCount=5;
  }
  display.clearDisplay();
      break;// swtich den çık
  } 
    case 4: // sayaca 5 ise
//       display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(10,0);
     display.print(" DENMARK");
     display.display(); 
      if (upPressCount==4){
          switch (leftPressCount) // sayaca göre switch kodunu çalıştır
  {
     case -1:
     leftPressCount=0;
     display.print("  13E"); // ekrana cümleyi yaz
      display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(40,40);
   display.display(); // ekrana cümleyi yaz
      break;
     case 0: // sayaca 1 ise
     display.print("  13E"); // ekrana cümleyi yaz
      display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(40,40);
   display.display();
     Serial.println("$GPGGA,061732.081,5535.349,N,01255.195,E,1,12,1.0,0.0,M,0.0,M,,*60");
    Serial.println("$GPGSA,A,3,01,02,03,04,05,06,07,08,09,10,11,12,1.0,1.0,1.0*30");
    Serial.println("$GPRMC,061732.081,A,5535.349,N,01255.195,E,310586.0,266.9,211221,000.0,W*45"); // ekrana cümleyi yaz
      break;
    case 1: // sayaca 1 ise
      display.print("  10E"); // ekrana cümleyi yaz
      display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(40,40);
   display.display(); // ekrana cümleyi yaz
      Serial.println("$GPGGA,061733.081,5527.135,N,01023.584,E,1,12,1.0,0.0,M,0.0,M,,*6C");
    Serial.println("$GPGSA,A,3,01,02,03,04,05,06,07,08,09,10,11,12,1.0,1.0,1.0*30");
    Serial.println("$GPRMC,061733.081,A,5527.135,N,01023.584,E,301887.8,272.1,211221,000.0,W*40");
      break; // swtich den çık

    case 2: // sayaca 2 ise
      display.print("  8E"); // ekrana cümleyi yaz
      display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(40,40);
   display.display(); // ekrana cümleyi yaz
      Serial.println("$GPGGA,061734.081,5532.365,N,00755.928,E,1,12,1.0,0.0,M,0.0,M,,*65");
    Serial.println("$GPGSA,A,3,01,02,03,04,05,06,07,08,09,10,11,12,1.0,1.0,1.0*30");
    Serial.println("$GPRMC,061734.081,A,5532.365,N,00755.928,E,301887.8,272.1,211221,000.0,W*49");
      break;// swtich den çık

    default :
    display.print("  8E"); // ekrana cümleyi yaz
      display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(40,40);
   display.display();
    leftPressCount=2;
  }
  display.clearDisplay();
      break;
      }
  case 5: // sayaca 1 ise
     display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(10,0);
     display.print(" FRANCE");
     display.display();
      if (upPressCount==5){
         switch (leftPressCount) // sayaca göre switch kodunu çalıştır
  {
     case -1:
     leftPressCount=0;
     display.print("  8E"); // ekrana cümleyi yaz
      display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(40,40);
   display.display(); // ekrana cümleyi yaz
      break;
     case 0: // sayaca 1 ise
     display.print("   8E"); // ekrana cümleyi yaz
      display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(40,40);
   display.display();
     Serial.println(F("$GPGGA,125140.724,5149.251,N,01431.435,E,1,12,1.0,0.0,M,0.0,M,,*66"));
    Serial.println(F("$GPGSA,A,3,01,02,03,04,05,06,07,08,09,10,11,12,1.0,1.0,1.0*30"));
    Serial.println(F("$GPRMC,125140.724,A,5149.251,N,01431.435,E,252458.4,270.0,201221,000.0,W*4D")); // ekrana cümleyi yaz
      break;
    case 1: // sayaca 1 ise
     display.print("   4E"); // ekrana cümleyi yaz
      display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(40,40);
   display.display(); // ekrana cümleyi yaz
      Serial.println(F("$GPGGA,125141.724,5149.251,N,01238.057,E,1,12,1.0,0.0,M,0.0,M,,*68"));
    Serial.println(F("$GPGSA,A,3,01,02,03,04,05,06,07,08,09,10,11,12,1.0,1.0,1.0*30"));
    Serial.println(F("$GPRMC,125141.724,A,5149.251,N,01238.057,E,322131.6,266.4,201221,000.0,W*4E"));
      break; // swtich den çık
    case 2: // sayaca 2 ise
     display.print("   0E"); // ekrana cümleyi yaz
      display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(40,40);
   display.display(); // ekrana cümleyi yaz
      Serial.println(F("$GPGGA,125142.724,5140.267,N,01014.355,E,1,12,1.0,0.0,M,0.0,M,,*6A"));
    Serial.println(F("$GPGSA,A,3,01,02,03,04,05,06,07,08,09,10,11,12,1.0,1.0,1.0*30"));
    Serial.println(F("$GPRMC,125142.724,A,5140.267,N,01014.355,E,237818.8,265.5,201221,000.0,W*47"));
      break;// swtich den çık

    case 3: // sayaca 3 ise
     display.print("   4W"); // ekrana cümleyi yaz
      display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(40,40);
   display.display(); // ekrana cümleyi yaz
      Serial.println(F("$GPGGA,125143.724,5132.074,N,00828.887,E,1,12,1.0,0.0,M,0.0,M,,*6C"));
    Serial.println(F("$GPGSA,A,3,01,02,03,04,05,06,07,08,09,10,11,12,1.0,1.0,1.0*30"));
    Serial.println(F("$GPRMC,125143.724,A,5132.074,N,00828.887,E,254524.8,264.5,201221,000.0,W*47"));
      break;// swtich den çık

    case 4 : // sayaca başka bir değer ise
    leftPressCount=3;
      display.print("   4W"); // ekrana cümleyi yaz
      display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(40,40);
   display.display(); // ekrana cümleyi yaz
  }
  display.clearDisplay();
      break;
      }
      case 6: // sayaca 1 ise
        display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(10,0);
     display.print(" UKRAINE");
     display.display();
    //  display.print("UKRAINE"); // ekrana cümleyi yaz
      if (upPressCount==6){
         switch (leftPressCount) // sayaca göre switch kodunu çalıştır
  {
     case -1:
     leftPressCount=0;
     display.print("  40E"); // ekrana cümleyi yaz
      display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(40,40);
   display.display(); // ekrana cümleyi yaz
      break;
     case 0: // sayaca 1 ise
     display.print("  40E"); // ekrana cümleyi yaz
      display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(40,40);
   display.display();
     Serial.println(F("$GPGGA,075347.716,4920.304,N,03954.628,E,1,12,1.0,0.0,M,0.0,M,,*63"));
    Serial.println(F("$GPGSA,A,3,01,02,03,04,05,06,07,08,09,10,11,12,1.0,1.0,1.0*30"));
    Serial.println(F("$GPRMC,075347.716,A,4920.304,N,03954.628,E,714756.8,270.8,211221,000.0,W*47")); // ekrana cümleyi yaz
      break;
    case 1: // sayaca 1 ise
    display.print("  35E"); // ekrana cümleyi yaz
      display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(40,40);
   display.display(); // ekrana cümleyi yaz
      Serial.println(F("$GPGGA,075348.716,4924.541,N,03449.920,E,1,12,1.0,0.0,M,0.0,M,,*69"));
    Serial.println(F("$GPGSA,A,3,01,02,03,04,05,06,07,08,09,10,11,12,1.0,1.0,1.0*30"));
    Serial.println(F("$GPRMC,075348.716,A,4924.541,N,03449.920,E,692835.5,268.7,211221,000.0,W*43"));
      break; // swtich den çık
    case 2: // sayaca 2 ise
      display.print("  30E"); // ekrana cümleyi yaz
      display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(40,40);
   display.display(); // ekrana cümleyi yaz
      Serial.println(F("$GPGGA,075349.716,4917.667,N,02954.814,E,1,12,1.0,0.0,M,0.0,M,,*69"));
    Serial.println(F("$GPGSA,A,3,01,02,03,04,05,06,07,08,09,10,11,12,1.0,1.0,1.0*30"));
    Serial.println(F("$GPRMC,075349.716,A,4917.667,N,02954.814,E,993652.1,268.1,211221,000.0,W*40"));
      break;// swtich den çık

    case 3: // sayaca 3 ise
     display.print("  23E"); // ekrana cümleyi yaz
      display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(40,40);
   display.display(); // ekrana cümleyi yaz
      Serial.println(F("$GPGGA,075350.716,4903.870,N,02253.235,E,1,12,1.0,0.0,M,0.0,M,,*69"));
    Serial.println(F("$GPGSA,A,3,01,02,03,04,05,06,07,08,09,10,11,12,1.0,1.0,1.0*30"));
    Serial.println(F("$GPRMC,075350.716,A,4903.870,N,02253.235,E,993652.1,268.1,211221,000.0,W*40"));
      break;// swtich den çık

    case 4 : // sayaca başka bir değer ise
    leftPressCount=3;
    display.print("  23E"); // ekrana cümleyi yaz
      display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(40,40);
   display.display(); // ekrana cümleyi yaz
  }
 display.clearDisplay(); 
      break;
      }
    default: // sayaca başka bir değer ise
    upPressCount=0;
      Serial.println("BASA DON"); // ekrana cümleyi yaz
  }
}
 
}
