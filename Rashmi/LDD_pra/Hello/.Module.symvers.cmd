cmd_/home/desd/directory_2023/Rashmi/LDD_pra/Hello/Module.symvers := sed 's/\.ko$$/\.o/' /home/desd/directory_2023/Rashmi/LDD_pra/Hello/modules.order | scripts/mod/modpost -m -a  -o /home/desd/directory_2023/Rashmi/LDD_pra/Hello/Module.symvers -e -i Module.symvers   -T -