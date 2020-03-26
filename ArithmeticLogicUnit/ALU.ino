
int lcd_key = 0;
int adc_key_in = 0;
#define btnRIGHT  0
#define btnUP     1
#define btnDOWN   2
#define btnLEFT   3
#define btnSELECT 4
#define btnNONE   5

struct ALU_Driver {
    int First;
    int Second;
    byte opCode : 3
};

ALU_Driver Driver[10];
int Result_Array[10];

int i=0;
String operate()
{
  switch(Driver[i].opCode){
    case 0: {
      int Addition = Driver[i].First + Driver[i].Second;
      String Result;
      Result = Driver[i].First;
      Result += "+";
      Result += Driver[i].Second;
      Result += "=";
      Result += Addition;
      Result_Array[i] = Addition;
      return Result;
    }
    case 1: {
      int Subtraction = Driver[i].First - Driver[i].Second;
      String Result;
      Result = Driver[i].First;
      Result += "-";
      Result += Driver[i].Second;
      Result += "=";
      Result += Subtraction;
      Result_Array[i] = Subtraction;
      return Result;
    }
    case 2: {
      int ShiftL = 
      break;
    }
    case 3: {
      int ShiftR = 
      break;
    }
    case 4: {
      int ShiftRS = 
      break;
    }
    case 5: {
      int AND = 
      break;
    }
    case 6: {
      int OR = 
      break;
    }
    case 7: {
      int XOR = 
      break;
    }
  }
}





void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
