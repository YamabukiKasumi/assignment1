#include <morse.h> 
Morse morse(13);
char MORSE[][4] = { {'.', '-', '*', '*'}, //A
{'-', '.', '.', '.'}, //B
{'-', '.', '-', '.'}, //C 
{'-', '.', '.', '*'}, //D 
{'.', '*', '*', '*'}, //E 
{'.', '.', '-', '.'}, //F 
{'-', '-', '.', '*'}, //G 
{'.', '.', '.', '.'}, //H 
{'.', '.', '*', '*'}, //I
{'.', '-', '-', '-'}, //J
{'-', '.', '-', '*'}, //K 
{'.', '-', '.', '.'}, //L
{'-', '-', '*', '*'}, //M 
{'-', '.', '*', '*'}, //N 
{'-', '-', '-', '*'}, //O 
{'.', '-', '-', '.'}, //P 
{'-', '-', '.', '-'}, //Q 
{'.', '-', '.', '*'}, //R 
{'.', '.', '.', '*'}, //S 
{'-', '*', '*', '*'}, //T 
{'.', '.', '-', '*'}, //U 
{'.', '.', '.', '-'}, //V 
{'.', '-', '-', '*'}, //W
{'-', '.', '.', '-'}, //X
{'-', '.', '-', '-'}, //Y
{'-', '-', '.', '.'} //Z
};
void setup()
{ Serial.begin(9600);}
void loop(){ 
  String str = ""; 
String morse_s = ""; 
int i, t , temp = 0; 
int n = 0; 
while (Serial.available() > 0) 
{ 
  temp = 1; 
}
str += char(Serial.read()); 
delay(2); 
n++; 
if (temp) 
{ 
  //查询表并且转换
  for (i = 0; i < n; i++)
  {
    for (t = 0; t < 4; t++)
      {
  //做一个判断
         if (str[i] >= 97 && str[i] <= 122)
           {
             morse_s += char(MORSE[int(str[i] - 97)][t]);
            }
       } 
   } 
    Serial.println(morse_s); //串口传入
    for (i = 0; morse_s[i]!='\0' ; i++)
    { 
      if (morse_s[i] == '.')
         {
            morse.dot(); 
          }
    else if (morse_s[i] == '-')morse.dash();
  //  else if (morse_s[i] == ' ')morse.w_space(); 
 //if (morse_s[i] != ' ' && str[i] != '*')morse.c_space();
    }
 Serial.println("完成发送"); 
 delay(2);
 }
 }
 
