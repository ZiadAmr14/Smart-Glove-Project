#ifndef _Bit_Math_H
#define _Bit_Math_H

#define SETBit(Var,Bit_No) Var=Var |(1<<Bit_No)

#define CLRBIT(Var,Bit_No) Var=Var & (~(1<<Bit_No))

#define ToggleBit(Var,Bit_No) Var=Var ^ (1<<Bit_No)

#define GetBit(Var,Bit_No) (Var>>Bit_No)&1

#endif
