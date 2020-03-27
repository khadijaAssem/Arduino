
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int i=-1;
const int up = 0;
const int down = 1;


struct ALU_Driver {
    int First;
    int Second;
    byte opCode : 3;
};

ALU_Driver Driver[10];
int Result_Array[10];

String operate() {
  switch(Driver[i].opCode) {
    case 0: {
      int Addition = Driver[i].First + Driver[i].Second;
      String Result;
      Result = Driver[i].First;
      Result += " + ";
      Result += Driver[i].Second;
      Result += " = ";
      Result += Addition;
      Result_Array[i] = Addition;
      return Result;
    }
    case 1: {
      int Subtraction = Driver[i].First - Driver[i].Second;
      String Result;
      Result = Driver[i].First;
      Result += " - ";
      Result += Driver[i].Second;
      Result += "=";
      Result += Subtraction;
      Result_Array[i] = Subtraction;
      return Result;
    }
    case 2: {
      int ShiftL = Driver[i].First << Driver[i].Second;
      String Result;
      Result = Driver[i].First;
      Result += " << ";
      Result += Driver[i].Second;
      Result += " = ";
      Result += ShiftL;
      Result_Array[i] = ShiftL;
      return Result; 
    }
    case 3: {
      int ShiftRUS = (unsigned) Driver[i].First >> Driver[i].Second;
      String Result;
      Result = Driver[i].First;
      Result += " unsigned >> ";
      Result += Driver[i].Second;
      Result += " = ";
      Result += ShiftRUS;
      Result_Array[i] = ShiftRUS;
      return Result;
      }
    case 4: {
      int ShiftRS = Driver[i].First >> Driver[i].Second;
      String Result;
      Result = Driver[i].First;
      Result += " >> ";
      Result += Driver[i].Second;
      Result += " = ";
      Result += ShiftRS;
      Result_Array[i] = ShiftRS;
      return Result;
    }
    case 5: {
      int AND = Driver[i].First & Driver[i].Second;
      String Result;
      Result = Driver[i].First;
      Result += " & ";
      Result += Driver[i].Second;
      Result += " = ";
      Result += AND;
      Result_Array[i] = AND;
      return Result;
    }
    case 6: {
      int OR = Driver[i].First | Driver[i].Second;
      String Result;
      Result = Driver[i].First;
      Result += " | ";
      Result += Driver[i].Second;
      Result += " = ";
      Result += OR;
      Result_Array[i] = OR;
      return Result;
    }
    case 7: {
      int XOR = Driver[i].First ^ Driver[i].Second;
      String Result;
      Result = Driver[i].First;
      Result += " ^ ";
      Result += Driver[i].Second;
      Result += " = ";
      Result += XOR;
      Result_Array[i] = XOR;
      return Result;
    }
  }
}

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
  if(i==8)
    i=0;
  if (digitalRead(up)==1){
    i++;
    lcd.print(operate());
  }
  else if (digitalRead(down)==1){
    i--;
    lcd.print(operate());
  }
}
