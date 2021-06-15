#ifndef GXM_BIT_H
#define GXM_BIT_H

#define GXM_BIT32_B0(u) ((u)&0xF)
#define GXM_BIT32_B1(u) (((u) >> 8) & 0xF)
#define GXM_BIT32_B2(u) (((u) >> 16) & 0xF)
#define GXM_BIT32_B3(u) (((u) >> 24) & 0xF)

#define GXM_BIT32(b3, b2, b1, b0)                                              \
    (((b3) << 24) | ((b2) << 16) | ((b1) << 8) | ((b0)))

#endif