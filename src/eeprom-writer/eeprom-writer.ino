#include <EEPROM.h>

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

// SPELL PAGE 928 BYTES (14 BYTES LIBRE)
#define EE_SPELL 0x60          //832 bytes     Spell msg
#define EE_META_TITLE 0x3A0    //32 bytes      Spell title
#define EE_META_HASH 0x3C0     //32 bytes      Spell hash (sha256)
#define EE_META_LENGTH 0x3E0   //2 bytes       Spell msg size
#define EE_META_CHSUM 0x3E2    //2 bytes       Spell chsum
#define EE_META_EPOCH 0x3E4    //4 bytes       Spell epoch
#define EE_META_I18N 0x3E8     //2 bytes       Spell lang (ISO 639‑3)
#define EE_META_REV 0x3EA      //2 bytes       Spell revision
#define EE_META_TIMES 0x3FA    //2 bytes       Page times written
#define EE_META_LINKFWD 0x3FC  //2 bytes       Next page
#define EE_META_LINKBWD 0x3FE  //2 bytes       Previous page

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    
    //HEADER
    EEPROM.update(EE_MAGIC_NUMBER, 0x7D);
    EEPROM.update(EE_MAGIC_NUMBER + 1, 0x73);
    EEPROM.update(EE_MAGIC_NUMBER + 2, 0xA4);
    EEPROM.update(EE_MAGIC_NUMBER + 3, 0x1C);
    EEPROM.update(EE_MAGIC_NUMBER + 4, 0xDC);
    EEPROM.update(EE_MAGIC_NUMBER + 5, 0x7E);
    EEPROM.update(EE_MAGIC_NUMBER + 6, 0xFA);
    EEPROM.update(EE_MAGIC_NUMBER + 7, 0xCD);
    EEPROM.update(EE_FS_VERSION, 0);
    EEPROM.update(EE_FS_VERSION + 1, 1);
    EEPROM.update(EE_FS_SIZE, 0);
    EEPROM.update(EE_FS_SIZE + 1, 0);
    EEPROM.update(EE_FS_SIZE + 2, 4);
    EEPROM.update(EE_FS_SIZE + 3, 0);

    //CONFIG
    EEPROM.update(EE_PAGE_COUNT, 0);
    EEPROM.update(EE_PAGE_COUNT + 1, 0);
    EEPROM.update(EE_BAUDRATE, 3);

    //DEVICE
    EEPROM.update(EE_VERSION, 1);
    EEPROM.update(EE_VERSION + 1, 0);
    EEPROM.update(EE_VERSION + 2, 0);
    EEPROM.update(EE_VERSION + 3, 1);
    EEPROM.update(EE_EDITION, 1);
    EEPROM.update(EE_ID, 0x97);
    EEPROM.update(EE_ID + 1, 0xFE);
    EEPROM.update(EE_ID + 2, 0xC1);
    EEPROM.update(EE_ID + 3, 0x96);
    EEPROM.update(EE_ID + 4, 0xDA);
    EEPROM.update(EE_ID + 5, 0x39);
    EEPROM.update(EE_ID + 6, 0x5C);
    EEPROM.update(EE_ID + 7, 0x5A);
    EEPROM.update(EE_MODEL, '\0');
    EEPROM.update(EE_MODEL + 1, '\0');
    EEPROM.update(EE_MODEL + 2, '\0');
    EEPROM.update(EE_MODEL + 3, '\0');
    EEPROM.update(EE_MODEL + 4, '\0');
    EEPROM.update(EE_MODEL + 5, '\0');
    EEPROM.update(EE_MODEL + 6, '\0');
    EEPROM.update(EE_MODEL + 7, '\0');
    EEPROM.update(EE_MODEL + 8, '\0');
    EEPROM.update(EE_MODEL + 9, '\0');
    EEPROM.update(EE_MODEL + 10, '\0');
    EEPROM.update(EE_MODEL + 11, '\0');
    EEPROM.update(EE_MODEL + 12, '\0');
    EEPROM.update(EE_MODEL + 13, '\0');
    EEPROM.update(EE_MODEL + 14, '\0');
    EEPROM.update(EE_MODEL + 15, '\0');
    EEPROM.update(EE_MODEL + 16, '\0');
    EEPROM.update(EE_MODEL + 17, '\0');
    EEPROM.update(EE_MODEL + 18, '\0');
    EEPROM.update(EE_MODEL + 19, '\0');
    EEPROM.update(EE_MODEL + 20, '\0');
    EEPROM.update(EE_MODEL + 21, '\0');
    EEPROM.update(EE_MODEL + 22, '\0');
    EEPROM.update(EE_MODEL + 23, '\0');
    EEPROM.update(EE_MODEL + 24, '\0');
    EEPROM.update(EE_MODEL + 25, '\0');
    EEPROM.update(EE_MODEL + 26, '\0');
    EEPROM.update(EE_MODEL + 27, '\0');
    EEPROM.update(EE_MODEL + 28, '\0');
    EEPROM.update(EE_MODEL + 29, '\0');
    EEPROM.update(EE_MODEL + 30, '\0');
    EEPROM.update(EE_MODEL + 31, '\0');
}

void loop() {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(125);
    digitalWrite(LED_BUILTIN, LOW);
    delay(125); 
}
