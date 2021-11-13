//Incluimos la libreria I2C para el uso de un LCD con modulo I2C/

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4);
  
//DECLARACIÓN DE VARIABLES GLOBALES

const int LDR = A0; //Asignación del fotoresistor LDR
const int Interruptor = 8; //Asignación del interruptor
const int ECHO = 2; //Asignación del pin eco del sensor ultrasónico
const int TRIGGER = 3; //Asignación del pin disparo del sensor ultrasónico
const int BUZZER = 4; //Asignación del zumbador o buzzer.
const int LEDR = 5; //Asignación del LED rojo
int valorLDR; //Variable de medición del LDR
int t; //TIEMPO
int d; //Variable de medición de distancia
int C = 0; //Variable del conteo
int duracion = 250; //Duración del tono
int fMin = 2000; //Tono de frecuencia mínima 
int fMax = 2500; //Tono de frecuencia máxima 
int i; //Variable de incrmetación de tonos 
int OP = 0; //Variable de habilitación del conteo

void setup() {
  //DECLARACION DE ENTRADAS Y SALIDA/
  Serial.begin(9600); //iniciailzamos la comunicación serial
  pinMode(TRIGGER, OUTPUT); //Variable Trigger es una salida digital
  pinMode(ECHO, INPUT); //Variable Echo es una entrada digital
  pinMode(LDR, INPUT); //Variable LDR declarada como entrada analógica 
  pinMode(LEDR, OUTPUT); //Variable LEDR fijada como una salida digital 
  pinMode(BUZZER, OUTPUT); //Variable del zumbador fijada como salida
  pinMode(Interruptor, INPUT); //Variable del conmutador configurada como entrada  
  digitalWrite(TRIGGER, LOW); //Inicializamos el pin de disparo con 0

  // Inicializamos el lcd
  lcd.init();
  lcd.backlight(); 
  
}

void loop() {

  /***Inicio de la rutina del sistema**/

  if (digitalRead(Interruptor) == HIGH) { //¿Interruptor de encendido del sistema esta cerrado?

    /***Verificación de la luminosidad**/

    valorLDR = map(analogRead(LDR), 0, 1023, 0, 100); //Conversión de la lectura del sensor LDR en porcentaje
    Serial.print("LDR: ");
    Serial.println(valorLDR); //Impresión en el monitor serial el valor del fotoresistor

    /***Impresión en pantalla LCD de la cantidad de personas**/

    if (valorLDR >= 20) { //¿Luminosidad es mayor o igual al 20%?
      digitalWrite(LEDR, LOW);
      Serial.print("PERSONAS; ");
      Serial.println(C);
      //JUANI MOSTRA EN EL LCD LA VARIABLE DE CONTEO C
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Entraron"); 
      lcd.setCursor(8,1)
      lcd.print("Personas");
      /*
      Mientras la variable de conteo sea menor a 100 se va a mostrar en el lcd
      Y cuando el interruptor se pulse se va a resetear
      */
    if(C <= 100)
    {
      lcd.setCursor(5,1);
      lcd.print(C);
      delay(1000);
      i++;
    }
    else if (Interruptor == 1)
    {
      lcd.clear();
      C = 0;
    }
      
      /***Sensor detector de ´movimiento´**/

      digitalWrite(TRIGGER, HIGH); //Se activa el disparo
      delayMicroseconds(10); //Pulso de 10us
      digitalWrite(TRIGGER, LOW); //Se desactiva el disparo
      t = pulseIn(ECHO, HIGH); //Se cuantifica el tiempo del pulso 
      d = t / 59; //Coneversión de tiempo a distancia en cm
      Serial.print("Distancia: ");
      Serial.print(d);
      Serial.print("cm"); //Impresión en el monitor serial el valor en distancia del ultrasonido
      Serial.println();
      delay(350);

      /***Programa de conteo de personas**/

      if (d == 0) {} //Condición por errores de inicialización del sensor ultrasónico
      else {
        if (d <= 80) { //Inicio de conteo cuando la distancia es menor a 80cm
          tone(BUZZER, 1500, 100); //Activación del buzzer
          while (OP == 0) { //Habilitación del conteo
            C = C + 1; //Incremento del conteo
            OP = 1; //Se inhibe el conteo ante la presencia del mismo objeto (Rompe el ciclo while, por ende el incremento no se produce). 
          }
        } else {
          OP = 0; //Si la distancia es menor a 80cm la variable de habilitación se reinicia
        }

        while (C == 5) { //Si el conteo llega a 5 personas suena una alarma de advertencia.
          if (digitalRead(Interruptor) == HIGH) { //Se comprueba nuevamente el estado del interruptor de encendido del sistema

            /***Rutina de los tonos de la alarma***/

            //sonido más agudo                  
            for (i = fMin; i <= fMax; i++)
              tone(BUZZER, i, duracion);

            //sonido más grave
            for (i = fMax; i >= fMin; i--)
              tone(BUZZER, i, duracion);
          } else {
            C = 0;
          }
        }
      }
    } else {
      digitalWrite(LEDR, HIGH);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print(PROHIBIDA LA ENTRADA.);
    }
  } else {

    /***Se reinicia todas las variables del sistema***/

    C = 0;
  }
}
