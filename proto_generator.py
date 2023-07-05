

import subprocess
from sys import stderr
import os

def install_and_initialize_nanopb():

    print("Installing Nanopb in the PC to be used to generate the protobuf files.", end='')
    try:

        result = subprocess.run(["pip3", "install", "--user","grpcio-tools"], check=False, capture_output=True)
        if result.returncode:
            print(" [Fail]")
            print(result.stderr.decode("utf-8"), end='', file=stderr)
            exit(1)


        
        # result = subprocess.run(["sudo", "-S", "apt","install","protobuf-compiler"], check=False, capture_output=True,text=True)
        # print(result.stdout)
        # if result.returncode:
        #     print(" [Fail]")
        #     print(result.stderr.decode("utf-8"), end='', file=stderr)
        #     exit(1)

        if os.path.isdir("nanopb-src"):
            result = subprocess.run(["git", "submodule", "update","--init","--recursive"], check=False, capture_output=True)
            if result.returncode:
                print(" [Fail]")
                print(result.stderr.decode("utf-8"), end='', file=stderr)
                exit(1)
            else:
                print(" [Success]")
        else:
            result = subprocess.run(["git", "submodule","add", "git@github.com:nanopb/nanopb.git","nanopb-src"], check=False, capture_output=True)
            if result.returncode:
                print(" [Fail]")
                print(result.stderr.decode("utf-8"), end='', file=stderr)
                exit(1)
            else:
                print(" [Success]")
    except OSError:
        print(" [Fail]")
        print("Unable to find git in your path.")
        print("Stopping the setup.")
        print("Have you installed the protobuf compiler? Type: sudo apt install protobuf-compiler")
        exit(1)
    except Exception as e:    
        print(" [Fail]")
        print("Error: " + str(e), file=stderr)
        print("Have you installed the protobuf compiler? Type: sudo apt install protobuf-compiler")
        exit(1)

def generate_source_code():
    print("Generating source files based on messages.proto.", end='')
    try:
        os.chdir("proto")
        
        command = ["protoc", "messages.proto","--plugin=protoc-gen-nanopb=/home/jeff/STM32CubeIDE/workspace_1.12.1/Intruder-Detection-System/nanopb-src/generator/protoc-gen-nanopb", "--nanopb_out=.", 
               "--proto_path","/home/jeff/STM32CubeIDE/workspace_1.12.1/Intruder-Detection-System/nanopb-src/generator/proto","--proto_path","/home/jeff/STM32CubeIDE/workspace_1.12.1/Intruder-Detection-System/proto"]
        # command = ["protoc", "--plugin=protoc-gen-nanopb=/home/jeff/STM32CubeIDE/workspace_1.12.1/Intruder-Detection-System/nanopb-src/generator/protoc-gen-nanopb", "--nanopb_out=.", 
        #         "./messages.proto","--proto_path","/home/jeff/STM32CubeIDE/workspace_1.12.1/Intruder-Detection-System/nanopb-src/generator/proto"]
        
        # command = ["protoc", "--plugin=protoc-gen-nanopb=/home/jeff/STM32CubeIDE/workspace_1.12.1/Intruder-Detection-System/nanopb-src/generator/", "--nanopb_out=.", 
        #         "./messages.proto"]
    
            
        result = subprocess.run(command, check=False, capture_output=True)
   
        os.chdir("..")

        if result.returncode:
            print(" [Fail]")
            print(result.stderr.decode("utf-8"), end='', file=stderr)
            exit(1)
        else:
            print(" [Success]")                             
                        
    except Exception as e:    
        print(" [Fail]")
        print("Error: " + str(e), file=stderr)
        exit(1)

def prepare_generated_files():
    newpath = r"./ConstrainedDeviceApp/Middlewares/Third_Party/generated"
    if not os.path.exists(newpath):
        os.makedirs(newpath)

    os.chdir("proto")
    copy_path = "../"+newpath

    # command1 = ["cp", "./messages.pb.c",copy_path]
    # command2 = ["cp", "./messages.pb.h",copy_path]

    command = [["cp", "./messages.pb.c",copy_path],["cp", "./messages.pb.h",copy_path]]
    try:
        print("Copying generated protobuf files into target directory: "+newpath, end='')
        for cmd in command:
            
            result = subprocess.run(cmd, check=False, capture_output=True)
    
            if result.returncode:
                print(" [Fail]")
                print(result.stderr.decode("utf-8"), end='', file=stderr)
                exit(1)
            else:
                print(" [Success]")                             
        os.chdir("..")
        command.clear()               
    except Exception as e:    
        print(" [Fail]")
        print("Error: " + str(e), file=stderr)
        exit(1)

    os.chdir("nanopb-src")
    command = [["cp", "./pb.h",copy_path],["cp", "./pb_encode.c",copy_path],["cp", "./pb_encode.h",copy_path],["cp", "./pb_decode.c",copy_path],["cp", "./pb_decode.h",copy_path],["cp", "./pb_common.c",copy_path],["cp", "./pb_common.h",copy_path]]
   
    try:
        print("Copying nanopb protobuf files into target directory: "+newpath, end='')
        for cmd in command:
            result = subprocess.run(cmd, check=False, capture_output=True)
    
            if result.returncode:
                print(" [Fail]")
                print(result.stderr.decode("utf-8"), end='', file=stderr)
                exit(1)
            else:
                print(" [Success]")                             
        os.chdir("..")
        command.clear()               
    except Exception as e:    
        print(" [Fail]")
        print("Error: " + str(e), file=stderr)
        exit(1)

if __name__ == "__main__":


    # ---------------------------------------
    install_and_initialize_nanopb()
    generate_source_code()
    prepare_generated_files()

    # ---------------------------------------
    # If the script did not exit before here we have completed it with success.
    print("Setup completed with success!")