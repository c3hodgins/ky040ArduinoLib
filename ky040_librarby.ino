int val;
int counter = 0;
class ky040{
  private:  
    int A;
    int B;
    int C;
    int prevA=0;
    int currA;
    int prevB=0;
    int currB;
    int num;
    int CLK;
    int DT;
    int SW;
  public:
    ky040(int clk,int dt, int sw){
      CLK = clk;
      DT = dt;
      SW = sw;
      pinMode(clk,INPUT);
      pinMode(dt,INPUT);
      pinMode(sw,INPUT);
      A =0;
      B =0;
      C =0;
    }
    int dir(){
      num =0;
      prevA = currA;
      prevB = currB;
      currA = digitalRead(CLK);
      currB = digitalRead(DT);
      if (prevA == 0 && prevB == 0){
        if (currA == 1 && currB == 0){
          num = 1;
        }else if(currB == 1 && currA == 0){
          num = -1;
        }
      }
      return num;
    }
};

ky040 rotaryEnc(4,3,2);


void setup(){  // put your setup code here, to run once:
Serial.flush();
Serial.begin(9600);
}


void loop(){
  int last = val;
  val = rotaryEnc.dir();
  if ((last != val)&& (val!= 0)){
    counter+=val;
    Serial.println(counter);
  }
}
