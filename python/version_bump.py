import yaml

version= "0.0.0"
with open("./version.yaml", "r") as buffer:
    version= buffer.read()
version= yaml.safe_load(version)["version"]

if not version.count(".") == 2 and not len(version) == 5: # I hope ill never need anything above 9.9.9 =w=
    exit(1)

SplitS= version.split(".", 2)
NVArray= [0, 0, 0]
NVArray[0]= int(SplitS[0])
NVArray[1]= int(SplitS[1])
NVArray[2]= int(SplitS[2])

if NVArray[1] == 9 and NVArray[2] == 9:
    NVArray[1]= 0
    NVArray[2]= 0
    NVArray[0]= NVArray[0]+ 1
elif NVArray[2] == 9 and not NVArray[1] == 9:
    NVArray[2]= 0
    NVArray[1]= NVArray[1]+ 1
else:
    NVArray[2]= NVArray[2]+ 1

newVer= f"{NVArray[0]}.{NVArray[1]}.{NVArray[2]}"

print(f"old version:    {version}")
print(f"new version:    {newVer}")
print("~~~~~~~~~~~~~~~~~~~~~~")

def replace(file):
    newStr= ""
    try:
        with open(file, "r") as rbuffer:
            newStr= rbuffer.read().replace(version, newVer)
        with open(file, "w") as wbuffer:
            wbuffer.write(newStr)
        print(f"[  ok  ] bumped {newStr.count(newVer)} versions in: {file}")
    except Exception as e:
        print(f"[ fail ] couldn't update: {file} | error: {e}")

replace("./build/debian.sh")
replace("./build/debian/control")
replace("./build/debian/changelog")
replace("./python/version_build.py")
replace("./build/CMakeLists.txt")
