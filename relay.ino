char datachar;
String input;
bool nyala = false;
void setup() 
{
    // put your setup code here, to run once:
    Serial.begin(9600);
    pinMode(13, OUTPUT);
}

void loop() 
{
    //Membaca input character keyboard yang dimasukkan ke variable datachar,
    // kemudian diappend ke variabel input (string).
    if (Serial.available())
    {
        datachar = Serial.read();
        input += datachar;
        delay(5);
    }
    //Jika string input berakhiran "ON", maka lampu akan menyala
    //alasan menggunakan akhiran karena ada kemungkinan user menulis input selain "ON" dan "OFF" sehingga
    //program akan membaca inputan terakhir yang dimasukkan oleh user saja
    if (input.endsWith("ON"))
    {
        //di sini digunakan variabel "nyala" agar ketika lampu dalam kondisi ON/menyala
        //program tidak perlu mengulangi kumpulan perintah di dalamnya (mengurangi redundansi).
        if (!nyala) 
        {
            Serial.println(input);
            digitalWrite(13, 1);    
            nyala = true;
            input = "";
        }
    }
    //Jika string input berakhiran "OFF", maka lampu akan menyala
    //alasan menggunakan akhiran karena ada kemungkinan user menulis input selain "ON" dan "OFF" sehingga
    //program akan membaca inputan terakhir yang dimasukkan oleh user saja
    else if (input.endsWith("OFF"))
    {
        //di sini digunakan variabel "nyala" agar ketika lampu dalam kondisi ON/menyala
        //program tidak perlu mengulangi kumpulan perintah di dalamnya (mengurangi redundansi).
        if (nyala) 
        {
            Serial.println(input);
            digitalWrite(13, 0);    
            nyala = false;
            input = "";
        }
    }
}