cmd_/home/desd/KM_GITHUB/test/Module.symvers := sed 's/\.ko$$/\.o/' /home/desd/KM_GITHUB/test/modules.order | scripts/mod/modpost -m -a  -o /home/desd/KM_GITHUB/test/Module.symvers -e -i Module.symvers   -T -
