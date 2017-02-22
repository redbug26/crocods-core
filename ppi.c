#include "ppi.h"

#include "sound.h"
#include "crtc.h"

#include "plateform.h"


#define PRINTER_BUSY    0x40    // Printer busy

#define REFRESH_HZ      0x10    // Screen refresh = 50Hz

#define CONSTRUCTEUR    0x07    // valeurs possibles :
// 0x00 = Isp
// 0x01 = Triumph
// 0x02 = Saisho
// 0x03 = Solavox
// 0x04 = Awa
// 0x05 = Schneider
// 0x06 = Orion
// 0x07 = Amstrad


#ifdef USE_TAPE


/********************************************************* !NAME! **************
 * Nom : CloseTap
 ********************************************************** !PATHS! *************
 * !./V1!\!./V2!\!./V3!\!./V4!\Fonctions
 ********************************************************** !1! *****************
 *
 * Fichier     : !./FPTH\/FLE!, ligne : !./LN!
 *
 * Description : Fermeture fichier cassette
 *
 * R�sultat    : /
 *
 * Variables globales modifi�es : fCas, OctetCalcul, PosBit, Mode
 *
 ********************************************************** !0! ****************/
void CloseTap( core_crocods_t *core )
{
    if ( core->fCas )
    {
        fwrite( BufTape, PosBufTape, 1, fCas );
        fclose( fCas );
        fCas = NULL;
    }
    OctetCalcul = 0;
    PosBit = 0;
    PosBufTape = 0;
    Mode = MODE_OFF;
#ifdef USE_SOUND_CAS
    SetSound( 0, 0, 0 );
#endif
}

/********************************************************* !NAME! **************
 * Nom : OpenTapWrite
 ********************************************************** !PATHS! *************
 * !./V1!\!./V2!\!./V3!\!./V4!\Fonctions
 ********************************************************** !1! *****************
 *
 * Fichier     : !./FPTH\/FLE!, ligne : !./LN!
 *
 * Description : Ouverture fichier cassette en �criture
 *
 * R�sultat    : /
 *
 * Variables globales modifi�es : fCas, OctetCalcul, PosBit, Mode
 *
 ********************************************************** !0! ****************/
void OpenTapWrite( core_crocods_t *core, char * Nom )
{
    CloseTap();
    fCas = fopen( Nom, "wb" );
    if ( fCas )
        Mode = MODE_WRITE;
}


/********************************************************* !NAME! **************
 * Nom : OpenTapRead
 ********************************************************** !PATHS! *************
 * !./V1!\!./V2!\!./V3!\!./V4!\Fonctions
 ********************************************************** !1! *****************
 *
 * Fichier     : !./FPTH\/FLE!, ligne : !./LN!
 *
 * Description : Ouverture fichier cassette en lecture
 *
 * R�sultat    : /
 *
 * Variables globales modifi�es : fCas, OctetCalcul, PosBit, Mode
 *
 ********************************************************** !0! ****************/
void OpenTapRead( core_crocods_t *core, char * Nom )
{
    CloseTap();
    fCas = fopen( Nom, "rb" );
    if ( fCas )
        Mode = MODE_READ;
}

#ifdef USE_SOUND_CAS
/********************************************************* !NAME! **************
 * Nom : SoundCas
 ********************************************************** !PATHS! *************
 * !./V1!\!./V2!\!./V3!\!./V4!\Fonctions
 ********************************************************** !1! *****************
 *
 * Fichier     : !./FPTH\/FLE!, ligne : !./LN!
 *
 * Description : Joue un son en fonction des bits lecture/�criture cassette
 *
 * R�sultat    : /
 *
 * Variables globales modifi�es : /
 *
 ********************************************************** !0! ****************/
static void SoundCas( core_crocods_t *core, int BitCas )
{
    static int ValBit = 0;
    static int CntBit = 0;
    static int CntFreq = 0;
    
    //
    // Calcul de la fr�quence : WriteCas est appel� tous les 1/384 cycles
    // d'horloge du Z80, qui est cadenc� � 3,3 Mhz, soit :
    // 3,3*1000000 / 384 = 8667 fois par secondes, soit ~ 4333 Hz
    //
    if ( ValBit != BitCas )
    {
        ValBit = BitCas;
        CntFreq++;
    }
    CntBit++;
    if ( CntBit == 255 )      // Attentre 255 mesures d'�chantillons
    {
        CntBit = 0;
        if ( ! CntFreq )
        {
            SetSound( 0, 0, 0 );
            SetSound( 3, 0, 0 );
        }
        else
        {
            SetSound( 0, 17 * CntFreq, 32 );       // 255 * 17 = 4301
            SetSound( 3, 17 * CntFreq, 16 );
        }
        CntFreq = 0;
    }
}
#endif

