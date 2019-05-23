# Operator 
## A expression evalator and multi language transpiler.

A  Cross Platform Node Based Editor developed in QT C++.
A builtin parser and python transplier is also written.
It usage absolutely zero third party libaries.

![working](https://user-images.githubusercontent.com/45932883/58257493-a515ad00-7d8e-11e9-93a4-959b0749083c.PNG)

The UI consist of 3 parts:
#### BlackBoard 
  ->black background grid area , movable,zoomable and resizable area,draws all connection.
#### NodeCore 
  ->base class of all operational Node entity , contains various properties and it store values and  connections.
##### Node UI Components 
     -> contain rewritten Label,NumberBox,TextBox,CheckBox , Port Connections etc.
     
## Caution
This is very early version things may break or may not work as expected.

## Usage
1. Right click on blackboard to bring context menu.
2. Start Adding And Connecting node.
3. When done Click on Result get button
4. #### Message Box Display Output if python is installed and Path is set
5. Currently output python file is generated at  
```
C:\Users\shive\OneDrive\Desktop\m.py 
```

     
     
## Output 
A python transpiled (.py) file generated as output of Program.


# Future Plans
######  Code Refactoring,Commenting and Code Cleanup
###### Transplier other major languages such as c++,c#.
###### Reflections for more Nodes.
###### More UI Controls
###### Serialization And Deserialization of Nodes
