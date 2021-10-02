const int Led1 = 3;
const int Led2 = 4;
const int Led3 = 5;
const int Led4 = 6;
const int Led5 = 7;
const int Led6 = 8;

void setup()
{
    pinMode(Led1, OUTPUT);
    pinMode(Led2, OUTPUT);
    pinMode(Led3, OUTPUT);
    pinMode(Led4, OUTPUT);
    pinMode(Led5, OUTPUT);
    pinMode(Led6, OUTPUT);
}

void inicioIzquierda()
{
    digitalWrite(Led1, HIGH);
    delay(500);
    digitalWrite(Led1, LOW);
    delay(500);
    digitalWrite(Led2, HIGH);
    delay(500);
    digitalWrite(Led2, LOW);
    delay(500);
    digitalWrite(Led3, HIGH);
    delay(500);
    digitalWrite(Led3, LOW);
    delay(500);
    digitalWrite(Led4, HIGH);
    delay(500);
    digitalWrite(Led4, LOW);
    delay(500);
    digitalWrite(Led5, HIGH);
    delay(500);
    digitalWrite(Led5, LOW);
    delay(500);
    digitalWrite(Led6, HIGH);
    delay(500);
    digitalWrite(Led6, LOW);
    delay(500);
}

void inicioDerecha()
{
    digitalWrite(Led6, HIGH);
    delay(500);
    digitalWrite(Led6, LOW);
    delay(500);
    digitalWrite(Led5, HIGH);
    delay(500);
    digitalWrite(Led5, LOW);
    delay(500);
    digitalWrite(Led4, HIGH);
    delay(500);
    digitalWrite(Led4, LOW);
    delay(500);
    digitalWrite(Led3, HIGH);
    delay(500);
    digitalWrite(Led3, LOW);
    delay(500);
    digitalWrite(Led2, HIGH);
    delay(500);
    digitalWrite(Led2, LOW);
    delay(500);
    digitalWrite(Led1, HIGH);
    delay(500);
    digitalWrite(Led1, LOW);
    delay(500);
    }

void loop()
{
   inicioDerecha();
   delay(50);
   inicioIzquierda(); 
}
/*
if (Pulsador == HIGH)
    {
        inicioDerecha();
    }
    else
    {
        inicioIzquierda();
    }
*/