/********************************************************* !NAME! **************
 * Nom : WriteCas
 ********************************************************** !PATHS! *************
 * !./V1!\!./V2!\!./V3!\!./V4!\Fonctions
 ********************************************************** !1! *****************
 *
 * Fichier     : !./FPTH\/FLE!, ligne : !./LN!
 *
 * Description : Ecriture d'un bit dans le fichier cassette
 *
 * R�sultat    : /
 *
 * Variables globales modifi�es : OctetCalcul, PosBit
 *
 ********************************************************** !0! ****************/
void WriteCas( core_crocods_t *core )
{
    if ( ( Output[ 2 ] & 0x10 ) && Mode == MODE_WRITE )
    {
#ifdef USE_SOUND_CAS
        SoundCas( Output[ 2 ] & 0x20 );
#endif
        OctetCalcul |= ( ( Output[ 2 ] & 0x20 ) >> 5 ) << PosBit++;
        if ( PosBit == 8 )
        {
            BufTape[ PosBufTape++ ] = OctetCalcul;
            PosBufTape &= ( SIZE_BUF_TAPE - 1 );
            if ( ! PosBufTape )
            {
                //
                // Optimisiation de la taille �crite : si le buffer est rempli
                // de z�ros, alors on ne l'�crit pas.
                // Attention : le buffer doit �tre sup�rieur � 1024 Octets
                //
                int i = 0, vmax = 0;
                for ( i = 0; i < SIZE_BUF_TAPE; i++ )
                    vmax += BufTape[ i ];
                
                if ( vmax )
                    fwrite( BufTape, SIZE_BUF_TAPE, 1, fCas );
            }
            OctetCalcul = 0;
            PosBit = 0;
        }
    }
}


/********************************************************* !NAME! **************
 * Nom : ReadCas
 ********************************************************** !PATHS! *************
 * !./V1!\!./V2!\!./V3!\!./V4!\Fonctions
 ********************************************************** !1! *****************
 *
 * Fichier     : !./FPTH\/FLE!, ligne : !./LN!
 *
 * Description : Lecture d'un bit depuis le fichier cassette
 *
 * R�sultat    : /
 *
 * Variables globales modifi�es : OctetCalcul, PosBit, BitTapeIn
 *
 ********************************************************** !0! ****************/
void ReadCas( core_crocods_t *core )
{
    BitTapeIn = 0;
    if ( ( Output[ 2 ] & 0x10 ) && Mode == MODE_READ )
    {
        if ( ! PosBufTape && ! PosBit )
            fread( BufTape, SIZE_BUF_TAPE, 1, fCas );
        
        if ( ! PosBit )
        {
            OctetCalcul = BufTape[ PosBufTape++ ];
            PosBufTape &= ( SIZE_BUF_TAPE - 1 );
        }
        if ( OctetCalcul & ( 1 << PosBit++ ) )
            BitTapeIn = 0x80;
        
        if ( PosBit == 8 )
            PosBit = 0;
        
#ifdef USE_SOUND_CAS
        SoundCas( BitTapeIn );
#endif
    }
}
#endif


/********************************************************* !NAME! **************
 * Nom : UpdatePSG
 ********************************************************** !PATHS! *************
 * !./V1!\!./V2!\!./V3!\!./V4!\Fonctions
 ********************************************************** !1! *****************
 *
 * Fichier     : !./FPTH\/FLE!, ligne : !./LN!
 *
 * Description : Mise � jour des registres du PSG en fonction du port A du PPI
 *
 * R�sultat    : /
 *
 * Variables globales modifi�es : RegPSGSel
 *
 ********************************************************** !0! ****************/
static void UpdatePSG( core_crocods_t *core )
{
    switch ( core->modePSG )
    {
        case 2: // MODE_WRITE
            
            
            if (core->RegPSGSel<6) {
                core->SoundBusy=10; // Number of frame to display
            }
            
            Write8912( core, core->RegPSGSel, core->Output[ 0 ] );
            break;
            
        case 3: // MODE_LATCH
            core->RegPSGSel = core->Output[ 0 ];
            break;
            
        default:
            //            printf("Unknown PSG: %d\n", core->modePSG);
            break;
    }
}


/********************************************************* !NAME! **************
 * Nom : PPI_WriteControl
 ********************************************************** !PATHS! *************
 * !./V1!\!./V2!\!./V3!\!./V4!\Fonctions
 ********************************************************** !1! *****************
 *
 * Fichier     : !./FPTH\/FLE!, ligne : !./LN!
 *
 * Description : Ecriture du registre de controle du PPI
 *
 * R�sultat    : /
 *
 * Variables globales modifi�es : RegsPPI, Output, Mask
 *
 ********************************************************** !0! ****************/
