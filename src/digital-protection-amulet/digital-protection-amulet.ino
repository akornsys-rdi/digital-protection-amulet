// `avrdude -patmega32u4 -catmelice_isp -Pusb -Ulfuse:w:0xFF:m -Uhfuse:w:0xD0:m -Uefuse:w:0xCB:m -Ulock:w:0xFF:m`
// `avrdude -patmega32u4 -catmelice_isp -Pusb -Uflash:w:/home/rileystarlight/bin/opt/arduino-1.8.19/hardware/arduino/avr/bootloaders/caterina/Caterina-Micro.hex:i` 

#include <EEPROM.h>

/*  I / O  */
#define RED 13
#define GREEN 10
#define BLUE 9

/*  E E P R O M  */
// HEADER 16 BYTES (2 BYTES LIBRES)
#define EE_MAGIC_NUMBER 0x00   //8 bytes
#define EE_FS_VERSION 0x08     //2 bytes
#define EE_FS_SIZE 0x0A        //4 bytes

// CONFIG 32 BYTES (12 BYTES LIBRES)
#define EE_PAGE_COUNT 0x10     //2 bytes
#define EE_BAUDRATE 0x12       //1 bytes
#define EE_CONFIG1 0x13        //1 bytes (aes128) bit0: CRYPTO
#define EE_PASS 0x20           //16 bytes (sha256 & 0xFFFF0000)

// DEVICE 48 BYTES (3 BYTES LIBRES)
#define EE_VERSION 0x30        //4 bytes
#define EE_EDITION 0x34        //1 bytes
#define EE_ID 0x38             //8 bytes
#define EE_MODEL 0x40          //32 bytes

// SPELL PAGE 928 BYTES (10 BYTES LIBRE)
#define EE_SPELL 0x60          //864 bytes     Spell msg (US after title, title first)
#define EE_META_HASH 0x3C0     //32 bytes      Spell hash (sha256)
#define EE_META_LENGTH 0x3E0   //2 bytes       Spell msg size
#define EE_META_REV 0x3E2      //2 bytes       Spell revision
#define EE_META_EPOCH 0x3E4    //8 bytes       Spell epoch (64-bit unix epoch)
#define EE_META_I18N 0x3EC     //3 bytes       Spell lang (ISO 639‑3) "spa"
#define EE_META_CHSUM 0x3EF    //1 bytes       Spell chsum (sum8)
#define EE_META_TIMES 0x3FA    //2 bytes       Page times written
#define EE_META_LINKFWD 0x3FC  //2 bytes       Next page
#define EE_META_LINKBWD 0x3FE  //2 bytes       Previous page

/*  C O N S T A N T S  */
#define MAGIC_NUMBER_LENGTH 8
#define MAGIC_NUMBER "\x7D\x73\xA4\x1C\xDC\x7E\xFA\xCD"
#define MAX_FS_VERSION 1

/*  E N U M  */
enum ee_status_t {
    UNINITIALIZED = -1,
    UNKNOWN = 0,
    INITIALIZED = 1,
    VALID = 2
};

enum baudrate_t {
    BR1200 = 1,
    BR4800 = 2,
    BR9600 = 3,
    BR19200 = 4,
    BR38400 = 5,
    BR57600 = 6,
    BR115200 = 7
};

void setup() {
    pinMode(RED, OUTPUT);
    pinMode(GREEN, OUTPUT);
    pinMode(BLUE, OUTPUT);
    digitalWrite(RED, HIGH);
    digitalWrite(GREEN, HIGH);
    digitalWrite(BLUE, HIGH);
    SerialUSB.begin(9600);
    for (unsigned char i = 255; i > 1; i--) {
        analogWrite(RED, i);
        delay(1);
    }
    for (unsigned char i = 255; i > 1; i--) {
        analogWrite(GREEN, i);
        delay(1);
    }
    for (unsigned char i = 0; i < 255; i++) {
        analogWrite(RED, i);
        delay(1);
    }
    for (unsigned char i = 255; i > 1; i--) {
        analogWrite(BLUE, i);
        delay(1);
    }
    for (unsigned char i = 0; i < 255; i++) {
        analogWrite(GREEN, i);
        delay(1);
    }
    for (unsigned char i = 255; i > 1; i--) {
        analogWrite(RED, i);
        delay(1);
    }
    for (unsigned char i = 0; i < 255; i++) {
        analogWrite(BLUE, i);
        analogWrite(RED, i);
        delay(1);
    }
}

void loop() {
    static bool first_run = true;
    static bool connected = false;
    static bool printed = false;
    static bool empty = true;
    static char dir = -1;
    unsigned char c = '\0';
    static unsigned char v = 255;
    static unsigned int length = 0;
    static unsigned long t = 0;
    static unsigned long t_led = 0;

    if (first_run) {
        if (EEPROM.read(EE_PAGE_COUNT + 1)) empty = false;
        length = (EEPROM.read(EE_META_LENGTH) << 8);
        length |= (EEPROM.read(EE_META_LENGTH + 1));
        first_run = false;
    }
    if ((millis() - t >= 100) && (!connected)) {
        t = millis();
        connected = SerialUSB;
    }
    if (empty) {
        if ((connected) && (!printed)) {
            SerialUSB.println("Digital Protection Amulet");
            SerialUSB.println("Special Edition: Unique version for Patri");
            SerialUSB.println("\nNo spells found.");
            printed = true;
        }
        digitalWrite(RED, (millis() & 0x80));
    }
    else {
        if ((connected) && (!printed)) {
            SerialUSB.println("Digital Protection Amulet");
            SerialUSB.println("Special Edition: Unique version for Patri");
            SerialUSB.println("\nOne spell found.");
            SerialUSB.print("\nSpell title: ");
            for (unsigned int i = 0; i < length; i++) {
                c = EEPROM.read(EE_SPELL + i);
                if (c == 0x1F) SerialUSB.print("\n\n    \"");
                else if (c == 0x0A) SerialUSB.print("\n    ");
                else if (c != 0x00) SerialUSB.print(char(c));
            }
            SerialUSB.println("\"\n");
            SerialUSB.println("No other spells found.");
            printed = true;
        }
        if (millis() - t_led >= 3) {
            t_led = millis();
            v += dir;
            if ((v == 255) || (v == 0)) dir = -dir;
            analogWrite(RED, v);
            analogWrite(BLUE, v);
        }
    }
}
