cmd_/home/desd/KM_GITHUB/LDD/Module_prog/add/Module.symvers := sed 's/\.ko$$/\.o/' /home/desd/KM_GITHUB/LDD/Module_prog/add/modules.order | scripts/mod/modpost -m -a  -o /home/desd/KM_GITHUB/LDD/Module_prog/add/Module.symvers -e -i Module.symvers   -T -