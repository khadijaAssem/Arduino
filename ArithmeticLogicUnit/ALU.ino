
#define btnUP     0
#define btnDOWN   1


struct ALU_Driver {
    int First;
    int Second;
    byte opCode : 3
};

ALU_Driver Driver[10];
int Result_Array[10];

int i=0;
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



void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
