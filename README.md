# Arduino SD Card Text Parser 
<p>

A very basic text parser utilizing the SD Arduino library. The parser runs down a text file one line at a time and uses a special formatting style to read each one. The format is as follows:  </p>

```
$_name_{ingredient1,portion1;ingredient2, portion2}
```

The `$` being the start of a line, `{` being the end of the name, and the items being split by comma or semicolon. In this case the comma works also like a ratio symbol `:` by being the ratio between each ingredient and its portion. 

The goal is to allow the Arduino to access an SD card like a hard drive and read from files much larger than their RAM. To edit the formatting, edit `struct` variables.
<br />
<br />
<sub><sup>Just a small program I worked on in my journey of learning C++ and Arduino!</sup></sub>

