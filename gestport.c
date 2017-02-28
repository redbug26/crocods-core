#include  "plateform.h"
#include  "config.h"
#include  "ppi.h"
#include  "crtc.h"
#include  "upd.h"
#include  "vga.h"
#include  "gestport.h"

u8 ReadPort( core_crocods_t *core, u16 port )
{
    if (port==0xfefe) {
        return 0xaa;        // CrocoDS Rompack
    }

    if ( ! ( port & 0x0480 ) ) {
        return( ReadUPD( core, port ) );
    }

    if ( ! ( port & 0x0800 ) ) {

        u16 index = (port & 0x0300) >> 8;
        if (index == 3)
        {
            printf("index 3\n");
            //            Data = PPI_ReadControl();
            return( ReadPPI( core, port ) );

        } else {
            //            Data = PPI_ReadPort(Index);
            return( ReadPPI( core, port ) );

        }
     }

    // Kempston Mouse http://www.cpcwiki.eu/index.php/Kempston_Mouse - test4.dsk in Arnold "acid" test and with Carrier.DSK

    if (port == 0xFBEE) {   // I/O port for X position is decoded as xxxx x0x1 xxx0 xxx0
        return core->kempstonMouseX;
    }
    if (port == 0xFBEF) {   // I/O port for Y position is decoded as xxxx x0x1 xxx0 xxx1
        return core->kempstonMouseY;
    }
    if (port == 0xFAEF) {   // I/O port for Buttons is decoded as    xxxx x0x0 xxx0 xxxx
        u8 button = core->kempstonMouseButton;
        core->kempstonMouseButton = 0;
        return button;
    }

    printf("Read P%04X\n", port);

    return( 0xFF );
}

void WritePort( core_crocods_t *core, u16 port, u8 val )
{
//    port=0; // A effacer

// http://cpcwiki.eu/index.php/Default_I/O_Port_Summary
// http://cpcwiki.eu/index.php/I/O_Port_Summary
// http://www.cpcwiki.eu/index.php/M4_Board <-- for the M4


    if ( ( port & 0xC000 ) == 0x04000 ) {
        // strcat(chaine, " VGA");
        WriteVGA( core, port, val );
        return;
    }

    if ( ! ( port & 0x4000 ) ) {
        // strcat(chaine, " CRC");
        WriteCRTC( core, port, val );
        return;

    }

    if ( ! ( port & 0x2000 ) ) {
        // strcat(chaine, " ROM");
        WriteROM( core, val );
        return;

    }

    if ( ! ( port & 0x1000 ) ) {
        // strcat(chaine, " PRN");
        //    PrintVal( val );
        return;

    }

    if ( ! ( port & 0x0800 ) ) {
        // strcat(chaine, " PPI");
        WritePPI( core, port, val );
        return;

    }

    if ( ! ( port & 0x0480 ) ) {
        // strcat(chaine, " UPD");
        WriteUPD( core, port, val );
        return;

    }

    if (port==0xF8FF) {     // Peripheral Soft Reset -> Do nothing
        return;
    }

    printf("Write P%04X %d\n", port, val);
}

