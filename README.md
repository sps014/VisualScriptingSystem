# Operator 
## A expression evalator and python transpiler.

A  Cross Platform Node Based Editor developed in QT C++.
A builtin parser and python transplier is also written.
##### It usage absolutely zero third party libaries.

![working](https://user-images.githubusercontent.com/45932883/58257493-a515ad00-7d8e-11e9-93a4-959b0749083c.PNG)

The Above Node Connection Generated the following code
```
def add(a,b):
 return a+b

def subtract(a,b):
 return a-b

def multiply(a,b):
 return a*b


print(multiply(add(9.8 ,11.7),subtract(11.7,9.6)))

```
### Nodes are arranged in context menu
![app context menu](https://user-images.githubusercontent.com/45932883/58385328-61c87200-800c-11e9-8737-96bbcefdd2a1.PNG)


### Integrated Error System (Powered by Python Interpreter)

![error_dialog](https://user-images.githubusercontent.com/45932883/58385355-cdaada80-800c-11e9-934b-e0b7b3d844f8.PNG)

---

The UI consist of 3 parts:
#### BlackBoard 
  ->black background grid area , movable,zoomable and resizable area,draws all connection.
#### NodeCore 
  ->base class of all operational Node entity , contains various properties and it store values and  connections.
##### Node UI Components 
     -> contain rewritten Label,NumberBox,TextBox,CheckBox ,Combobox, Port Connections etc.
   
---
## Caution
This is very early version things may break or may not work as expected.

---
## Usage
1. Right click on blackboard to bring context menu.
2. Start Adding And Connecting node.
3. When done Click on Result get button
4. #### Message Box Display Output if python is installed and Path is set
5. Currently output python file is generated at  
```
C:\Users\shive\OneDrive\Desktop\m.py 
```

 ---  
     
## Output 
A python transpiled (.py) file generated as output of Program.

---

## Build
```shell
windeployqt --qmldir C:\Users\Path\Project\Operator  C:\Users\Path\ReleaseBinary\build-Operator-Desktop_Qt_5_13_0_MinGW_64_bit-Release\release\operator.exe
```

# Future Plans
######  Code Refactoring,Commenting and Code Cleanup
###### Reflections for more Nodes.
###### More UI Controls
###### Serialization And Deserialization of Nodes
