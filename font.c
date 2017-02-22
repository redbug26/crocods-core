#include  "crocods.h"

//byte array representing the picture
const u16 fontData[] = {
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0101, 0x0002, 0x0000, 0x0000, 0x0301, 0x0002, 0x0000, 0x0000, 0x0304, 0x0002, 0x0000, 0x0000, 0x0605, 0x0002, 0x0000, 0x0000, 0x0202, 0x0002, 0x0000, 0x0000, 0x0707, 0x0002, 0x0000, 0x0000, 0x0808, 0x0002, 0x0000, 0x0000, 0x0202, 0x0002, 0x0000, 0x0000, 0x0201, 0x0201, 0x0000, 0x0000, 0x0201, 0x0201, 0x0000, 0x0000, 0x0203, 0x0203, 0x0000, 0x0000, 0x0202, 0x0202, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0201, 0x0100, 0x0002, 0x0400, 0x0404, 0x0404, 0x0204, 0x0200, 0x0205, 0x0502, 0x0202, 0x0000, 0x0203, 0x0300, 0x0002, 0x0700, 0x0707, 0x0707, 0x0207, 0x0200, 0x0207, 0x0702, 0x0202, 0x0000, 0x0202, 0x0200, 0x0002, 0x0000, 0x0100, 0x0002, 0x0000, 0x0100, 0x0101, 0x0101, 0x0000, 0x0904, 0x0402, 0x0902, 0x0204, 0x0500, 0x0508, 0x020A, 0x0202, 0x0000, 0x030A, 0x0308, 0x0000, 0x0607, 0x0702, 0x0602, 0x0207, 0x0702, 0x0707, 0x0707, 0x020A, 0x0200, 0x0702, 0x0202, 0x0002, 0x0000, 0x0000, 0x0000, 0x0000, 0x0100, 0x0201, 0x0000, 0x0A01, 0x0300, 0x0203, 0x0400, 0x0209, 0x0200, 0x0202, 0x0605, 0x0002, 0x0000, 0x0300, 0x0206, 0x0000, 0x0000, 0x0607, 0x0702, 0x0207, 0x0700, 0x0206, 0x0800, 0x0208, 0x0A00, 0x0002, 0x0200, 0x0202, 0x0000, 0x0901, 0x0000, 0x0000, 0x0100, 0x0100, 0x0209, 0x0000, 0x0A00, 0x0904, 0x0202, 0x0000, 0x0500, 0x0506, 0x0002, 0x0A05, 0x0603, 0x0002, 0x0803, 0x0206, 0x0207, 0x0000, 0x0708, 0x0002, 0x0702, 0x0807, 0x0206, 0x0A07, 0x0200, 0x0202, 0x0002, 0x0202, 0x0000, 0x0100, 0x0901, 0x0002, 0x0000, 0x0000, 0x0901, 0x0002, 0x0000, 0x0400, 0x0209, 0x0000, 0x0000, 0x0200, 0x0002, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0901, 0x0002, 0x0000, 0x0400, 0x0209, 0x0000, 0x0000, 0x0500, 0x0002, 0x0000, 0x0000, 0x0300, 0x0002, 0x0000, 0x0000, 0x0700, 0x000A, 0x0000, 0x0000, 0x0200, 0x0607, 0x0002, 0x0000, 0x0000, 0x0202, 0x0002, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0100, 0x0009, 0x0000, 0x0000, 0x0200, 0x0204, 0x0000, 0x0000, 0x0000, 0x0205, 0x0000, 0x0000, 0x0000, 0x0203, 0x0000, 0x0000, 0x0000, 0x0207, 0x0000, 0x0000, 0x0700, 0x0206, 0x0000, 0x0000, 0x0200, 0x0002, 0x0000, 0x0000, 0x0100, 0x0002, 0x0000, 0x0100, 0x0102, 0x0102, 0x000A, 0x0200, 0x0304, 0x0A04, 0x0002, 0x0000, 0x0502, 0x020A, 0x0000, 0x0000, 0x0803, 0x0A03, 0x0000, 0x0700, 0x070A, 0x0702, 0x000A, 0x0200, 0x0702, 0x0202, 0x0002, 0x0000, 0x0200, 0x0002, 0x0000, 0x0000, 0x0300, 0x0002, 0x0000, 0x0000, 0x0100, 0x0002, 0x0000, 0x0000, 0x0400, 0x0002, 0x0000, 0x0505, 0x0505, 0x0505, 0x0208, 0x0202, 0x0302, 0x0202, 0x0202, 0x0000, 0x0700, 0x0002, 0x0000, 0x0000, 0x0700, 0x0002, 0x0000, 0x0000, 0x0200, 0x0002, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0800, 0x0A08, 0x0000, 0x0000, 0x0300, 0x0A03, 0x0000, 0x0000, 0x0200, 0x0207, 0x0000, 0x0000, 0x0700, 0x0206, 0x0000, 0x0000, 0x0200, 0x0002, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0505, 0x0505, 0x0505, 0x0208, 0x0202, 0x0202, 0x0202, 0x0202, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0700, 0x0207, 0x0000, 0x0000, 0x0800, 0x0208, 0x0000, 0x0000, 0x0200, 0x0202, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0400, 0x000A, 0x0000, 0x0000, 0x0605, 0x0002, 0x0000, 0x0300, 0x0206, 0x0000, 0x0000, 0x0607, 0x0002, 0x0000, 0x0700, 0x0206, 0x0000, 0x0000, 0x0200, 0x0002, 0x0000, 0x0000, 0x0100, 0x0101, 0x0301, 0x0000, 0x0901, 0x0202, 0x0109, 0x0203, 0x0204, 0x0000, 0x0400, 0x0204, 0x0205, 0x0000, 0x0500, 0x0205, 0x0203, 0x0000, 0x0300, 0x0203, 0x0607, 0x0000, 0x0706, 0x0208, 0x0702, 0x0707, 0x0807, 0x020A, 0x0200, 0x0202, 0x0202, 0x0002, 0x0000, 0x0300, 0x0201, 0x0000, 0x0000, 0x0103, 0x0201, 0x0000, 0x0000, 0x0400, 0x0204, 0x0000, 0x0000, 0x0500, 0x0205, 0x0000, 0x0000, 0x0300, 0x0203, 0x0000, 0x0000, 0x0700, 0x0207, 0x0000, 0x0000, 0x0700, 0x0207, 0x0000, 0x0000, 0x0200, 0x0202, 0x0000, 0x0100, 0x0101, 0x0301, 0x0000, 0x0901, 0x0202, 0x0109, 0x0203, 0x0202, 0x0000, 0x0400, 0x0203, 0x0000, 0x0800, 0x0805, 0x020A, 0x0800, 0x0803, 0x020A, 0x0002, 0x0708, 0x0206, 0x0002, 0x0000, 0x0707, 0x0707, 0x0707, 0x0207, 0x0202, 0x0202, 0x0202, 0x0202, 0x0100, 0x0101, 0x0301, 0x0000, 0x0901, 0x0202, 0x0109, 0x0203, 0x0202, 0x0000, 0x0400, 0x0204, 0x0000, 0x0505, 0x0505, 0x0202, 0x0000, 0x0200, 0x030A, 0x0203, 0x0607, 0x0000, 0x0706, 0x0208, 0x0702, 0x0707, 0x0807, 0x020A, 0x0200, 0x0202, 0x0202, 0x0002, 0x0000, 0x0000, 0x0101, 0x0002, 0x0000, 0x0100, 0x0101, 0x0002, 0x0000, 0x0904, 0x0404, 0x0002, 0x0500, 0x0206, 0x0505, 0x0002, 0x0603, 0x0002, 0x0303, 0x0002, 0x0707, 0x0707, 0x0707, 0x0207, 0x0202, 0x0202, 0x0707, 0x0202, 0x0000, 0x0000, 0x0202, 0x0002, 0x0103, 0x0101, 0x0101, 0x0002, 0x0103, 0x0202, 0x0202, 0x0002, 0x0404, 0x0404, 0x0304, 0x0000, 0x0805, 0x020A, 0x0506, 0x0208, 0x0202, 0x0002, 0x0300, 0x0203, 0x0607, 0x0000, 0x0700, 0x0208, 0x0702, 0x0707, 0x0807, 0x020A, 0x0200, 0x0202, 0x0202, 0x0002, 0x0000, 0x0103, 0x0201, 0x0000, 0x0100, 0x0901, 0x0202, 0x0000, 0x0403, 0x0404, 0x0304, 0x0000, 0x0505, 0x0206, 0x050A, 0x0208, 0x0803, 0x0002, 0x0800, 0x0203, 0x0708, 0x0006, 0x0700, 0x0208, 0x0802, 0x0707, 0x0807, 0x0202, 0x0200, 0x0202, 0x0202, 0x0002, 0x0101, 0x0101, 0x0101, 0x0201, 0x0202, 0x0202, 0x010A, 0x0201, 0x0000, 0x0000, 0x0404, 0x0209, 0x0000, 0x0800, 0x0605, 0x0002, 0x0000, 0x0300, 0x0A03, 0x0000, 0x0000, 0x0700, 0x0207, 0x0000, 0x0000, 0x0700, 0x0207, 0x0000, 0x0000, 0x0200, 0x0202, 0x0000, 0x0300, 0x0101, 0x0301, 0x0000, 0x0103, 0x0209, 0x010A, 0x0003, 0x0403, 0x000A, 0x0400, 0x0203, 0x0800, 0x0505, 0x0805, 0x0202, 0x0303, 0x020A, 0x0302, 0x0003, 0x0707, 0x0006, 0x0700, 0x0207, 0x0702, 0x0707, 0x0707, 0x0202, 0x0200, 0x0202, 0x0202, 0x0002, 0x0300, 0x0101, 0x0301, 0x0000, 0x0103, 0x0209, 0x010A, 0x0003, 0x0304, 0x0002, 0x0300, 0x0204, 0x0508, 0x0206, 0x0500, 0x0205, 0x0800, 0x0303, 0x0303, 0x0208, 0x0000, 0x0602, 0x0707, 0x0206, 0x0000, 0x0707, 0x0A08, 0x0002, 0x0000, 0x0202, 0x0202, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0100, 0x0201, 0x0000, 0x0000, 0x0300, 0x0203, 0x0000, 0x0000, 0x0200, 0x0202, 0x0000, 0x0000, 0x0300, 0x0203, 0x0000, 0x0000, 0x0800, 0x0208, 0x0000, 0x0000, 0x0200, 0x0202, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0300, 0x0A03, 0x0000, 0x0000, 0x0400, 0x0A04, 0x0000, 0x0000, 0x0000, 0x0205, 0x0000, 0x0000, 0x0300, 0x0206, 0x0000, 0x0000, 0x0200, 0x0202, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0100, 0x000A, 0x0000, 0x0000, 0x0901, 0x0002, 0x0000, 0x0400, 0x0209, 0x0000, 0x0000, 0x0605, 0x0002, 0x0000, 0x0000, 0x0302, 0x000A, 0x0000, 0x0000, 0x0200, 0x0A07, 0x0000, 0x0000, 0x0000, 0x0702, 0x000A, 0x0000, 0x0000, 0x0200, 0x0002, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0404, 0x0404, 0x0404, 0x0203, 0x0202, 0x0202, 0x0202, 0x0202, 0x0303, 0x0303, 0x0303, 0x0208, 0x0202, 0x0202, 0x0202, 0x0202, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0100, 0x000A, 0x0000, 0x0000, 0x0200, 0x0A01, 0x0000, 0x0000, 0x0000, 0x0402, 0x000A, 0x0000, 0x0000, 0x0200, 0x0A05, 0x0000, 0x0000, 0x0300, 0x0206, 0x0000, 0x0000, 0x0607, 0x0002, 0x0000, 0x0700, 0x0206, 0x0000, 0x0000, 0x0A00, 0x0002, 0x0000, 0x0000, 0x0101, 0x0001, 0x0000, 0x0100, 0x0209, 0x010A, 0x0000, 0x0400, 0x0002, 0x0400, 0x0002, 0x0000, 0x0002, 0x0605, 0x0002, 0x0000, 0x0300, 0x0206, 0x0000, 0x0000, 0x0000, 0x0002, 0x0000, 0x0000, 0x0700, 0x000A, 0x0000, 0x0000, 0x0000, 0x0002, 0x0000, 0x0000, 0x0101, 0x0101, 0x0000, 0x0100, 0x0209, 0x0902, 0x0001, 0x0904, 0x0402, 0x0204, 0x0409, 0x0205, 0x0605, 0x0202, 0x0500, 0x0203, 0x0603, 0x0000, 0x0300, 0x0607, 0x0702, 0x0207, 0x0700, 0x0702, 0x0206, 0x0202, 0x0607, 0x0200, 0x0707, 0x0707, 0x0206, 0x0900, 0x0101, 0x0901, 0x0002, 0x0100, 0x0903, 0x0103, 0x0002, 0x0400, 0x0209, 0x0409, 0x000A, 0x0509, 0x000A, 0x050A, 0x0209, 0x0308, 0x0303, 0x0303, 0x0208, 0x0707, 0x0202, 0x0702, 0x0207, 0x0807, 0x0002, 0x0800, 0x0207, 0x0202, 0x0002, 0x0200, 0x0202, 0x0101, 0x0101, 0x0301, 0x0000, 0x0101, 0x0202, 0x0109, 0x0203, 0x0404, 0x0002, 0x0100, 0x0204, 0x0505, 0x0505, 0x0505, 0x020A, 0x0303, 0x0202, 0x0302, 0x0203, 0x0707, 0x0002, 0x070A, 0x0208, 0x0707, 0x0707, 0x0807, 0x020A, 0x0202, 0x0202, 0x0202, 0x0002, 0x0900, 0x0101, 0x0101, 0x000A, 0x0109, 0x0A01, 0x0902, 0x0A01, 0x0404, 0x020A, 0x0000, 0x0200, 0x0505, 0x0002, 0x0000, 0x0000, 0x0303, 0x000A, 0x0000, 0x0000, 0x0706, 0x0207, 0x0600, 0x0A07, 0x0602, 0x0707, 0x0707, 0x0206, 0x0200, 0x0202, 0x0202, 0x0002, 0x0101, 0x0101, 0x0903, 0x0000, 0x0101, 0x0A02, 0x0101, 0x0009, 0x0404, 0x0002, 0x0402, 0x0204, 0x0505, 0x0002, 0x0500, 0x0205, 0x0303, 0x0002, 0x0300, 0x0203, 0x0707, 0x0A02, 0x0707, 0x0206, 0x0707, 0x0707, 0x0608, 0x0002, 0x0202, 0x0202, 0x0202, 0x0000, 0x0101, 0x0101, 0x0101, 0x0201, 0x0101, 0x0202, 0x0202, 0x0202, 0x0404, 0x0002, 0x0000, 0x0000, 0x0505, 0x0505, 0x0805, 0x0002, 0x0303, 0x0202, 0x0202, 0x0002, 0x0707, 0x0002, 0x0000, 0x0000, 0x0707, 0x0707, 0x0707, 0x0007, 0x0202, 0x0202, 0x0202, 0x0202, 0x0101, 0x0101, 0x0101, 0x0201, 0x0101, 0x0202, 0x0202, 0x0202, 0x0404, 0x0002, 0x0000, 0x0000, 0x0505, 0x0505, 0x0805, 0x0002, 0x0303, 0x0202, 0x0202, 0x0002, 0x0707, 0x0002, 0x0000, 0x0000, 0x0707, 0x0002, 0x0000, 0x0000, 0x0202, 0x0002, 0x0000, 0x0000, 0x0900, 0x0101, 0x0101, 0x000A, 0x0109, 0x0A01, 0x0902, 0x0A01, 0x0404, 0x020A, 0x0000, 0x0200, 0x0505, 0x0002, 0x0505, 0x0205, 0x0303, 0x000A, 0x0302, 0x0203, 0x0706, 0x0207, 0x0700, 0x0207, 0x0602, 0x0707, 0x0707, 0x0206, 0x0200, 0x0202, 0x0202, 0x0002, 0x0101, 0x0002, 0x0100, 0x0201, 0x0101, 0x0002, 0x0100, 0x0201, 0x0404, 0x0002, 0x0100, 0x0204, 0x0505, 0x0505, 0x0505, 0x0205, 0x0303, 0x0202, 0x0302, 0x0203, 0x0707, 0x0002, 0x0700, 0x0207, 0x0707, 0x0002, 0x0800, 0x0208, 0x0202, 0x0002, 0x0200, 0x0202, 0x0000, 0x0101, 0x0002, 0x0000, 0x0000, 0x0101, 0x0002, 0x0000, 0x0000, 0x0404, 0x0002, 0x0000, 0x0000, 0x0505, 0x0002, 0x0000, 0x0000, 0x0303, 0x0002, 0x0000, 0x0000, 0x0707, 0x0002, 0x0000, 0x0000, 0x0808, 0x0002, 0x0000, 0x0000, 0x0202, 0x0002, 0x0000, 0x0000, 0x0000, 0x0100, 0x0201, 0x0000, 0x0000, 0x0100, 0x0201, 0x0000, 0x0000, 0x0400, 0x0204, 0x0000, 0x0000, 0x0500, 0x0205, 0x0000, 0x0000, 0x0300, 0x0203, 0x0000, 0x0000, 0x0708, 0x0208, 0x0702, 0x0707, 0x0807, 0x0202, 0x0200, 0x0202, 0x0202, 0x0002, 0x0101, 0x0002, 0x0100, 0x0009, 0x0101, 0x0002, 0x0301, 0x0002, 0x0404, 0x0402, 0x0203, 0x0000, 0x0505, 0x0805, 0x0002, 0x0000, 0x0303, 0x0302, 0x0A08, 0x0000, 0x0707, 0x0202, 0x0807, 0x000A, 0x0808, 0x0002, 0x0702, 0x0A08, 0x0202, 0x0002, 0x0200, 0x0202, 0x0101, 0x0002, 0x0000, 0x0000, 0x0101, 0x0002, 0x0000, 0x0000, 0x0404, 0x0002, 0x0000, 0x0000, 0x0505, 0x0002, 0x0000, 0x0000, 0x0303, 0x0002, 0x0000, 0x0000, 0x0707, 0x0002, 0x0000, 0x0000, 0x0707, 0x0707, 0x0707, 0x0208, 0x0202, 0x0202, 0x0202, 0x0202, 0x0901, 0x0002, 0x0900, 0x0201, 0x0101, 0x0209, 0x0109, 0x0201, 0x0404, 0x0304, 0x0404, 0x0204, 0x0505, 0x0508, 0x0508, 0x0205, 0x0803, 0x030A, 0x080A, 0x0203, 0x0807, 0x0202, 0x0802, 0x0207, 0x0807, 0x0002, 0x0800, 0x0208, 0x0202, 0x0002, 0x0200, 0x0202, 0x0101, 0x0000, 0x0100, 0x0201, 0x0101, 0x0001, 0x0100, 0x0201, 0x0404, 0x0403, 0x0400, 0x0204, 0x0505, 0x080A, 0x0505, 0x0205, 0x0303, 0x0202, 0x0308, 0x0203, 0x0707, 0x0002, 0x0702, 0x0207, 0x0707, 0x0002, 0x0800, 0x0208, 0x0202, 0x0002, 0x0000, 0x0202, 0x030A, 0x0101, 0x0301, 0x000A, 0x0103, 0x020A, 0x010A, 0x0203, 0x0404, 0x0002, 0x0402, 0x0204, 0x0505, 0x0002, 0x0500, 0x0205, 0x0303, 0x0002, 0x0300, 0x0203, 0x0708, 0x020A, 0x070A, 0x0208, 0x080A, 0x0707, 0x0807, 0x020A, 0x0200, 0x0202, 0x0202, 0x0002, 0x0101, 0x0101, 0x0101, 0x0009, 0x0101, 0x0202, 0x0102, 0x0201, 0x0404, 0x0002, 0x0400, 0x0204, 0x0505, 0x0505, 0x0505, 0x0206, 0x0303, 0x0202, 0x0202, 0x0002, 0x0707, 0x0002, 0x0000, 0x0000, 0x0707, 0x0002, 0x0000, 0x0000, 0x0202, 0x0002, 0x0000, 0x0000, 0x030A, 0x0101, 0x0301, 0x000A, 0x0103, 0x020A, 0x010A, 0x0203, 0x0404, 0x0002, 0x0402, 0x0204, 0x0505, 0x0002, 0x0500, 0x0205, 0x0303, 0x0702, 0x030A, 0x0208, 0x0708, 0x020A, 0x0707, 0x020A, 0x080A, 0x0707, 0x0A08, 0x0207, 0x0200, 0x0202, 0x0202, 0x0002, 0x0101, 0x0101, 0x0101, 0x0009, 0x0101, 0x0202, 0x0102, 0x0201, 0x0404, 0x0002, 0x0400, 0x0204, 0x0505, 0x0505, 0x0505, 0x0206, 0x0303, 0x0202, 0x0308, 0x0002, 0x0707, 0x0002, 0x0702, 0x0208, 0x0707, 0x0002, 0x0700, 0x0208, 0x0202, 0x0002, 0x0200, 0x0202, 0x0109, 0x0101, 0x0101, 0x0000, 0x0101, 0x020A, 0x0902, 0x0201, 0x0404, 0x0002, 0x0000, 0x0202, 0x0506, 0x0505, 0x0505, 0x0006, 0x0200, 0x0202, 0x030A, 0x0203, 0x0807, 0x0006, 0x0700, 0x0207, 0x0702, 0x0707, 0x0707, 0x0206, 0x0200, 0x0202, 0x0202, 0x0002, 0x0101, 0x0101, 0x0101, 0x0301, 0x0202, 0x0102, 0x0201, 0x0202, 0x0000, 0x0400, 0x0204, 0x0000, 0x0000, 0x0500, 0x0205, 0x0000, 0x0000, 0x0300, 0x0203, 0x0000, 0x0000, 0x0700, 0x0207, 0x0000, 0x0000, 0x0700, 0x0207, 0x0000, 0x0000, 0x0200, 0x0202, 0x0000, 0x0101, 0x0002, 0x0300, 0x0203, 0x0101, 0x0002, 0x0100, 0x0201, 0x0404, 0x0002, 0x0400, 0x0204, 0x0505, 0x0002, 0x0500, 0x0205, 0x0303, 0x0002, 0x0300, 0x0203, 0x0708, 0x0206, 0x0706, 0x0208, 0x0802, 0x0707, 0x0807, 0x020A, 0x0200, 0x0202, 0x0202, 0x0002, 0x0901, 0x0002, 0x0300, 0x0201, 0x0301, 0x0002, 0x0100, 0x0201, 0x0403, 0x0002, 0x0400, 0x0209, 0x0502, 0x0208, 0x0505, 0x0002, 0x0800, 0x0203, 0x0603, 0x0002, 0x0200, 0x0707, 0x0207, 0x0000, 0x0000, 0x0708, 0x0206, 0x0000, 0x0000, 0x0202, 0x0002, 0x0000, 0x0301, 0x0002, 0x0300, 0x0201, 0x0301, 0x0002, 0x0300, 0x0201, 0x0304, 0x0402, 0x0300, 0x0204, 0x0805, 0x0805, 0x0805, 0x0205, 0x0303, 0x0A03, 0x0308, 0x0203, 0x0707, 0x020A, 0x0802, 0x0207, 0x0A07, 0x0002, 0x0200, 0x0208, 0x0202, 0x0000, 0x0000, 0x0202, 0x0301, 0x0000, 0x0000, 0x0301, 0x0102, 0x0003, 0x0100, 0x0203, 0x0200, 0x0304, 0x0304, 0x0002, 0x0000, 0x0502, 0x0208, 0x0000, 0x0000, 0x0803, 0x0803, 0x0000, 0x0700, 0x0208, 0x0702, 0x0008, 0x0807, 0x0002, 0x0200, 0x0807, 0x020A, 0x0000, 0x0000, 0x0202, 0x0103, 0x0000, 0x0000, 0x0100, 0x0302, 0x0001, 0x0000, 0x0901, 0x0200, 0x0403, 0x0409, 0x0209, 0x0000, 0x0502, 0x0605, 0x0002, 0x0000, 0x0300, 0x0203, 0x0000, 0x0000, 0x0700, 0x0207, 0x0000, 0x0000, 0x0700, 0x0207, 0x0000, 0x0000, 0x0200, 0x0202, 0x0000, 0x0101, 0x0101, 0x0101, 0x0203, 0x0202, 0x0202, 0x0301, 0x0202, 0x0000, 0x0400, 0x0203, 0x0002, 0x0000, 0x0805, 0x0202, 0x0000, 0x0300, 0x0208, 0x0002, 0x0000, 0x0807, 0x0202, 0x0000, 0x0000, 0x0707, 0x0707, 0x0707, 0x0207, 0x0202, 0x0202, 0x0202, 0x0202, 0x0000, 0x0101, 0x0301, 0x0002, 0x0000, 0x0301, 0x0202, 0x0002, 0x0000, 0x0304, 0x0002, 0x0000, 0x0000, 0x0805, 0x0002, 0x0000, 0x0000, 0x0803, 0x0002, 0x0000, 0x0000, 0x0807, 0x0002, 0x0000, 0x0000, 0x0707, 0x0807, 0x0002, 0x0000, 0x0202, 0x0202, 0x0002, 0x0A01, 0x0000, 0x0000, 0x0000, 0x0102, 0x0009, 0x0000, 0x0000, 0x0200, 0x0904, 0x0000, 0x0000, 0x0000, 0x0502, 0x0006, 0x0000, 0x0000, 0x0200, 0x0603, 0x0000, 0x0000, 0x0000, 0x0702, 0x0006, 0x0000, 0x0000, 0x0200, 0x0A07, 0x0000, 0x0000, 0x0000, 0x0202, 0x0000, 0x0101, 0x0301, 0x0002, 0x0000, 0x0202, 0x0301, 0x0002, 0x0000, 0x0000, 0x0304, 0x0002, 0x0000, 0x0000, 0x0805, 0x0002, 0x0000, 0x0000, 0x0803, 0x0002, 0x0000, 0x0000, 0x0807, 0x0002, 0x0000, 0x0707, 0x0807, 0x0002, 0x0000, 0x0202, 0x0202, 0x0002, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0100, 0x000A, 0x0000, 0x0000, 0x0904, 0x0A04, 0x0000, 0x0500, 0x0206, 0x0502, 0x000A, 0x0200, 0x0002, 0x0200, 0x0002, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0707, 0x0707, 0x0707, 0x0208, 0x0202, 0x0202, 0x0202, 0x0202, 0x0000, 0x0100, 0x0901, 0x0000, 0x0000, 0x0100, 0x0202, 0x0000, 0x0000, 0x0900, 0x0204, 0x0000, 0x0000, 0x0000, 0x0202, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0404, 0x0304, 0x0000, 0x0000, 0x0200, 0x0502, 0x0008, 0x0000, 0x0303, 0x0303, 0x0208, 0x0700, 0x0208, 0x0702, 0x0208, 0x0000, 0x0707, 0x0707, 0x0207, 0x0000, 0x0200, 0x0202, 0x0202, 0x0100, 0x0001, 0x0000, 0x0000, 0x0100, 0x0201, 0x0000, 0x0000, 0x0400, 0x0404, 0x0404, 0x0000, 0x0500, 0x0205, 0x0802, 0x0005, 0x0300, 0x0203, 0x0000, 0x0203, 0x0700, 0x0207, 0x0600, 0x0207, 0x0700, 0x0707, 0x0707, 0x0206, 0x0000, 0x0202, 0x0202, 0x0002, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0403, 0x0404, 0x000A, 0x0800, 0x0A05, 0x0602, 0x0205, 0x0300, 0x0203, 0x0000, 0x0202, 0x0800, 0x0A07, 0x0000, 0x0207, 0x0200, 0x0708, 0x0707, 0x0206, 0x0000, 0x0202, 0x0202, 0x0002, 0x0000, 0x0000, 0x0100, 0x0201, 0x0000, 0x0000, 0x0100, 0x0201, 0x0000, 0x0404, 0x0404, 0x0204, 0x0500, 0x0208, 0x0502, 0x0205, 0x0300, 0x0002, 0x0300, 0x0203, 0x0700, 0x0006, 0x0700, 0x0207, 0x0A00, 0x0707, 0x0707, 0x0207, 0x0000, 0x0202, 0x0202, 0x0202, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0403, 0x0304, 0x0000, 0x0800, 0x0205, 0x0202, 0x0208, 0x0300, 0x0303, 0x0303, 0x0203, 0x0800, 0x0207, 0x0202, 0x0202, 0x0A00, 0x0708, 0x0707, 0x0002, 0x0000, 0x0202, 0x0202, 0x0002, 0x0000, 0x0A00, 0x0103, 0x0203, 0x0000, 0x0300, 0x0201, 0x0202, 0x0400, 0x0404, 0x0404, 0x0203, 0x0200, 0x0502, 0x0205, 0x0202, 0x0000, 0x0300, 0x0203, 0x0000, 0x0000, 0x0700, 0x0207, 0x0000, 0x0000, 0x0700, 0x0207, 0x0000, 0x0000, 0x0200, 0x0202, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0404, 0x0304, 0x0002, 0x0500, 0x0206, 0x0502, 0x0208, 0x0300, 0x0006, 0x0300, 0x0203, 0x0200, 0x0707, 0x0707, 0x0207, 0x0000, 0x0202, 0x0702, 0x0208, 0x0000, 0x0707, 0x0807, 0x0206, 0x0100, 0x0201, 0x0000, 0x0000, 0x0100, 0x0201, 0x0000, 0x0000, 0x0400, 0x0404, 0x0404, 0x0000, 0x0500, 0x0205, 0x0802, 0x0205, 0x0300, 0x0203, 0x0000, 0x0203, 0x0700, 0x0207, 0x0000, 0x0207, 0x0700, 0x0207, 0x0000, 0x0207, 0x0200, 0x0202, 0x0000, 0x0202, 0x0000, 0x0100, 0x0201, 0x0000, 0x0000, 0x0A00, 0x020A, 0x0000, 0x0000, 0x0300, 0x0203, 0x0000, 0x0000, 0x0500, 0x0205, 0x0000, 0x0000, 0x0300, 0x0203, 0x0000, 0x0000, 0x0700, 0x0207, 0x0000, 0x0000, 0x0700, 0x0207, 0x0000, 0x0000, 0x0200, 0x0202, 0x0000, 0x0000, 0x0100, 0x0201, 0x0000, 0x0000, 0x0A00, 0x020A, 0x0000, 0x0000, 0x0300, 0x0203, 0x0000, 0x0000, 0x0500, 0x0205, 0x0000, 0x0000, 0x0300, 0x0203, 0x0000, 0x0000, 0x0700, 0x0207, 0x0000, 0x0000, 0x0700, 0x0208, 0x0000, 0x0700, 0x0708, 0x020A, 0x0000, 0x0100, 0x0201, 0x0000, 0x0000, 0x0100, 0x0201, 0x0000, 0x0000, 0x0400, 0x0204, 0x0400, 0x0203, 0x0500, 0x0205, 0x0805, 0x0202, 0x0300, 0x0303, 0x0208, 0x0002, 0x0700, 0x0207, 0x0807, 0x0000, 0x0700, 0x0207, 0x0702, 0x0008, 0x0200, 0x0202, 0x0200, 0x0202, 0x0000, 0x0101, 0x0203, 0x0000, 0x0000, 0x0100, 0x0201, 0x0000, 0x0000, 0x0400, 0x0204, 0x0000, 0x0000, 0x0500, 0x0205, 0x0000, 0x0000, 0x0300, 0x0203, 0x0000, 0x0000, 0x0700, 0x0207, 0x0000, 0x0000, 0x0700, 0x0207, 0x0000, 0x0000, 0x0200, 0x0202, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0400, 0x0409, 0x040A, 0x000A, 0x0500, 0x0805, 0x0805, 0x0205, 0x0300, 0x0208, 0x0203, 0x0203, 0x0700, 0x0208, 0x0207, 0x0207, 0x0700, 0x0208, 0x0207, 0x0207, 0x0200, 0x0202, 0x0202, 0x0202, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0400, 0x0403, 0x0404, 0x0000, 0x0500, 0x0205, 0x0802, 0x0205, 0x0300, 0x0208, 0x0200, 0x0203, 0x0700, 0x0208, 0x0000, 0x0207, 0x0700, 0x0208, 0x0000, 0x0207, 0x0200, 0x0202, 0x0000, 0x0202, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0403, 0x0404, 0x0000, 0x0800, 0x0605, 0x0602, 0x0205, 0x0300, 0x0203, 0x0000, 0x0203, 0x0800, 0x0607, 0x0000, 0x0207, 0x0200, 0x0708, 0x0707, 0x0206, 0x0000, 0x0202, 0x0202, 0x0002, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0400, 0x0404, 0x0404, 0x0009, 0x0500, 0x0205, 0x0602, 0x0205, 0x0300, 0x0203, 0x0600, 0x0203, 0x0700, 0x0707, 0x0707, 0x0206, 0x0700, 0x0207, 0x0202, 0x0002, 0x0700, 0x0207, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0900, 0x0404, 0x0404, 0x0204, 0x0500, 0x0206, 0x0502, 0x0205, 0x0300, 0x0006, 0x0300, 0x0203, 0x0600, 0x0707, 0x0707, 0x0207, 0x0000, 0x0202, 0x0702, 0x0207, 0x0000, 0x0000, 0x0700, 0x0207, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0304, 0x0409, 0x0204, 0x0000, 0x0505, 0x0605, 0x0202, 0x0000, 0x0803, 0x0202, 0x0000, 0x0000, 0x0807, 0x0002, 0x0000, 0x0000, 0x0807, 0x0002, 0x0000, 0x0000, 0x0202, 0x0002, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0403, 0x0404, 0x0002, 0x0800, 0x0205, 0x0202, 0x0002, 0x0000, 0x0308, 0x0303, 0x0006, 0x0000, 0x0200, 0x0702, 0x0207, 0x0700, 0x0707, 0x0707, 0x0206, 0x0200, 0x0202, 0x0202, 0x0002, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0100, 0x0201, 0x0000, 0x0400, 0x0404, 0x0404, 0x0204, 0x0200, 0x0502, 0x0205, 0x0202, 0x0000, 0x0300, 0x0203, 0x0000, 0x0000, 0x0800, 0x0207, 0x0000, 0x0000, 0x0A00, 0x0708, 0x0007, 0x0000, 0x0000, 0x0202, 0x0202, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0400, 0x0002, 0x0400, 0x0204, 0x0500, 0x0002, 0x0500, 0x0205, 0x0300, 0x0002, 0x0300, 0x0203, 0x0700, 0x0008, 0x0700, 0x0208, 0x0200, 0x0707, 0x0807, 0x0206, 0x0000, 0x0202, 0x0202, 0x0202, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0400, 0x0002, 0x0400, 0x0204, 0x0800, 0x000A, 0x0500, 0x0208, 0x0600, 0x0203, 0x0303, 0x0206, 0x0000, 0x0A08, 0x0807, 0x0202, 0x0000, 0x0706, 0x0607, 0x0002, 0x0000, 0x0200, 0x0202, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0400, 0x0203, 0x0000, 0x0204, 0x0500, 0x0208, 0x0205, 0x0205, 0x0800, 0x0203, 0x0203, 0x0203, 0x0600, 0x0607, 0x0607, 0x0208, 0x0200, 0x0706, 0x0706, 0x0202, 0x0000, 0x0202, 0x0202, 0x0002, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0400, 0x0009, 0x0400, 0x0209, 0x0200, 0x0605, 0x0805, 0x0202, 0x0000, 0x0302, 0x0208, 0x0002, 0x0000, 0x0807, 0x0607, 0x0000, 0x0700, 0x0206, 0x0702, 0x0006, 0x0200, 0x0202, 0x0200, 0x0202, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0400, 0x0002, 0x0400, 0x0204, 0x0500, 0x0002, 0x0500, 0x0205, 0x0300, 0x0008, 0x0300, 0x0208, 0x0200, 0x0707, 0x0707, 0x0208, 0x0000, 0x0202, 0x0708, 0x0206, 0x0700, 0x0707, 0x0608, 0x0202, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0400, 0x0404, 0x0404, 0x0203, 0x0200, 0x0202, 0x0805, 0x0202, 0x0000, 0x0300, 0x0208, 0x0002, 0x0000, 0x0807, 0x0202, 0x0000, 0x0700, 0x0707, 0x0707, 0x0207, 0x0200, 0x0202, 0x0202, 0x0202, 0x0000, 0x0900, 0x0201, 0x0000, 0x0000, 0x0100, 0x020A, 0x0000, 0x0000, 0x0400, 0x0002, 0x0000, 0x0000, 0x0605, 0x0002, 0x0000, 0x0000, 0x0302, 0x0000, 0x0000, 0x0000, 0x0700, 0x000A, 0x0000, 0x0000, 0x0600, 0x0207, 0x0000, 0x0000, 0x0000, 0x0202, 0x0000, 0x0000, 0x0300, 0x0002, 0x0000, 0x0000, 0x0100, 0x0002, 0x0000, 0x0000, 0x0400, 0x0002, 0x0000, 0x0000, 0x0500, 0x0002, 0x0000, 0x0000, 0x0300, 0x0002, 0x0000, 0x0000, 0x0700, 0x0002, 0x0000, 0x0000, 0x0700, 0x0002, 0x0000, 0x0000, 0x0200, 0x0002, 0x0000, 0x0000, 0x0901, 0x0000, 0x0000, 0x0000, 0x0102, 0x0002, 0x0000, 0x0000, 0x0400, 0x0002, 0x0000, 0x0000, 0x0600, 0x0205, 0x0000, 0x0000, 0x0300, 0x0206, 0x0000, 0x0000, 0x0700, 0x0002, 0x0000, 0x0000, 0x0607, 0x0002, 0x0000, 0x0000, 0x0202, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0101, 0x0002, 0x0201, 0x0400, 0x0209, 0x0403, 0x0209, 0x0200, 0x0002, 0x0202, 0x0002, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000};

//palette information (all the colors used in the picture)
// BGR (xBBBBBGGGGGRRRRR)
const u16 fontPalette[] = {
0x0000, 0x7BFF, 0x0885, 0x4AF9, 0x6B9D, 0x5B3B, 0x21AF, 0x3A97, 0x2A13, 0x25F2, 0x194B, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, 0x7C1F, };

const u32 fontDataSize = sizeof(fontData) / sizeof(u16);
const u32 fontPaletteSize = sizeof(fontPalette) / sizeof(u16);
