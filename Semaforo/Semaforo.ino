// La secuencia del semaforo es la siguiente Rojo 3 segundos > Verde 3 segundos > Amarillo 2 segundos > Se repite

const int rojo = 3;
const int amarillo = 4;
const int verde = 5;

void setup() 
{
 pinMode(rojo, OUTPUT);
 pinMode(amarillo, OUTPUT);
 pinMode(verde, OUTPUT);
}

void loop()
{
    digitalWrite(rojo, HIGH);
    delay(3000);
    digitalWrite(rojo, LOW);
    digitalWrite(verde, HIGH);
    delay(3000);
    digitalWrite(verde, LOW);
    digitalWrite(amarillo, HIGH);
    delay(2000);
    digitalWrite(amarillo, LOW);
}
