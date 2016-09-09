#ifndef SM_W_P_H_INCLUDED
#define SM_W_P_H_INCLUDED
#define true 1
#define false 0


typedef enum {
eShutdown = 0,
ePowerOn,
eHybernate,
eSDL,
eSDE,
eDDC,
eED
} eState;

typedef eState (*tFunctionPointer)(int, int, int, int);

void sm_p_process(void);

eState state_shutdown(int OnOff, int LidOnOff, int LFP, int EFP);
eState state_PowerOn(int OnOff, int LidOnOff, int LFP, int EFP);
eState state_Hybernate(int OnOff, int LidOnOff, int LFP, int EFP);
eState state_SDL(int OnOff, int LidOnOff, int LFP, int EFP);
eState state_SDE(int OnOff, int LidOnOff, int LFP, int EFP);
eState state_DDC(int OnOff, int LidOnOff, int LFP, int EFP);
eState state_ED(int OnOff, int LidOnOff, int LFP, int EFP);

#endif // SM_W_P_H_INCLUDED


