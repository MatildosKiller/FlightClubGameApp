import subprocess

sourse_files = ["main.cpp","Character.cpp","Math.cpp","Weapon.cpp"]
output_executable = "FightClubGame.exe"
vs_edition = "Community"
arch = 64

#vs
vs_path = r"c:\Program Files\Microsoft Visual Studio\2022"
vcvars_suffix = r"VC\Auxiliary\Build"
vcvarsall_path = rf"{vs_path}\{vs_edition}\{vcvars_suffix}\vcvars{arch}.bat"

#compiler
compile_command = ["cl"]+sourse_files+["/c","/O2","/EHsc","/FAc"]

#linker
def source_to_obj(files):
    return [f.replace(".cpp",".obj") for f in files]

obj_files = source_to_obj(sourse_files)

link_command = ["link"]+obj_files+["/out:" + output_executable, "/time","/map","/nologo"]

build_commands = [
    compile_command,
    link_command
]

def run_command (command):
    try:
        subprocess.run(command)
    except subprocess.CalledProcessError as e:
        print(f"Error running command: {' '.join(command)}")
        print(e.stderr)

if __name__=="__main__":
    print("Compilling and linking game...")
    build_command = [vcvarsall_path,"&&"]
    for command in build_commands:
        build_command+= command + ["&&"]
    build_command.pop()
    build_command_str = ' '.join(build_command)

    run_command(build_command_str)



