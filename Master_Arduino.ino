#include <Wire.h> // Wire kütüphanemizi projemize dahil ediyoruz
#include <Servo.h>
Servo onsolomuz;
Servo onsolustbacak;
Servo onsolkaval;
Servo onsagomuz;
Servo onsagustbacak;
Servo onsagkaval;
Servo arkasolomuz;
Servo arkasolustbacak;
Servo arkasolkaval;
Servo arkasagomuz;
Servo arkasagustbacak;
Servo arkasagkaval;// motor1 adında servo motor nesnesi tanımlandı
byte alinan[4]; // Alınan veriyi hafızada tutmak için 2 indisli dizemiz 
 
void setup() {
  Wire.begin(); // Wire haberleşmeyi Master olarak başlat
  Serial.begin(9600); // Seri haberleşmeyi 9600 baud rate ile başlat
  onsolomuz.attach(2);
onsolustbacak.attach(4);
onsolkaval.attach(3);
onsagomuz.attach(5);
onsagustbacak.attach(7);
onsagkaval.attach(6);
arkasolomuz.attach(8);
arkasolustbacak.attach(9);
arkasolkaval.attach(10);
arkasagomuz.attach(11);
arkasagustbacak.attach(12);
arkasagkaval.attach(13);// Servo motorun 9. Pine bağlandığı belirtildi

}
 
void loop() {
  onsolomuz.write(101); 
onsolustbacak.write(10); 
onsolkaval.write(30); 
onsagomuz.write(77); 
onsagustbacak.write(80); 
onsagkaval.write(170);
arkasolomuz.write(87); 
arkasolustbacak.write(180); 
arkasolkaval.write(160); 
arkasagomuz.write(99); 
arkasagustbacak.write(20); 
arkasagkaval.write(30);
  Wire.requestFrom(1,4); // 1 numaralı slave cihaza 2 byte okuma isteği gönder
  
  if(Wire.available()){ // eğer gelen veri var ise
    int gelen = Wire.available();// Gelen byte sayısını gelen değişkenine aktar
    for(int i = 0; i<gelen; i++){ // gelen byte sayısı kadar döngüyü devam ettir
      alinan[i] = Wire.read(); // her döngüde 1 byte oku ve alinan dizisine aktar
    }
   byte sol_on = (alinan[0]); // okunan 2 byte veriyi bir word veriye dönüştür
   byte sol_arka= (alinan[1]);
   byte sag_on= (alinan[2]);
   byte sag_arka=(alinan[3]);
    Serial.print("sol_on : ");  // Seri porta Okunan yaz aynı satırdan devam et
    Serial.print(sol_on); // sonucu seri porta yaz
    Serial.print("   sol_arka : ");  // Seri porta Okunan yaz aynı satırdan devam et
    Serial.print(sol_arka); // sonucu seri porta yaz
    Serial.print("   sag_on : ");  // Seri porta Okunan yaz aynı satırdan devam et
    Serial.print(sag_on); // sonucu seri porta yaz
    Serial.print("   sag_arka :");
    Serial.println(sag_arka);
  }

while(alinan[2]>2 && alinan[3]<=255 ){
onsagomuz.write(57);
arkasagomuz.write(119);
  Wire.requestFrom(1,4); // 1 numaralı slave cihaza 2 byte okuma isteği gönder
  
  if(Wire.available()){ // eğer gelen veri var ise
    int gelen = Wire.available();// Gelen byte sayısını gelen değişkenine aktar
    for(int i = 0; i<gelen; i++){ // gelen byte sayısı kadar döngüyü devam ettir
      alinan[i] = Wire.read(); // her döngüde 1 byte oku ve alinan dizisine aktar
    }
   byte sol_on = (alinan[0]); // okunan 2 byte veriyi bir word veriye dönüştür
   byte sol_arka= (alinan[1]);
   byte sag_on= (alinan[2]);
   byte sag_arka=(alinan[3]);
    Serial.print("sol_on : ");  // Seri porta Okunan yaz aynı satırdan devam et
    Serial.print(sol_on); // sonucu seri porta yaz
    Serial.print("   sol_arka : ");  // Seri porta Okunan yaz aynı satırdan devam et
    Serial.print(sol_arka); // sonucu seri porta yaz
    Serial.print("   sag_on : ");  // Seri porta Okunan yaz aynı satırdan devam et
    Serial.print(sag_on); // sonucu seri porta yaz
    Serial.print("   sag_arka :");
    Serial.println(sag_arka);
  }
}
while((alinan[0]>11) && alinan[1]>=2){
onsolomuz.write(121);
arkasolomuz.write(67);
  Wire.requestFrom(1,4); // 1 numaralı slave cihaza 2 byte okuma isteği gönder
  
  if(Wire.available()){ // eğer gelen veri var ise
    int gelen = Wire.available();// Gelen byte sayısını gelen değişkenine aktar
    for(int i = 0; i<gelen; i++){ // gelen byte sayısı kadar döngüyü devam ettir
      alinan[i] = Wire.read(); // her döngüde 1 byte oku ve alinan dizisine aktar
    }
   byte sol_on = (alinan[0]); // okunan 2 byte veriyi bir word veriye dönüştür
   byte sol_arka= (alinan[1]);
   byte sag_on= (alinan[2]);
   byte sag_arka=(alinan[3]);
    Serial.print("sol_on : ");  // Seri porta Okunan yaz aynı satırdan devam et
    Serial.print(sol_on); // sonucu seri porta yaz
    Serial.print("   sol_arka : ");  // Seri porta Okunan yaz aynı satırdan devam et
    Serial.print(sol_arka); // sonucu seri porta yaz
    Serial.print("   sag_on : ");  // Seri porta Okunan yaz aynı satırdan devam et
    Serial.print(sag_on); // sonucu seri porta yaz
    Serial.print("   sag_arka :");
    Serial.println(sag_arka);
  }
}



    
  }
