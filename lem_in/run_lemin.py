#!python3
import sys
import os
import subprocess as spr

def print_usage():
    print(
    '''usage: run_lemin arg1 arg2
    arg1 = name of lem-in file
    arg2 = file with anthill (z or no_z)

    this program do:
        1. run lem-in < [map....no_z]
        2. remake res of lem-in to map with z coordinate
        3. run ./visu with res with z coordinate
    ''')

if len(sys.argv) != 3:
    print_usage()
    exit()

prog_name = sys.argv[1]
prog_name_base = os.path.basename(sys.argv[1])
map_name = sys.argv[2]

if "_no_z" in map_name:
    map_name_no_z = map_name
    map_name_z = map_name.replace("_no_z", "_z")
elif "_z" in map_name:
    map_name_z = map_name
    map_name_no_z = map_name.replace("_z", "_no_z")
else:
    print("error map name")

res_name_no_z = map_name_no_z + "_res_" + prog_name_base
res_name_z = map_name_z + "_res_" + prog_name_base

start_str = prog_name + " < " + map_name_no_z + " > " + res_name_no_z
print(start_str)
p = spr.Popen(start_str, shell=True)
p.wait()
start_convert_str = "python3 _convert_res_noz_to_z.py " + map_name_z + " " + res_name_no_z + " > " + res_name_z
print(start_convert_str)
p = spr.Popen(start_convert_str, shell=True)
p.wait()

p = spr.Popen("./visu " + res_name_z, shell=True)
print("finished")
