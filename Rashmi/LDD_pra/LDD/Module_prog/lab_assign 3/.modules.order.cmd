cmd_/home/desd/KM_GITHUB/LDD/Module_prog/lab/modules.order := {   echo /home/desd/KM_GITHUB/LDD/Module_prog/lab/one.ko;   echo /home/desd/KM_GITHUB/LDD/Module_prog/lab/two.ko; :; } | awk '!x[$$0]++' - > /home/desd/KM_GITHUB/LDD/Module_prog/lab/modules.order