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
#define EE_SPELL 0x60          //864 bytes     Spell msg (US after title, title first)
#define EE_META_HASH 0x3C0     //32 bytes      Spell hash (sha256)
#define EE_META_LENGTH 0x3E0   //2 bytes       Spell msg size
#define EE_META_REV 0x3E2      //2 bytes       Spell revision
#define EE_META_EPOCH 0x3E4    //4 bytes       Spell epoch
#define EE_META_I18N 0x3E8     //3 bytes       Spell lang (ISO 639‑3) "spa"
#define EE_META_CHSUM 0x3EB    //1 bytes       Spell chsum (sum)
#define EE_META_TIMES 0x3FA    //2 bytes       Page times written
#define EE_META_LINKFWD 0x3FC  //2 bytes       Next page
#define EE_META_LINKBWD 0x3FE  //2 bytes       Previous page


void setup() {
    SerialUSB.begin(9600);
    while(!SerialUSB);
}

void loop() {
    unsigned char c = 0;
    SerialUSB.println("EEPROM DUMP\n");
    for(unsigned int i = 0; i < EEPROM.length(); i++) {
        SerialUSB.print("0x");
        SerialUSB.print(i, HEX);
        SerialUSB.print(" - 0x");
        SerialUSB.println(EEPROM.read(i),HEX);
    }

    SerialUSB.print("\nMAGIC NUMBER - 0x");
    for(unsigned int i = EE_MAGIC_NUMBER; i < EE_MAGIC_NUMBER + 8; i++) {
        SerialUSB.print(EEPROM.read(i), HEX);
    }

    SerialUSB.print("\nFS VERSION - 0x");
    for(unsigned int i = EE_FS_VERSION; i < EE_FS_VERSION + 2; i++) {
        SerialUSB.print(EEPROM.read(i), HEX);
    }

    SerialUSB.print("\nFS SIZE - 0x");
    for(unsigned int i = EE_FS_SIZE; i < EE_FS_SIZE + 4; i++) {
        SerialUSB.print(EEPROM.read(i), HEX);
    }

    SerialUSB.print("\nFCONFIG EMPTY - 0x");
    for(unsigned int i = EE_PAGE_COUNT; i < EE_PAGE_COUNT + 2; i++) {
        SerialUSB.print(EEPROM.read(i), HEX);
    }

    SerialUSB.print("\nCONFIG BAUDRATE - 0x");
    SerialUSB.print(EEPROM.read(EE_BAUDRATE), HEX);

    SerialUSB.print("\nCONFIG CONFIG - 0x");
    SerialUSB.print(EEPROM.read(EE_CONFIG1), HEX);

    SerialUSB.print("\nCONFIG PASS - 0x");
    for(unsigned int i = EE_PASS; i < EE_PASS + 16; i++) {
        SerialUSB.print(EEPROM.read(i), HEX);
    }

    SerialUSB.print("\nDEVICE VERSION - 0x");
    for(unsigned int i = EE_VERSION; i < EE_VERSION + 4; i++) {
        SerialUSB.print(EEPROM.read(i), HEX);
    }

    SerialUSB.print("\nDEVICE EDITION - 0x");
    SerialUSB.print(EEPROM.read(EE_EDITION), HEX);

    SerialUSB.print("\nDEVICE ID - 0x");
    for(unsigned int i = EE_ID; i < EE_ID + 8; i++) {
        SerialUSB.print(EEPROM.read(i), HEX);
    }

    SerialUSB.print("\nDEVICE MODEL - ");
    for(unsigned int i = EE_MODEL; i < EE_MODEL + 32; i++) {
        SerialUSB.print(char(EEPROM.read(i)));
    }

    SerialUSB.println("\nSPELL [");
    for(unsigned int i = EE_SPELL; i < EE_SPELL + 864; i=i+32) {
        for(unsigned int j = i; j < i + 32; j++) {
            SerialUSB.print(char(EEPROM.read(j)));
        }
        SerialUSB.println();
    }
    SerialUSB.print("]");

    SerialUSB.print("\nSPELL HASH - 0x");
    for(unsigned int i = EE_META_HASH; i < EE_META_HASH + 32; i++) {
        SerialUSB.print(EEPROM.read(i), HEX);
    }

    SerialUSB.print("\nSPELL LENGTH - 0x");
    for(unsigned int i = EE_META_LENGTH; i < EE_META_LENGTH + 2; i++) {
        SerialUSB.print(EEPROM.read(i), HEX);
    }

    SerialUSB.print("\nSPELL REV - 0x");
    for(unsigned int i = EE_META_REV; i < EE_META_REV + 2; i++) {
        SerialUSB.print(EEPROM.read(i), HEX);
    }

    SerialUSB.print("\nSPELL EPOCH - 0x");
    for(unsigned int i = EE_META_EPOCH; i < EE_META_EPOCH + 4; i++) {
        SerialUSB.print(EEPROM.read(i), HEX);
    }

    SerialUSB.print("\nSPELL I18N - ");
    for(unsigned int i = EE_META_I18N; i < EE_META_I18N + 3; i++) {
        SerialUSB.print(char(EEPROM.read(i)));
    }

    SerialUSB.print("\nSPELL CKSUM - 0x");
    SerialUSB.print(EEPROM.read(EE_META_CHSUM), HEX);

    SerialUSB.print("\nPAGE TIMES WRITTEN - 0x");
    for(unsigned int i = EE_META_TIMES; i < EE_META_TIMES + 2; i++) {
        SerialUSB.print(EEPROM.read(i), HEX);
    }

    SerialUSB.print("\nPAGE LINK FORWARD- 0x");
    for(unsigned int i = EE_META_LINKFWD; i < EE_META_LINKFWD + 2; i++) {
        SerialUSB.print(EEPROM.read(i), HEX);
    }

    SerialUSB.print("\nPAGE LINK BACKWARD - 0x");
    for(unsigned int i = EE_META_LINKBWD; i < EE_META_LINKBWD + 2; i++) {
        SerialUSB.print(EEPROM.read(i), HEX);
    }

    while(1);
}
