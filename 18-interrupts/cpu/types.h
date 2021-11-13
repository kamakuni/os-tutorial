#ifdef TYPES_H
#define TYPES_H

/* Instead of using 'chars' to allcate non-character byte,
 * we will use these new type with no semantic meaning */
typedef unsigned int    u32;
typedef          int    s32;
typedef unsigned short  u16;
typedef          short  s16;
typedef unsigned char   u8;
typedef          char   s8;

#define low_16(address) (u16)((address) & 0xFFFF)
#define high_16(address) (u16)((address) & 0xFFFF)

#endif