static void PPI_WriteControl( core_crocods_t *core, int val )
{
    core->RegsPPI[ 3 ] = val;
    if ( val & 0x80 )
    {
        core->RegsPPI[ 0 ] = core->RegsPPI[ 2 ] = 0;
        core->Mask[ 0 ] = ( val & 0x10 ) ? 0xFF : 0;
        core->Mask[ 2 ] = 0xFF;
        if ( ! ( val & 0x01 ) )
            core->Mask[ 2 ] &= 0xF0;
        
        if ( ! ( val & 0x08 ) )
            core->Mask[ 2 ] &= 0x0F;
    }
    else
    {
        int BitMask = 1 << ( ( val >> 1 ) & 0x07 );
        if ( val & 1 )
            core->RegsPPI[ 2 ] |= BitMask;
        else
            core->RegsPPI[ 2 ] &= ~BitMask;
    }
    core->Output[ 0 ] = ( core->RegsPPI[ 0 ] & ~core->Mask[ 0 ] ) | core->Mask[ 0 ];
    core->Output[ 2 ] = ( core->RegsPPI[ 2 ] & ~core->Mask[ 2 ] ) | core->Mask[ 2 ];
}


/********************************************************* !NAME! **************
 * Nom : WritePPI
 ********************************************************** !PATHS! *************
 * !./V1!\!./V2!\!./V3!\!./V4!\Fonctions
 ********************************************************** !1! *****************
 *
 * Fichier     : !./FPTH\/FLE!, ligne : !./LN!
 *
 * Description : Ecriture d'un registre du PPI
 *
 * R�sultat    : /
 *
 * Variables globales modifi�es : RegsPPI, Output, ligneClav, modePSG
 *
 ********************************************************** !0! ****************/
void WritePPI( core_crocods_t *core, int adr, int val )
{
    switch( ( adr >> 8 ) & 3 )
    {
        case 0 : // 0xF4xx
            core->RegsPPI[ 0 ] = val;
            core->Output[ 0 ] = ( val & ~core->Mask[ 0 ] ) | core->Mask[ 0 ];
            UpdatePSG(core);
            break;
            
        case 1 : // 0xF5xx
            break;
            
        case 2 : // 0xF6xx
            core->RegsPPI[ 2 ] = val;
            core->Output[ 2 ] = ( val & ~core->Mask[ 2 ] ) | core->Mask[ 2 ];
            core->ligneClav = core->Output[ 2 ] & 0x0F;
            core->modePSG = core->Output[ 2 ] >> 6;
            UpdatePSG(core);
            break;
            
        case 3 : // 0xF7xx
            PPI_WriteControl( core, val );
            break;
    }
}


/********************************************************* !NAME! **************
 * Nom : ReadPPI
 ********************************************************** !PATHS! *************
 * !./V1!\!./V2!\!./V3!\!./V4!\Fonctions
 ********************************************************** !1! *****************
 *
 * Fichier     : !./FPTH\/FLE!, ligne : !./LN!
 *
 * Description : Lecture d'un registre du PPI
 *
 * R�sultat    : Le registre du PPI selectionn�
 *
 * Variables globales modifi�es : /
 *
 ********************************************************** !0! ****************/
int ReadPPI( core_crocods_t *core, int adr )
{
    switch( ( adr >> 8 ) & 3 )
    {
        case 0 : // 0xF4xx
            if ( core->modePSG == 1 )
            {
                if ( core->RegPSGSel == 14 ) {
                    core->KeyboardScanned = TRUE;
                    return( core->clav[ core->ligneClav ] );
                }
                
                return(Read8912(core, core->RegPSGSel));
            }
            return( 0xFF );
            
        case 1 : // 0xF5xx
            return( ( CONSTRUCTEUR << 1 )
                   | REFRESH_HZ
                   | core->VSync
#ifdef USE_TAPE
                   | BitTapeIn
#endif
                   ); // Port B toujours en lecture
            
        case 2 : // 0xF6xx
            return( ( core->Input[ 2 ] & core->Mask[ 2 ] )
                   | ( core->RegsPPI[ 2 ] & ~core->Mask[ 2 ] )
                   );
    }
    return( 0xFF );
}

void ResetPPI( core_crocods_t *core) {
    core->fCas = NULL;  // Handle fichier lecture ou �criture cassette
    
    core->BitTapeIn = 0;  // Bit de lecture cassette pour le port F5xx
    core->PosBit = 0;  // Position de bit de calcul pour lecture/�criture cassette
    core->OctetCalcul = 0;   // Octet de calcul pour lecture/�criture cassette
    core->Mode = MODE_OFF;  // Mode d'acc�s cassette (lecture, �criture, ou off)
    
}



BOOL Keyboard_HasBeenScanned(core_crocods_t *core)
{
    return core->KeyboardScanned;
}

void Keyboard_Reset(core_crocods_t *core)
{
    core->KeyboardScanned = FALSE;
}
