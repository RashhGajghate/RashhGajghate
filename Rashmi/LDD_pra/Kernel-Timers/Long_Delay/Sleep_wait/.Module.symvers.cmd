cmd_/home/desd/KM_GITHUB/Kernel-Timers/Long_Delay/Sleep_wait/Module.symvers := sed 's/\.ko$$/\.o/' /home/desd/KM_GITHUB/Kernel-Timers/Long_Delay/Sleep_wait/modules.order | scripts/mod/modpost -m -a  -o /home/desd/KM_GITHUB/Kernel-Timers/Long_Delay/Sleep_wait/Module.symvers -e -i Module.symvers   -T -