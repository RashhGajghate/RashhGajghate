cmd_/home/desd/KM_GITHUB/LDD/Linux-devicedriver/Multiple_CDD/Module.symvers := sed 's/\.ko$$/\.o/' /home/desd/KM_GITHUB/LDD/Linux-devicedriver/Multiple_CDD/modules.order | scripts/mod/modpost -m -a  -o /home/desd/KM_GITHUB/LDD/Linux-devicedriver/Multiple_CDD/Module.symvers -e -i Module.symvers   -T -