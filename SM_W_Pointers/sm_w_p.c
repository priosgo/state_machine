#include "sm_w_p.h"
#include <stdio.h>
#include <stdlib.h>
tFunctionPointer test;

tFunctionPointer SMTable[7]  = {&state_shutdown, &state_PowerOn, &state_Hybernate, &state_SDL, &state_SDE, &state_DDC, &state_ED};;
eState sm_state;
void sm_p_process(void){

sm_state=(*SMTable[sm_state])(1,0,1,0);

}

eState state_shutdown(int OnOff, int LidOnOff, int LFP, int EFP){
eState lsm_state;
            //Transition conditions
            if (OnOff == true){
                lsm_state = ePowerOn;
            } else {
                lsm_state = eShutdown;
            }
return(lsm_state);
}

eState state_PowerOn(int OnOff, int LidOnOff, int LFP, int EFP){
eState lsm_state=0;
if (OnOff == false){
                lsm_state = eShutdown;
            } else {
                if (LidOnOff==false){
                    lsm_state=eHybernate;
                }else{
                    if (LFP == false && EFP == false){
                        lsm_state = ePowerOn;
                    } else if(LFP == false && EFP == true){
                        lsm_state = eSDE;
                    } else if (LFP == true && EFP == false){
                            lsm_state = eSDL;
                    } else if (LFP == true && EFP == true){
                            lsm_state = eDDC;
                    }
                    }
                }
return(lsm_state);
}
eState state_Hybernate(int OnOff, int LidOnOff, int LFP, int EFP){
    eState lsm_state=0;
    if (OnOff == false){

            } else {
                if (LidOnOff==false){

                }else{
                    if (LFP == false && EFP == false){
                        lsm_state = ePowerOn;
                    } else if(LFP == false && EFP == true){
                        lsm_state = eSDE;
                    } else if (LFP == true && EFP == false){
                            lsm_state = eSDL;
                    } else if (LFP == true && EFP == true){
                            lsm_state = eDDC;
                    }
                }
            }

return lsm_state;
}
eState state_SDL(int OnOff, int LidOnOff, int LFP, int EFP){
    eState lsm_state=0;
    if (OnOff == false){
                lsm_state = eShutdown;
            } else {
                if(LidOnOff==false){
                    lsm_state = eHybernate;
                }else{
                    if (LFP == false && EFP == false){
                        lsm_state = ePowerOn;
                    } else if(LFP == false && EFP == true){
                        lsm_state = eSDE;
                    } else if (LFP == true && EFP == false){
                            lsm_state = eSDL;
                    } else if (LFP == true && EFP == true){
                            lsm_state = eDDC;
                    }
                }
            }
return lsm_state;
}
eState state_SDE(int OnOff, int LidOnOff, int LFP, int EFP){
    eState lsm_state=0;
    if (OnOff == false){
                lsm_state = eShutdown;
            } else {
                if(LidOnOff==false){
                    lsm_state = eHybernate;
                }else{
                    if (LFP == false && EFP == false){
                        lsm_state = ePowerOn;
                    } else if(LFP == false && EFP == true){
                        lsm_state = eSDE;
                    } else if (LFP == true && EFP == false){
                            lsm_state = eSDL;
                    } else if (LFP == true && EFP == true){
                            lsm_state = eDDC;
                    }
                }
            }
return lsm_state;
}
eState state_DDC(int OnOff, int LidOnOff, int LFP, int EFP){
    eState lsm_state=0;
    if (OnOff == false){
                lsm_state = eShutdown;
            } else {
                if(LidOnOff==false){
                    lsm_state = eHybernate;
                }else{
                    if (LFP == false && EFP == false){
                        lsm_state = ePowerOn;
                    } else if(LFP == false && EFP == true){
                        lsm_state = eSDE;
                    } else if (LFP == true && EFP == false){
                            lsm_state = eSDL;
                    } else if (LFP == true && EFP == true){
                            lsm_state = eDDC;
                    }
                }
            }
return lsm_state;
}
eState state_ED(int OnOff, int LidOnOff, int LFP, int EFP){
eState lsm_state=0;

if (OnOff == false){
                lsm_state = eShutdown;
            } else {
                if (LidOnOff==false){
                    lsm_state = eHybernate;
                }else{
                    if (LFP == false && EFP == false){
                        lsm_state = ePowerOn;
                    } else if(LFP == false && EFP == true){
                        lsm_state = eSDE;
                    } else if (LFP == true && EFP == false){
                            lsm_state = eSDL;
                    } else if (LFP == true && EFP == true){
                            lsm_state = eDDC;
                    } else lsm_state = eED;
                }
            }
return lsm_state;
}
