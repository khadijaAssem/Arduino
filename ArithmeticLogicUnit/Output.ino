#include <OutputModule.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int j=-1;
const int up = 0;
const int down = 1;

OutputModule op = OutputModule();
void setup(){
  Serial.begin(9600);
  pinMode(up,INPUT);
  pinMode(down,INPUT);
	for(int i=0;i<8;i++){
		String k = String(i);
		op.setOutput(k,i);
	}
	lcd.begin(16, 2);
  lcd.print("hello, world!");
}
void loop(){
	if(j==8)
		j=0;
  if (digitalRead(up)==1){
    j++;
    lcd.print(op.getOutput(j));
  }
  else if (digitalRead(down)==1){
    j--;
    lcd.print(op.getOutput(j));
  }
}
