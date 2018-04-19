#define PIN_SER 3
#define PIN_RCK 0
#define PIN_SCK 4
#define PIN_BUTTON 2
void setup() {
  pinMode(PIN_SER, OUTPUT);
  pinMode(PIN_RCK, OUTPUT);
  pinMode(PIN_SCK, OUTPUT);
  pinMode(PIN_BUTTON, INPUT);
  digitalWrite(PIN_BUTTON, HIGH); 
  digitalWrite(PIN_RCK,LOW);
  digitalWrite(PIN_SCK,LOW);
  for(int i=0;i < 16;i++){
    digitalWrite(PIN_SCK, LOW);
    digitalWrite(PIN_SER, LOW);
    digitalWrite(PIN_SCK, HIGH);
  }
  for(int i=0;i < 8;i++){
    digitalWrite(PIN_SCK, LOW);
    digitalWrite(PIN_SER, HIGH);
    digitalWrite(PIN_SCK, HIGH);
  }
  digitalWrite(PIN_RCK,HIGH);
  digitalWrite(PIN_RCK,LOW);
  delay(100);
}
int row_write(int num){
 int row=0;
 int data;
 data = (1 << num);
 for(int i=0;i < 8;i++){
  digitalWrite(PIN_SCK, LOW);
  row = (data >> 7-i) & 0b00000001;
  if(!row){
    digitalWrite(PIN_SER,HIGH);
  }else{
    digitalWrite(PIN_SER,LOW);        
  }
  digitalWrite(PIN_SCK, HIGH);
 }
}
int col_write(int data,int rev){
 int col=0;
 for(int i=0;i < 8;i++){
  digitalWrite(PIN_SCK, LOW);
  if(rev == 0){
    col = (data >> 7-i) & 1;
  }else{
    col = (data >> i) & 1;    
  }
  if(col){
    digitalWrite(PIN_SER,HIGH);
  }else{
    digitalWrite(PIN_SER,LOW);        
  }
  digitalWrite(PIN_SCK, HIGH);
 }
}
int flg=1;
int y=0;
int nico[][8] ={{
               0b00100100,
               0b01000000,
               0b01011000,
               0b10011000,
               0b10000000,
               0b01000000,
               0b01000011,
               0b00100000
               },{
               0b00100100,
               0b01000000,
               0b01000000,
               0b10011000,
               0b10000000,
               0b01000000,
               0b01000011,
               0b00100000
               },{
               0b00100000,
               0b01000000,
               0b01010000,
               0b10001000,
               0b10010000,
               0b01000010,
               0b01000001,
               0b00100000
               }
};
int kao=0;
int timer=-1000;
void loop() {
  timer--;
  if(digitalRead(PIN_BUTTON) == LOW){kao = 2;}else{
    if(timer<=0){
      kao = random(10,20) % 2;
      if(timer < -10){
        kao = 1;
      }
      timer = random(10,100);
    }    
  }
  
  for(int row=0;row < 8;row++){
    col_write(nico[kao][row],0);
    col_write(nico[kao][row],1);
    row_write(row);    
    digitalWrite(PIN_RCK,HIGH);
    digitalWrite(PIN_RCK,LOW);    
//    delay(100);
  }
}
